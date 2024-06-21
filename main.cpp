#include "mbed.h"
#include "hc06.h"
#include "l298n.h"
#include "mechanum_kine.h"
#include "diff_kine.h"

HC06 _HC06(D10,D2);
L298N LDrive(D7,D8,D5,    D14,D4,D3,  1);
L298N RDrive(D12,D13,D9,  D15,D11,D6, 2);

std::pair<float, float> diaCoords;
std::pair<float, float> diffVel;
float cmdVel[4];

int main() {
    int8_t receivedBytes[3];
    while (1) {
        if (_HC06.readCommand(receivedBytes)) {
            switch(receivedBytes[0]){
                case 101:
                    diaCoords = convertToDia(receivedBytes[1],receivedBytes[2]);
                    calcMechanumRpm(0.0f, diaCoords.first, diaCoords.second, cmdVel);
                    LDrive.setFBRpm(cmdVel[3],-cmdVel[0]);
                    RDrive.setFBRpm(-cmdVel[2],cmdVel[1]);
                    break;

                case 102:
                    diffVel = calcDiffRpm(receivedBytes[1],receivedBytes[2]);
                    LDrive.setFBRpm(diffVel.second,diffVel.second);
                    RDrive.setFBRpm(-diffVel.first,-diffVel.first);
                    break;
            }
        }
    }
}
