#!/bin/bash

COMPILER="./build/Compiler"
BASE_DIR="${1:-tests}"
VALID_DIR="$BASE_DIR/valid_tests"
INVALID_DIR="$BASE_DIR/invalid_tests"

OUTPUT_BASE="output"
VALID_OUTPUT="$OUTPUT_BASE/valid"
INVALID_OUTPUT="$OUTPUT_BASE/invalid"

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# $1 - test dir
# $2 - output dir
# $3 - type: "valid" (stderr is empty) or "invalid" (stderr is not empty)
run_tests() {
    local test_dir="$1"
    local out_dir="$2"
    local test_type="$3"   # valid or invalid
    local type_name="$([ "$test_type" = "valid" ] && echo "Валидные" || echo "Невалидные")"
    
    mkdir -p "$out_dir"
    
    shopt -s nullglob
    local test_files=("$test_dir"/*.minijava)
    if [ ${#test_files[@]} -eq 0 ]; then
        echo "No .minijava in $test_dir"
        return 0
    fi
    
    local total=0 passed=0 failed=0
    
    for test_file in "${test_files[@]}"; do
        base_name=$(basename "$test_file" .minijava)
        output_file="$out_dir/$base_name.out"
        
        stderr_output=$("$COMPILER" "$test_file" "$output_file" 2>&1 >/dev/null)
        exit_code=$?
        
        total=$((total + 1))
        
        if [ "$test_type" = "valid" ]; then
            if [ -z "$stderr_output" ]; then
                echo -e "${GREEN}✅ $base_name: SUCCESS (stderr is empty, code $exit_code)${NC}"
                passed=$((passed + 1))
            else
                echo -e "${RED}❌ $base_name: FAILED (stderr is not empty)${NC}"
                echo "   First line stderr: $(echo "$stderr_output" | head -n1)"
                failed=$((failed + 1))
            fi
        else
            if [ -n "$stderr_output" ]; then
                echo -e "${GREEN}✅ $base_name: SUCCESS (stderr is not empty)${NC}"
                echo -e "$stderr_output"
                passed=$((passed + 1))
            else
                echo -e "${RED}❌ $base_name: FAILED (stderr is empty)${NC}"
                failed=$((failed + 1))
            fi
        fi
    done
    
    echo "RESULTS $type_name: PASSSED $passed, FAILED $failed (all $total)"
    echo "----------------------------------------"
    return $failed
}

if [ ! -f "$COMPILER" ]; then
    echo "$COMPILER did not found"
    exit 1
fi

mkdir -p "$OUTPUT_BASE"

run_tests "$VALID_DIR" "$VALID_OUTPUT" "valid"
valid_failures=$?

run_tests "$INVALID_DIR" "$INVALID_OUTPUT" "invalid"
invalid_failures=$?

echo "===== TESTS ====="
if [ $valid_failures -eq 0 ] && [ $invalid_failures -eq 0 ]; then
    echo -e "${GREEN}All tests PASSED.${NC}"
    exit 0
else
    echo -e "${RED}Some tests FAILED.${NC}"
    echo "FAILED valid tests: $valid_failures, in invalid: $invalid_failures"
    exit 1
fi
