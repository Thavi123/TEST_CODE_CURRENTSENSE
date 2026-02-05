//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1> 
//!
//! This example is an empty project setup for Driverlib development.
//!
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2025 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"


#define DAC_REF_VOLTAGE   3.3f
#define TEST_DAC_VOLTAGE  1.0f 
uint32_t  epwm0TZIntCount;
uint32_t  epwm1TZIntCount;
uint32_t  epwm2TZIntCount;

volatile uint32_t g9;

 uint16_t dac_val;

 static inline uint16_t dacCode(float volts);
//  __interrupt void INT_myEPWM0_TZ_ISR(void);
//  __interrupt void INT_myEPWM1_TZ_ISR(void);
 __interrupt void INT_myEPWM2_TZ_ISR(void);
// 
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // PinMux and Peripheral Initialization
    //
    Board_init();

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();


      // ---------------- CMPSS INIT ----------------
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS1);

    CMPSS_enableModule(CMPSS1_BASE);

    CMPSS_configDAC(
        CMPSS1_BASE,
        CMPSS_DACVAL_SYSCLK |
        CMPSS_DACSRC_SHDW
    );

    // ---------------- SET DAC -------------------
    dac_val = dacCode(TEST_DAC_VOLTAGE);
    CMPSS_setDACValueLow(CMPSS1_BASE, dac_val);


    //     // ---------------- TRIP ZONE --------------
    // EPWM_enableTripZoneSignals(myEPWM0_BASE, EPWM_TZ_SIGNAL_OSHT1);

    // EPWM_setTripZoneAction(
    //     myEPWM0_BASE,
    //     EPWM_TZ_ACTION_EVENT_TZA,
    //     EPWM_TZ_ACTION_LOW
    // );

    // // Clear old trips
    // EPWM_clearTripZoneFlag(myEPWM0_BASE, EPWM_TZ_FLAG_OST);

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //

    //   DEVICE_DELAY_US(2000000); // 2 sec ON
    // EPWM_forceTripZoneEvent(myEPWM0_BASE, EPWM_TZ_FORCE_EVENT_OST);

    EINT;
    ERTM;

//     // Let PWM run for 5 seconds
// DEVICE_DELAY_US(5000000);   // 5 sec

// // Simulate FAULT: drive GPIO9 LOW
// GPIO_writePin(9, 0);

// nothing else needed — TZ will fire automatically


//     DEVICE_DELAY_US(1000000); // 1s so you can see PWM first
// EPWM_forceTripZoneEvent(myEPWM2_BASE, EPWM_TZ_FORCE_EVENT_OST);

// // Let PWM run briefly so you can see it first
// DEVICE_DELAY_US(200000);

// // Force a one-shot trip in software
// EPWM_forceTripZoneEvent(myEPWM0_BASE, EPWM_TZ_FORCE_EVENT_OST);
// EPWM_forceTripZoneEvent(myEPWM1_BASE, EPWM_TZ_FORCE_EVENT_OST);
// EPWM_forceTripZoneEvent(myEPWM2_BASE, EPWM_TZ_FORCE_EVENT_OST);

// DEVICE_DELAY_US(200000);  // see PWM first

// EPWM_forceTripZoneEvent(myEPWM2_BASE, EPWM_TZ_FORCE_EVENT_OST);

// // read flags (watch in debugger)
// volatile uint16_t tzflg = EPWM_getTripZoneFlagStatus(myEPWM2_BASE);



    while(1)
    {
            g9  = GPIO_readPin(9);
        // if(GPIO_readPin(9) == 0)
        //  {
        //   EPWM_forceTripZoneEvent(myEPWM2_BASE,
        //                     EPWM_TZ_FORCE_EVENT_OST);
        //  }
//         if(epwm2TZIntCount == 1)
// {
//     EPWM_clearTripZoneFlag(myEPWM2_BASE,
//                            EPWM_TZ_FLAG_OST | EPWM_TZ_INTERRUPT);
// }


        
    }
}

static inline uint16_t dacCode(float volts)
{
    if (volts < 0.0f) volts = 0.0f;
    if (volts > DAC_REF_VOLTAGE) volts = DAC_REF_VOLTAGE;
    return (uint16_t)((volts / DAC_REF_VOLTAGE) * 4095.0f);
}


// __interrupt void INT_myEPWM0_TZ_ISR(void)
// {
//     epwm0TZIntCount++;
//     // // Clear TZ flags
//     // EPWM_clearTripZoneFlag(myEPWM0_BASE,
//     //                        EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST);

//     Interrupt_clearACKGroup(INT_myEPWM0_TZ_INTERRUPT_ACK_GROUP);
// }
// __interrupt void INT_myEPWM1_TZ_ISR(void)
// {
//     epwm1TZIntCount++;
// //     // Clear TZ flags
//     // EPWM_clearTripZoneFlag(myEPWM1_BASE,
//     //                        EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST);

//     Interrupt_clearACKGroup(INT_myEPWM1_TZ_INTERRUPT_ACK_GROUP);
// }
__interrupt void INT_myEPWM2_TZ_ISR(void)
{
    epwm2TZIntCount++;
    // // Clear TZ flags
 //   EPWM_clearTripZoneFlag(myEPWM2_BASE, EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST);

    Interrupt_clearACKGroup(INT_myEPWM2_TZ_INTERRUPT_ACK_GROUP);
}

