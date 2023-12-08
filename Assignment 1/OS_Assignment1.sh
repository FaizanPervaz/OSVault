#20I-0565 Faizan
#!/bin/bash

function display_help {
    echo "  -uc  Create a new user with administrator privileges"
    echo "  -ld  List installed applications"
    echo "  -ins Install Dropbox"
    echo "  -ipcon Set Network Settings"
    echo "  -help  Display this help message"
}

function create_user {
    read -p "Enter user: " username
    read -s -p "Enter password: " password
    echo
    sudo adduser $username
    sudo usermod -aG sudo $username
    echo "New User is created."
}

function list_installed_apps {
    dpkg --get-selections 
    echo "Installed applications are listed."
}

function install_dropbox {
    sudo apt-get update
    sudo apt-get install -y dropbox
    echo "Dropbox is installed."
}

function set_ip_config {
    read -p "Enter IP : " ipaddress
    read -p "Enter mask: " mask
    read -p "Enter gateway : " gateway
    read -p "Enter DNS: " dns

    
    sudo ip addr add $ipaddress/$mask dev ens33
    sudo ip route add default via $gateway
    echo "nameserver $dns" | sudo tee /etc/resolv.conf > /dev/null
    echo "IP address, mask, gateway, and DNS are set."   
}

# Main script
echo "21-0565-Faizan Pervaz"  

while [ "$1" != "" ]; do
    case $1 in
        -uc)
            create_user
            ;;
        -ld)
            list_installed_apps
            ;;
        -ins)
            install_dropbox
            ;;
        -ipcon)
            set_ip_config
            ;;
        -help)
            display_help
            ;;
        *)
            echo "Invalid command"
            display_help
    esac
    shift
done
