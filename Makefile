# Compiler and flags
CXX := g++
CC := gcc

CXXFLAGS := -std=c++17 -Wall -Wextra -O2
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET := converter.exe

INCLUDES := \
    -I./Batch_Processing_Components/Batch_Processor_Instance \
    -I./Batch_Processing_Components/Error_Handers \
    -I./G25_Components/G25_Initialization \
    -I./G25_Components/G25_Math \
    -I./Timing_Components/Timing_Core \
    -I./Timing_Components/Timing_Wrapper \
    -I./Frontend_Components/UI \
    -I./Frontend_Components/Frontend_Linkage

SRCS_CPP := \
    main.cpp \
    Batch_Processing_Components/Batch_Processor_Instance/batch_processor.cpp \
    Frontend_Components/UI/UI.cpp \
    Frontend_Components/Frontend_Linkage/frontend.cpp

SRCS_C := \
    Batch_Processing_Components/Error_Handers/error_handling.c \
    G25_Components/G25_Initialization/g25_init.c \
    G25_Components/G25_Math/g25_math.c \
    Timing_Components/Timing_Core/timing.c

TIMING_ASM_SRC := Timing_Components/Timing_Core/timing.s

# --- Object File Definitions ---
TIMING_ASM_OBJ := $(TIMING_ASM_SRC:.s=_asm.o)

OBJS := \
    $(SRCS_CPP:.cpp=.o) \
    $(SRCS_C:.c=.o) \
    $(TIMING_ASM_OBJ)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

%_asm.o: %.s
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# Directives must be outside the recipe block
ifeq ($(OS),Windows_NT)
clean:
	-del /F /Q $(subst /,\,$(OBJS)) $(subst /,\,$(TARGET)) 2>nul
else
clean:
	-rm -f $(OBJS) $(TARGET)
endif