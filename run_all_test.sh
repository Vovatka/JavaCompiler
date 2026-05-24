#!/bin/bash

# Путь к компилятору
COMPILER="./build/Compiler"

# Базовая директория с тестами (можно переопределить аргументом)
BASE_DIR="${1:-tests}"

# Директории с тестами
VALID_DIR="$BASE_DIR/valid_tests"
INVALID_DIR="$BASE_DIR/invalid_tests"

# Директории для выходных файлов
OUTPUT_BASE="output"
VALID_OUTPUT="$OUTPUT_BASE/valid"
INVALID_OUTPUT="$OUTPUT_BASE/invalid"

# Цвета для вывода
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Функция запуска тестов из заданной директории
# $1 - директория с тестами
# $2 - выходная директория
# $3 - тип ожидаемого результата: "success" (код 0) или "failure" (код !=0)
# $4 - название типа тестов для вывода
run_tests() {
    local test_dir="$1"
    local out_dir="$2"
    local expected_type="$3"
    local test_type="$4"
    
    if [ ! -d "$test_dir" ]; then
        echo "Предупреждение: директория $test_dir не найдена, пропускаем $test_type тесты"
        return 0
    fi
    
    mkdir -p "$out_dir"
    
    shopt -s nullglob
    local test_files=("$test_dir"/*.minijava)
    
    if [ ${#test_files[@]} -eq 0 ]; then
        echo "Не найдено .minijava файлов в $test_dir"
        return 0
    fi
    
    echo "===== $test_type тесты (ожидается ${expected_type}) ====="
    local total=0 passed=0 failed=0
    
    for test_file in "${test_files[@]}"; do
        base_name=$(basename "$test_file" .minijava)
        output_file="$out_dir/$base_name.out"
        
        "$COMPILER" "$test_file" "$output_file"
        actual_exit=$?
        
        total=$((total + 1))
        
        # Определяем, успешен ли запуск согласно ожиданиям
        if [ "$expected_type" = "success" ]; then
            if [ $actual_exit -eq 0 ]; then
                echo -e "${GREEN}✅ [$test_type] $base_name: успех (код $actual_exit)${NC}"
                passed=$((passed + 1))
            else
                echo -e "${RED}❌ [$test_type] $base_name: провал (ожидался 0, получен $actual_exit)${NC}"
                failed=$((failed + 1))
            fi
        else  # ожидается failure (ненулевой код)
            if [ $actual_exit -ne 0 ]; then
                echo -e "${GREEN}✅ [$test_type] $base_name: успех (код $actual_exit, ошибка как и ожидалось)${NC}"
                passed=$((passed + 1))
            else
                echo -e "${RED}❌ [$test_type] $base_name: провал (ожидалась ошибка, но компилятор вернул 0)${NC}"
                failed=$((failed + 1))
            fi
        fi
    done
    
    echo "Результаты $test_type: пройдено $passed, не пройдено $failed (всего $total)"
    echo "----------------------------------------"
    return $failed
}

# Проверка наличия компилятора
if [ ! -f "$COMPILER" ]; then
    echo "Ошибка: компилятор не найден по пути $COMPILER"
    exit 1
fi

mkdir -p "$OUTPUT_BASE"

# Запуск валидных тестов (ожидаем код 0)
run_tests "$VALID_DIR" "$VALID_OUTPUT" "success" "Валидные"
valid_failures=$?

# Запуск невалидных тестов (ожидаем ненулевой код)
run_tests "$INVALID_DIR" "$INVALID_OUTPUT" "failure" "Невалидные"
invalid_failures=$?

# Итог
echo "===== Сводка ====="
if [ $valid_failures -eq 0 ] && [ $invalid_failures -eq 0 ]; then
    echo -e "${GREEN}Все тесты пройдены успешно.${NC}"
    exit 0
else
    echo -e "${RED}Некоторые тесты не оправдали ожиданий.${NC}"
    echo "Провалов в валидных: $valid_failures, в невалидных: $invalid_failures"
    exit 1
fi
