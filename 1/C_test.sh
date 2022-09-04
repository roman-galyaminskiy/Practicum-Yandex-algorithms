
#!/bin/bash

#assert(result, expected)
assert () {
  if [ "$1" == "$2" ] 
  then
    echo "SUCCESS"
  else
    echo "ERROR"
  fi
}

g++ -Wall -g -std=c++17 C.cpp -o C.out

if [[ $? -eq 0 ]]
then
  echo "Compiled"
  
  result=$(echo "4
  3
  1 2 3
  0 2 6
  7 4 1
  2 7 0
  3
  0" | ./C.out)
  assert "$result" "7 7"
  result=$(echo "4
  3
  1 2 3
  0 2 6
  7 4 1
  2 7 0
  0
  0" | ./C.out)
  assert "$result" "0 2"
  result=$(echo "1
  1
  1
  0
  0" | ./C.out)
  assert "$result" ""
  result=$(echo "2
  2
  1 2
  -2 -1
  0
  0" | ./C.out)
  assert "$result" "-2 2"
  result=$(echo "2
  2
  1 2
  -2 -1
  1
  0" | ./C.out)
  assert "$result" "-1 1"
  result=$(echo "2
  2
  1 2
  -2 -1
  0
  1" | ./C.out)
  assert "$result" "-1 1"
  result=$(echo "2
  2
  1 2
  -2 -1
  1
  1" | ./C.out)
  assert "$result" "-2 2"
fi