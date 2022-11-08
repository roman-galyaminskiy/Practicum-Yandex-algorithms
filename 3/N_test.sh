#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 N.cpp -o N.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "4
7 8
7 8
2 3
6 10
" | ./N.out) 
  # echo "$result" 
  assert "$result" "2 3
6 10"

result=$(echo "4
2 3
5 6
3 4
3 4
" | ./N.out) 
  # echo "$result" 
  assert "$result" "2 4
5 6"

result=$(echo "6
1 3
3 5
4 6
5 6
2 4
7 10
" | ./N.out) 
  # echo "$result" 
  assert "$result" "1 6
7 10"

result=$(echo "3
48 76
0 8
40 93
" | ./N.out) 
  # echo "$result" 
  assert "$result" "0 8
40 93"

fi 