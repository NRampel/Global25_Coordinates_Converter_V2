#include "frontend.hpp"

void convertToUnscaled(const std::string& sampleName, const std::vector<float>& coords) {
    std::cout<<sampleName << "_unscaled,"; 
    for(uint8_t d = 0; d < DIMS; d++) {
        float scaledCoord = scaledToUnscaled(coords[d], d); 
        std::cout << scaledCoord << (d == DIMS -1 ? "" : ","); 
    }
    std::cout<<"\n"; 
}

void convertToScaled(const std::string& sampleName, const std::vector<float>& coords) {
    std::cout<<sampleName << "_scaled,"; 
    for(uint8_t d = 0; d < DIMS; d++) {
        float scaledCoord = unscaledToScaled(coords[d], d); 
        std::cout << scaledCoord << (d == DIMS -1 ? "" : ","); 
    }
    std::cout<<"\n"; 
}