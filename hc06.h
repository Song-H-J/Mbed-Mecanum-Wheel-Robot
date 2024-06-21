#include "mbed.h"

class HC06{
    Serial bt;
  public:
    HC06(PinName TX, PinName RX): bt(TX, RX, 115200){}

    bool readCommand(int8_t *bytes){
        if (bt.readable()) {
            int bytesRead = 0;

            while (bytesRead < 3) {
                if (bt.readable()) {
                    bytes[bytesRead++] = bt.getc();
                }
            }
            return true;
        }
        return false;
    }
};