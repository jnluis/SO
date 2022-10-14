#!/bin/bash
function compare_numbers(){
    if [[ $1 -gt $2 ]]; then
        return 0;
    elif [[ $1 -lt $2 ]]; then
        return 1;
    else 
        return 2;
    fi
}

echo "Escreve dois números"
read num1
read num2
compare_numbers $num1 $num2

case $? in
0)
echo "O primeiro número é maior que o segundo"
;;
1)
echo "O segundo número é maior que o primeiro"
;;
2)
echo "Os números são iguais"
;;
esac