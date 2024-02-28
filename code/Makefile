CC = g++
FLAGS = -g -Wall -Werror -O2 -std=c++17
OBJ_DIR = obj-files
SOURCES = manager.cpp provider.cpp member.cpp service.cpp interface.cpp main.cpp
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
DEPS = manager.h provider.h member.h service.h interface.h

$(OBJ_DIR)/%.o: %.cpp $(DEPS) | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(FLAGS)

ChocAnTerminal: $(OBJS)
	$(CC) -o $@ $^ $(FLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) ChocAnTerminal


