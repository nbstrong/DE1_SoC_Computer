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
#define PRIV_TIMER_LOAD ((volatile int*) MPCORE_PRIV_TIMER+0)
#define PRIV_TIMER_COUNTER ((volatile int*) MPCORE_PRIV_TIMER+1)
#define PRIV_TIMER_CONTROL ((volatile int*) MPCORE_PRIV_TIMER+2)

#define TIMERINIT         0xFFFFFFFF // Timer Decrements (cannot be changed)
#define TIMERCLOCKSPERSEC 200000000  // ARM A9 MPCore Private Timer runs off 200 MHz
#define TIMERSTART        0x1        // Enable
#define TIMERSTOP         0x0        // Disable

void compare(uint8_t a, uint8_t b);
void print_chip_id();
void simplePageTest(uint8_t *page_buf, uint64_t address, uint16_t num_cols);
void patternPageTest(uint8_t *page_buf, uint16_t num_pages);
void simpleBlockTest(uint8_t *page_buf, uint16_t block_addr, uint16_t num_pages);

uint16_t fails, compares = 0;

int main(void) {
    uint8_t page[PAGELEN] = {0};
    unsigned int sw_timer_start, sw_timer_end, sw_timer_total = 0;
    *PRIV_TIMER_LOAD    = 0x0;
    *PRIV_TIMER_CONTROL = 0x0;

    init_nand();

    print_chip_id();
    print_status();


    for(int i = 0;i < 10; i++) {
      *PRIV_TIMER_LOAD = TIMERINIT;         // Initialize timer
      *PRIV_TIMER_CONTROL = TIMERSTART;     // Start timer
      sw_timer_start = *PRIV_TIMER_COUNTER; // Read current value

      write_page(page, gen_address(0,i,0));

      sw_timer_end = *PRIV_TIMER_COUNTER;   // Read current value
      *PRIV_TIMER_CONTROL = TIMERSTOP;      // Stop timer
      sw_timer_total = sw_timer_start - sw_timer_end;
      printf("\nSW Cycles: %u SW Time: %E sec", sw_timer_total, ((float)sw_timer_total)/TIMERCLOCKSPERSEC);
    }

    // memset(page, 1, PAGELEN);
    // simplePageTest(page, gen_address(0, 0, 0), NUM_COLS);

    // memset(page, 2, PAGELEN);
    // simplePageTest(page, gen_address(0, 1, 0), NUM_COLS);

    // memset(page, 1, PAGELEN);
    // simplePageTest(page, gen_address(0, 0, 0), NUM_COLS);

    // memset(page, 1, PAGELEN);
    // simplePageTest(page, gen_address(0, 0, 0), NUM_COLS);

    // simpleBlockTest(page, 2, NUM_PAGES);
    // simpleBlockTest(page, 20, NUM_PAGES);

    // This fails because I am not handling 64 bit numbers correctly
    // on a 32 bit embedded system.
    // simpleBlockTest(page, 200, NUM_PAGES);

    // _command_write(NAND_BLOCK_ERASE_CMD);

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

void simplePageTest(uint8_t *page_buf, uint64_t address, uint16_t num_cols) {
    // Writes a single page provided by page_buf to the nand page
    // Then compares expected vs actual values up to num_cols

    printf("\n\nExecuting Simple Page Test at Address %llx", address);

    // Copy the page to generate expected values
    uint8_t exp_page[PAGELEN] = {0};
    memcpy(exp_page, page_buf, PAGELEN);

    // Write the page and then read the page from nand
    write_page(page_buf, address);
    read_page(page_buf, address);

    // Compare the expected vs actual
    for(int col_addr = 0; col_addr < NUM_COLS; col_addr++) {
        printf("\n%x : ", col_addr);
        compare(exp_page[col_addr], page_buf[col_addr]);
    }
}

void simpleBlockTest(uint8_t *page_buf, uint16_t block_addr, uint16_t num_pages) {
    // Writes the first three pages with its page_buf address + 1

    printf("\n\nExecuting Simple Block Test at Block %x", block_addr);

    for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
        memset(page_buf, (page_addr + 1), PAGELEN);
        write_page(page_buf, gen_address(block_addr, page_addr, 0));
    }

    for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
        read_page(page_buf, gen_address(block_addr, page_addr, 0));

        for(int col_addr = 0; col_addr < NUM_COLS; col_addr++) {
            printf("\n%llx : ", gen_address(block_addr, page_addr, col_addr));
            compare(page_addr + 1, page_buf[page_addr]);
        }
    }
}
