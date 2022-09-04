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

g++ -Wall -g -std=c++17 E.cpp -o E.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"    
  result=$(echo "19
i love segment tree" | ./E.out)
  echo "$result"
  assert "$result" "segment
7"
  result=$(echo "19
frog jumps from river" | ./E.out)
  # echo "$result"
  assert "$result" "jumps
5"
  result=$(echo "14
              " | ./E.out)
  # echo "$result"
  assert "$result" "
0"
  result=$(echo "13
dsfd sdf fd f" | ./E.out)
  # echo "$result"
  assert "$result" "dsfd
4"
  result=$(echo "15
 s sd dfg fdfg " | ./E.out)
  # echo "$result"
  assert "$result" "fdfg
4"
  result=$(echo "25
s s s s s sssssssssssssssss" | ./E.out)
  # echo "$result"
  assert "$result" "sssssssssssssss
15"
  result=$(echo "25
sssssssssssssss s s s s s" | ./E.out)
  # echo "$result"
  assert "$result" "sssssssssssssss
15"
fi
