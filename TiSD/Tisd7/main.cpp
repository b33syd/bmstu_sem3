#include <iostream>

#include "library.h"
#include "AVL.cpp"
#include "BST.cpp"
#include "HashTableClose.cpp"
#include "HashTableOpen.cpp"


int compare_count;

void probel(int n) {
	for(int i = 0; i < n; i++) {
		cout << " ";
	}
}

unsigned int hash_function(Data<char> const & obj) {

	return (unsigned int) (obj.value);
}

unsigned int hash_function(Data<int> const & obj) {
	return (unsigned int) (obj.value);
}



void log(const char *str)
{ ; /*cout << "log: " << str << endl;*/ }

template<typename T>
void from_file_to_struct(T *obj)
{
	ifstream inp;
	inp.open("/home/alexey/repos/bmstu_sem3/TiSD/Tisd7/data.txt");
	int data;
	while (inp >> data)
	{
		obj->Insert(Data<int>(data));
	}
	inp.close();
}

template<typename T>
void from_string_to_struct(string str, T *obj)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
		{
			obj->Insert(Data<char>(str[i]));
		}
	}
}

template<typename Tp,typename T>
void work_with_tree(T *tree)
{
	char a;
	Tp data;
	while (true)
	{

		cout << "**************************************************************" << endl;
		cout << "Выберите одно из следующих действий:" << endl;
		cout << "1: Отобразить дерево (1 способ)" << endl;
		cout << "2: Отобразить дерево (2 способ)" << endl;
		cout << "3: Добавить число в дерево" << endl;
		cout << "4: Удалить число из дерева" << endl;
		cout << "5: Удалить все вхождения числа в дереве" << endl;
		cout << "6: Поиск числа" << endl;
		cout << "7: Закончить работу" << endl;
		cin >> a;
		switch (a)
		{
			case '1':
				show(tree);
				break;
			case '2':
				show_as_tree(tree);
				break;
			case '3':
				cout << "Введите число: " << endl;
				cin >> data;
					tree->Insert(Data<Tp>(data));
				break;
			case '4':
				cout << "Введите число: " << endl;
				cin >> data;
				if (tree->Remove(Data<Tp>(data)))
				{
					cout << "Число успешно удалено" << endl;
				} else
				{
					cout << "Дерево не содержит числа" << endl;
				}
				break;
			case '5':
				cout << "Введите число: " << endl;
				cin >> data;
				while (tree->Search(Data<Tp>(data)))
				{ tree->Remove(Data<Tp>(data)); }
				cout << "Число успешно удалено" << endl;
				break;
			case '6':
				cout << "Введите число: " << endl;
				cin >> data;
				cout << (tree->Search(Data<Tp>(data)) ? "Число есть в дереве" : "Числа нет в дереве") << endl;
				break;
			case '7':
				return;
			default:
				cout << "Команда не найдена";
				break;
		}
	}

}

template<typename Tp,typename T>
void work_with_table(T *table)
{
	char a;
	Tp data;
	while (true)
	{

		cout << "**************************************************************" << endl;
		cout << "Выберите одно из следующих действий:" << endl;
		cout << "1: Отобразить таблицу" << endl;
		cout << "2: Добавить число в таблицу" << endl;
		cout << "3: Удалить число из таблицы" << endl;
		cout << "4: Удалить все вхождения числа в таблице" << endl;
		cout << "5: Поиск числа" << endl;
		cout << "6: Закончить работу" << endl;
		cin >> a;
		switch (a)
		{
			case '1':
				table->Show();
				break;
			case '2':
				cout << "Введите число: " << endl;
				cin >> data;

					table->Insert(Data<Tp>(data));
				break;
			case '3':
				cout << "Введите число: " << endl;
				cin >> data;
				if (table->Delete_element(Data<Tp>(data)))
				{
					cout << "Число успешно удалено" << endl;
				} else
				{
					cout << "Таблица не содержит числа" << endl;
				}
				break;
			case '4':
				cout << "Введите число: " << endl;
				cin >> data;
				while (table->Delete_element(Data<Tp>(data)))
				{ ; }
				cout << "Число успешно удалено" << endl;
				break;
			case '5':
				cout << "Введите число: " << endl;
				cin >> data;
				cout << (table->Search(Data<Tp>(data)) ? "Число есть в таблице" : "Числа нет в таблице") << endl;
				break;
			case '6':
				return;
			default:
				cout << "Команда не найдена";
				break;
		}
	}

}

template<typename Tp,typename T>
bool find(char ch, T *obj)
{
	compare_count = 0;
	time_t t1 = clock();
	Data<Tp> tmp(ch);
	bool res = obj->Search(tmp);
	time_t t2 = clock();
	cout << "Время работы(мкс):" << t2 - t1 << endl;
	cout << "Кол-во сравнений: " << compare_count << endl;
	cout << "Объем памяти(байт): " << obj->Memory() << endl;
	//TODO подсчет памяти
	return res;
}

template <typename  Tp>
void interface()
{
	char menu_index;
	Tp data;

	BST<Data<Tp>> *binary_tree = new BST<Data<Tp>>();
	AVL<Data<Tp>> *avl_tree = new AVL<Data<Tp>>();
	HashTableClose<Data<Tp>> *close_table = new HashTableClose<Data<Tp>>(4);
	HashTableOpen<Data<Tp>> *open_table = new HashTableOpen<Data<Tp>>(4);
	string str;
	while (true)
	{

		cout << "**************************************************************" << endl;
		cout << "Выберите одно из следующих действий:" << endl;
		cout << "0: Загрузить данные из файла" << endl;
		cout << "1: Работа с bst деревом" << endl;
		cout << "2: Работа с avl деревом" << endl;
		cout << "3: Работа с хэш таблицей с открытой адресацией" << endl;
		cout << "4: Работа с хэш таблицей с закрытой адресацией" << endl;
		cout << "5: Сравнение времени поиска" << endl;
		//cout << "6: Изменить исходную строку" << endl;
		cout << "6: Закончить работу" << endl;
		cin >> menu_index;
		switch (menu_index)
		{
			case '0':
				from_file_to_struct(binary_tree);
				from_file_to_struct(avl_tree);
				from_file_to_struct(close_table);
				from_file_to_struct(open_table);
				cout << "Элементы добавлены в структуры\n" << endl;
				break;
			case '1':
				work_with_tree<Tp>(binary_tree);
				break;
			case '2':
				work_with_tree<Tp>(avl_tree);
				break;
			case '3':
				work_with_table<Tp>(open_table);
				break;
			case '4':
				work_with_table<Tp>(close_table);
				break;
			case '5':
				cout << "Введите число: " << endl;
				cin >> data;
				cout << "Время поиска" << endl;
				cout << "\nБинарное дерево: \n";
				find<Tp>(data, binary_tree);
				cout << "\nAvl дерево: \n";
				find<Tp>(data, avl_tree);
				cout << "\nТаблица с открытой адресацией: \n";
				find<Tp>(data, open_table);
				cout << "\nТаблица с закрытой адресацией: \n";
				find<Tp>(data, close_table);
				//
				break;

			case '6':
				return ;
			default:
				cout << "Команда не найдена"<<endl;
				break;
		}
	}
}

int main()
{
	interface<int>();
	std::cout << "Hello, World!" << std::endl;
	return 0;
}