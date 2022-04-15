# TCL File Generated by Component Editor 18.1
# Fri Apr 15 14:07:59 CDT 2022
# DO NOT MODIFY


# 
# nand_avalon "nand_avalon" v2.4
#  2022.04.15.14:07:59
# https://opencores.org/projects/nand_controller
# 

# 
# request TCL package from ACDS 16.1
# 
package require -exact qsys 16.1


# 
# module nand_avalon
# 
set_module_property DESCRIPTION https://opencores.org/projects/nand_controller
set_module_property NAME nand_avalon
set_module_property VERSION 2.4
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property GROUP OpenCores
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME nand_avalon
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL nand_avalon
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file nand_avalon.vhd VHDL PATH hdl/rtl/nand_avalon/hdl/nand_avalon.vhd TOP_LEVEL_FILE
add_fileset_file nand_master.vhd VHDL PATH hdl/rtl/nand_avalon/hdl/nand_master.vhd
add_fileset_file io_unit.vhd VHDL PATH hdl/rtl/nand_avalon/hdl/io_unit.vhd
add_fileset_file latch_unit.vhd VHDL PATH hdl/rtl/nand_avalon/hdl/latch_unit.vhd
add_fileset_file onfi_package.vhd VHDL PATH hdl/rtl/nand_avalon/hdl/onfi_package.vhd
add_fileset_file extension_module.vhd VHDL PATH hdl/rtl/nand_avalon/hdl/extension_module.vhd


# 
# parameters
# 


# 
# display items
# 


# 
# connection point clock
# 
add_interface clock clock end
set_interface_property clock clockRate 0
set_interface_property clock ENABLED true
set_interface_property clock EXPORT_OF ""
set_interface_property clock PORT_NAME_MAP ""
set_interface_property clock CMSIS_SVD_VARIABLES ""
set_interface_property clock SVD_ADDRESS_GROUP ""

add_interface_port clock clk clk Input 1


# 
# connection point avalon_slave_0
# 
add_interface avalon_slave_0 avalon end
set_interface_property avalon_slave_0 addressUnits WORDS
set_interface_property avalon_slave_0 associatedClock clock
set_interface_property avalon_slave_0 associatedReset reset_sink
set_interface_property avalon_slave_0 bitsPerSymbol 8
set_interface_property avalon_slave_0 burstOnBurstBoundariesOnly false
set_interface_property avalon_slave_0 burstcountUnits WORDS
set_interface_property avalon_slave_0 explicitAddressSpan 0
set_interface_property avalon_slave_0 holdTime 1
set_interface_property avalon_slave_0 linewrapBursts false
set_interface_property avalon_slave_0 maximumPendingReadTransactions 0
set_interface_property avalon_slave_0 maximumPendingWriteTransactions 0
set_interface_property avalon_slave_0 readLatency 0
set_interface_property avalon_slave_0 readWaitStates 0
set_interface_property avalon_slave_0 readWaitTime 0
set_interface_property avalon_slave_0 setupTime 0
set_interface_property avalon_slave_0 timingUnits Cycles
set_interface_property avalon_slave_0 writeWaitTime 0
set_interface_property avalon_slave_0 ENABLED true
set_interface_property avalon_slave_0 EXPORT_OF ""
set_interface_property avalon_slave_0 PORT_NAME_MAP ""
set_interface_property avalon_slave_0 CMSIS_SVD_VARIABLES ""
set_interface_property avalon_slave_0 SVD_ADDRESS_GROUP ""

add_interface_port avalon_slave_0 readdata readdata Output 32
add_interface_port avalon_slave_0 writedata writedata Input 32
add_interface_port avalon_slave_0 pread read_n Input 1
add_interface_port avalon_slave_0 pwrite write_n Input 1
add_interface_port avalon_slave_0 address address Input 3
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isFlash 0
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point conduit_end
# 
add_interface conduit_end conduit end
set_interface_property conduit_end associatedClock clock
set_interface_property conduit_end associatedReset ""
set_interface_property conduit_end ENABLED true
set_interface_property conduit_end EXPORT_OF ""
set_interface_property conduit_end PORT_NAME_MAP ""
set_interface_property conduit_end CMSIS_SVD_VARIABLES ""
set_interface_property conduit_end SVD_ADDRESS_GROUP ""

add_interface_port conduit_end nand_ale nand_ale Output 1
add_interface_port conduit_end nand_cle nand_cle Output 1
add_interface_port conduit_end nand_data nand_data Bidir 16
add_interface_port conduit_end nand_nce nand_nce Output 1
add_interface_port conduit_end nand_nre nand_nre Output 1
add_interface_port conduit_end nand_nwe nand_nwe Output 1
add_interface_port conduit_end nand_nwp nand_nwp Output 1
add_interface_port conduit_end nand_rnb nand_rnb Input 1


# 
# connection point reset_sink
# 
add_interface reset_sink reset end
set_interface_property reset_sink associatedClock clock
set_interface_property reset_sink synchronousEdges DEASSERT
set_interface_property reset_sink ENABLED true
set_interface_property reset_sink EXPORT_OF ""
set_interface_property reset_sink PORT_NAME_MAP ""
set_interface_property reset_sink CMSIS_SVD_VARIABLES ""
set_interface_property reset_sink SVD_ADDRESS_GROUP ""

add_interface_port reset_sink resetn reset_n Input 1

