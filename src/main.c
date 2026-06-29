#include "n32g031.h"
#include "n32g031_gpio.h"
#include "n32g031_rcc.h"

/* ฟังก์ชันหน่วงเวลา (1000 = ประมาณ 1 วินาที) */
void Delay_ms_Simple(uint32_t ms) {
    for(volatile uint32_t i = 0; i < ms * 1200; i++) {
        __NOP();
    }
}

int main(void) {
    /* 1. เปิดสัญญาณนาฬิกา (Clock) ให้พอร์ต A */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);

    /* 2. ตั้งค่าขา PA1 (ไฟสีแดง) เป็น Output */
    GPIO_InitType GPIO_InitStructure;
    GPIO_InitStruct(&GPIO_InitStructure);
    GPIO_InitStructure.Pin = GPIO_PIN_1; 
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUTPUT_PP; 
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    while(1) {
        /* -------- สั่งไฟกะพริบ -------- */
        GPIO_SetBits(GPIOA, GPIO_PIN_1);     // เปิดไฟแดง (ON)
        Delay_ms_Simple(1000);               // หน่วงเวลา 1 วินาที

        GPIO_ResetBits(GPIOA, GPIO_PIN_1);   // ปิดไฟแดง (OFF)
        Delay_ms_Simple(1000);               // หน่วงเวลา 1 วินาที
    }
}