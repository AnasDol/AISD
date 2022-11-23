# AISD
Абстрактный тип данных "Список" + консольное меню

Интерфейс АТД «Список» включает следующие операции: 
• конструктор, 
• конструктор копирования, 
• деструктор, 
• опрос размера списка, 
• очистка списка, 
• проверка списка на пустоту, 
• опрос наличия заданного значения, 
• чтение значения с заданным номером в списке, 
• изменение значения с заданным номером в списке, 
• получение позиции в списке для заданного значения, 
• включение нового значения, 
• включение нового значения в позицию с заданным номером, 
• удаление заданного значения из списка, 
• удаление значения из позиции с заданным номером, 


• запрос прямого итератора begin(), 
• запрос обратного итератора rbegin() //(для вариантов задания 1, 2, 5, 7), 
• запрос «неустановленного» прямого итератора end(), 
• запрос «неустановленного» обратного итератора rend() // (для вариантов задания 1, 2, 5, 7), 
• прямой и обратный (для вариантов задания 1, 2, 5, 7) итератор для доступа к значениям в списке с основными операциями (набор операций зависит от вида структуры для списка):  
 операция доступа по чтению и записи к текущему значению *, 
 операция инкремента для перехода к следующему (к предыдущему для обратного итератора) значению в списке ++, 
 операция декремента для перехода к предыдущему (к следующему для обратного итератора) значению в списке --, 
 проверка равенства однотипных итераторов ==, 
 проверка неравенства однотипных итераторов !=. 

Для отладки и тестирования операций интерфейс АТД «Список» включает дополнительные операции: 
• запрос числа элементов списка, просмотренных предыдущей опе-
рацией (опроса наличия заданного значения, включения нового значе-
ния в позицию с заданным номером, удаления значения из позиции с 
заданным номером). 
• вывод на экран последовательности значений данных из списка.
