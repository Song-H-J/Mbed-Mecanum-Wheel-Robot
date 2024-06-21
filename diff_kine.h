#include "mbed.h"

#ifndef DIFF_KINE_H
#define DIFF_KINE_H

extern float d;
extern float rr;

float constrain(float value, float min, float max);
std::pair<float, float> calcDiffRpm(int8_t v_x, int8_t omega_y);

#endif // DIFF_KINE_H