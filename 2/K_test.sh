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
  result=$(echo "3" | ./L.out) 
  # echo "$result" 
  assert "$result" "3"
  result=$(echo "0" | ./L.out) 
  # echo "$result" 
  assert "$result" "1"
fi 