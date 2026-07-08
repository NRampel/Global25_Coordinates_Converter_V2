#include "Batch_Processing_Components/Batch_Processor_Instance/batch_processor.hpp"

void convertToUnscaled(const std::string& sampleName, const std::vector<float>& coords) {
    std::cout<<sampleName << "_unscaled,"; 
    for(uint8_t d = 0; d < DIMS; d++) {
        float scaledCoord = scaledToUnscaled(coords[d], d); 
        std::cout << scaledCoord << (d == DIMS -1 ? "" : ","); 
    }
    std::cout<<"\n"; 
}

int main(int argc, char*argv[]) {
    if(argc<2) error_handle(1); 
    std::string filePath = argv[1]; 
    BatchProcessor convertUnscaledtoScaled(filePath, convertToUnscaled); 
    convertUnscaledtoScaled.run(); 
    return 0; 
}

