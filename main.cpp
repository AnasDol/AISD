#include <iostream>
#include "List.cpp"
using namespace std;

#define Type int

int main() {
	
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
}