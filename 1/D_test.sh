#!/bin/bash

#!/bin/bash

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

g++ -Wall -g -std=c++17 D.cpp -o D.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"
  
  result=$(echo "5
1 2 5 4 8" | ./D.out)
  # echo "$result"
  assert "$result" "2"
  result=$(echo "7
-1 -10 -8 0 2 0 5" | ./D.out)
  # echo "$result"
  assert "$result" "3"
  result=$(echo "5
1 2 5 4 8" | ./D.out)
  # echo "$result"
  assert "$result" "2"
  result=$(echo "5
1 1 1 1 1" | ./D.out)
  assert "$result" "0"
  result=$(echo "5
2 1 1 1 2" | ./D.out)
  assert "$result" "2"
  result=$(echo "5
-273 273 -273 273 -273 " | ./D.out)
  assert "$result" "2"
  result=$(echo "1
-273" | ./D.out)
  assert "$result" "0"
  result=$(echo "2
2 1" | ./D.out)
  assert "$result" "1"
  result=$(echo "2
2 2" | ./D.out)
  assert "$result" "0"
  result=$(echo "2
1 2" | ./D.out)
  assert "$result" "1"
fi
