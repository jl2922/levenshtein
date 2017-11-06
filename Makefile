CXX := g++
CXX_WARNING_OPTIONS := -Wall -Wextra -Wno-expansion-to-defined -Wno-int-in-bool-context
CXXFLAGS := -std=c++17 -O3 $(CXX_WARNING_OPTIONS)
SRC_DIR := src
OBJ_DIR := build
EXE := lev.x

# Load Makefile.config if exists.
LOCAL_MAKEFILE := local.mk
ifneq ($(wildcard $(LOCAL_MAKEFILE)),)
	include $(LOCAL_MAKEFILE)
endif

SRCS := $(shell find $(SRC_DIR) ! -name "main.cc" -name "*.cc")
OBJS := $(SRCS:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
MAIN := $(SRC_DIR)/main.cc
HEADERS := $(shell find $(SRC_DIR) -name "*.h")

.PHONY: all clean

all: $(EXE)

clean:
	rm -rf $(OBJ_DIR)
	rm -f ./$(EXE)

$(EXE): $(OBJS) $(MAIN) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(MAIN) $(OBJS) -o $(EXE)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(HEADERS)
	mkdir -p $(@D) && $(CXX) $(CXXFLAGS) -c $< -o $@