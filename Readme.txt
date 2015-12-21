================================================================================
                               Template Project
================================================================================

/*******************************************************************************
* Copyright (C) 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
*
* This software, including source code, documentation and related
* materials ( "Software" ), is owned by Cypress Semiconductor
* Corporation ( "Cypress" ) and is protected by and subject to worldwide
* patent protection (United States and foreign), United States copyright
* laws and international treaty provisions. Therefore, you may use this
* Software only as provided in the license agreement accompanying the
* software package from which you obtained this Software ( "EULA" ).
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the
* Software source code solely for use in connection with Cypress's
* integrated circuit products. Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE. Cypress reserves the right to make
* changes to the Software without notice. Cypress does not assume any
* liability arising out of the application or use of the Software or any
* product or circuit described in the Software. Cypress does not
* authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ( "High Risk Product" ). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*/

================================================================================
History
Date        Ver       Initials   Description
2015-06-30  2.0.0     MSCH/ACEH  New MCU Template / Package release, replacing
                                 MCU templates before v20

2015-08-03  2.0.1     MSCH       Updated generation script to fix FPU and MPU usage
                                 for ARM MDK

2015-08-18  2.0.2     NOSU       Updated SVD files to improve compatibility with
                                 register/bit definitions of MCU templates before
                                 v20
                                 Removed HDMICEC related definitions in S6E2Cx
                                 series
                                 Fixed the folder structure descriptions in Readme.txt

2015-09-02  2.0.3     NOSU       Replaced copyright notice from Spansion to Cypress.


Supported toolchain versions


ARM        5.11
Atollic    4.3.1
IAR        7.30
iSYSTEM    9.12.213
================================================================================

This is a project template for S6E2CCxL (with x = flash size). It includes some
basic settings for e.g. Linker, C-Compiler.


Clock settings:
---------------
Crystal:   4 MHz
HCLK:    200 MHz
PCLK0 :  100 MHz
PCLK1:   200 MHz
PCLK2 :  100 MHz


