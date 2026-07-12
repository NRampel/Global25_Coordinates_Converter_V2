#ifndef BATCH_PROCESSOR_HPP
#define BATCH_PROCESSOR_HPP 

#include <iostream>
#include <cstdint> 
#include <string>
#include <fstream>
#include <vector> 
#include <functional>
#include "../Error_Handers/error_handling.h"
#include "../../Timing_Components/Timing_Wrapper/timing_wrapper.hpp"
#include "../../G25_Components/G25_Math/g25_math.h"
#include "../../G25_Components/G25_Initialization/g25_init.h"



class BatchProcessor {
    public:
        using LineProcessorCallback = std::function<void(const std::string& sampleName, const std::vector<float>& coords, std::string& buffer)>;
        explicit BatchProcessor(const std::string& inputFile, LineProcessorCallback lineProcessor);
        ~BatchProcessor();
        void run();
    private:
        void processFile(std::string& outputBuffer);
        bool processLine(const std::string& line, std::string& outputBuffer);
        std::string m_inputFilePath;
        size_t m_linesProcessed;
        size_t m_linesFailed;
        LineProcessorCallback m_lineProcessor;
        const std::string m_outputFilePath = "converted_output.txt";
};

#endif