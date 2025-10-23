#include "lora_manager.h"
#include "config.h"
#include "esp_log.h"

LoraManager::LoraManager() : e220ttl(&Serial2, LORA_AUX_PIN, LORA_M0_PIN, LORA_M1_PIN) {}

bool LoraManager::setup() {
    ESP_LOGI(TAG_LORA, "Inicializando módulo LoRa E220...");

    pinMode(LORA_M0_PIN, OUTPUT);
    pinMode(LORA_M1_PIN, OUTPUT);

    // Modo Normal (0, 0) para transmissão
    digitalWrite(LORA_M0_PIN, LOW);
    digitalWrite(LORA_M1_PIN, LOW);
    
    Serial2.begin(LORA2ESP_BAUDRATE, SERIAL_8N1, LORA_RX_PIN, LORA_TX_PIN);
    e220ttl.begin();

    delay(1000); // Delay de estabilização
    
    ResponseStructContainer config = e220ttl.getConfiguration();
    if (config.status.code != 1) {
        ESP_LOGE(TAG_LORA, "Falha ao comunicar com o módulo E220: %s", config.status.getResponseDescription().c_str());
        config.close();
        return false;
    }
    
    ESP_LOGI(TAG_LORA, "Módulo LoRa E220 inicializado com sucesso.");
    config.close();
    return true;
}

bool LoraManager::sendMessage(const char* message) {
    ResponseStatus rs = e220ttl.sendMessage(message);
    if (rs.code != 1) {
        ESP_LOGE(TAG_LORA, "Erro ao enviar mensagem LoRa: %s", rs.getResponseDescription().c_str());
        return false;
    }
    return true;
}