#!/bin/bash

show_menu() {
    echo "Menu:"
    echo "1. Date"
    echo "2. List files"
    echo "3. Display directory"
    echo "4. Exit"
}

while true; do
    show_menu
    read -p "Enter choice: " choice

    case $choice in
        1)
            date
            ;;
        2)
            ls
            ;;
        3)
            pwd
            ;;
        4)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid"
            ;;
    esac
done
