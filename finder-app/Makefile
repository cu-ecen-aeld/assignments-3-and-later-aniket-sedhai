#variables

CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror
TARGET := writer
SRC := writer.c
OBJ := $(SRC:.c=.o)

# default target to build the writer application
all: $(TARGET)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# build the writer application
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Clean target to remove the "writer" application and .o file
clean:
	rm -f $(OBJ) $(TARGET)

# Add PHONY targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
