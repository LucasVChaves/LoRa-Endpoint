#ifndef CONFIG_H
#define CONFIG_H

// =================================================================
// CONFIGURAÇÕES DE LOGGING E DEBUG
// =================================================================

// Tags para identificação dos logs nos diferentes módulos do sistema.
#define TAG_MAIN "Main"
#define TAG_FSM "AppFSM"
#define TAG_LORA "Lora"
#define TAG_SENSOR "SensorSvc"
#define TAG_POWER "Power"
#define TAG_BMP280 "BMP280"

// =================================================================
// CONFIGURAÇÕES DE HARDWARE (PINOS)
// =================================================================

// Pinos LoRa E220
#define LORA_RX_PIN 16
#define LORA_TX_PIN 17
#define LORA_AUX_PIN 18
#define LORA_M0_PIN 19
#define LORA_M1_PIN 21

// LED de status
#define LED_BUILTIN 2

#endif