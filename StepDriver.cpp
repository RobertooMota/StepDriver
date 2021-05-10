#include "StepDriver.h";

StepDriver::StepDriver(byte pinEnb, byte pinStep, byte pinDir)
{
    pinMode(pinEnb, OUTPUT);
    pinMode(pinStep, OUTPUT);
    pinMode(pinDir, OUTPUT);

    _pinEnb = pinEnb;
    _pinStep = pinStep;
    _pinDir = pinDir;
}