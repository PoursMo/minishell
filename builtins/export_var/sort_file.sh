#!/bin/bash

# Check if a filename is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 input_file.txt"
    exit 1
fi

# Assign argument to a variable
input_file="$1"
output_file="sorted_$input_file"

# Check if the file exists
if [ ! -f "$input_file" ]; then
    echo "Error: File '$input_file' does not exist."
    exit 1
fi

# Sort the file alphabetically and save it
sort "$input_file" > "$output_file"

# Print success message
echo "Sorted file created: $output_file"
