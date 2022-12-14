# Анализ

## Время работы

При вставке и извлечении выполяются одна или несколько операций из списка:

- Проверяем текущий размер дека
- Сдвигаем указатель
- Возвращаем значение
- Записываем значение

Число операций не зависит от размера входных данных (от числа запросов на изменение дека), следовательно сложность каждой операции O(1).

## Память

Для реализации используется кольцевой буфер на массиве постоянного размера. 
Реализация требует O(n) памяти, где n - размер массива под буфер.

# Доказательство

Докажем, что реализованная структура данных соотвествует семантике двухсторонней очереди, с помощью инварианта цикла.

## Инвариант: 

`head` указывает первый элемент с начала дека, `tail` указывает на адрес свободной ячейки, следующей за последним элементом в деке.

$T_i$

```
 0 1 2 3 4 5 6 7
|X|X|X| | | |X|X|
       T     H
```

## Инициализация: 

До начала цикла дек пустой, `head` и `tail` указывают на элемент с адресом 0. Инвариант соблюдается.

$T_0$

```
 0 1 2 3 4 5 6 7
| | | | | | | | |
 T          
 H
```

## Сохранение (Maintenance): 

Докажем, что инвариант сохраняется после каждой итерации. В простейшем случае при вставке в начало мы сдвигаем указатель `head` на 1 влево, а при извлечении на 1 вправо. При работе с концом дека всё наоборот: сдвигаем указатель `tail` на 1 вправо при вставке и влево при извлечении. Инвариант соблюдается. 

$T_{i + 1}$

```
push_back(N)

 0 1 2 3 4 5 6 7
|X|X|X|N| | |X|X|
         T   H
```

Для реализации используется кольцевой буфер на массиве постоянного размера. Для массива длины `n` адресом следующим за адресом последнего элемента в массиве будет `0`, и наоборот адресом предшествующим первому элементу массива будет адрес `n - 1`. Т.е. при выходе указателей за границы массива инвариант соблюдается.

Максимальный размер дека определяется максимальным размером массива. Если дек полностью заполнен, то head и tail указывают на первый элемент с начала дека. Инвариант соблюдается.

$T_{j}$

```
push_back(N)

 0 1 2 3 4 5 6 7
|X|X|X|X|X|X|X|X|
             H
             T
```

При попытке извлечь элемент из пустого дека или вставить значение полностью заполненный дек выводится ошибка, а `head` и `tail` остаются неизменными.

## Завершение:

Цикл завершается, когда заканчиваются команды на вставку/извленение. По завершению цикла дек может быть пустым, заполненным или частично заполненным, как мы показали раньше во всех случаях инвариант соблюдается.


