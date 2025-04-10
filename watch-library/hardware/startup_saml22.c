/**
 * \file
 *
 * \brief gcc starttup file for SAML22
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#include "saml22.h"

/* Initialize segments */
extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;

/** \cond DOXYGEN_SHOULD_SKIP_THIS */
int main(void);
/** \endcond */

void __libc_init_array(void);

/* Default empty handler */
void Dummy_Handler(void);

/* Cortex-M0+ core handlers */
void NonMaskableInt_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SVCall_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void SYSTEM_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler"))); /* MCLK, OSC32KCTRL, OSCCTRL, PAC, PM, SUPC, TAL */
void WDT_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void FREQM_Handler           ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef ID_USB
void USB_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif
void NVMCTRL_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DMAC_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EVSYS_Handler           ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM0_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM1_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM2_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef ID_SERCOM3
void SERCOM3_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif
#ifdef ID_SERCOM4
void SERCOM4_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif
#ifdef ID_SERCOM5
void SERCOM5_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif
void TCC0_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AC_Handler              ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef ID_PTC
void PTC_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif
void SLCD_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef ID_AES
void AES_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif
#ifdef ID_TRNG
void TRNG_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif

/* Exception Table */
__attribute__ ((section(".vectors"), used))
const DeviceVectors exception_table = {

        /* Configure Initial Stack Pointer, using linker-generated symbols */
        .pvStack                = (void*) (&_estack),

        .pfnReset_Handler       = (void*) Reset_Handler,
        .pfnNonMaskableInt_Handler = (void*) NonMaskableInt_Handler,
        .pfnHardFault_Handler   = (void*) HardFault_Handler,
        .pvReservedM12          = (void*) (0UL), /* Reserved */
        .pvReservedM11          = (void*) (0UL), /* Reserved */
        .pvReservedM10          = (void*) (0UL), /* Reserved */
        .pvReservedM9           = (void*) (0UL), /* Reserved */
        .pvReservedM8           = (void*) (0UL), /* Reserved */
        .pvReservedM7           = (void*) (0UL), /* Reserved */
        .pvReservedM6           = (void*) (0UL), /* Reserved */
        .pfnSVCall_Handler      = (void*) SVCall_Handler,
        .pvReservedM4           = (void*) (0UL), /* Reserved */
        .pvReservedM3           = (void*) (0UL), /* Reserved */
        .pfnPendSV_Handler      = (void*) PendSV_Handler,
        .pfnSysTick_Handler     = (void*) SysTick_Handler,

        /* Configurable interrupts */
        .pfnSYSTEM_Handler      = (void*) SYSTEM_Handler,         /*  0 Main Clock, 32k Oscillators Control, Oscillators Control, Peripheral Access Controller, Power Manager, Supply Controller, Trigger Allocator */
        .pfnWDT_Handler         = (void*) WDT_Handler,            /*  1 Watchdog Timer */
        .pfnRTC_Handler         = (void*) RTC_Handler,            /*  2 Real-Time Counter */
        .pfnEIC_Handler         = (void*) EIC_Handler,            /*  3 External Interrupt Controller */
        .pfnFREQM_Handler       = (void*) FREQM_Handler,          /*  4 Frequency Meter */
#ifdef ID_USB
        .pfnUSB_Handler         = (void*) USB_Handler,            /*  5 Universal Serial Bus */
#else
        .pvReserved5            = (void*) (0UL),                  /*  5 Reserved */
#endif
        .pfnNVMCTRL_Handler     = (void*) NVMCTRL_Handler,        /*  6 Non-Volatile Memory Controller */
        .pfnDMAC_Handler        = (void*) DMAC_Handler,           /*  7 Direct Memory Access Controller */
        .pfnEVSYS_Handler       = (void*) EVSYS_Handler,          /*  8 Event System Interface */
        .pfnSERCOM0_Handler     = (void*) SERCOM0_Handler,        /*  9 Serial Communication Interface 0 */
        .pfnSERCOM1_Handler     = (void*) SERCOM1_Handler,        /* 10 Serial Communication Interface 1 */
        .pfnSERCOM2_Handler     = (void*) SERCOM2_Handler,        /* 11 Serial Communication Interface 2 */
#ifdef ID_SERCOM3
        .pfnSERCOM3_Handler     = (void*) SERCOM3_Handler,        /* 12 Serial Communication Interface 3 */
#else
        .pvReserved12           = (void*) (0UL),                  /* 12 Reserved */
#endif
#ifdef ID_SERCOM4
        .pfnSERCOM4_Handler     = (void*) SERCOM4_Handler,        /* 13 Serial Communication Interface 4 */
#else
        .pvReserved13           = (void*) (0UL),                  /* 13 Reserved */
#endif
#ifdef ID_SERCOM5
        .pfnSERCOM5_Handler     = (void*) SERCOM5_Handler,        /* 14 Serial Communication Interface 5 */
#else
        .pvReserved14           = (void*) (0UL),                  /* 14 Reserved */
#endif
        .pfnTCC0_Handler        = (void*) TCC0_Handler,           /* 15 Timer Counter Control */
        .pfnTC0_Handler         = (void*) TC0_Handler,            /* 16 Basic Timer Counter 0 */
        .pfnTC1_Handler         = (void*) TC1_Handler,            /* 17 Basic Timer Counter 1 */
        .pfnTC2_Handler         = (void*) TC2_Handler,            /* 18 Basic Timer Counter 2 */
        .pfnTC3_Handler         = (void*) TC3_Handler,            /* 19 Basic Timer Counter 3 */
        .pfnADC_Handler         = (void*) ADC_Handler,            /* 20 Analog Digital Converter */
        .pfnAC_Handler          = (void*) AC_Handler,             /* 21 Analog Comparators */
#ifdef ID_PTC
        .pfnPTC_Handler         = (void*) PTC_Handler,            /* 22 Peripheral Touch Controller */
#else
        .pvReserved22           = (void*) (0UL),                  /* 22 Reserved */
#endif
        .pfnSLCD_Handler        = (void*) SLCD_Handler,           /* 23 Segment Liquid Crystal Display Controller */
#ifdef ID_AES
        .pfnAES_Handler         = (void*) AES_Handler,            /* 24 Advanced Encryption Standard */
#else
        .pvReserved24           = (void*) (0UL),                  /* 24 Reserved */
#endif
#ifdef ID_TRNG
        .pfnTRNG_Handler        = (void*) TRNG_Handler            /* 25 True Random Generator */
#else
        .pvReserved25           = (void*) (0UL)                   /* 25 Reserved */
#endif
};

/**
 * \brief This is the code that gets called on processor reset.
 * To initialize the device, and call the main() routine.
 */
void Reset_Handler(void)
{
    uint32_t *pSrc, *pDest;

    /* Initialize the relocate segment */
    pSrc = &_etext;
    pDest = &_srelocate;

    if (pSrc != pDest) {
        for (; pDest < &_erelocate;) {
            *pDest++ = *pSrc++;
        }
    }

    /* Clear the zero segment */
    for (pDest = &_szero; pDest < &_ezero;) {
            *pDest++ = 0;
    }

    /* Set the vector table base address */
    pSrc = (uint32_t *) & _sfixed;
    SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);

    /* Initialize the C library */
    __libc_init_array();

    /* Branch to main function */
    main();

    /* Infinite loop */
    while (1);
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler(void)
{
    NVIC_SystemReset();
}
