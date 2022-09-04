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

g++ -Wall -g -std=c++17 Final_B.cpp -o Final_B.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"    
  result=$(echo "3
1231
2..2
2..2
2..2" | ./Final_B.out)
  # echo "$result"
  assert "$result" "2"  
  result=$(echo "4
1111
9999
1111
9911
" | ./Final_B.out)
  # echo "$result"
  assert "$result" "1" 
  result=$(echo "4
1111
1111
1111
1111
" | ./Final_B.out)
  # echo "$result"
  assert "$result" "0" 
  result=$(echo "4
....
....
....
....
" | ./Final_B.out)
  # echo "$result"
  assert "$result" "0" 
  result=$(echo "10
1111
1111
1123
4567
" | ./Final_B.out)
  # echo "$result"
  assert "$result" "7" 
  result=$(echo "10
....
.1..
....
....
" | ./Final_B.out)
  # echo "$result"
  assert "$result" "1" 
fi