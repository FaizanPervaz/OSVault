#!/bin/bash

calculate_bill() {
    if [ $units -le 300 ]; then
        cost=$((units * 2))
    elif [ $units -gt 300 ] && [ $units -le 500 ]; then
        cost=$((units * 5))
    elif [ $units -gt 500 ]; then
        cost=$((units * 7))
    fi
}

read -p "Enter units: " units

cost=0
calculate_bill

echo "Electricity Bill: Rs. $cost"
