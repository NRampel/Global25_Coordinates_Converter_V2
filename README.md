# Global25_Coordinates_Converter_V2
A high-performance batch processing tool that is designed to convert Global25 (G25) Coordinates between their scaled and unscaled formats. 

Built with a focus on execution speed and close to bare-metal optimization. This tool utilizes a C++ file I/O wrapper around a pre-calculated C math engine. The pipeline is profited using native x86 'rdtsc' Assembly instructions for zero-overhead, cycle-accurate benchmarking. 
#
### Tech Stack: 
* **Backend:** ![C](https://img.shields.io/badge/c-%2300599C.svg?style=flat&logo=c&logoColor=white) ![Assembly](https://img.shields.io/badge/Assembly-6E4C13?style=flat&logo=codeigniter&logoColor=white)
* **Frontend:** ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=flat&logo=c%2B%2B&logoColor=white)
* **Build System:** ![Make](https://img.shields.io/badge/make-%23000000.svg?style=flat&logo=gnu&logoColor=white)

### Prerequisites
* A `g++` & `gcc` compiler (preferably [MinGW-w64](https://www.mingw-w64.org/)).
* `GNU Make` for executing build commands.
# 
## Usage
**Windows**
* Compile the project using `mingw32-make`, then run the executable:
```bash
mingw32-make
.\converter.exe
```
* Move the created file outside the root directory and rename it

**Linux** 
* Compile the project using `make`, then run the executable:
```bash
make
./converter
```
* Move the created file outside the root directory and rename it
