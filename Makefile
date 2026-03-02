.PHONY: build

PRJ_SOURCE_CODE := src
PRJ_OUTPUT_DIR  := out
PRJ_OBJECTS_DIR := lib

### Derived Variables ###
CPP_SRC_FILES   := $(shell find -L $(PRJ_SOURCE_CODE) -type f -name "*.cpp"  -print)                # All C++ files
CPP_OBJECTS     := $(patsubst $(PRJ_SOURCE_CODE)/%.cpp,$(PRJ_OBJECTS_DIR)/%.o, $(CPP_SRC_FILES)) 

all: $(CPP_OBJECTS)
	@echo "Executing target '$@'"
	ar rvs lib/libpterminal.a $^
	@echo "Finished executing the target '$@'"

clean: 
	@echo "Executing target '$@'"
	rm -rf lib/*

# Generic C/C++ files build target (Object generation)
${PRJ_OBJECTS_DIR}/%.o : $(PRJ_SOURCE_CODE)/%.cpp
	@echo "Building '$<' for project '${PRJ_NAME}'"

	g++ -Iinclude/ -c $< -o $@

	@echo "Built '$<' for project '${PRJ_NAME}'"