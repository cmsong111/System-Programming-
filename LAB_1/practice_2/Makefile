CC = gcc
CFLAGS = -Wall -Werror

SRC_DIR = src
LIB_DIR = lib
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

all: static_example

static_example: main.c libmath_operations.a
	$(CC) $(CFLAGS) -o $@ main.c -L$(LIB_DIR) -lmath_operations

libmath_operations.a: $(OBJS)
	ar rcs $(LIB_DIR)/$@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o
	rm -f $(LIB_DIR)/*.a static_example
