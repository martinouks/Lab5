# Dossiers
SRC_DIR := src
INCLUDE_DIR := include
BIN_DIR := bin

# Nom de l'exécutable
TARGET := $(BIN_DIR)/main

CXX := g++
CXXFLAGS := -Wall -Wextra -w -std=c++11 -I$(INCLUDE_DIR)

# Fichiers source
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Règle par défaut : construire l'exécutable
all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean
