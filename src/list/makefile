WORK_DIR := $(shell cd ../../; pwd)

BIN_DIR = ${WORK_DIR}/bin/list

SRC = ${WORK_DIR}/src
LIST_SRC = $(SRC)/list

OBJECTS+=linkList.o
OBJECTS+=test.o

INCLUDE= -I$(WORK_DIR)/include/list
ISDELVD_O = $(addprefix $(BIN_DIR)/, $(OBJECTS))

#CC = g++
CPP = g++
CFLAGS= -c $(INCLUDE)

all    : mkbin $(ISDELVD_O) $(BIN_DIR)/list
 
$(BIN_DIR)/list: $(ISDELVD_O)
	$(CPP)	-o	$(BIN_DIR)/list $(ISDELVD_O)

$(BIN_DIR)/%.o:	$(LIST_SRC)/%.cpp
	$(CPP)	$(CFLAGS)	-o	$@ $<

mkbin:
	-rm -rf $(BIN_DIR)
	-mkdir -p $(BIN_DIR)
clean:
	-rm -rf $(BIN_DIR)/*.o
