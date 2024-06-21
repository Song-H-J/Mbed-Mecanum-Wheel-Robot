#include "mbed.h"

class L298N{
    DigitalOut f_dir1;
    DigitalOut f_dir2;
    PwmOut f_pwm;

    DigitalOut b_dir1;
    DigitalOut b_dir2;
    PwmOut b_pwm;

    int8_t dir_type;

  public:
    L298N(PinName F_DIR1, PinName F_DIR2, PinName F_PWM,
          PinName B_DIR1, PinName B_DIR2, PinName B_PWM, int8_t DIR_TYPE):
          f_dir1(F_DIR1), f_dir2(F_DIR2), f_pwm(F_PWM),
          b_dir1(B_DIR1), b_dir2(B_DIR2), b_pwm(B_PWM), dir_type(DIR_TYPE){}
    
    void setFBRpm(float f_rpm, float b_rpm){
        switch(dir_type){
            case 1:
                if(f_rpm>0){ f_dir1.write(false); f_dir2.write(true); f_pwm.write(abs(f_rpm));}
                else if(f_rpm<0) {f_dir1.write(true); f_dir2.write(false); f_pwm.write(abs(f_rpm));}
                else {f_dir1.write(false); f_dir2.write(false); f_pwm.write(0.0f);}
                if(b_rpm>0){ b_dir1.write(true); b_dir2.write(false); b_pwm.write(abs(b_rpm));}
                else if(b_rpm<0) {b_dir1.write(false); b_dir2.write(true); b_pwm.write(abs(b_rpm));}
                else {b_dir1.write(false); b_dir2.write(false); b_pwm.write(0.0f);}

                break;
            case 2:
                if(f_rpm>0){ f_dir1.write(true); f_dir2.write(false); f_pwm.write(abs(f_rpm));}
                else if(f_rpm<0) {f_dir1.write(false); f_dir2.write(true); f_pwm.write(abs(f_rpm));}
                else {f_dir1.write(false); f_dir2.write(false); f_pwm.write(0.0f);}
                if(b_rpm>0){ b_dir1.write(false); b_dir2.write(true); b_pwm.write(abs(b_rpm));}
                else if(b_rpm<0) {b_dir1.write(true); b_dir2.write(false); b_pwm.write(abs(b_rpm));}
                else {b_dir1.write(false); b_dir2.write(false); b_pwm.write(0.0f);}
                break;
        }
    }

};