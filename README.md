# DE1_SoC_Computer

To clone:  
`git clone --recursive https://github.com/nbstrong/DE1_SoC_Computer.git`  

If the hdl/rtl/nand_avalon folder isn't showing as populated with files or they are out of date run:  
`git submodule sync && git submodule update`  

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
