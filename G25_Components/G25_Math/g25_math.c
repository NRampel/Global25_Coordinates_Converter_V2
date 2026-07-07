#include "g25_math.h"

const double eigenvaluesLUT[DIMS] = {
      129.557, 103.130, 14.222, 10.433, 9.471, 
        7.778, 5.523, 5.325, 4.183, 3.321, 
        2.637, 2.246, 2.210, 1.894, 1.842, 
        1.758, 1.700, 1.605, 1.580, 1.564, 
        1.557, 1.529, 1.519, 1.452, 1.434
}; 

double sqrtEigenValuesLUT[DIMS]; 

float scaledToUnscaled(float coordinate, uint8_t dimension) {
    return (coordinate / sqrtEigenValuesLUT[dimension]); 
}

float unscaledToScaled(float coordinate, uint8_t dimension) {
    return (coordinate * sqrtEigenValuesLUT[dimension]); 
}