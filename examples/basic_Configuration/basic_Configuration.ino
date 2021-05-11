/*
  Autor   : Roberto Mota
  Projeto : Controller Step Motor
  Data    : 2021/05/10
  Obs     : v1
*/



#include <StepDriver.h>  //Include library

StepDriver motor(3, 4, 5);  //Instance -> object(step pin, dir pin, enb pin)

void setup()
{
  motor.setAccel(1);    //aceleration (mm/s²)
  motor.setStepMM(22);  //Set steps per mm
  motor.setVel(1);      //Velocity of delay (not is mm/s)

}
void loop()
{
  motor.moveTo(20);  //move to 20mm (ABSOLUTE COORDINATES) 
}
