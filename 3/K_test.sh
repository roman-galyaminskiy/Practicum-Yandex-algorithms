#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 K.cpp -o K.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"; ./K.out; 
fi 