#include "frontend.hpp"

void convertToUnscaled(const std::string& sampleName, const std::vector<float>& coords, std::string& buffer) {
    buffer += sampleName + "_unscaled,"; 
    for(uint8_t d = 0; d < DIMS; d++) {
        float unscaledCoord = scaledToUnscaled(coords[d], d); 
        buffer += std::to_string(unscaledCoord); 
        buffer += (d == DIMS - 1 ? "\n" : ",");
    }
}

void convertToScaled(const std::string& sampleName, const std::vector<float>& coords, std::string& buffer) {
    buffer += sampleName + "_scaled,"; 
    for(uint8_t d = 0; d < DIMS; d++) {
        float scaledCoord = unscaledToScaled(coords[d], d); 
        buffer += std::to_string(scaledCoord); 
        buffer += (d == DIMS - 1 ? "\n" : ",");
    }
}