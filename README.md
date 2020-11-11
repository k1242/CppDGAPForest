# Деревья на C++
Общую теорию можно найти по **красно-черным** [здесь](https://neerc.ifmo.ru/wiki/index.php?title=%D0%9A%D1%80%D0%B0%D1%81%D0%BD%D0%BE-%D1%87%D0%B5%D1%80%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE) и по **АВЛ** [здесь](https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE).

## Красно-черное дерево
...

## АВЛ-дерево
...

## Тестирование
При различных размерах дерева (от 0 до <img src="https://latex.codecogs.com/gif.latex?10^8" /> элементов) измеряется время вставки элемента (insert), поиска (find) и удаения (remove). Каждое измерение производится <img src="https://latex.codecogs.com/gif.latex?10^6" /> раз. По МНК находим линейное и нелинейное приближение (для понимания применимости линейной аппроксимации), из корней диагональных элементов ковариационной матрицы нахожим ошибку полученных величин.

Можете самостоятельно воспользоваться
[кодом](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/TestSet.cpp)
 для тестирования и
[блокнотом](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/read_data.ipynb) 
для обработки результатов. 

## Результаты

### АВЛ-дерево

![find](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/figures/AVL_find.png)

![insert](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/figures/AVL_insert.png)

![remove](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/figures/AVL_remove.png)

### Красно-чёрное дерево

![find](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/figures/RB_find.png)

![insert](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/figures/RB_insert.png)

![remove](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/figures/RB_remove.png)

### Общий обзор

Можно заметить, что время работы достаточно схоже для одни и тех же действий. Светлым показано нелинейная аппрокимация точек, которая, как видно, ни сильно отличается в пределах погрешности.

![overview](https://github.com/k1242/CppDGAPForest/blob/main/Testing%20system/figures/overview.png)
