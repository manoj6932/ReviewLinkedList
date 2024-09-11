
#include <stdio.h>

#define TARGET_TEMP 25.0
#define KP 1.0
#define KI 0.01
#define KD 0.0
#define MAX_OUTPUT 100.0

int main() {
    double current_temp = 20.0;
    double error = 0.0;
    double integral = 0.0;
    double derivative = 0.0;
    double prev_error = 0.0;
    double output = 0.0;

    while (1) {
        // read temperature sensor
        // ...

        // compute error
        error = TARGET_TEMP - current_temp;

        // compute PID components
        integral += error;
        derivative = error - prev_error;
        prev_error = error;

        // compute output
        output = KP * error + KI * integral + KD * derivative;

        // limit output to maximum value
        if (output > MAX_OUTPUT) {
            output = MAX_OUTPUT;
        }

        // control air conditioner based on output
        // ...

        // wait for some time
        // ...
    }

    return 0;
}
