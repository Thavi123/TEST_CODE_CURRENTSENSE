/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	INPUTXBAR_init();
	SYNC_init();
	ASYSCTL_init();
	EPWM_init();
	EPWMXBAR_init();
	GPIO_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// ANALOG -> myANALOGPinMux0 Pinmux
	//
	// Analog PinMux for A0/C15/CMP1_DACL
	GPIO_setPinConfig(GPIO_231_GPIO231);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(231, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A1
	GPIO_setPinConfig(GPIO_232_GPIO232);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(232, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A10/C10, GPIO230
	GPIO_setPinConfig(GPIO_230_GPIO230);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(230, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A11/C0
	GPIO_setPinConfig(GPIO_237_GPIO237);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(237, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A12/C1
	GPIO_setPinConfig(GPIO_238_GPIO238);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(238, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A15/C7
	GPIO_setPinConfig(GPIO_233_GPIO233);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(233, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A16/C16, GPIO28
	GPIO_setPinConfig(GPIO_28_GPIO28);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(28, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A17/C17, GPIO20
	GPIO_setPinConfig(GPIO_20_GPIO20);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(20, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A18/C18, GPIO21
	GPIO_setPinConfig(GPIO_21_GPIO21);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(21, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A19/C19, GPIO13
	GPIO_setPinConfig(GPIO_13_GPIO13);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(13, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A2/C9, GPIO224
	GPIO_setPinConfig(GPIO_224_GPIO224);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(224, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A20/C20, GPIO12
	GPIO_setPinConfig(GPIO_12_GPIO12);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(12, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A3/C5, GPIO242
	GPIO_setPinConfig(GPIO_242_GPIO242);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(242, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A4/C14
	GPIO_setPinConfig(GPIO_225_GPIO225);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(225, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A5/C2
	GPIO_setPinConfig(GPIO_244_GPIO244);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(244, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A6, GPIO228
	GPIO_setPinConfig(GPIO_228_GPIO228);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(228, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A7/C3
	GPIO_setPinConfig(GPIO_245_GPIO245);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(245, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A8/C11
	GPIO_setPinConfig(GPIO_241_GPIO241);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(241, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C4/A14
	GPIO_setPinConfig(GPIO_239_GPIO239);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(239, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C6, GPIO226
	GPIO_setPinConfig(GPIO_226_GPIO226);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(226, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C8/A9, GPIO227
	GPIO_setPinConfig(GPIO_227_GPIO227);
	// AGPIO -> Analog mode selected
	GPIO_setAnalogMode(227, GPIO_ANALOG_ENABLED);
	//
	// EPWM2 -> myEPWM2 Pinmux
	//
	GPIO_setPinConfig(myEPWM2_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM2_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM2_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(myEPWM2_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM2_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM2_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// GPIO5 -> CSA_OUT Pinmux
	GPIO_setPinConfig(GPIO_5_GPIO5);

}

//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to internal.
	//
	ASysCtl_setAnalogReferenceInternal( ASYSCTL_VREFHI );
	//
	// Set the internal analog voltage reference selection to 1.65V.
	//
	ASysCtl_setAnalogReference1P65( ASYSCTL_VREFHI );
	//
	// This function disables CMPSSx.COMPL and the associated DAC will act as a
	// general purpose DAC with 11 bit resolution
	//
	ASysCtl_enableCMPSSExternalDAC(ASYSCTL_CMPSS1_DACL);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 6000);	
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0);	
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(myEPWM2_BASE);	
    EPWM_setPhaseShift(myEPWM2_BASE, 0);	
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 3000);	
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, 3000);	
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_disableActionQualifierShadowLoadMode(myEPWM2_BASE, EPWM_ACTION_QUALIFIER_A);	
    EPWM_setActionQualifierShadowLoadMode(myEPWM2_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_disableActionQualifierShadowLoadMode(myEPWM2_BASE, EPWM_ACTION_QUALIFIER_B);	
    EPWM_setActionQualifierShadowLoadMode(myEPWM2_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM2_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM2_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM2_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM2_BASE);	
    EPWM_setTripZoneAction(myEPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(myEPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_enableTripZoneSignals(myEPWM2_BASE, EPWM_TZ_SIGNAL_OSHT1);	
    EPWM_enableTripZoneInterrupt(myEPWM2_BASE, EPWM_TZ_INTERRUPT_OST);	
}

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void EPWMXBAR_init(){
	myEPWMXBAR0_init();
}

void myEPWMXBAR0_init(){
		

}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	CSA_OUT_init();
}

void CSA_OUT_init(){
	GPIO_setPadConfig(CSA_OUT, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(CSA_OUT, GPIO_QUAL_3SAMPLE);
	GPIO_setDirectionMode(CSA_OUT, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
	myINPUTXBARINPUT0_init();
}

void myINPUTXBARINPUT0_init(){
	XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_myEPWM2_TZ
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myEPWM2_TZ, &INT_myEPWM2_TZ_ISR);
	Interrupt_enable(INT_myEPWM2_TZ);
}
//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
