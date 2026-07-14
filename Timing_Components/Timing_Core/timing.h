#ifndef TIMING_H
#define TIMING_H

#include <stdint.h>

#ifdef _WIN32
    #include <windows.h>
#else 
    #include <unistd.h>  
    #include <sys/time.h>   
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern uint64_t get_clock_cycles(void);
double cycles_to_miliseconds(uint64_t cycles);

#ifdef __cplusplus
}
#endif

#endif