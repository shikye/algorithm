CC=gcc
ROOT_DIR=$(shell pwd)
SRC=$(wildcard $(ROOT_DIR)/src/*.c)
SRC_PATH=$(ROOT_DIR)/src
OBJ_file=$(patsubst %.c,%.o, $(notdir $(SRC)))
OBJ=$(addprefix $(OBJS_DIR)/,$(OBJ_file))
BIN=a.out
OBJS_DIR=$(ROOT_DIR)/debug/obj
BIN_DIR=$(ROOT_DIR)/debug/bin
INC=$(addprefix -I , $(ROOT_DIR)/include)


all: $(OBJ_file) main

$(OBJ_file):%.o:$(SRC_PATH)/%.c
	$(CC) -c -g $< $(INC) -o $(OBJS_DIR)/$@

main:$(OBJ)
	$(CC) $^ -g -o $(ROOT_DIR)/a.out





