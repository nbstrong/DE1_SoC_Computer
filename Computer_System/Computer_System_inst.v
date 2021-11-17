	Computer_System u0 (
		.adc_sclk                        (<connected-to-adc_sclk>),                        //                  adc.sclk
		.adc_cs_n                        (<connected-to-adc_cs_n>),                        //                     .cs_n
		.adc_dout                        (<connected-to-adc_dout>),                        //                     .dout
		.adc_din                         (<connected-to-adc_din>),                         //                     .din
		.audio_ADCDAT                    (<connected-to-audio_ADCDAT>),                    //                audio.ADCDAT
		.audio_ADCLRCK                   (<connected-to-audio_ADCLRCK>),                   //                     .ADCLRCK
		.audio_BCLK                      (<connected-to-audio_BCLK>),                      //                     .BCLK
		.audio_DACDAT                    (<connected-to-audio_DACDAT>),                    //                     .DACDAT
		.audio_DACLRCK                   (<connected-to-audio_DACLRCK>),                   //                     .DACLRCK
		.audio_pll_clk_clk               (<connected-to-audio_pll_clk_clk>),               //        audio_pll_clk.clk
		.audio_pll_ref_clk_clk           (<connected-to-audio_pll_ref_clk_clk>),           //    audio_pll_ref_clk.clk
		.audio_pll_ref_reset_reset       (<connected-to-audio_pll_ref_reset_reset>),       //  audio_pll_ref_reset.reset
		.av_config_SDAT                  (<connected-to-av_config_SDAT>),                  //            av_config.SDAT
		.av_config_SCLK                  (<connected-to-av_config_SCLK>),                  //                     .SCLK
		.expansion_jp1_export            (<connected-to-expansion_jp1_export>),            //        expansion_jp1.export
		.expansion_jp2_export            (<connected-to-expansion_jp2_export>),            //        expansion_jp2.export
		.hex3_hex0_export                (<connected-to-hex3_hex0_export>),                //            hex3_hex0.export
		.hex5_hex4_export                (<connected-to-hex5_hex4_export>),                //            hex5_hex4.export
		.hps_io_hps_io_emac1_inst_TX_CLK (<connected-to-hps_io_hps_io_emac1_inst_TX_CLK>), //               hps_io.hps_io_emac1_inst_TX_CLK
		.hps_io_hps_io_emac1_inst_TXD0   (<connected-to-hps_io_hps_io_emac1_inst_TXD0>),   //                     .hps_io_emac1_inst_TXD0
		.hps_io_hps_io_emac1_inst_TXD1   (<connected-to-hps_io_hps_io_emac1_inst_TXD1>),   //                     .hps_io_emac1_inst_TXD1
		.hps_io_hps_io_emac1_inst_TXD2   (<connected-to-hps_io_hps_io_emac1_inst_TXD2>),   //                     .hps_io_emac1_inst_TXD2
		.hps_io_hps_io_emac1_inst_TXD3   (<connected-to-hps_io_hps_io_emac1_inst_TXD3>),   //                     .hps_io_emac1_inst_TXD3
		.hps_io_hps_io_emac1_inst_RXD0   (<connected-to-hps_io_hps_io_emac1_inst_RXD0>),   //                     .hps_io_emac1_inst_RXD0
		.hps_io_hps_io_emac1_inst_MDIO   (<connected-to-hps_io_hps_io_emac1_inst_MDIO>),   //                     .hps_io_emac1_inst_MDIO
		.hps_io_hps_io_emac1_inst_MDC    (<connected-to-hps_io_hps_io_emac1_inst_MDC>),    //                     .hps_io_emac1_inst_MDC
		.hps_io_hps_io_emac1_inst_RX_CTL (<connected-to-hps_io_hps_io_emac1_inst_RX_CTL>), //                     .hps_io_emac1_inst_RX_CTL
		.hps_io_hps_io_emac1_inst_TX_CTL (<connected-to-hps_io_hps_io_emac1_inst_TX_CTL>), //                     .hps_io_emac1_inst_TX_CTL
		.hps_io_hps_io_emac1_inst_RX_CLK (<connected-to-hps_io_hps_io_emac1_inst_RX_CLK>), //                     .hps_io_emac1_inst_RX_CLK
		.hps_io_hps_io_emac1_inst_RXD1   (<connected-to-hps_io_hps_io_emac1_inst_RXD1>),   //                     .hps_io_emac1_inst_RXD1
		.hps_io_hps_io_emac1_inst_RXD2   (<connected-to-hps_io_hps_io_emac1_inst_RXD2>),   //                     .hps_io_emac1_inst_RXD2
		.hps_io_hps_io_emac1_inst_RXD3   (<connected-to-hps_io_hps_io_emac1_inst_RXD3>),   //                     .hps_io_emac1_inst_RXD3
		.hps_io_hps_io_qspi_inst_IO0     (<connected-to-hps_io_hps_io_qspi_inst_IO0>),     //                     .hps_io_qspi_inst_IO0
		.hps_io_hps_io_qspi_inst_IO1     (<connected-to-hps_io_hps_io_qspi_inst_IO1>),     //                     .hps_io_qspi_inst_IO1
		.hps_io_hps_io_qspi_inst_IO2     (<connected-to-hps_io_hps_io_qspi_inst_IO2>),     //                     .hps_io_qspi_inst_IO2
		.hps_io_hps_io_qspi_inst_IO3     (<connected-to-hps_io_hps_io_qspi_inst_IO3>),     //                     .hps_io_qspi_inst_IO3
		.hps_io_hps_io_qspi_inst_SS0     (<connected-to-hps_io_hps_io_qspi_inst_SS0>),     //                     .hps_io_qspi_inst_SS0
		.hps_io_hps_io_qspi_inst_CLK     (<connected-to-hps_io_hps_io_qspi_inst_CLK>),     //                     .hps_io_qspi_inst_CLK
		.hps_io_hps_io_sdio_inst_CMD     (<connected-to-hps_io_hps_io_sdio_inst_CMD>),     //                     .hps_io_sdio_inst_CMD
		.hps_io_hps_io_sdio_inst_D0      (<connected-to-hps_io_hps_io_sdio_inst_D0>),      //                     .hps_io_sdio_inst_D0
		.hps_io_hps_io_sdio_inst_D1      (<connected-to-hps_io_hps_io_sdio_inst_D1>),      //                     .hps_io_sdio_inst_D1
		.hps_io_hps_io_sdio_inst_CLK     (<connected-to-hps_io_hps_io_sdio_inst_CLK>),     //                     .hps_io_sdio_inst_CLK
		.hps_io_hps_io_sdio_inst_D2      (<connected-to-hps_io_hps_io_sdio_inst_D2>),      //                     .hps_io_sdio_inst_D2
		.hps_io_hps_io_sdio_inst_D3      (<connected-to-hps_io_hps_io_sdio_inst_D3>),      //                     .hps_io_sdio_inst_D3
		.hps_io_hps_io_usb1_inst_D0      (<connected-to-hps_io_hps_io_usb1_inst_D0>),      //                     .hps_io_usb1_inst_D0
		.hps_io_hps_io_usb1_inst_D1      (<connected-to-hps_io_hps_io_usb1_inst_D1>),      //                     .hps_io_usb1_inst_D1
		.hps_io_hps_io_usb1_inst_D2      (<connected-to-hps_io_hps_io_usb1_inst_D2>),      //                     .hps_io_usb1_inst_D2
		.hps_io_hps_io_usb1_inst_D3      (<connected-to-hps_io_hps_io_usb1_inst_D3>),      //                     .hps_io_usb1_inst_D3
		.hps_io_hps_io_usb1_inst_D4      (<connected-to-hps_io_hps_io_usb1_inst_D4>),      //                     .hps_io_usb1_inst_D4
		.hps_io_hps_io_usb1_inst_D5      (<connected-to-hps_io_hps_io_usb1_inst_D5>),      //                     .hps_io_usb1_inst_D5
		.hps_io_hps_io_usb1_inst_D6      (<connected-to-hps_io_hps_io_usb1_inst_D6>),      //                     .hps_io_usb1_inst_D6
		.hps_io_hps_io_usb1_inst_D7      (<connected-to-hps_io_hps_io_usb1_inst_D7>),      //                     .hps_io_usb1_inst_D7
		.hps_io_hps_io_usb1_inst_CLK     (<connected-to-hps_io_hps_io_usb1_inst_CLK>),     //                     .hps_io_usb1_inst_CLK
		.hps_io_hps_io_usb1_inst_STP     (<connected-to-hps_io_hps_io_usb1_inst_STP>),     //                     .hps_io_usb1_inst_STP
		.hps_io_hps_io_usb1_inst_DIR     (<connected-to-hps_io_hps_io_usb1_inst_DIR>),     //                     .hps_io_usb1_inst_DIR
		.hps_io_hps_io_usb1_inst_NXT     (<connected-to-hps_io_hps_io_usb1_inst_NXT>),     //                     .hps_io_usb1_inst_NXT
		.hps_io_hps_io_spim1_inst_CLK    (<connected-to-hps_io_hps_io_spim1_inst_CLK>),    //                     .hps_io_spim1_inst_CLK
		.hps_io_hps_io_spim1_inst_MOSI   (<connected-to-hps_io_hps_io_spim1_inst_MOSI>),   //                     .hps_io_spim1_inst_MOSI
		.hps_io_hps_io_spim1_inst_MISO   (<connected-to-hps_io_hps_io_spim1_inst_MISO>),   //                     .hps_io_spim1_inst_MISO
		.hps_io_hps_io_spim1_inst_SS0    (<connected-to-hps_io_hps_io_spim1_inst_SS0>),    //                     .hps_io_spim1_inst_SS0
		.hps_io_hps_io_uart0_inst_RX     (<connected-to-hps_io_hps_io_uart0_inst_RX>),     //                     .hps_io_uart0_inst_RX
		.hps_io_hps_io_uart0_inst_TX     (<connected-to-hps_io_hps_io_uart0_inst_TX>),     //                     .hps_io_uart0_inst_TX
		.hps_io_hps_io_i2c0_inst_SDA     (<connected-to-hps_io_hps_io_i2c0_inst_SDA>),     //                     .hps_io_i2c0_inst_SDA
		.hps_io_hps_io_i2c0_inst_SCL     (<connected-to-hps_io_hps_io_i2c0_inst_SCL>),     //                     .hps_io_i2c0_inst_SCL
		.hps_io_hps_io_i2c1_inst_SDA     (<connected-to-hps_io_hps_io_i2c1_inst_SDA>),     //                     .hps_io_i2c1_inst_SDA
		.hps_io_hps_io_i2c1_inst_SCL     (<connected-to-hps_io_hps_io_i2c1_inst_SCL>),     //                     .hps_io_i2c1_inst_SCL
		.hps_io_hps_io_gpio_inst_GPIO09  (<connected-to-hps_io_hps_io_gpio_inst_GPIO09>),  //                     .hps_io_gpio_inst_GPIO09
		.hps_io_hps_io_gpio_inst_GPIO35  (<connected-to-hps_io_hps_io_gpio_inst_GPIO35>),  //                     .hps_io_gpio_inst_GPIO35
		.hps_io_hps_io_gpio_inst_GPIO40  (<connected-to-hps_io_hps_io_gpio_inst_GPIO40>),  //                     .hps_io_gpio_inst_GPIO40
		.hps_io_hps_io_gpio_inst_GPIO41  (<connected-to-hps_io_hps_io_gpio_inst_GPIO41>),  //                     .hps_io_gpio_inst_GPIO41
		.hps_io_hps_io_gpio_inst_GPIO48  (<connected-to-hps_io_hps_io_gpio_inst_GPIO48>),  //                     .hps_io_gpio_inst_GPIO48
		.hps_io_hps_io_gpio_inst_GPIO53  (<connected-to-hps_io_hps_io_gpio_inst_GPIO53>),  //                     .hps_io_gpio_inst_GPIO53
		.hps_io_hps_io_gpio_inst_GPIO54  (<connected-to-hps_io_hps_io_gpio_inst_GPIO54>),  //                     .hps_io_gpio_inst_GPIO54
		.hps_io_hps_io_gpio_inst_GPIO61  (<connected-to-hps_io_hps_io_gpio_inst_GPIO61>),  //                     .hps_io_gpio_inst_GPIO61
		.irda_TXD                        (<connected-to-irda_TXD>),                        //                 irda.TXD
		.irda_RXD                        (<connected-to-irda_RXD>),                        //                     .RXD
		.leds_export                     (<connected-to-leds_export>),                     //                 leds.export
		.memory_mem_a                    (<connected-to-memory_mem_a>),                    //               memory.mem_a
		.memory_mem_ba                   (<connected-to-memory_mem_ba>),                   //                     .mem_ba
		.memory_mem_ck                   (<connected-to-memory_mem_ck>),                   //                     .mem_ck
		.memory_mem_ck_n                 (<connected-to-memory_mem_ck_n>),                 //                     .mem_ck_n
		.memory_mem_cke                  (<connected-to-memory_mem_cke>),                  //                     .mem_cke
		.memory_mem_cs_n                 (<connected-to-memory_mem_cs_n>),                 //                     .mem_cs_n
		.memory_mem_ras_n                (<connected-to-memory_mem_ras_n>),                //                     .mem_ras_n
		.memory_mem_cas_n                (<connected-to-memory_mem_cas_n>),                //                     .mem_cas_n
		.memory_mem_we_n                 (<connected-to-memory_mem_we_n>),                 //                     .mem_we_n
		.memory_mem_reset_n              (<connected-to-memory_mem_reset_n>),              //                     .mem_reset_n
		.memory_mem_dq                   (<connected-to-memory_mem_dq>),                   //                     .mem_dq
		.memory_mem_dqs                  (<connected-to-memory_mem_dqs>),                  //                     .mem_dqs
		.memory_mem_dqs_n                (<connected-to-memory_mem_dqs_n>),                //                     .mem_dqs_n
		.memory_mem_odt                  (<connected-to-memory_mem_odt>),                  //                     .mem_odt
		.memory_mem_dm                   (<connected-to-memory_mem_dm>),                   //                     .mem_dm
		.memory_oct_rzqin                (<connected-to-memory_oct_rzqin>),                //                     .oct_rzqin
		.ps2_port_CLK                    (<connected-to-ps2_port_CLK>),                    //             ps2_port.CLK
		.ps2_port_DAT                    (<connected-to-ps2_port_DAT>),                    //                     .DAT
		.ps2_port_dual_CLK               (<connected-to-ps2_port_dual_CLK>),               //        ps2_port_dual.CLK
		.ps2_port_dual_DAT               (<connected-to-ps2_port_dual_DAT>),               //                     .DAT
		.pushbuttons_export              (<connected-to-pushbuttons_export>),              //          pushbuttons.export
		.sdram_addr                      (<connected-to-sdram_addr>),                      //                sdram.addr
		.sdram_ba                        (<connected-to-sdram_ba>),                        //                     .ba
		.sdram_cas_n                     (<connected-to-sdram_cas_n>),                     //                     .cas_n
		.sdram_cke                       (<connected-to-sdram_cke>),                       //                     .cke
		.sdram_cs_n                      (<connected-to-sdram_cs_n>),                      //                     .cs_n
		.sdram_dq                        (<connected-to-sdram_dq>),                        //                     .dq
		.sdram_dqm                       (<connected-to-sdram_dqm>),                       //                     .dqm
		.sdram_ras_n                     (<connected-to-sdram_ras_n>),                     //                     .ras_n
		.sdram_we_n                      (<connected-to-sdram_we_n>),                      //                     .we_n
		.sdram_clk_clk                   (<connected-to-sdram_clk_clk>),                   //            sdram_clk.clk
		.slider_switches_export          (<connected-to-slider_switches_export>),          //      slider_switches.export
		.system_pll_ref_clk_clk          (<connected-to-system_pll_ref_clk_clk>),          //   system_pll_ref_clk.clk
		.system_pll_ref_reset_reset      (<connected-to-system_pll_ref_reset_reset>),      // system_pll_ref_reset.reset
		.vga_CLK                         (<connected-to-vga_CLK>),                         //                  vga.CLK
		.vga_HS                          (<connected-to-vga_HS>),                          //                     .HS
		.vga_VS                          (<connected-to-vga_VS>),                          //                     .VS
		.vga_BLANK                       (<connected-to-vga_BLANK>),                       //                     .BLANK
		.vga_SYNC                        (<connected-to-vga_SYNC>),                        //                     .SYNC
		.vga_R                           (<connected-to-vga_R>),                           //                     .R
		.vga_G                           (<connected-to-vga_G>),                           //                     .G
		.vga_B                           (<connected-to-vga_B>),                           //                     .B
		.video_in_TD_CLK27               (<connected-to-video_in_TD_CLK27>),               //             video_in.TD_CLK27
		.video_in_TD_DATA                (<connected-to-video_in_TD_DATA>),                //                     .TD_DATA
		.video_in_TD_HS                  (<connected-to-video_in_TD_HS>),                  //                     .TD_HS
		.video_in_TD_VS                  (<connected-to-video_in_TD_VS>),                  //                     .TD_VS
		.video_in_clk27_reset            (<connected-to-video_in_clk27_reset>),            //                     .clk27_reset
		.video_in_TD_RESET               (<connected-to-video_in_TD_RESET>),               //                     .TD_RESET
		.video_in_overflow_flag          (<connected-to-video_in_overflow_flag>),          //                     .overflow_flag
		.video_pll_ref_clk_clk           (<connected-to-video_pll_ref_clk_clk>),           //    video_pll_ref_clk.clk
		.video_pll_ref_reset_reset       (<connected-to-video_pll_ref_reset_reset>)        //  video_pll_ref_reset.reset
	);

