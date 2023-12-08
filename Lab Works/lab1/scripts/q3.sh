#!/bin/bash

read -p "Enter a number: " number

if [[ $number -lt 0 ]]; then
    echo "No Factorial Exists"
elif [[ $number -eq 0 || $number -eq 1 ]]; then
    echo "Factorial of $number is 1."
else
    fact=1

    for ((i=1; i<=number; i++)); do
        fact=$((fact * i))
    done
    
    echo "Factorial of $number is $fact ."
fi

