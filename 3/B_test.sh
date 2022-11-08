#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 B.cpp -o B.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "23" | ./B.out) 
  # echo "$result" 
  assert "$result" "ad ae af bd be bf cd ce cf "
  result=$(echo "92" | ./B.out) 
  # echo "$result" 
  assert "$result" "wa wb wc xa xb xc ya yb yc za zb zc "
fi 