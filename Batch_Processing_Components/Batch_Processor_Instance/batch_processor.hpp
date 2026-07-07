#ifndef BATCH_PROCESSOR_HPP
#define BATCH_PROCESSOR_HPP 

#include <cstdint> 
#include <string>
#include <ifstream>
#include <vector> 
#include "../Error_Handers/error_handling.h"
#include "../../Timing_Components/Timing_Wrapper/timing_wrapper.hpp"
#include "../../G25_Components/G25_Math/g25_math.h"

class BatchProcessor {
    public: 
        explicit BatchProcessor(const std::string& inputFile); 
        ~BatchProcessor(); 
        void run(); 
    private:
        void processFile(); 
        void processLine(const std::string& line); 
        std::string inputFilePath; 
        size_t linesProcessed; 
        size_t linesFailed; 
}

#endif