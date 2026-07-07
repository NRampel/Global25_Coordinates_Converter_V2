#include "timing.h"

static uint64_t cpuFreq = 0; 

static void calibrate_cpu_frequency() {
    uint64_t start = get_clock_cycles(); 
    Sleep(1000); 
    uint64_t end = get_clock_cycles(); 
    cpuFreq = end - start; 
}

double cycles_to_miliseconds(uint64_t cycles) {
    if(cpuFreq == 0) calibrate_cpu_frequency(); 
    return(double)cycles / (double)cpuFreq * 1000.0; 
}
