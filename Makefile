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
COMMON_SRCS_ASM := Timing_Components/Timing_Core/timing.s

MAIN_SRC1 := unscaled_to_scaled.cpp
MAIN_SRC2 := scaled_to_unscaled.cpp

COMMON_OBJS := \
    $(COMMON_SRCS_CPP:.cpp=.o) \
    $(COMMON_SRCS_C:.c=.o) \
    $(COMMON_SRCS_ASM:.s=.o)

MAIN_OBJ1 := $(MAIN_SRC1:.cpp=.o)
MAIN_OBJ2 := $(MAIN_SRC2:.cpp=.o)


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

%.o: %.s
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-del $(TARGET1) $(TARGET2) $(COMMON_OBJS) $(MAIN_OBJ1) $(MAIN_OBJ2)