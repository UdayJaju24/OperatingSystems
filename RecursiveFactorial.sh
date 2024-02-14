# Function to find the factorial of a number using recurrence method
function factorial_recurrence() {
    if [ $1 -eq 0 ]; then
        echo 1
    else
        local prev=$(factorial_recurrence $(($1 - 1)))
        echo $(($1 * $prev))
    fi
}

# Get the number from the user
read -p "Enter a number to find its factorial: " num

# Find the factorial using recurrence method
fact_rec=$(factorial_recurrence $num)

# Print the results
echo "Factorial of $num using recurrence method: $fact_rec"

