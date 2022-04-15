#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "address_map_arm.h"
#include "../../hdl/rtl/nand_avalon/sw/nand.h"

#define VERBOSE 0 // Whether to print passing compare results
#define NUM_COLS 10          // How many addresses to test
#define NUM_PAGES 3
#define NUM_BLOCKS 3

void compare(uint8_t a, uint8_t b, uint64_t addr);
void print_chip_id();
void simplePageTest(uint8_t *page_buf, uint64_t address, uint16_t num_cols);
void patternPageTest(uint8_t *page_buf, uint16_t num_pages);
void simpleBlockTest(uint8_t *page_buf, uint16_t block_addr, uint16_t num_pages);
void compare_pages(uint8_t *page_buf, uint8_t *exp_page_buf, uint16_t num_bytes);
void startupTest();


uint32_t fails, compares = 0;

int main(void) {
    uint8_t page[PAGELEN] = {0};
    uint8_t exp_ones_page[PAGELEN] = {0};
    uint8_t exp_erased_page[PAGELEN] = {0};
    uint8_t exp_zeros_page[PAGELEN] = {0};
    uint64_t address = 0;

    init_nand();

    print_chip_id();
    print_status();

    startupTest();

    printf("\nFormat is Address : Cycles : Seconds");

    /**************************************************************************/
    // printf("\nMeasuring 10 pages writes of zeros to address 0");
    // memset(page, 0, PAGELEN);
    // _command_write(CTRL_RESET_INDEX_CMD);
    // for(uint16_t col_addr = 0; col_addr < PAGELEN; col_addr++) {
    //     _command_write_data(CTRL_SET_DATA_PAGE_BYTE_CMD, page[col_addr]);
    // }
    // for(int i = 0;i < 10; i++) {
    //   address = gen_address(0,0,0);
    //   _set_address(address);

    //   _command_write(NAND_PAGE_PROGRAM_CMD);

    //   print_time(address);
    // }

    /**************************************************************************/
    // printf("\nMeasuring 10 block erases on block 0");
    // address = gen_address(0,0,0);
    // _set_address(address);
    // for(int i = 0;i < 10; i++) {
    //   _command_write(NAND_BLOCK_ERASE_CMD);
    //   print_time(address);
    // }

    /**************************************************************************/
    // Note: Reads cannot be measured
    // printf("\nMeasuring 10 page reads on block 0");
    // address = gen_address(0,0,0);
    // _set_address(address);
    // for(int i = 0;i < 10; i++) {
    //   _command_write(NAND_READ_PAGE_CMD);
    //   print_time(address);
    // }

    /**************************************************************************/
    // printf("\nMeasuring 10 chip resets");
    // address = gen_address(0,0,0);
    // _set_address(address);
    // for(int i = 0;i < 10; i++) {
    //   _command_write(NAND_RESET_CMD);
    //   print_time(address);
    // }

    /**************************************************************************/
    // printf("\nMeasuring writing zeros to every page in a block");
    // memset(page, 0, PAGELEN);
    // _command_write(CTRL_RESET_INDEX_CMD);
    // for(uint16_t col_addr = 0; col_addr < PAGELEN; col_addr++) {
    //     _command_write_data(CTRL_SET_DATA_PAGE_BYTE_CMD, page[col_addr]);
    // }
    // for(int i = 0;i < 256; i++) {
    //   address = gen_address(0,i,0);
    //   _set_address(address);
    //   _command_write(NAND_PAGE_PROGRAM_CMD);
    //   print_time(address);
    // }

    /**************************************************************************/
    // printf("\nMeasuring writing zeros to every page in a block");
    // memset(page, 0, PAGELEN);
    // _command_write(CTRL_RESET_INDEX_CMD);
    // for(uint16_t col_addr = 0; col_addr < PAGELEN; col_addr++) {
    //     _command_write_data(CTRL_SET_DATA_PAGE_BYTE_CMD, page[col_addr]);
    // }
    // for(int i = 0;i < 256; i++) {
    //   address = gen_address(0,i,0);
    //   _set_address(address);
    //   _command_write(NAND_PAGE_PROGRAM_CMD);
    //   print_time(address);
    // }

    // /**************************************************************************/
    // printf("\nErasing a block, verifying, then writing ones to page 0 and interrupting. Then verifying");
    // memset(exp_ones_page, 0x1, PAGELEN);
    // memset(exp_erased_page, 0xFF, PAGELEN);
    // memset(exp_zeros_page, 0x0, PAGELEN);
    // // Set address for erase
    // address = gen_address(0,0,0);
    // _set_address(address);
    // // Erase block
    // _command_write(NAND_BLOCK_ERASE_CMD);
    // print_time(address);
    // // Verify page is erased
    // read_page(page, address);
    // printf("\nVerifying page is erased");
    // compare_pages(page, exp_erased_page, PAGELEN);
    // printf("\nDone verifying.");
    // // Setup extension modules to interrupt
    // _write_delay_reg(10000);
    // _write_cntrl_reg(1);
    // // Write exp_page to chip
    // write_page(exp_ones_page, address);
    // // Print how long the operation took
    // print_time(address);
    // // See what the difference between all exp_page and actual page is
    // _write_controller_buffer(exp_zeros_page);
    // _read_controller_buffer(page);
    // printf("\nVerifying controller buffer is different");
    // compare_pages(page, exp_zeros_page, PAGELEN);
    // printf("\nDone verifying.");
    // _command_write(NAND_READ_PARAMETER_PAGE_CMD); // Controller or nand chip requires this command to function correctly after interrupting
    // read_page(page, address);
    // printf("\nVerifying page is ones");
    // compare_pages(page, exp_ones_page, PAGELEN);
    // printf("\nDone verifying.");

    /**************************************************************************/
    printf("\nWriting ones to a block, verifying, then interrupting an erase to a block, and printing out the block");
    memset(exp_ones_page, 0x1, PAGELEN);
    memset(exp_erased_page, 0xFF, PAGELEN);
    memset(exp_zeros_page, 0x0, PAGELEN);
    // Set address
    address = gen_address(0,0,0);
    _set_address(address);
    // Writes ones to page
    write_page(exp_ones_page, address);
    print_time(address);
    read_page(page, address);
    printf("\nVerifying page is ones");
    compare_pages(page, exp_ones_page, PAGELEN);
    printf("\nDone verifying.");
    // Setup extension modules to interrupt
    _write_delay_reg(100000);
    _write_cntrl_reg(1);
    // Erase block
    _command_write(NAND_BLOCK_ERASE_CMD);
    print_time(address);
    // Verifying controller buffer is different
    _write_controller_buffer(exp_zeros_page);
    _read_controller_buffer(page);
    printf("\nVerifying controller buffer is different");
    compare_pages(page, exp_zeros_page, PAGELEN);
    printf("\nDone verifying.");
    // See what the difference between all exp_page and actual page is
    // _command_write(NAND_READ_PARAMETER_PAGE_CMD); // Controller or nand chip requires this command to function correctly after interrupting
    read_page(page, address);
    print_page_buffer(page, 500, 1);
    // compare_pages(page, exp_erased_page, 1000);

    // This fails because I am not handling 64 bit numbers correctly
    // on a 32 bit embedded system.
    // simpleBlockTest(page, 200, NUM_PAGES);

    printf("\n\n[Compares:Fails] %i:%i", compares, fails);
    printf("\nFin.");
    while(1) {}
    return 0;
}

