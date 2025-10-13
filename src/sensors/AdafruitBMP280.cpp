#include "AdafruitBMP280.h"
#include "config.h"
#include "esp_log.h"

Bmp280Sensor::Bmp280Sensor() : bmp(Adafruit_BMP280()) {}

bool Bmp280Sensor::setup() {
    ESP_LOGI(TAG_BMP280, "Inicializando sensor BMP280...");
    if (!bmp.begin()) {
        ESP_LOGE(TAG_BMP280, "Não foi possível encontrar o sensor BMP280, verifique a conexão!");
        return false;
    }
    bmp.setSampling(Adafruit_BMP280::MODE_FORCED,
                    Adafruit_BMP280::SAMPLING_X1,
                    Adafruit_BMP280::SAMPLING_X1,
                    Adafruit_BMP280::FILTER_OFF,
                    Adafruit_BMP280::STANDBY_MS_1);
    ESP_LOGI(TAG_BMP280, "Sensor BMP280 inicializado com sucesso.");
    return true;
}

float Bmp280Sensor::read() {
    if (bmp.takeForcedMeasurement()) {
        return bmp.readTemperature();
    }
    return -999.0f; // Valor de erro
}