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
	local description="$2"
	local output=$($PROGRAM "$input" | tr '\n' ' ')

	printf "${YELLOW}Test: ${GREEN}[$input] Case: [$description]\n${RESET}"
	printf "$output \n"
	printf "\n"
}

printf "${GREEN}==========ARGUMENTS TEST=============${RESET}\n"
run_test "" "empty string test"


printf "${GREEN}==========INVALID INPUT TEST=============${RESET}\n"
run_test "++123" "multiple +"
run_test "-01ab" "mixed input"
run_test "42ff" "multiple f"
run_test "42.42.42.42" "multiple dots"

printf "${GREEN}==========CHAR TEST=============${RESET}\n"
run_test "a" "normal displayable char"
run_test "Z" "normal displayable char"
run_test "33" "first displayable char <!>"
run_test "126" "last displayable char <~>"
run_test "127" "last nondisplayable char <DEL>"
run_test "32" "nondisplayable char <SPACE>"
run_test "0" "nondisplayable char <NULL>"
run_test "128" "impossible char <out of range>"
run_test "-1" "impossible char <out of range>"

printf "${GREEN}==========INT TEST=============${RESET}\n"
run_test "2147483647" "int max"
run_test "-2147483648" "int min"
run_test "2147483648" "int max + 1"
run_test "-2147483649" "int min - 1"

printf "${GREEN}==========FLOAT TEST=============${RESET}\n"
run_test "0f" "integer.0f display"
run_test "42f" "integer.0f display"
run_test "3.40282e+38" "Float MAX (scientific notation)"
run_test "-3.40282e+38" "Float MIN (scientific notation)"
run_test "3.40282347e+38f" "Float MAX with f suffix"
run_test "1e39" "Beyond float max, within double"
run_test "3.5e38" "Slightly above float max"

printf "${GREEN}==========DOUBLE TEST=============${RESET}\n"
run_test "1e400" "Huge value - exceeds double"
run_test "3.1234567890123456789" "loss precision"

printf "${GREEN}==========SPECIAL LITERAL TEST=============${RESET}\n"
run_test "inff" "with f"
run_test "+inff" "with f"
run_test "-inff" "with f"
run_test "inf" "without f"
run_test "+inf" "without f"
run_test "nan" "without f"
run_test "nanf" "with f"
