#!/bin/bash
#ordenacao selection-sort
#criar um txt à parte com numeros desordenados
#depois ler do ficheiro e colocar no array
# ciclo for a começar em 0 e a acabar em i<n -1 se calhar até consegue ir ao - 2
# criar outro for dentro do outro
#readarray -t array < ./numbers.txt #lê o ficheiro. É preciso colocar o caminho do ficheiro. O -t serve para strip off the newline characters.
# No entanto, por este método, não passamos o ficheiro como argumento
list=$(<"$1")
readarray -t arr <<< "$list"
echo elements: ${arr[@]} #elements from array
echo count ${#arr[@]} #number os elments from array
for ((i = 0; i < ${#arr[@]}-2; i++)); do
    small=${arr[$i]}
    index=$i
    for ((j=i+1;j<${#arr[@]};j++)); do
        if ((arr[j]<small)) 
        then
            small=${arr[$j]}
            index=$j
        fi
    done
temp=${arr[$i]}
arr[$i]=${arr[$index]}
arr[$index]=$temp
done
echo "Printing sorted array"
for ((i=0;i<${#arr[@]};i++)); do
    echo ${arr[$i]} #printing sorted array
done