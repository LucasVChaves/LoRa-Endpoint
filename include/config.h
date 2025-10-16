#ifndef CONFIG_H
#define CONFIG_H

// =================================================================
// CONFIGURAÇÕES DE SLEEP
// =================================================================

// Tempo que o dispositivo ficará em modo de sono profundo (Deep Sleep).
const uint8_t SLEEP_INTERVAL_HOURS = 3;

// Conversão do intervalo para microssegundos
const uint64_t SLEEP_INTERVAL_US = (uint64_t)SLEEP_INTERVAL_HOURS * 3600 * 1000000;

// =================================================================
// CONFIGURAÇÕES DE LOGGING E DEBUG
// =================================================================

// Tags para identificação dos logs nos diferentes módulos do sistema.
#define TAG_MAIN "Main"
#define TAG_FSM "FSM"
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

// Pinos Sensores
#define BMP280_SCL 22
#define BMP280_SDA 23

// LED de status
#define LED_BUILT_IN 2

#endif