# Анализ

## Доказательство корректности

Т.к. в постановке задачи есть описание алгоритма, докажем его корретность. Быстрая сортировка относится к алгоритмам "Разделяй и властвуй", мы будем рассматривать этап "разделяй", т.к. в нем выполняется для работа. Доказательство не зависит от варианта выбора pivot-а.

Докажем по индукции для массива длины n:

База: n = 1. Массив единичной длины отсортирован.

Переход: предположим, что алгоритм работает корректно для любой длинны < n. 

Рассмотрим массив длины n. Выберем произвольный pivot и поменяем элементы в 
массиве так, что все элементы до pivot - строго меньше его, а все элементы 
стоящие после него - строго больше его. Пусть число элементов меньше pivot 
равно $n_1$, а больше - $n_2$. 

$n_1 < n,  n_2 < n$

следовательно $n_1$ и $n_2$ будут отсортированны корректно, согласно 
предположению. Тогда все элементы меньше pivot-а будут отсортированны, за ними 
будет следовать pivot и за ним все элементы больше него, также отсортированные. 
Т.е. весь массив длины n отсортирован.

Значит по принципу математической индукции алгоритм работает для всякого n.
Что и требовалось доказать. 

## Время работы

Рандомизированная быстрая сортировка работает в среднем O(logn). В
теоритическом разделе доказательство не приводится.

## Память

~~Алгоритм работает "in-place", следовательно O(1)~~. 
При глубине дерева рекурсии в среднем O(logn), алгоритм в средем использует
O(logn) памяти, т.к. работает "in-place".

