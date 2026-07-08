#include "batch_processor.hpp"
#include <iostream>
#include <sstream>

BatchProcessor::BatchProcessor(const std::string& inputFile, LineProcessorCallback lineProcessor)
    : m_inputFilePath(inputFile),
      m_linesProcessed(0),
      m_linesFailed(0),
      m_lineProcessor(lineProcessor) {
    initEigenvalues();
}

BatchProcessor::~BatchProcessor() {
    std::cout << "\n--- Batch Processing Summary ---\n";
    std::cout << "Lines successfully processed: " << m_linesProcessed << "\n";
    std::cout << "Lines failed to parse: " << m_linesFailed << "\n";
    std::cout << "------------------------------\n";
}

void BatchProcessor::run() {
    ScopedTimer timer("Batch Processing");
    processFile();
}

bool BatchProcessor::processLine(const std::string& line) {
    std::string segment;
    std::vector<float> coords;
    std::stringstream ss(line);
    if (!std::getline(ss, segment, ',')) return false; 
    std::string sampleName = segment;
    while (coords.size() < DIMS && std::getline(ss, segment, ',')) {
        try {
            coords.push_back(std::stof(segment));
        } catch (const std::exception& e) {
            return false;
        }
    }
    if (coords.size() != DIMS) return false; 
    m_lineProcessor(sampleName, coords);

    return true;
}

void BatchProcessor::processFile() {
    std::ifstream inputFile(m_inputFilePath);
    if (!inputFile.is_open()) error_handle(1);
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') continue; 
        if (processLine(line)) {
            m_linesProcessed++;
        } else {
            m_linesFailed++;
        }
    }
}