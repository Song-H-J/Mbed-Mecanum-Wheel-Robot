#include "mechanum_kine.h"

// Variable definitions
float r = 2.5f;
float l = 6.0f;
float w = 7.0f;

// Function definition
void calcMechanumRpm(float wbz, float vbx, float vby, float (&u)[4]) {
    u[0] = (1 / r) * ((-l - w) * wbz + vbx - vby);
    u[1] = (1 / r) * ((l + w) * wbz + vbx + vby);
    u[2] = (1 / r) * ((l + w) * wbz + vbx - vby);
    u[3] = (1 / r) * ((-l - w) * wbz + vbx + vby);
}

std::pair<float, float> convertToDia(int8_t x, int8_t y) {
    float normX = static_cast<float>(x) / 100.0;
    float normY = static_cast<float>(y) / 100.0;

    float diamondX = normX * 1.75;
    float diamondY = normY * 1.75;

    return std::make_pair(diamondX, diamondY);
}