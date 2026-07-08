#ifndef G25_MATH_H
#define G25_MATH_H 

#include "../g25.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DIMS 25 
#define MAX_INPUT_LEN 512

extern const double eigenvaluesLUT[DIMS];
extern double sqrtEigenValuesLUT[DIMS];

float scaledToUnscaled(float coordinate, uint8_t dimension); 
float unscaledToScaled(float coordinate, uint8_t dimension); 

#ifdef __cplusplus
}
#endif

#endif