void compare(uint8_t a, uint8_t b, uint64_t addr) {
    compares++;
    if(a == b) {
        if(VERBOSE) { printf("\n %llx : [PASS] : %hhx == %hhx", addr, a, b); }
    }
    else {
        printf("\n %llx  : [FAIL] : %hhx != %hhx", addr, a, b);
        fails++;
    }
}

void compare_pages(uint8_t *page_buf, uint8_t *exp_page_buf, uint16_t num_bytes) {
    // Compare the expected vs actual
    for(int byte_addr = 0; byte_addr < num_bytes; byte_addr++) {
        if(VERBOSE) { printf("%x : ", byte_addr); }
        compare(page_buf[byte_addr], exp_page_buf[byte_addr], byte_addr);
    }
}

void print_chip_id() {
    _command_write(CTRL_RESET_INDEX_CMD);
    for(uint8_t i = 0; i < 5; i++) {
        uint8_t id = 0;
        id = _command_read(CTRL_GET_ID_BYTE_CMD);
        printf("\nID Byte %hhi : %hhx", i, id);
    }
    printf("\n");
}

void simplePageTest(uint8_t *page_buf, uint64_t address, uint16_t num_cols) {
    // Writes a single page provided by page_buf to the nand page
    // Then compares expected vs actual values up to num_cols

    if(VERBOSE) { printf("\nExecuting Simple Page Test at Address %llx", address); }

    // Copy the page to generate expected values
    uint8_t exp_page[PAGELEN] = {0};
    uint8_t rd_page[PAGELEN] = {0};
    memcpy(exp_page, page_buf, PAGELEN);
    memset(rd_page, 0x72, PAGELEN);

    // Write the page and then read the page from nand
    write_page(exp_page, address);
    read_page(rd_page, address);
    compare_pages(rd_page, exp_page, num_cols);
}

