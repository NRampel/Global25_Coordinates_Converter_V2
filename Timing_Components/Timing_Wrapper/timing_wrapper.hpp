#ifndef TIMING_WRAPPER_HPP 
#define TIMING_WRAPPER_HPP

#include <chrono>
#include <iostream> 
#include <string> 
#include "../Timing_Core/timing.h"

class ScopedTimer {
    public:
        ScopedTimer(const std::string& name)
            : m_Name(name), m_Start(std::chrono::high_resolution_clock::now()) {}

        ~ScopedTimer() {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - m_Start);
            std::cout << "[TIMER] " << m_Name << ": " << duration.count() << " us\n";
        };    

    private:
        std::string m_Name;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
};

class ScopedCycleCounter {
    public:
        ScopedCycleCounter(const std::string& name) : m_Name(name), m_StartCycles(get_clock_cycles()) {}

        ~ScopedCycleCounter() {
            uint64_t elapsed = get_clock_cycles() - m_StartCycles;
            std::cout << "[CYCLES] " << m_Name << ": " << elapsed << " cycles\n";
        }

    private:
        std::string m_Name;
        uint64_t m_StartCycles;
};

#endif