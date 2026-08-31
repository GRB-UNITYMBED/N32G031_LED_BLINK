#include "n32g031.h"
#include "n32g031_gpio.h"
#include "n32g031_rcc.h"

/* Delay function (1000 = approx. 1 second) */
void Delay_ms_Simple(uint32_t ms) {
    for(volatile uint32_t i = 0; i < ms * 1200; i++) {
        __NOP();
    }
}

int main(void) {
    /* 1. Enable Clock for Port A (GPIOA) */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);

    /* 2. Configure Pin PA1 (Red LED) as Output */
    GPIO_InitType GPIO_InitStructure;
    GPIO_InitStruct(&GPIO_InitStructure);
    GPIO_InitStructure.Pin = GPIO_PIN_1; 
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUTPUT_PP; 
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    while(1) {
        /* -------- Blink LED -------- */
        GPIO_SetBits(GPIOA, GPIO_PIN_1);     // Turn ON Red LED
        Delay_ms_Simple(1000);               // Delay 1 second

        GPIO_ResetBits(GPIOA, GPIO_PIN_1);   // Turn OFF Red LED
        Delay_ms_Simple(1000);               // Delay 1 second
    }
}
