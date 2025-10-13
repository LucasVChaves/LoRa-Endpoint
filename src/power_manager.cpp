#include "power_manager.h"
#include "config.h"
#include "esp_log.h"
#include <Arduino.h>

void PowerManager::sleep(uint64_t time_s) {
    uint64_t sleep_time_us = (time_s > 0) ? time_s * 1000000 : SLEEP_INTERVAL_US;
    
    ESP_LOGI(TAG_POWER, "Entrando em Deep Sleep por %llu segundos.", sleep_time_us / 1000000);
    
    // Desliga a serial também.
    Serial.flush();
    Serial.end();

    esp_sleep_enable_timer_wakeup(sleep_time_us);
    esp_deep_sleep_start();
}