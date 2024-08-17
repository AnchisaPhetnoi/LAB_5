#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16); 
LED led2(17); 
LED led3(5); 
LED led4(18); 
LED led5(19); 
LED led6(21); 
LED led7(22); 
LED led8(23); 

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

extern "C" void app_main(void)
{
    int i = 0;
    while(1)
    {
        // เปิดไฟ LED ดวงที่ i
        leds[i].ON();
        vTaskDelay(100/portTICK_PERIOD_MS);
        
        // ปิดไฟ LED ดวงที่ i
        leds[i].OFF();
        
        // อัปเดต index ของ i
        if(i++ >= 7) i = 0; // เมื่อถึง LED ดวงสุดท้าย ให้กลับไปที่ดวงแรก
    }
}
