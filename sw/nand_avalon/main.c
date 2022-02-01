#include <stdio.h>
#include <stdint.h>
#include "address_map_arm.h"
#include "nand.h"

#define PRINT_PASSES 1 // Whether to print passing compare results
#define N 10          // How many addresses to test

void compare(__uint8_t a, __uint8_t b);
void print_chip_id();
void print_status();
void simplePageTest();

uint8_t page [PAGELEN];

__uint16_t fails, compares = 0;

int main(void) {

    init_nand();

    print_chip_id();
    print_status();

    simplePageTest();

    // Erase chip
    _command_write(NAND_BLOCK_ERASE_CMD);
    // Verify chip is erased
    _command_write(NAND_READ_PAGE_CMD);
    _command_write(CTRL_RESET_INDEX_CMD);
    for(__uint16_t i = 0; i < N; i = i + 1) {
        __uint8_t rdData = _command_read(CTRL_GET_DATA_PAGE_BYTE_CMD);
        compare(rdData, 0xFF);
    }

    printf("\n\n[Compares:Fails] %hi:%hi", compares, fails);
    printf("\nFin.");
    while(1) {}
    return 0;
}

void compare(__uint8_t a, __uint8_t b) {
    compares++;
    if(a == b) {
        if(PRINT_PASSES) {
            printf("\n[PASS] : %hhx == %hhx", a, b);
        }
    }
    else {
        printf("\n[FAIL] : %hhx != %hhx", a, b);
        fails++;
    }
}

void print_chip_id() {
    _command_write(CTRL_RESET_INDEX_CMD);
    for(__uint8_t i = 0; i < 5; i++) {
        __uint8_t id = 0;
        id = _command_read(CTRL_GET_ID_BYTE_CMD);
        printf("\nID Byte %hhi : %hhx", i, id);
    }
}

void print_status() {
    __uint8_t status = 0;
    status = _command_read(CTRL_GET_STATUS_CMD);
    printf("\n\n%hhx : is ONFI compliant          ", ((status >> 0) & 1));
    printf("\n%hhx : bus width (0 - x8 / 1 - x16) ", ((status >> 1) & 1));
    printf("\n%hhx : is chip enabled              ", ((status >> 2) & 1));
    printf("\n%hhx : is chip write protected      ", ((status >> 3) & 1));
    printf("\n%hhx : array pointer out of bounds  ", ((status >> 4) & 1));
}

void simplePageTest() {
    // Writes the first three pages with its page address + 1
    __uint8_t rdData;
    __uint64_t addr = 0;

    __uint16_t num_pages = 3;
    for(__uint16_t pgAddr = 0; pgAddr < num_pages; pgAddr++) {
        addr = pgAddr << 16;
        set_address(addr);
        addr = get_address();
        printf("\nAddr %llx", addr);

        // // Write controller pages with known sequence
        // _command_write(CTRL_RESET_INDEX_CMD);
        // for(__uint16_t colAddr = 0; colAddr < N; colAddr++) {
        //     _command_write_data(CTRL_SET_DATA_PAGE_BYTE_CMD, pgAddr+1);
        // }
        // // Write controller pages to NAND
        // _command_write(NAND_PAGE_PROGRAM_CMD);
    }

    for(__uint16_t pgAddr = 0; pgAddr < num_pages; pgAddr++) {
        addr = pgAddr << 16;
        set_address(addr);
        addr = get_address();
        printf("\nAddr %llx", addr);

        // // Read previously written page from NAND
        // _command_write(NAND_READ_PAGE_CMD);
        // _command_write(CTRL_RESET_INDEX_CMD);
        // for(__uint16_t colAddr = 0; colAddr < N; colAddr++) {
        //     rdData = _command_read(CTRL_GET_DATA_PAGE_BYTE_CMD);
        //     compare(rdData, pgAddr+1);
        // }
    }
}
