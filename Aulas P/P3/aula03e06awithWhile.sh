#!/bin/bash
# Wait for a host, given as argument, to come back online.
host=$1
while !(ping -c 1 "$host" >& /dev/null ); do #while is like a negation of until
echo "$host is still unavailable."
sleep 5
done;
echo -e "$host is available again.\a"