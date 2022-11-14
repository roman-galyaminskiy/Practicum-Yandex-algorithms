#assert(result, expected) 
assert () { 
  if [ "$1" == "$2" ]  
  then 
    echo "SUCCESS" 
  else 
    echo "ERROR: $1 != $2" 
  fi 
} 
 
g++ -Wall -g -std=c++17 D.cpp -o D.out
 
if [[ $? -eq 0 ]] 
then 
  echo "Compiled"     
  result=$(echo "8
вышивание крестиком
рисование мелками на парте
настольный керлинг
настольный керлинг
кухня африканского племени ужасмай
тяжелая атлетика
таракановедение
таракановедение
" | ./D.out) 
  # echo "$result" 
  assert "$result" "вышивание крестиком
рисование мелками на парте
настольный керлинг
кухня африканского племени ужасмай
тяжелая атлетика
таракановедение"
# result=$(echo "62
# evildnk
# zdfjebxlwg
# prm
# bnfvwdy
# cxiwypbt
# fkxgw
# ar
# vwanbwqnsg
# eskqrvv
# qulvigaqt
# akvapab
# eulxoc
# fj
# ckttk
# qemzm
# xvzcy
# erczzncx
# smxvabamiu
# nupywmu
# csu
# runia
# maph
# pinrap
# etpqje
# hxtemhk
# exzheotlwv
# kthc
# m
# tzojmvvn
# jhddyzqh
# xbfsmklmkb
# dmwulqq
# dhcfkzwsy
# p
# gqdzkkpbk
# ekdivnm
# inyacaron
# g
# yels
# ebniakgo
# ugb
# cyfcw
# rnlbulnyeh
# enux
# r
# ywjyrfn
# ghpmphdir
# xvbjfh
# fw
# yujtdwxn
# vphkj
# tm
# s
# wndm
# gcd
# oncdvivny
# f
# wpkzx
# es
# isclsld
# lkrlnd
# xeuzdk
# " | ./D.out) 
#   # echo "$result" 
#   assert "$result" "evildnk
# zdfjebxlwg
# prm
# bnfvwdy
# cxiwypbt
# fkxgw
# ar
# vwanbwqnsg
# eskqrvv
# qulvigaqt
# akvapab
# eulxoc
# fj
# ckttk
# qemzm
# xvzcy
# erczzncx
# smxvabamiu
# nupywmu
# csu
# runia
# maph
# pinrap
# etpqje
# hxtemhk
# exzheotlwv
# kthc
# m
# tzojmvvn
# jhddyzqh
# xbfsmklmkb
# dmwulqq
# dhcfkzwsy
# p
# gqdzkkpbk
# ekdivnm
# inyacaron
# g
# yels
# ebniakgo
# ugb
# cyfcw
# rnlbulnyeh
# enux
# r
# ywjyrfn
# ghpmphdir
# xvbjfh
# fw
# yujtdwxn
# vphkj
# tm
# s
# wndm
# gcd
# oncdvivny
# f
# wpkzx
# es
# isclsld
# lkrlnd
# xeuzdk"
fi 
