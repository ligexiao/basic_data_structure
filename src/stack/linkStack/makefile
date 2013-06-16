WORK_DIR := $(shell cd ../../../; pwd)

BIN_DIR = ${WORK_DIR}/bin/linkStack

SRC = ${WORK_DIR}/src
STACK_SRC = $(SRC)/stack/linkStack

OBJECTS+=test.o
OBJECTS+=linkStack.o

INCLUDE= -I$(WORK_DIR)/include/stack/linkStack
ISDELVD_O = $(addprefix $(BIN_DIR)/, $(OBJECTS))

CPP = g++
CFLAGS= -c $(INCLUDE)

all    : mkbin $(ISDELVD_O) $(BIN_DIR)/linkStack
 

$(BIN_DIR)/linkStack: $(ISDELVD_O)
	$(CPP)  -o  $(BIN_DIR)/linkStack $(ISDELVD_O)

$(BIN_DIR)/%.o: $(STACK_SRC)/%.cpp
	$(CPP) $(CFLAGS) -o	$@ $<
mkbin:
	-rm -rf $(BIN_DIR)
	-mkdir -p $(BIN_DIR)
clean:
	-rm -rf $(BIN_DIR)/*.o
