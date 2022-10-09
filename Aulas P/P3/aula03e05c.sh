#!/bin/bash
# For all the files in a folder, show their properties
for f in $1/*.txt; do
    if [ "$#" -ne 1 ]; then
        echo "Illegal number of parameters" else
do mv -- "$f" "new_$f";
        echo "Finished"
fi
done;
# not working as intended
# correct code:
#for file in *.txt; do mv "$file" "yourPrefix$file"; done;