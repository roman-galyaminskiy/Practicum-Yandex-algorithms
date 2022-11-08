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
  result=$(echo "10
put -34
put -23
get
size
get
size
get
get
put 80
size
" | ./J.out) 
  # echo "$result" 
  assert "$result" "-34
1
-23
0
error
error
1"
  result=$(echo "6
put -66
put 98
size
size
get
get
" | ./J.out) 
  # echo "$result" 
  assert "$result" "2
2
-66
98"
  result=$(echo "9
get
size
put 74
get
size
put 90
size
size
size
" | ./J.out) 
  # echo "$result" 
  assert "$result" "error
0
74
0
1
1
1"
fi 