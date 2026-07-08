# Compiler and flags
CXX := g++
CC := gcc

CXXFLAGS := -std=c++17 -Wall -Wextra -O2
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET1 := unscaled_to_scaled.exe
TARGET2 := scaled_to_unscaled.exe

INCLUDES := \
    -I./Batch_Processing_Components/Batch_Processor_Instance \
    -I./Batch_Processing_Components/Error_Handers \
    -I./G25_Components/G25_Initialization \
    -I./G25_Components/G25_Math \
    -I./Timing_Components/Timing_Core \
    -I./Timing_Components/Timing_Wrapper

COMMON_SRCS_CPP := Batch_Processing_Components/Batch_Processor_Instance/batch_processor.cpp
COMMON_SRCS_C := \
    Batch_Processing_Components/Error_Handers/error_handling.c \
    G25_Components/G25_Initialization/g25_init.c \
    G25_Components/G25_Math/g25_math.c \
    Timing_Components/Timing_Core/timing.c

# Handle the assembly source file separately to avoid name collisions
TIMING_ASM_SRC := Timing_Components/Timing_Core/timing.s

MAIN_SRC1 := unscaled_to_scaled.cpp
MAIN_SRC2 := scaled_to_unscaled.cpp

# --- Object File Definitions ---
# Create a unique object file for the assembly source (e.g., timing_asm.o)
TIMING_ASM_OBJ := $(TIMING_ASM_SRC:.s=_asm.o)

COMMON_OBJS := \
    $(COMMON_SRCS_CPP:.cpp=.o) \
    $(COMMON_SRCS_C:.c=.o)   \
    $(TIMING_ASM_OBJ)

MAIN_OBJ1 := $(MAIN_SRC1:.cpp=.o)
MAIN_OBJ2 := $(MAIN_SRC2:.cpp=.o)

# --- Aggregate lists for cleaning ---
# These MUST be defined after all object and target variables
EXECUTABLES := $(TARGET1) $(TARGET2)
OBJECTS := $(COMMON_OBJS) $(MAIN_OBJ1) $(MAIN_OBJ2)

.PHONY: all
all: $(TARGET1) $(TARGET2)

$(TARGET1): $(MAIN_OBJ1) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)


$(TARGET2): $(MAIN_OBJ2) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# This rule correctly builds a file like 'timing_asm.o' from 'timing.s'
%_asm.o: %.s
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

.PHONY: clean
# Use 'del' on Windows and 'rm' on other systems for portability.
clean:
ifeq ($(OS),Windows_NT)
	-del /F /Q $(subst /,\,$(OBJECTS)) $(subst /,\,$(EXECUTABLES)) 2>nul
else
	-rm -f $(OBJECTS) $(EXECUTABLES)
endif