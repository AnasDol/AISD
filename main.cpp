
#include <iostream>
#include "List.cpp"
using namespace std;

#define Type int

int main() {

	List<Type> list;

	/*list.add(1);
	list.show();

	list.add(2);
	list.add(3);
	list.show();

	list.add(4, 2);
	list.show();
	
	list.add(5, 1);
	list.show();

	list.add(6, 0);
	list.show();

	list.add(7, 5);
	list.show();

	list.add(8, 7);
	list.show();

	cout << "\n" << list.getSize() << "\n\n";

	list.clear();
	list.show();
	if (list.isEmpty()) list.add(9);
	list.show();
	if (list.isExisting(9)) list.add(10);
	list.show();

	List<Type>* list2 = new List<Type>(list);
	list2->show();

	cout << "\n\n" << list.read(1) << "\n\n";

	list.add(11);
	list.add(12);
	list.add(13);
	list.add(14);
	list.add(15);
	list.add(16);
	list.show();

	cout << "\n\n" << list.read(0);
	cout << "\n\n" << list.read(7);
	cout << "\n\n" << list.read(5);
	cout << "\n\n" << list.read(2);
	cout << "\n\n" << list.read(6) << "\n\n";

	list.show();
	list.update(4, 17);
	list.show();
	list.update(7, 18);
	list.show();
	list.update(0, 19);
	list.show();
	list.update(1, 20);
	list.show();

	cout << "\n" << list.getIndex(20);
	cout << "\n" << list.getIndex(19);
	cout << "\n" << list.getIndex(11);
	cout << "\n" << list.getIndex(18);
	cout << "\n" << list.getIndex(2) << "\n\n";

	list.show();
	list.remove(11);
	list.show();
	list.remove(12);
	list.show();
	list.remove(14);
	list.show();
	list.remove(15);
	list.show();

	list.add(21);
	list.add(22);
	list.add(23);
	list.add(24);
	cout << "\n\n";
	list.show();

	list.remove(2, true);
	list.show();
	list.remove(0, true);
	list.show();
	list.remove(5, true);
	list.show();

	cout << "\n";
	for (auto iter = list.begin(); iter != list.end(); ++iter) {
		std::cout << *iter << std::endl;
	}

	cout << "\n\n";
	list.clear();
	list.show();
	list.add(25);
	list.show();
	list.remove(25);
	list.show();

	list.add(26);
	list.add(27);
	list.add(28);
	list.add(29);
	list.show();

	
	
	cout << "\n";
	for (auto iter = list.rbegin(); iter != list.rend(); ++iter) 
	{
		std::cout << *iter << std::endl;
	}*/

	list.add(1);
	list.add(2);
	list.add(3);

	

	/*cout << "\n";
	for (auto iter = list.begin(); iter != list.end(); ++iter) {
		std::cout << *iter << std::endl;
	}

	cout << "\n";
	for (auto iter = list.rbegin(); iter != list.rend(); ++iter) {
		std::cout << *iter << std::endl;
	}*/

	try {
		auto iter = list.begin();
		cout << *iter;
		++iter;
		cout << *iter;
		++iter;
		cout << *iter;
		++iter;
		cout << *iter;
	}
	catch (exception ex) 
	{
		cout << ex.what();
	}


}
/*
#include <iostream>
#include "List.cpp"
using namespace std;

#define Type int

int main() {
	//system("\chcp 1251");
	//setlocale(LC_ALL, "rus");
	//system("cls");
	List<Type> list;
	int x, y;
	auto iter = list.begin();
	bool isExit = false;
	cout << "-1. Выход" << endl;
	cout << "0. Просмотр списка" << endl;
	cout << "1. Опрос размера списка" << endl;
	cout << "2. Очистка списка" << endl;
	cout << "3. Проверка списка на пустоту" << endl;
	cout << "4. Опрос наличия заданного значения" << endl;
	cout << "5. Чтение значения с заданным номером в списке" << endl;
	cout << "6. Изменение значения с заданным номером в списке" << endl;
	cout << "7. Получение позиции в списке для заданного значения" << endl;
	cout << "8. Включение нового значения" << endl;
	cout << "9. Включение нового значения в позицию с заданным номером" << endl;
	cout << "10. Удаление заданного значения из списка" << endl;
	cout << "11. Удаление значения из позиции с заданным номером" << endl;
	cout << "Прямой итератор:" << endl;
	cout << "\t12. Операция доступа по чтению к текущему значению" << endl;
	cout << "\t13. Операция доступа по записи к текущему значению" << endl;
	cout << "\t14. Операция инкремента для перехода к следующему значению в списке" << endl;
	cout << "\t15. Операция декремента для перехода к предыдущему значению в списке" << endl;
	cout << "\t16. Проверка равенства однотипных итераторов" << endl;
	cout << "\t17. Проверка неравенства однотипных итераторов" << endl;
	cout << "Обратный итератор:" << endl;
	cout << "\t18. Операция доступа по чтению к текущему значению" << endl;
	cout << "\t19. Операция доступа по записи к текущему значению" << endl;
	cout << "\t20. Операция инкремента для перехода к предыдущему значению в списке" << endl;
	cout << "\t21. Операция декремента для перехода к следующему значению в списке" << endl;
	cout << "\t22. Проверка равенства однотипных итераторов" << endl;
	cout << "\t23. Проверка неравенства однотипных итераторов" << endl;
	cout << "24. Запрос числа элементов списка, просмотренных предыдущей операцией" << endl;

	while (!isExit) {
		int ans;
		cin >> ans;
		switch (ans) {
		case -1:
			isExit = true;
			break;
		case 0:
			list.show();
			break;
		case 1:
			cout << list.getSize() << endl;
			break;
		case 2:
			list.clear();
			cout << "Список очищен" << endl;
			break;
		case 3:
			cout << list.isEmpty() << endl;
			break;
		case 4:
			cout << "Введите значение" << endl;
			cin >> x;
			cout << list.isExisting(x) << endl;
			break;
		case 5:
			cout << "Введите номер значения" << endl;
			cin >> x;
			y = list.read(x);
			if ((y > -1) && (y < list.getSize())) cout << y << endl;
			else cout << "Неверный индекс" << endl;
			break;
		case 6:
			cout << "Введите номер значения" << endl;
			cin >> x;
			cout << "Введите новое значение" << endl;
			cin >> y;
			cout << list.update(x, y) << endl;
			break;
		case 7:
			cout << "Введите значение" << endl;
			cin >> y;
			cout << list.getIndex(y) << endl;
			break;
		case 8:
			cout << "Введите новое значение" << endl;
			cin >> y;
			list.add(y);
			if (list.getSize() == 1) iter = list.begin();
			break;
		case 9:
			cout << "Введите позицию вставки" << endl;
			cin >> x;
			cout << "Введите значение" << endl;
			cin >> y;
			cout << list.add(x, y) << endl;
			break;
		case 10:
			cout << "Введите значение" << endl;
			cin >> y;
			cout << list.remove(y) << endl;
			break;
		case 11:
			cout << "Введите номер значения" << endl;
			cin >> x;
			cout << list.remove(x, true) << endl;
			break;
		case 12:
			if (!list.isEmpty()) cout << *iter << endl;
			else cout << "Список пуст!" << endl;
			break;
		case 13:
			if (!list.isEmpty()) {
				cout << "Введите значение" << endl;
				cin >> y;
				*iter = y;
			}
			else cout << "Список пуст!" << endl;
			break;
		case 14:

			break;

		case 24:
			cout << "Число операций = " << list.getStepCount() << endl;
			break;
		default:
			cout << "Введена неверная команда!" << endl;
		}
	}
	return 0;
}*/