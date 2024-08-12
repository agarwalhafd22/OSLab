#!/bin/bash

# Function to display usage

usage() {
    echo "Usage: $0 string1 string2 [string3 ...]"
    exit 1
}

# Function to sort strings
sort_strings() {
    local strings=("$@")
    IFS=$'\n' sorted=($(sort <<<"${strings[*]}"))
    unset IFS
    echo "${sorted[@]}"
}

# Check if at least one argument is provided
if [ "$#" -lt 1 ]; then
    usage
fi

# Call the sort_strings function with all command-line arguments
sorted_strings=$(sort_strings "$@")

# Output the sorted strings
echo "Sorted strings:"
echo "$sorted_strings"
