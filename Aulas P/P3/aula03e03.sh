#!/bin/bash
# This script checks the existence of a file
[[ $# = 1 ]] || { echo "Erro: Indique ficheiro" >&2; exit 1; }
echo "Checking..."
if [[ -a $1 ]] #verifica se existe
then
    echo "$1 existe"
    if [[ -f $1 ]] ; then #se é uma 'regula file'
        echo "É um ficheiro normal"
    elif [[ -d $1 ]]; then
        echo "$1 é um diretório"
    fi
    echo "Permissões:"
    if [[ -r $1 ]] || [[ -w $1 ]] || [[ -x $1 ]];
    then
        [[ -r $1 ]] && echo "leitura";
        [[ -w $1 ]] && echo "escrita";
        [[ -x $1 ]] && echo "execuçao";  # acabar em casa estas condicoes
    else echo "Nenhuma"
    fi
else
    echo "$1 não existe"

fi
echo "...done."