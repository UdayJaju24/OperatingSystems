#!/bin/bash

# Get user input for the string
echo "Enter the string: "
read string

# Get user input for the sub-string
echo "Enter the sub-string to search for: "
read substring

# Use grep to search for the sub-string in the string and count the occurrences
count=$(echo "$string" | grep -o "$substring" | wc -l)

# Output the result
echo "The sub-string '$substring' occurs $count times in the string '$string'"
