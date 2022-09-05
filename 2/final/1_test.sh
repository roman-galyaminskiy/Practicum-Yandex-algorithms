#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 1.cpp -o 1.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "4
4
push_front 861
push_front -819
pop_back
pop_back
" | ./1.out) 
  # echo "$result" 
  assert "$result" "861
-819"
  result=$(echo "7
10
push_front -855
push_front 0
pop_back
pop_back
push_back 844
pop_back
push_back 823
" | ./1.out) 
  # echo "$result" 
  assert "$result" "-855
0
844"
  result=$(echo "6
6
push_front -201
push_back 959
push_back 102
push_front 20
pop_front
pop_back
" | ./1.out) 
  # echo "$result" 
  assert "$result" "20
102"
fi 