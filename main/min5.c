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
    int j = 7; // เริ่มจากดวงที่ 8 เพื่อให้สวนกับ i

    while(1)
    {
        // เปิดไฟ LED ดวงที่ i และ j
        leds[i].ON();
        leds[j].ON();
        vTaskDelay(100/portTICK_PERIOD_MS);

        // ปิดไฟ LED ดวงที่ i และ j
        leds[i].OFF();
        leds[j].OFF();

        // อัปเดต index สำหรับไฟดวงแรก
        i++;
        if (i >= 7) i = 0; // เมื่อถึง LED ดวงสุดท้าย ให้กลับไปที่ดวงแรก
        
        // อัปเดต index สำหรับไฟดวงที่สอง
        j--;
        if (j <= 0) j = 7; // เมื่อถึง LED ดวงแรกสุด ให้กลับไปที่ดวงสุดท้าย
    }
}
