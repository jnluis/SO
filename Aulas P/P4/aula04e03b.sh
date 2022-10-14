#!/bin/bash
lista=( $(seq 2 3 15) )
echo vals ${lista[@]} #values from lista array
echo count ${#lista[@]}#number os elments from lista array
echo index ${!lista[@]}#indexes from lista array
for ((i = 0; i < ${#lista[@]}; i++)); do
lista[i]=$((${lista[i]}+1)) #increment lista array by one
echo "$i: ${lista[i]}"
done
unset lista[1]
unset lista[3] #tira os valores de indice e valor da lista
echo count ${#lista[@]} #nova lista
for i in ${!lista[@]}; do
echo "$i: ${lista[i]}"#os elementos que ficam não deiminuem o index, ficam com o mesmo
done