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
1. Open Modelsim
2. Navigate to DE1_SoC_Computer/simulation/modelsim
3. run `do sim.do`

## To run hardware tests:
Design requires Intel FPGA University Monitor. Project is located in DE1_SoC_Computer/sw

## Folder Structure
Synthesis HDL
  * hdl/rtl/*
  * DE1_SoC_Computer.v

Constraints
  * DE1_SoC_Computer.qsf
  * DE1_SoC_Computer.sdc

Testbench HDL
  * hdl/behav/*

Modelsim files
  * simulation/modelsim/*

Software drivers and tests
  * sw/*
