#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TARGET_TEMP 25.0
#define KP 1.0
#define KI 0.01
#define KD 0.0
#define MAX_OUTPUT 100.0
#define MAX_TEMP_DELTA 2.0
#define MIN_WAIT_TIME 1
#define MAX_WAIT_TIME 10
double read_temperature() {
    // simulate temperature reading
    double temp = (double)rand() / RAND_MAX * 10.0 + 20.0;
    return temp;
}
void control_air_conditioner(double output) {
    // simulate air conditioner control
    printf('AC output: %f\n', output);
}
int main() {
    double current_temp = 20.0;
    double error = 0.0;
    double integral = 0.0;
    double derivative = 0.0;
    double prev_error = 0.0;
    double output = 0.0;
    time_t start_time;
    int wait_time = 0;
    // seed random number generator
    srand(time(NULL));
    while (1) {
        // read temperature sensor
        current_temp = read_temperature();
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
        control_air_conditioner(output);
        // wait for some time
        wait_time = (int)((double)(MAX_WAIT_TIME - MIN_WAIT_TIME + 1) * rand() / (RAND_MAX + 1.0) + MIN_WAIT_TIME);
        printf('Waiting for %d seconds...\n', wait_time);
        start_time = time(NULL);
        while ((time(NULL) - start_time) < wait_time) {
            // do nothing
        }
        // update PID gains based on temperature delta
        double temp_delta = current_temp - TARGET_TEMP;
        if (temp_delta > MAX_TEMP_DELTA) {
            KP *= 1.5;
            KI *= 2.0;
            KD *= 0.5;
        } else if (temp_delta < -MAX_TEMP_DELTA) {
            KP *= 0.5;
            KI *= 0.25;
            KD *= 2.0;
        }
    }
    return 0;
}

