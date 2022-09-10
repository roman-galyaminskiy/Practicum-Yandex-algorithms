#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 2.cpp -o 2.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "2 1 + 3 *" | ./2.out) 
  # echo "$result" 
  assert "$result" "9"
  result=$(echo "7 2 + 4 * 2 +" | ./2.out) 
  # echo "$result" 
  assert "$result" "38"
  result=$(echo "-1 -3 +" | ./2.out) 
  # echo "$result" 
  assert "$result" "-4"
  result=$(echo "-1 -3 -" | ./2.out) 
  # echo "$result" 
  assert "$result" "2"
  result=$(echo "-1 -3 - 5 +" | ./2.out) 
  # echo "$result" 
  assert "$result" "7"
  result=$(echo "-1 3 /" | ./2.out) 
  # echo "$result" 
  assert "$result" "-1"
  result=$(echo "-1 3 /" | ./2.out) 
  # echo "$result" 
  assert "$result" "-1"
  result=$(echo "-5 3 /" | ./2.out) 
  # echo "$result" 
  assert "$result" "-2"
  result=$(echo "-555 333 /" | ./2.out) 
  # echo "$result" 
  assert "$result" "-2"
  result=$(echo "-555 333 *" | ./2.out) 
  # echo "$result" 
  assert "$result" "-184815"
  result=$(echo "2 5 - 4 /" | ./2.out) 
  # echo "$result" 
  assert "$result" "-1"
  result=$(echo "-4 3 * 3 -5 - / -7 -1 - -8 -10 - + *" | ./2.out)
  # echo "$result" 
  assert "$result" "8"
  result=$(echo "4 2 * 4 / 25 * 2 - 12 / 500 2 * + 2 / -999 + 71 + -1 * 2 / 1000 + 6 * 8065 - 787 + 66 * 456 - 45 * 10 / 3000 +" | ./2.out)
  # echo "$result" 
  assert "$result" "948"
  result=$(echo "4 2 * 4 / 25 * 2 - 12 / 500 2 * + 2 / -999 + 71 + -1 * 2 / 1000 + 6 * 8065 - 787 + 66 * 456 - 45 * 10 /" | ./2.out)
  # echo "$result" 
  assert "$result" "-2052"
fi 