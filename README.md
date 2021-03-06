# DE1_SoC_Computer

## Software Required:
Quartus Prime Version 18.1.0 Build 625 09/12/2018 SJ Lite Edition

ModelSim - INTEL FPGA STARTER EDITION 10.5b

Intel FPGA Monitor Program 18.1 (Dec 5, 2018)

## To clone:  
`git clone --recursive https://github.com/nbstrong/DE1_SoC_Computer.git`  

If the hdl/rtl/nand_avalon folder isn't showing as populated with files or they are out of date run:  
`git submodule sync && git submodule update`  

## To run simulations:
1. Open Modelsim and continue from TCL console
2. Navigate to hdl/rtl/nand_avalon/sim/modelsim/
3. run `do sim.do`

## To run hardware tests:
1. Open Intel FPGA University Monitor
2. Open project located in DE1_SoC_Computer/sw/nand_avalon/
3. Download bitfile DE1_SoC_Computer_time_limited.sof to fpga
4. Compile and load main.c

## Folder Structure
Synthesis HDL
  * hdl/rtl/nand_avalon/hdl/*
  * DE1_SoC_Computer.v

Constraints
  * DE1_SoC_Computer.qsf
  * DE1_SoC_Computer.sdc

Testbench HDL
  * hdl/rtl/nand_avalon/sim/behav/*

Modelsim files
  * hdl/rtl/nand_avalon/sim/modelsim/*

Software tests
  * sw/nand_avalon/*

Nand drivers
  * hdl/rtl/nand_avalon/sw/*


The nand_avalon wiki has miscellaneous useful data.
