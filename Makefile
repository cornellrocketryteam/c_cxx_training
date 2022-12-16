#====================================================
# CRT Training Build Framework v1
#====================================================
# A build framework that supports single-file
# applications written in C

# Dependencies: GCC

#----------------------------------------------------
# Setup

### Set colors because I like pretty colors
BLUE  =\033[0;34m
PURPLE=\033[0;35m
GREEN =\033[0;32m
RED   =\033[0;31m
ORANGE=\033[0;33m
CYAN  =\033[0;36m
RESET =\033[0m

### Set compilation and linker flags
CFLAGS  := -Wall -O3
LDFLAGS := -lm

### Set commands correct based on operating system

ifdef OS # Only defined in Windows
    RM         := del /Q /S /F
	PATH_SLASH := \
    TARGETS    := $(basename $(notdir $(wildcard app\*.c)))
else # Linux
    RM         := rm -rf
	PATH_SLASH := /
    TARGETS    := $(basename $(notdir $(wildcard app/*.c)))
endif

#----------------------------------------------------
# Compilation

.PHONY: intro build

all: $(TARGETS)
	@echo "${GREEN} - All executables built in build directory${RESET}"

intro :
	@echo ""
	@echo "${CYAN}########################################${RESET}"
	@echo "${CYAN}## CRT Build System${RESET}"
	@echo "${CYAN}########################################${RESET}"
	@echo ""

build :
	@echo "${PURPLE} - Making Clean Build Directory${RESET}"
	@${RM} build
	@mkdir build

$(TARGETS) : intro build
	$(eval source_file=$(addprefix app$(PATH_SLASH), $(addsuffix .c,$@)))
	$(eval target_file=$(basename $(subst app,build,$(source_file))))
	$(eval eval_file=$(notdir $(target_file)))

	@echo "${ORANGE} - Building Executable: $(eval_file)${RESET}"
	@gcc $(CFLAGS) $(LDFLAGS) -o $(target_file) $(source_file)

ifneq "$(MAKECMDGOALS)" "all"
ifneq "$(MAKECMDGOALS)" ""
	@echo "${GREEN} - Executable built in build directory${RESET}"
endif
endif

