#!/bin/bash

if [[ "$1" == "create" ]]; then
    # join space-separated arguments with underscore
    FILENAME=$(echo "${*:2}" | tr ' ' '_')
    make create FILENAME="$FILENAME"
elif [[ "$1" == "build" ]]; then
    if [[ $# -ne 2 ]]; then
        echo "Usage: $0 build [filename.cpp]"
        exit 1
    fi
    make compile FILENAME="${2%.*}" && make run FILENAME="${2%.*}" && make clean
else
    echo "Usage: $0 [create|build] [filename (for create/build)]"
fi
