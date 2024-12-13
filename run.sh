#!/bin/bash
# Script to run the project

# Default arguments
INPUT_FILE="data/input.txt"
OUTPUT_FILE="results/output.txt"
ITERATIONS=10

# Parse command-line arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        --input) INPUT_FILE="$2"; shift ;;
        --output) OUTPUT_FILE="$2"; shift ;;
        --iterations) ITERATIONS="$2"; shift ;;
        *) echo "Unknown parameter: $1"; exit 1 ;;
    esac
    shift
done

# Run the executable with the specified arguments
./bin/project_executable --input "$INPUT_FILE" --output "$OUTPUT_FILE" --iterations "$ITERATIONS"
