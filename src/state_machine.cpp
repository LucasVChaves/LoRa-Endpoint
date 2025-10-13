#include "state_machine.h"
#include "config.h"
#include "esp_log.h"

StateMachine::StateMachine(Sensor& sensor, LoraManager& lora, PowerManager& power)
    : sensor(sensor), lora(lora), power(power), currentState(STATE_INIT) {}

void StateMachine::run() {
    switch (currentState) {
        case STATE_INIT:
            handleInit();
            break;
        case STATE_READ_SENSORS:
            handleReadSensors();
            break;
        case STATE_TRANSMIT_DATA:
            handleTransmitData();
            break;
        case STATE_SLEEP:
            handleSleep();
            break;
        case STATE_ERROR:
            handleError();
            break;
    }
}

void StateMachine::handleInit() {
    ESP_LOGI(TAG_FSM, "Estado: INICIALIZANDO");
    bool sensorOk = sensor.setup();
    bool loraOk = lora.setup();

    if (sensorOk && loraOk) {
        currentState = STATE_READ_SENSORS;
    } else {
        ESP_LOGE(TAG_FSM, "Falha na inicialização de hardware.");
        currentState = STATE_ERROR;
    }
    run();
}

void StateMachine::handleReadSensors() {
    ESP_LOGI(TAG_FSM, "Estado: LENDO SENSORES");
    currentTemperature = sensor.read();

    ESP_LOGI(TAG_SENSOR, "Temperatura: %.2f C.", currentTemperature);

    currentState = STATE_TRANSMIT_DATA;
    run();
}

void StateMachine::handleTransmitData() {
    ESP_LOGI(TAG_FSM, "Estado: TRANSMITINDO DADOS");
    char payload[50];
    snprintf(payload, sizeof(payload), "T:%.2f", currentTemperature);

    if (lora.sendMessage(payload)) {
        ESP_LOGI(TAG_LORA, "Payload '%s' enviado com sucesso.", payload);
        currentState = STATE_SLEEP;
    } else {
        ESP_LOGE(TAG_LORA, "Falha ao enviar payload.");
        currentState = STATE_ERROR;
    }
    run();
}

void StateMachine::handleSleep() {
    ESP_LOGI(TAG_FSM, "Estado: DORMINDO");
    power.sleep();
    // Neste caso teria entrado em sleep, se não entrou é pq deu merda
    ESP_LOGE(TAG_FSM, "Passou do sleep, fodeu!");
}

void StateMachine::handleError() {
    ESP_LOGE(TAG_FSM, "Estado: ERRO. O sistema irá dormir para economizar energia.");
    // TODO: Piscar um led ou beep num buzzer pra alertar erro.
    power.sleep(60);
}