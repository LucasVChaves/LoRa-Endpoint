#ifndef FSM_H
#define FSM_H

#include "lora_manager.h"
#include "sensor.h"
#include "power_manager.h"

enum AppState {
    STATE_INIT,
    STATE_READ_SENSORS,
    STATE_TRANSMIT_DATA,
    STATE_SLEEP,
    STATE_ERROR
};

class StateMachine {
public:
    StateMachine(Sensor& sensor, LoraManager& lora, PowerManager& power);
    void run();

private:
    void handleInit();
    void handleReadSensors();
    void handleTransmitData();
    void handleSleep();
    void handleError();

    AppState currentState;
    Sensor& sensor;
    LoraManager& lora;
    PowerManager& power;

    float currentTemperature = 0.0f;
};

#endif // FSM_H