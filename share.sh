#!/bin/bash

find . -type f \( -name "*.cc" -o -name "*.hh" -o -name "Makefile" -o -name "*.conf" \) \
	     -exec sh -c 'echo "File: {}" && nl {}' \; | \
	     xclip -selection c
