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
  result=$(echo "{[()]}" | ./H.out) 
  # echo "$result" 
  assert "$result" "True"
  result=$(echo "()" | ./H.out) 
  # echo "$result" 
  assert "$result" "True"
  result=$(echo "(((" | ./H.out) 
  # echo "$result" 
  assert "$result" "False"
  result=$(echo "(" | ./H.out) 
  # echo "$result" 
  assert "$result" "False"
  result=$(echo ")))" | ./H.out) 
  # echo "$result" 
  assert "$result" "False"
  result=$(echo "()[]{}" | ./H.out) 
  # echo "$result" 
  assert "$result" "True"
fi 