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

g++ -Wall -g -std=c++17 H.cpp -o H.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"  
  result=$(echo "1010
1011" | ./H.out)
  # echo "$result"  
  assert "$result" "10101"
  result=$(echo "1
1" | ./H.out)
  # echo "$result"  
  assert "$result" "10"
  result=$(echo "0
0" | ./H.out)
  # echo "$result"  
  assert "$result" "0"
  result=$(echo "0
1" | ./H.out)
  # echo "$result"  
  assert "$result" "1"
  result=$(echo "1
0" | ./H.out)
  # echo "$result"  
  assert "$result" "1"
  result=$(echo "101
1" | ./H.out)
  # echo "$result"  
  assert "$result" "110"
  result=$(echo "1100
101111" | ./H.out)
  # echo "$result"  
  assert "$result" "111011"
  result=$(echo "1101110101000001000100101000100101100010101100001111001101011111111
10101001011000011110101111101000101111110111110011000101111000011000101001000010101000
" | ./H.out)
  # echo "$result"  
  assert "$result" "10101001011000100000011110010000111000011100110111110010001101111010100010101110100111"
fi