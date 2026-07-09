#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <stdint.h>
#include <stdio.h> 
#include <stdlib.h> 

#ifdef __cplusplus
    #define NO_RETURN [[noreturn]]
#else
    #define NO_RETURN _Noreturn
#endif

#ifdef __cplusplus
extern "C" {
#endif

    NO_RETURN void error_handle(uint8_t errorCode);

#ifdef __cplusplus
}
#endif


#endif