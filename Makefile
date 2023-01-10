#====================================================
# CRT Training Build Framework v3
#====================================================
# A build framework that supports multi-file
# applications written in C++

# Dependencies: GCC

#----------------------------------------------------
# Setup

### Set compilation and linker flags
CFLAGS  := -Wall -O3
LDFLAGS := -lm

### Set commands correct based on operating system

ifeq ($(OS),Windows_NT)  # Windows
    RM_BUILD   := if exist build ( rmdir /s /q build )

intro :
	@echo ########################################
	@echo ## CRT Build System
	@echo ########################################

endif

ifneq ($(OS),Windows_NT) # Linux
    RM_BUILD   := rm -rf build

intro :
	@echo "########################################"
	@echo "## CRT Build System"
	@echo "########################################"

endif

TARGETS := $(basename $(notdir $(wildcard app/*.cc)))
SOURCES := $(subst .cc,.o,$(subst src,build,$(wildcard src/*.cc)))

#----------------------------------------------------
# Compilation

.PHONY: intro build

all: $(TARGETS)
	@echo  - All executables built in build directory

build :
	@echo  - Making Clean Build Directory
	@${RM_BUILD}
	@mkdir build

test:
	echo $(SOURCES)

$(SOURCES) :
	$(eval source_file=$(subst .o,.cc,$(subst build,src,$@)))
	$(eval file_name=$(notdir $@))

	@echo  - Building Object File: $(file_name)
	@g++ $(CFLAGS) -c -Isrc -o $@ $(source_file)

$(TARGETS) : intro build $(SOURCES)
	$(eval source_file=$(addprefix app/, $(addsuffix .cc,$@)))
	$(eval target_file=$(basename $(subst app,build,$(source_file))))
	$(eval eval_file=$(notdir $(target_file)))

	@echo  - Building Executable: $(eval_file)
	@g++ $(CFLAGS) $(LDFLAGS) -Isrc -o $(target_file) $(source_file) $(SOURCES)

ifneq "$(MAKECMDGOALS)" "all"
ifneq "$(MAKECMDGOALS)" ""
	@echo  - Executable built in build directory
endif
endif
