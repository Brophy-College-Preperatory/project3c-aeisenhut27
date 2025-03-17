# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = voting

# Source file
SRCS = voting.c

# Object file
OBJS = $(SRCS:.c=.o)
# Default target: Compile the program
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove compiled files
clean:
	rm -f $(OBJS) $(TARGET)