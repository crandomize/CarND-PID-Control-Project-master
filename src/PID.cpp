#include "PID.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    Kp = 0;
    Ki = 0;
    Kd = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    prev_cte = 0.0;
    int_cte = 0.0;

    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

}


void PID::GetValues(double cte, double& steering, double&speed){

    
    int_cte += cte;

    steering = -Kp*cte - Kd*(cte-prev_cte) - Ki*int_cte;

    std::cout << "steering: " << steering << " cte " << cte << " p " << Kp*cte << " d " << Kd*(cte-prev_cte) << " i " << Ki*int_cte << std::endl;

    prev_cte = cte;

    if(steering>1.0) steering = 1.0;
    if(steering<-1.0) steering = -1.0;

    std::cout << "steering: " << steering << " cte " << cte << std::endl;

    speed = 10 + 30 *(1-abs(steering));
}


void PID::UpdateError(double cte) {
}

double PID::TotalError() {
    return 0;
}

