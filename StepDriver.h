
#ifndef STEPDRIVER_H
#define STEPDRIVER_H
#include <Arduino.h>

//Métodos do motor de passo
/*
1 - Ir para direita / esquerda
2 - Girar sem fim direita / esquerda
*/

//Caracteristicas
/*
1 - velocidade
2 - Aceleracao
3 - passos por mm
*/

class StepDriver
{
public:
    StepDriver(byte pinEnb, byte pinStep, byte pinDir);
    void moveTo(double distance);
    void stepByStep();

    void setVel(int motorVel);
    void setStepMM(unsigned int steps);
    void setAccel(float accel);

private:
    //tipo STRING

    //tipo BYTE
    byte(_pinEnb);
    byte(_pinStep);
    byte(_pinDir);

    //tipo INT
    int _motorvel;
    unsigned int _steps;

    //tipo FLOAT
    double _distance;
    float _accel;
};
#endif