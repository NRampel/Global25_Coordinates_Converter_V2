#include "g25_init.h"

void initEigenvalues(void) {
    for(uint8_t d = 0; d < DIMS; d++) {
        sqrtEigenValuesLUT[d] = sqrt(eigenvaluesLUT[d]); 
    }
}

