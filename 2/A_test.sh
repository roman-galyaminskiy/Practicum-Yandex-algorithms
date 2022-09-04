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
  result=$(echo "4
3
1 2 3
0 2 6
7 4 1
2 7 0
" | ./A.out) 
  # echo "$result" 
  assert "$result" "1 0 7 2
2 2 4 7
3 6 1 0"
  result=$(echo "9
5
-7 -1 0 -4 -9
5 -1 2 2 9
3 1 -8 -1 -7
9 0 8 -8 -1
2 4 5 2 8
-7 10 0 -4 -8
-3 10 -7 10 3
1 6 -7 -5 9
-1 9 9 1 9
" | ./A.out) 
  # echo "$result" 
  assert "$result" "-7 5 3 9 2 -7 -3 1 -1
-1 -1 1 0 4 10 10 6 9
0 2 -8 8 5 0 -7 -7 9
-4 2 -1 -8 2 -4 10 -5 1
-9 9 -7 -1 8 -8 3 9 9"
  result=$(echo "1
1
1
" | ./A.out) 
  # echo "$result" 
  assert "$result" "1"
fi 