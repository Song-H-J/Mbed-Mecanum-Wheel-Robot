#include "diff_kine.h"

float d=7.0f;
float rr=2.5f;

float constrain(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

std::pair<float, float> calcDiffRpm(int8_t v_x, int8_t omega_y) {
    float uL = (v_x - omega_y * d) / rr;
    float uR = (v_x + omega_y * d) / rr;

    uL = constrain(uL, -1.0f, 1.0f);
    uR = constrain(uR, -1.0f, 1.0f);
    return std::make_pair(uL,uR);
}