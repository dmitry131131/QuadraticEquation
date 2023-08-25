# Квадратка
Консольная программа для решения квадратного уравнения

### Компиляция
`make rec`     -- чтобы скомпилировать пользовательскую версию программы

`make rec_t`   -- чтобы скомпилировать программу в версии тестирования

## Использование
### Пользовательская версия 
`[]`       -- ручной консользый ввод и сонсольный вывод
Введите 3 соэффициента квадратного уравнения a b c через пробел

`[-f] [filename]`      -- Построчно вводит 3 числа из файла `filename` и выводит результаты вычислений в консоль
Программа работает, пока не встретит конец файла

`[-h]`           -- Выводит инструкцию по эксплуатации в консоль

### Режим тестирования
`[-t] [filename]`   -- открывает `filename` и тестируется
Программа считывает 3 коеффициента, проводит вычисления и сравнивает результат с образцом из `filename`
`a b c  real1 complex1 real2 complex2`   -- формат данных в `filename`
`real1, real2` - действительные часть решений квадратного уравнения 
`complex1, complex2` - комплексная часть решений квадратного уравнения

# QuadraticEquation
Console programm to solve quadratic equation

### Compile
`make rec`       -- compile realise version

`make rec_t`      -- compile test version 

## Usage: [flag]
### Realise Mode
`[]`               -- console input and console output
Enter a b c decimal coefficients separated by a space

`[-f] [filename]`  -- input first 3 numbers in row from and output solutions to console
programm works until End Of File

`[-h]`             -- output help information about programm


### Test Mode
`[-t] [filename]`  -- test mode:
programm read first 3 numbers, solve equation and compare roots with roots in file
a b c  real1 complex1 real2 complex2
a, b, c - decimal coefficient
real1, real2 - real parts of first and second answers
complex1, complex2 - complex parts of first and second answers
