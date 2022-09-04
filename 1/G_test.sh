#!/bin/bash

#assert(result, expected)
assert () {
  if [ "$1" == "$2" ] 
  then
    echo "SUCCESS"
  else
    echo "ERROR: $1 != $2"
  fi
}

g++ -Wall -g -std=c++17 G.cpp -o G.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"  
  result=$(echo "0" | ./G.out)
  # echo "$result"  
  assert "$result" "0"
  result=$(echo "1" | ./G.out)
  # echo "$result"  
  assert "$result" "1"
  result=$(echo "5" | ./G.out)
  # echo "$result"
  assert "$result" "101"
  result=$(echo "14" | ./G.out)
  # echo "$result"
  assert "$result" "1110"
  result=$(echo "255" | ./G.out)
  # echo "$result"
  assert "$result" "11111111"
  result=$(echo "256" | ./G.out)
  # echo "$result"
  assert "$result" "100000000"
fi
