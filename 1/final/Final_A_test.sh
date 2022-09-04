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

g++ -Wall -g -std=c++17 Final_A.cpp -o Final_A.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"    
  result=$(echo "5
0 1 4 9 0" | ./Final_A.out)
  # echo "$result"
  assert "$result" "0 1 2 1 0"
  result=$(echo "6
0 7 9 4 8 20" | ./Final_A.out)
  # echo "$result"
  assert "$result" "0 1 2 3 4 5"
  result=$(echo "6
7 9 4 8 20 0" | ./Final_A.out)
  # echo "$result"
  assert "$result" "5 4 3 2 1 0"
  result=$(echo "6
7 9 0 4 8 20" | ./Final_A.out)
  # echo "$result"
  assert "$result" "2 1 0 1 2 3"
  result=$(echo "6
0 1 0 2 3 4" | ./Final_A.out)
  # echo "$result"
  assert "$result" "0 1 0 1 2 3"
  result=$(echo "6
0 1 2 3 4 0" | ./Final_A.out)
  # echo "$result"
  assert "$result" "0 1 2 2 1 0"
  result=$(echo "6
0 0 0 0 0 0" | ./Final_A.out)
  # echo "$result"
  assert "$result" "0 0 0 0 0 0"
  result=$(echo "5
0 1 4 9 0" | ./Final_A.out)
  # echo "$result"
  assert "$result" "0 1 2 1 0"
  result=$(echo "4
0 1 1 0" | ./Final_A.out)
  # echo "$result"
  assert "$result" "0 1 1 0"
  result=$(echo "9
98 0 10 77 0 59 28 0 94" | ./Final_A.out)
  # echo "$result"
  assert "$result" "1 0 1 1 0 1 1 0 1"
  result=$(echo "20
3 15 0 22 31 32 0 41 0 0 50 0 0 66 0 76 77 82 0 89" | ./Final_A.out)
  # echo "$result"
  assert "$result" "2 1 0 1 2 1 0 1 0 0 1 0 0 1 0 1 2 1 0 1"
fi