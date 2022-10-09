#!/bin/bash
# select structure to create menus
# exercise 'c done here too
select arg in $@; do
if [[ $arg == "" ]]; then
echo "You picked a none valid choice"
break
else
echo "You picked $arg ($REPLY)."
fi
done