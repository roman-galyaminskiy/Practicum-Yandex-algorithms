#!/bin/bash

#assert(result, expected)
assert () {
  if [[ $1 -eq $2 ]] 
  then
    echo "SUCCESS"
  else
    echo "ERROR"
  fi
}

g++ -Wall -g -std=c++17 B.cpp -o B.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"

  result=$(echo 0 0 0 | ./B.out)
  assert result "WIN"
  result=$(echo 0 2 4 | ./B.out)
  assert result "WIN"
  result=$(echo -2 0 4 | ./B.out)
  assert result "WIN"
  result=$(echo 1 2 4 | ./B.out)
  assert result "FAIL"
  result=$(echo 1000000000 -1000000000 2 | ./B.out)
  assert result "WIN"
  result=$(echo 0 -1000000000 2 | ./B.out)
  assert result "WIN"
  result=$(echo 1 2 9 | ./B.out)
  assert result "FAIL"
  result=$(echo 1 3 9 | ./B.out)
  assert result "WIN"
  result=$(echo 999999995 -999999999 99999997 | ./B.out)
  assert result "WIN"
fi