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

g++ -Wall -g -std=c++17 F.cpp -o F.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"    
  result=$(echo "A man, a plan, a canal: Panama" | ./F.out)
  # echo "$result"
  assert "$result" "True"
  result=$(echo "" | ./F.out)
  # echo "$result"
  assert "$result" "False"
  result=$(echo "a" | ./F.out)
  # echo "$result"
  assert "$result" "True"
  result=$(echo "zo" | ./F.out)
  # echo "$result"
  assert "$result" "False"
  result=$(echo "zz" | ./F.out)
  # echo "$result"
  assert "$result" "True"
  result=$(echo "saippuakivikauppias" | ./F.out)
  # echo "$result"
  assert "$result" "True"
  result=$(echo "22022022" | ./F.out)
  # echo "$result"
  assert "$result" "True"
  result=$(echo "TopOt" | ./F.out)
  # echo "$result"
  assert "$result" "True"
  result=$(echo "Topоt" | ./F.out)
  # echo "$result"
  assert "$result" "False"
  result=$(echo "TopOt " | ./F.out)
  # echo "$result"
  assert "$result" "True"
  result=$(echo "12 21 %@#%%&*% " | ./F.out)
  # echo "$result"
  assert "$result" "True"
fi
