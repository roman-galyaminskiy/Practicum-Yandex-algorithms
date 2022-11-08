#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 J.cpp -o J.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "5
4 3 9 2 1" | ./J.out) 
  # echo "$result" 
  assert "$result" "3 4 2 1 9
3 2 1 4 9
2 1 3 4 9
1 2 3 4 9"
  
  result=$(echo "5
12 8 9 10 11" | ./J.out) 
  # echo "$result" 
  assert "$result" "8 9 10 11 12"

  result=$(echo "5
1 2 3 4 5" | ./J.out) 
  # echo "$result" 
  assert "$result" "1 2 3 4 5"
fi 