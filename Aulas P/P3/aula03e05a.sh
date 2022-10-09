#!/bin/bash
# For all the files in a folder, show their properties
for f in $1/*; do
    if [ "$#" -ne 1 ]; then
        echo "Illegal number of parameters"
    else
        file "$f"
fi
done