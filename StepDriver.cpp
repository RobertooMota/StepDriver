#include "StepDriver.h";

StepDriver::StepDriver(byte pinEnb, byte pinStep, byte pinDir)
{
    Serial.begin(9600);
    pinMode(pinEnb, OUTPUT);
    pinMode(pinStep, OUTPUT);
    pinMode(pinDir, OUTPUT);

    _pinEnb = pinEnb;
    _pinStep = pinStep;
    _pinDir = pinDir;

    if (_motorvel == 0)
        _motorvel = 5;
    if (_accel == 0)
        _accel = 1;
    if (_steps == 0)
        _steps = 20;
}

void StepDriver::setVel(int motorVel)
{
    _motorvel = motorVel;
}

void StepDriver::setAccel(float accel)
{
    _accel = accel;
}

void StepDriver::setStepMM(unsigned int steps)
{
    _steps = steps;
}

void StepDriver::parameterStatus()
{

    Serial.println(_motorvel);
    Serial.println(_accel);
    Serial.println(_steps);
}

void StepDriver::moveTo(double distance)
{

    if (distance > _currentDistance)
    {
        _stepsTotal = (distance * _steps) - (_currentDistance * _steps);

        digitalWrite(_pinDir, HIGH);

        while (_stepsTotal > 0)
        {
            digitalWrite(_pinStep, HIGH);
            delay(_motorvel);
            digitalWrite(_pinStep, LOW);
            _stepsTotal--;
        }
    }
    else
    {
        digitalWrite(_pinDir, LOW);
        _stepsTotal = (_currentDistance * _steps) - (distance * _steps);

        while (_stepsTotal > 0)
        {
            digitalWrite(_pinStep, HIGH);
            delay(_motorvel);
            digitalWrite(_pinStep, LOW);
            _stepsTotal--;
        }
        
    }

    _currentDistance = distance;

    /* Caso precise usar a distancia de um passo
    float oneStep()
    {
        float resul = 1 / _steps;
        return resul;
    }
    */
}