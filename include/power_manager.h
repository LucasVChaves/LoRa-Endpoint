#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

#include <stdint.h>

class PowerManager {
public:
    void sleep(uint64_t time_s = 0);
};

#endif // POWER_MANAGER_H