#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    p_error = i_error = d_error = 0.0;
    cte_last = cte_sum = 0;
}

void PID::UpdateError(double cte) {
    cte_sum += cte;
    p_error = Kp * cte;
    d_error = Kd * (cte - cte_last);
    i_error = Ki * cte_sum;
    cte_last = cte;
}

double PID::TotalError() {
    double total_error = p_error + d_error + i_error;
    return  total_error;
}
