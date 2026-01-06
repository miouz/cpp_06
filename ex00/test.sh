#!/bin/bash

#color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'
RESET='\033[0m'

PROGRAM="./convert"

if [ ! -f $PROGRAM ]; then
	printf "${RED} Error: $PROGRAM do not exit\n${RESET}"
	exit 1
fi 

run_test(){
	local input="$1"

	printf "${YELLOW}Running test ${GREEN}[$input] \n${RESET}"
	printf "${YELLOW}Result: \n${RESET}"
	$PROGRAM "$input"
	printf "\n"
}

run_test "a"