================================================================================
File Structure
--------------

 + cmsis                                     CMSIS related files
 | + include                                 CMSIS header files (for GNU toolchains)
 | + svd                                     SVD files
 | | |-> s6e2ccxl.sfr                        precompiled SVD file
 | | |-> s6e2ccxl.svd                        SVD file defined in CMSIS
 |
 + common                                    Common files folder
 | |-> base_types.h                          Defines base types variables
 | |-> fgpio.h                               GPIO macros used for fast GPIOs
 | |-> gpio.h                                GPIO macros used for GPIOs
 | |-> gpio_s6e2ccxl.h                       GPIO macros used for GPIOs
 | |-> S6E2CCxL.h                            MCU Headerfile
 | |-> system_s6e2cc.c                       System file defined in CMSIS
 | |-> system_s6e2cc.h                       System file defined in CMSIS
 |
 + doc                                       Documentation folder
 | |-> + doxy                                Output folder for Doxygen
 | |-> Doxyfile                              Doxygen configuration
 | |-> s6e2ccxl.pin                          Pin list
 |
 + example                                   Example folder, containing source & IDE workspaces
 | + ARM                                     ARM/µVision IDE workspace
 | | |-> *.FLM                               Flash loaders, please copy to C:\Keil_v5\ARM\Flash\
 | | |-> s6e2ccxl_template.uvprojx           ARM/µVision IDE project/workspace file
 | | |-> startup_s6e2cc.s                    Startup file for ARM/µVision
 | | + output                                output folder
 | | | + release                             output folder for release build
 | | | | |-> s6e2ccxl_template.srec          firmware file
 | | | |
 | | | + debug                               output folder for debug build
 | | | | |-> s6e2ccxl_template.srec          firmware file
 | | |                                       +--------------------------------------------------------------------+
 | | |                                       |  General Hints to setup ARM µVision                                |
 | | |                                       |  ======================================                            |
 | | |                                       |  - Copy the *.FLM files to C:\Keil\ARM\Flash\                      |
 | | |                                       |  - Install legacy support if using Keil V5 for Cortex-M Devices:   |
 | | |                                       |    http://www2.keil.com/mdk5/legacy/                               |
 | | |                                       +--------------------------------------------------------------------+
 | |
 | + Atollic                                 Atollic IDE workspace
 | | |-> .project                            Atollic IDE project/workspace file
 | | |-> startup_s6e2cc.s                    Startup file for Atollic
 | | + ..._release                           output folder for release build
 | | | |-> s6e2ccxl_template.srec            firmware file
 | | + ..._debug                             output folder for debug build
 | | | |-> s6e2ccxl_template.srec            firmware file
 | |
 | + IAR                                     IAR IDE workspace
 | | |-> s6e2ccxl_template.eww               IAR project/workspace file
 | | |-> startup_s6e2cc.s                    Startup file for IAR
 | | + output                                output folder
 | | | | + release                           output folder for release build
 | | | | | + exe                             
 | | | | |   |-> s6e2ccxl_template.srec      firmware file
 | | | | + debug                             output folder for debug build
 | | | | | + exe                             
 | | | | |   |-> s6e2ccxl_template.srec      firmware file
 | |
 | + iSYSTEM                                 iSYSTEM IDE workspace
 | | |-> s6e2ccxl_template.xjrf              iSYSTEM project/workspace file
 | | |-> startup_s6e2cc.s                    Startup file for iSYSTEM
 | | + output                                output folder
 | | | + release                             output folder for release build
 | | | | |-> s6e2ccxl_template.srec          firmware file
 | | | + debug                               output folder for debug build
 | | | | |-> s6e2ccxl_template.srec          firmware file
 | + make                                    Makefile environment
 | | |-> startup_s6e2cc.s                    Startup file for GNU toolchain
 | | |-> makefile                            makefile
 | | |-> clean.bat                           Cleanup script
 | | |-> make.bat                            Start make process
 | | |-> MakeFileUpdate.exe                  Run every time, new folders were added to update the makefile
 | | | + release                             output folder for release build
 | | | | |-> s6e2ccxl_template.srec          firmware file
 | | | + debug                               output folder for debug build
 | | | | |-> s6e2ccxl_template.srec          firmware file
 | |                                         +--------------------------------------------------------------------+
 | |                                         |  General Hints to setup make on Windows                            |
 | |                                         |  ======================================                            |
 | |                                         |  - Download and install http://gnuwin32.sourceforge.net/           |
 | |                                         |  - Download and install MinGW http://www.mingw.org/                |
 | |                                         |  - Check in system advanced properties if the PATH variable        |
 | |                                         |    includes the MinGW binary path                                  |
 | |                                         |  - Install iSYSTEM WinIDEA Open or change the TOOLSDIR variable    |
 | |                                         |   in the makefile to your GNU tool chain                           |
 | |                                         +--------------------------------------------------------------------+
 | |
 | + source                                  Source files
 | | |-> main.c                              Main file
 | | |-> mcu.h                               Includes mcu related header files
 | | + config                                Configuration directory
 | | | |-> RTE_Device.h                      Configuration file RTE_Device.h defined by CMSIS
 | | | |-> iomux.c                           Used with Pin & Code Wizard
 | | | |-> iomux.h                           Used with Pin & Code Wizard
 |
 + library                                   Library folder
 | + examples                                Library examples folder (empty)
 | + highlevel                               Library high level folder (empty)
 | + lowlevel                                Library low level folder (empty)
 | + middleware                              Library middle ware folder (empty)
 + thirdparty                                Third party folder (empty)
--------------------------------------------------------------------------------

    s6e2ccxl             = MCU name, x = flash size
    s6e2cc               = MCU series name
    s6e2ccxl_template    = Project name
    Debug                = Project compiled to run in RAM
    Release              = Project compiled to run in Flash
================================================================================
 
================================================================================ 
  Automatic created by McuTemplateGen 
  [2015-09-24 10:54:22.903]  
================================================================================ 
 
================================================================================ 
EOF (not truncated) 
================================================================================ 
 
