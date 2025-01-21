#!/bin/bash

# Check if two arguments (file names) are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 file1.txt file2.txt"
    exit 1
fi

# Assign arguments to variables
file1="$1"
file2="$2"

# Check if both files exist
if [ ! -f "$file1" ]; then
    echo "Error: $file1 does not exist."
    exit 1
fi

if [ ! -f "$file2" ]; then
    echo "Error: $file2 does not exist."
    exit 1
fi

# Display lines that are in file1 but not in file2
grep -Fxv -f "$file2" "$file1"
