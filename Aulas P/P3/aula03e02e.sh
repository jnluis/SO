#!/bin/bash
# Conditional block if
if [ "$1" -ne 1 ]; then
    echo "Illegal number of parameters"
else
    if [[ $1 -gt 5 && $1 -lt 10 ]] ; then
        echo "O argumento é maior que 5 e menor que 10"
    else
        echo "nao é"
    fi
fi

