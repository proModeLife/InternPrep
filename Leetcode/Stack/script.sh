#!/bin/bash

if [[ "$1" == "create" ]]; then
    # join space-separated arguments with underscore
    FILENAME=$(echo "${*:2}" | tr ' ' '_')

    # append .py extension to filename
    FILENAME="$FILENAME.cpp"

    # create new Python file
    touch "$FILENAME"

    nvim "$FILENAME"
fi
