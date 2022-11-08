#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 2.cpp -o 2.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "5
alla 4 100
gena 6 1000
gosha 2 90
rita 2 90
timofey 4 80
" | ./2.out) 
  # echo "$result" 
assert "$result" "gena
timofey
alla
gosha
rita"
result=$(echo "5
alla 0 0
gena 0 0
gosha 0 0
rita 0 0
timofey 0 0
" | ./2.out) 
  # echo "$result" 
assert "$result" "alla
gena
gosha
rita
timofey"
fi 