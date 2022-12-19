#====================================================
# CRT Training Build Framework v1
#====================================================
# A build framework that supports single-file
# applications written in C

# Dependencies: GCC

#----------------------------------------------------
# Setup

### Set compilation and linker flags
CFLAGS  := -Wall -O3
LDFLAGS := -lm

### Set commands correct based on operating system

ifeq ($(OS),Windows_NT)  # Windows
    RM_BUILD   := if exist build ( rmdir /s /q build )

endif

ifneq ($(OS),Windows_NT) # Linux
    RM_BUILD   := rm -rf build

endif

TARGETS := $(basename $(notdir $(wildcard app/*.c)))

#----------------------------------------------------
# Compilation

.PHONY: intro build

all: $(TARGETS)
	@echo  - All executables built in build directory

intro :
	@echo ########################################
	@echo ## CRT Build System
	@echo ########################################

build :
	@echo  - Making Clean Build Directory
	@${RM_BUILD}
	@mkdir build

$(TARGETS) : intro build
	$(eval source_file=$(addprefix app/, $(addsuffix .c,$@)))
	$(eval target_file=$(basename $(subst app,build,$(source_file))))
	$(eval eval_file=$(notdir $(target_file)))

	@echo  - Building Executable: $(eval_file)
	@gcc $(CFLAGS) $(LDFLAGS) -o $(target_file) $(source_file)

ifneq "$(MAKECMDGOALS)" "all"
ifneq "$(MAKECMDGOALS)" ""
	@echo  - Executable built in build directory
endif
endif

