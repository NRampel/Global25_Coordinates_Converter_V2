# Global25_Coordinates_Converter_V2
A high-performance batch processing tool that is designed to convert Global25 (G25) Coordinates between their scaled and unscaled formats. 

Built with a focus on execution speed and close to bare-metal optimization. This tool utilizes a C++ file I/O wrapper around a pre-calculated C math engine. The pipeline is profited using native x86 'rdtsc' Assembly instructions for zero-overhead, cycle-accurate benchmarking. 

## Tech Stack: 
* Backend: ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![Assembly](https://img.shields.io/badge/Assembly-6E4C13?style=for-the-badge&logo=codeigniter&logoColor=white)
* Frontend: ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

## Prerequisites 
* Have a g++ & gcc compiler, preferably the MinGW-w64 compiler
