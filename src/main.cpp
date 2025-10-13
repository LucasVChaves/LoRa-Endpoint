#include <Arduino.h>
#include "config.h"
#include "esp_log.h"
#include "state_machine.h"
#include "lora_manager.h"
#include "power_manager.h"
#include "sensors/AdafruitBMP280.h"

Bmp280Sensor sensor;
LoraManager lora;
PowerManager power;

StateMachine fsm(sensor, lora, power);

void setup() {
    Serial.begin(115200);
    delay(1000); // Tempo para a serial estabilizar
    ESP_LOGI(TAG_MAIN, "=== Firmware Endpoint LoRa v1.0 ===");
    fsm.run();
}

void loop() {
    // O loop fica vazio pq toda a lógica está na maquina de estados e o esp dorme no final do ciclo.
}