# global variables

CC=gcc
CSTD=iso9899:1990
CFLAGS=-Wall -Wextra -pedantic
DEBUG=-ggdb
CCOMMAND=$(CC) $(CFLAGS) $(DEBUG) -std=$(CSTD)

LIB_TYPE=static
LIB_NAME=mem
OUTPUT_LIB_NAME=lib$(LIB_NAME)

BUILD_DIR=build

LIB_DIR=$(BUILD_DIR)/lib
LIB_PATH=$(LIB_DIR)/$(LIB_TYPE)/$(OUTPUT_LIB_NAME)

SRC_DIR=src
INCLUDE_DIR=include
BIN_DIR=$(BUILD_DIR)/bin

TEST_SRC_DIR=tests
TEST_OUTPUT_DIR=tests
TEST_PREFIX=test_

TEST_NAMES=alloc alloc_with_size_info realloc realloc_with_size_info
TEST_OBJECTS=$(addprefix $(BIN_DIR)/$(TEST_OUTPUT_DIR)/, $(addsuffix .o, $(TEST_NAMES)))
TEST_EXECUTABLES=$(addprefix $(BIN_DIR)/$(TEST_OUTPUT_DIR)/, $(TEST_NAMES))
RUNNABLE_TESTS=$(addprefix $(TEST_PREFIX), $(TEST_NAMES))

all: $(LIB_PATH).a


# build main library

$(LIB_PATH).a: $(BIN_DIR)/$(LIB_NAME).o | $(LIB_DIR)/$(LIB_TYPE)
	ar rcs $(LIB_PATH).a -o $(BIN_DIR)/$(LIB_NAME).o

$(BIN_DIR)/$(LIB_NAME).o: $(SRC_DIR)/$(LIB_NAME).c $(INCLUDE_DIR)/$(LIB_NAME).h | $(BIN_DIR)
	$(CCOMMAND) -I$(INCLUDE_DIR) -c $(SRC_DIR)/$(LIB_NAME).c -o $@


# build and run tests

test-run: $(RUNNABLE_TESTS)

$(RUNNABLE_TESTS): $(TEST_PREFIX)%: $(BIN_DIR)/$(TEST_OUTPUT_DIR)/%
	./$<

test-build: $(TEST_EXECUTABLES)

$(TEST_EXECUTABLES): %: %.o $(LIB_PATH).a
	$(CC) $(CFLAGS) $< -o $@ -L$(LIB_DIR)/$(LIB_TYPE) -l$(LIB_NAME) 

$(TEST_OBJECTS): $(BIN_DIR)/$(TEST_OUTPUT_DIR)/%.o: $(TEST_SRC_DIR)/%.c | $(BIN_DIR)/$(TEST_OUTPUT_DIR)
	$(CCOMMAND) -I$(INCLUDE_DIR) -c $< -o $@


# build required directories

$(BIN_DIR)/$(TEST_OUTPUT_DIR): | $(BIN_DIR)
	mkdir $(BIN_DIR)/$(TEST_OUTPUT_DIR)

$(LIB_DIR)/$(LIB_TYPE): | $(LIB_DIR)
	mkdir $(LIB_DIR)/$(LIB_TYPE)

$(LIB_DIR): | $(BUILD_DIR)
	mkdir $(LIB_DIR)

$(BIN_DIR): | $(BUILD_DIR)
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

.PHONY: clean

clean:
	rm -rf $(LIB_DIR)/* $(BIN_DIR)/*
