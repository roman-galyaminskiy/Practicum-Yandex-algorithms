#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 G.cpp -o G.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "10
pop
pop
push 4
push -5
push 7
pop
pop
get_max
pop
get_max" | ./G.out) 
  # echo "$result" 
  assert "$result" "error
error
4
None"
  result=$(echo "10
get_max
push -6
pop
pop
get_max
push 2
get_max
pop
push -2
push -6" | ./G.out) 
  # echo "$result" 
  assert "$result" "None
error
None
2"
  result=$(echo "8
get_max
push 7
pop
push -2
push -1
pop
get_max
get_max" | ./G.out) 
  # echo "$result" 
  assert "$result" "None
-2
-2"
  result=$(echo "7
get_max
pop
pop
pop
push 10
get_max
push -9" | ./G.out) 
  # echo "$result" 
  assert "$result" "None
error
error
error
10"
fi 