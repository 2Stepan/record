#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

void write_record(char name[20], int score, int level)
{
	fstream file("record.dat", ios::app);
	if (!file)
	{
		cout << "Ошибка открытия файла для записи" << endl;
		return;
	}
	file << name << " " << score << " " << level << endl;
	file.close();
}

void print_records()
{
	fstream file("record.dat", ios::in);
	if (!file)
	{
		cout << "Ошибка открытия файла для чтения" << endl;
		return;
	}
	char name[20];
	int score, level;
	cout << "\n=== СПИСОК РЕКОРДОВ ===\n";
	while (file >> name >> score >> level)
	{
		cout << "Имя: " << name << ", Очки: " << score << ", Уровень: " << level << endl;
	}
	file.close();
}

void search_record(char name[20])
{
	fstream file("record.dat", ios::in);
	if (!file)
	{
		cout << "Ошибка открытия файла для чтения" << endl;
		return;
	}
	int score, level;
	bool found = false;
	char file_name[20];
	while (file >> file_name >> score >> level)
	{
		if (strcmp(name, file_name) == 0)
		{
			cout << "Имя: " << file_name << ", Очки: " << score << ", Уровень: " << level << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Рекорд с именем " << name << " не найден." << endl;
	}
	file.close();
}

void delete_records()
{
	fstream file("record.dat", ios::out | ios::trunc);
	if (!file)
	{
		cout << "Ошибка открытия файла для удаления" << endl;
		return;
	}
	file.close();
	cout << "Все рекорды удалены." << endl;
}

int main(int argc,char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char name[20];
    int score, level, choice;

    while (true)
    {
        cout << "\n=== МЕНЕДЖЕР РЕКОРДОВ ===\n1. Добавить новый рекорд\n2. Показать все рекорды\n3. Найти рекорд по имени\n4. Удалить все рекорды\n0. Выход\nВыберите действие : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
			cout << "\nВведите имя игрока: ";
			cin >> name;
			cout << "\nВведите количество очков: ";
			cin >> score;
			cout << "\nВведите уровень: ";
			cin >> level;
			write_record(name, score, level);
            break;
        case 2:
			print_records();
            break;
        case 3:
			cout << "\nВведите имя игрока для поиска: ";
			cin >> name;
			search_record(name);
            break;
        case 4:
			delete_records();
            break;
        default:
            cout << "\nВы ввели неверное значение\n";
            break;

        }
    }

    return 0;
}