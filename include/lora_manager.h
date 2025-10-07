#ifndef LORA_MANAGER_H
#define LORA_MANAGER_H

#include "LoRa_E220.h"

class LoraManager {
public:
    LoraManager();
    bool setup();
    bool sendMessage(const char* message);

private:
    LoRa_E220 e220ttl;
};

#endif