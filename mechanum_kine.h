#include "mbed.h"

#ifndef MECHANUM_KINE_H
#define MECHANUM_KINE_H

extern float r;
extern float l;
extern float w;

void calcMechanumRpm(float wbz, float vbx, float vby, float (&u)[4]);
std::pair<float, float> convertToDia(int8_t x, int8_t y);

#endif // MECHANUM_KINE_H

