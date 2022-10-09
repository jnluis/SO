#!/bin/bash
# Calculate the sum of a series of numbers.
SCORE="0"
SUM="0"
AVG="0"
COUNTER="0"
while true; do
echo -n "Enter your score [0-10] ('q' to quit) ('r' to restart): "
read SCORE;
if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
echo "Try again: "
elif [[ "$SCORE" == "q" ]]; then
echo "Sum: $SUM."
AVG=$((SUM / COUNTER))
echo "Average: $AVG."
break
elif [[ "$SCORE" == "r" ]]; then
if [[ $COUNTER -eq 0 ]]; then
echo "You had already restarted variables"
else
SCORE="0"
SUM="0"
AVG="0"
COUNTER="0"
fi
else
SUM=$((SUM + SCORE))
COUNTER=$((COUNTER + 1))
fi
done
echo "Exiting."