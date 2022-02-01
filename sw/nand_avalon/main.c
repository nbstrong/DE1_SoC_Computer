#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "address_map_arm.h"
#include "nand.h"

#define PRINT_PASSES 1 // Whether to print passing compare results
#define NUM_COLS 10          // How many addresses to test
#define NUM_PAGES 3
#define NUM_BLOCKS 3

void compare(uint8_t a, uint8_t b);
void print_chip_id();
void print_status();
void simplePageTest(uint16_t num_pages);
void patternPageTest(uint16_t num_pages);
void simpleBlockTest(uint16_t num_blocks, uint16_t num_pages);

uint16_t fails, compares = 0;

int main(void) {
    init_nand();

    print_chip_id();
    print_status();

    // simplePageTest(NUM_PAGES);
    // patternPageTest(NUM_PAGES);

    simpleBlockTest(NUM_BLOCKS, NUM_PAGES);

    // Erase chip
    _command_write(NAND_BLOCK_ERASE_CMD);

    printf("\n\n[Compares:Fails] %hi:%hi", compares, fails);
    printf("\nFin.");
    while(1) {}
    return 0;
}

void compare(uint8_t a, uint8_t b) {
    compares++;
    if(a == b) {
        if(PRINT_PASSES) {
            printf("%hhx == %hhx : [PASS]", a, b);
        }
    }
    else {
        printf("%hhx != %hhx : [FAIL]", a, b);
        fails++;
    }
}

void print_chip_id() {
    _command_write(CTRL_RESET_INDEX_CMD);
    for(uint8_t i = 0; i < 5; i++) {
        uint8_t id = 0;
        id = _command_read(CTRL_GET_ID_BYTE_CMD);
        printf("\nID Byte %hhi : %hhx", i, id);
    }
}

void print_status() {
    uint8_t status = 0;
    status = _command_read(CTRL_GET_STATUS_CMD);
    printf("\n\n%hhx : is ONFI compliant          ", ((status >> 0) & 1));
    printf("\n%hhx : bus width (0 - x8 / 1 - x16) ", ((status >> 1) & 1));
    printf("\n%hhx : is chip enabled              ", ((status >> 2) & 1));
    printf("\n%hhx : is chip write protected      ", ((status >> 3) & 1));
    printf("\n%hhx : array pointer out of bounds  ", ((status >> 4) & 1));
}

void simplePageTest(uint16_t num_pages) {
    // Writes the first three pages with its page_buf address + 1
    uint8_t* page_buf = (uint8_t*)calloc(sizeof(uint8_t), PAGELEN);

    for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
        memset(page_buf, (page_addr + 1), PAGELEN);
        set_address(page_addr << 16);
        write_page(page_buf);
    }

    for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
        set_address(page_addr << 16);
        page_buf = read_page(page_buf);

        for(int col_addr = 0; col_addr < NUM_COLS; col_addr++) {
            printf("\n%x : ", (((page_addr << 16) | col_addr)));
            compare(page_addr + 1, *(page_buf + page_addr));
        }
    }

    free(page_buf);
}

void patternPageTest(uint16_t num_pages) {
    // Writes the first three pages with its col address
    uint8_t* page_buf = (uint8_t*)calloc(sizeof(uint8_t), PAGELEN);
    assert(NUM_COLS <= 512);

    for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
        // Write pattern to page_buf buffer
        for(uint8_t col_addr = 0; col_addr < NUM_COLS; col_addr++) {
            *(page_buf + col_addr) = col_addr;
        }

        set_address(page_addr << 16);
        write_page(page_buf);
    }

    for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
        set_address(page_addr << 16);
        page_buf = read_page(page_buf);

        for(uint8_t col_addr = 0; col_addr < NUM_COLS; col_addr++) {
            printf("\n%x : ", (((page_addr << 16) | col_addr)));
            compare(*(page_buf + col_addr), col_addr);
        }
    }

    free(page_buf);
}

void simpleBlockTest(uint16_t num_blocks, uint16_t num_pages) {
    // Writes the first three pages with its page_buf address + 1
    uint8_t* page_buf = (uint8_t*)calloc(sizeof(uint8_t), PAGELEN);

    for (uint16_t block_addr = 0; block_addr < num_blocks; block_addr++) {
        for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
            memset(page_buf, (page_addr + 1), PAGELEN);
            set_address(block_addr << 27 | page_addr << 16);
            write_page(page_buf);
        }

        for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
            set_address(block_addr << 27 | page_addr << 16);
            page_buf = read_page(page_buf);

            for(int col_addr = 0; col_addr < NUM_COLS; col_addr++) {
                printf("\n%x : ", (((block_addr << 27) | (page_addr << 16) | col_addr)));
                compare(page_addr + 1, *(page_buf + page_addr));
            }
        }
    }

    free(page_buf);
}
