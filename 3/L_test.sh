#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 L.cpp -o L.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "6
1 2 4 4 6 8
3
" | ./L.out) 
  # echo "$result" 
  assert "$result" "3 5"


  echo "Compiled"     
  result=$(echo "6
1 2 4 4 4 4
3
" | ./L.out) 
  # echo "$result" 
  assert "$result" "3 -1"

  echo "Compiled"     
  result=$(echo "6
1 2 4 4 4 4
10
" | ./L.out) 
  # echo "$result" 
  assert "$result" "-1 -1"

  echo "Compiled"     
  result=$(echo "6
1 1 4 4 4 4
1
" | ./L.out) 
  # echo "$result" 
  assert "$result" "1 3"

  echo "Compiled"     
  result=$(echo "8
1 11 15 18 21 30 33 39
1
" | ./L.out) 
  # echo "$result" 
  assert "$result" "1 2"
fi 