// void simpleBlockTest(uint8_t *page_buf, uint16_t block_addr, uint16_t num_pages) {
//     // Writes the first three pages with its page_buf address + 1

//     if(VERBOSE) { printf("\n\nExecuting Simple Block Test at Block %x", block_addr); }

//     for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
//         memset(page_buf, (page_addr + 1), PAGELEN);
//         write_page(page_buf, gen_address(block_addr, page_addr, 0));
//     }

//     for(uint16_t page_addr = 0; page_addr < num_pages; page_addr++) {
//         read_page(page_buf, gen_address(block_addr, page_addr, 0));

//         for(int col_addr = 0; col_addr < NUM_COLS; col_addr++) {
//             printf("\n%llx : ", gen_address(block_addr, page_addr, col_addr));
//             compare(page_addr + 1, page_buf[page_addr]);
//         }
//     }
// }

void startupTest() {
  uint8_t page[PAGELEN] = {0};
  uint8_t exp_page[PAGELEN] = {0};

  printf("\nBeginning Startup Test");
  _command_write(NAND_BLOCK_ERASE_CMD);

  // Writes and Reads the first 5 pages
  for(int i = 0; i < 5;i++) {
    uint64_t address = gen_address(0, i, 0);
    if(VERBOSE) { printf("\nExecuting Page Write then Read at Address %llx", address); }
    memset(exp_page, i, PAGELEN);
    simplePageTest(exp_page, address, PAGELEN);
  }

  // Erase the block
  _command_write(NAND_BLOCK_ERASE_CMD);
  // Confirm its erased
  // Reads the first 5 pages
  for(int i = 0; i < 5;i++) {
    uint64_t address = gen_address(0, i, 0);
    if(VERBOSE) {  printf("\nExecuting Page Read at Address %llx", address); }
    memset(exp_page, 0xFF, PAGELEN);
    read_page(page, address);
    compare_pages(page, exp_page, PAGELEN);
  }

  // Writes the first 5 pages
  for(int i = 0; i < 5;i++) {
    uint64_t address = gen_address(0, i, 0);
    if(VERBOSE) {  printf("\nExecuting Page Write at Address %llx", address); }
    memset(exp_page, i, PAGELEN);
    write_page(exp_page, address);
  }

    // Reads the first 5 pages
  for(int i = 0; i < 5;i++) {
    uint64_t address = gen_address(0, i, 0);
    if(VERBOSE) {  printf("\nExecuting Page Read at Address %llx", address); }
    memset(exp_page, i, PAGELEN);
    read_page(page, address);
    compare_pages(page, exp_page, PAGELEN);
  }

  _command_write(NAND_BLOCK_ERASE_CMD);
  printf("\nStartup Test Complete\n");
}