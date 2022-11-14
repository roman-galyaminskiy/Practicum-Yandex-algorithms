#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 A.cpp -o A.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "123
100003
a" | ./A.out) 
  # echo "$result" 
  assert "$result" "97"
  result=$(echo "123
100003
hash" | ./A.out) 
  # echo "$result" 
  assert "$result" "6080"
  result=$(echo "123
100003
HaSH" | ./A.out) 
  # echo "$result" 
  assert "$result" "56156"
  result=$(echo "123
100003" | ./A.out) 
  # echo "$result" 
  assert "$result" "0"
fi 