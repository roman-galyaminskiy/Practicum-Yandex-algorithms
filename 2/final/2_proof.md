# Анализ

Пусть n - число токенов в исходной стороке.

## Время работы

Мы выполняем парсинг исходной строки и вычисление операций. Нам необходимо считать все $n$ токенов и выполнить приблизительно $n/2$ вычислений (расписал ниже), итого O(n).

## Память

Мы храним строку в памяти целиком, мы кладем на стек операнды из извлекаем их при полученнии знака операции.

Рассмотрим случай, при котором число операндов в стеке будет максимальным: 
все операнды должны быть перечислены до первого знака операций.

$x_1 x_2 ... x_m op_{1} op_{2} ... op_{k}$, причем

$k = m - 1$, как и при записи в инфиксной форме.

Т.е. в худшем случае на стеке будет $(n + 1)/2$ операднов или O(n)

# Доказательство

Докажем, что порядок вычислений соотвествует [обратной польской записи](shorturl.at/kHJNR), с помощью инварианта цикла. Предполагаем, что на вход приходит корректное выражение.

## Инвариант: 

Операнды операции расположены перед её знаком.

## Инициализация: 

Получаем на вход сроку с выражением в обратной польской нотации. Инвариант выполняется.

## Сохранение (Maintenance): 

Будем использовать стек. При извлечении значения из непустого стека, возвращается последний добавленный элемент.

Читаем выражение слева направо до переноса строки или события EOF, обрабатывая последовательности символов разделенные пробелами (токены). Если очередной токен - число, то кладем его в стек. Если это знак операции, то извлекаем два последних значения из стека, вычисляем результат и кладем результат обратно в стек.

Таким образом знаку операции всегда минимум 2 операнда. Это или токены из выражения или результаты выполнения последней опеарции. Инвариант выполняется.

## Завершение:

Цикл завершается, когда заканчиваются токены в выражении. После выполнения последней операции, последнее значение в стеке - результат выражения. Инвариант выполняется.
