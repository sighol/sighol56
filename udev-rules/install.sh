#!/bin/bash

# Check if the script is run as root
if [ "$EUID" -ne 0 ]; then
  echo "This script must be run as root or with sudo."
  exit 1
fi

# Install the udev rule
install -m644 99-auto-mount-rp2040.rules /etc/udev/rules.d/99-auto-mount-rp2040.rules

# Reload udev
udevadm control --reload-rules && udevadm trigger
