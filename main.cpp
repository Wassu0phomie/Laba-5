#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
	string Fam;
	string Name;
	string Patronymic;
	char Sex;
	int Group;
	int idInGroup;
	int Grades[8]{ 0, 0, 0, 0, 0, 0, 0, 0 };
	float avg = 0.0f;
}S;



/*void Copy()
{
	ifstream reading("Input.txt");
	ofstream record("Buffer.txt", ios::out); // открытие файла для ввода
	if (reading){
		if (record) {
			int N;
			reading >> N;
			record << N << endl;
			for (int i = 0; i < N; i++) {
				reading >> S.Fam;
				record << S.Fam << '\n';
				reading >> S.Name;
				record << S.Name << '\n';
				reading >> S.Patronymic;
				record << S.Patronymic << '\n';
				reading >> S.Sex;
				record << S.Sex << '\n';
				reading >> S.Group;
				record << S.Group << '\n';
				reading >> S.idInGroup;
				record << S.idInGroup << '\n';
				for (int j = 0; j < 8; j++) {
					reading >> S.Grades[j];
					record << S.Grades[j] << ' ';
				}

			}
		}
		else {
			cout << "Ошибка открытия файла";
		}
	}
	else {
		cout << "Ошибка открытия файла";
	}
	reading.close();
	record.close();
}*/

void readFile(Student* (&S))
{
	ifstream reading("Input.txt");

	if (reading) {
		int N;
		reading >> N;
		S = new Student[N]; // Выделяем память
		for (int i = 0; i < N; i++) {
			reading >> S[i].Fam;
			reading >> S[i].Name;
			reading >> S[i].Patronymic;
			reading >> S[i].Sex;
			reading >> S[i].Group;
			reading >> S[i].idInGroup;
			for (int j = 0; j < 8; j++) {
				reading >> S[i].Grades[j];
			}
		}
	}
	else {
		cout << "Открыть файл не удалось! \n";
	}
	reading.close();
}

int AmountOfStudent()
{
	ifstream reading("Input.txt");
	int N;
	if (reading) {
		reading >> N;
	}
	else {
		cout << "Открыть файл не удалось! \n";
	}

	reading.close();

	return N;
}

void Print()
{
	ifstream reading("Input.txt");

	if (reading) {
		int N;
		reading >> N;

		cout << "Количество студентов: " << N << endl << endl;

		for (int i = 0; i < N; i++) {

			reading >> S.Fam;
			reading >> S.Name;
			reading >> S.Patronymic;
			reading >> S.Sex;
			reading >> S.Group;
			reading >> S.idInGroup;
			for (int j = 0; j < 8; j++) {
				reading >> S.Grades[j];
			}

			cout << "Student №" << i + 1 << ":" << endl;
			cout << "FIO: " << S.Fam << " " << S.Name << " " << S.Patronymic << endl;
			cout << "SEX:" << S.Sex << endl;
			cout << "GROUP: " << S.Group << endl;
			cout << "ID IN GROUP: " << S.idInGroup << endl;
			cout << "GRADES: ";
			for (int j = 0; j < 8; j++) {
				cout << " " << S.Grades[j];
			}
			cout << endl;
			cout << "_______________________________________" << endl;
		}

		cout << "Данные считаны!\n";
	}
	else {
		cout << "Открыть файл не удалось! \n";
	}
}

void changeStudent(Student* S)
{
	readFile(S);

	int N = AmountOfStudent();
	cout << "Выберети номер студента из базы (от 1 до " << N << "): ";
	int dn;
	cin >> dn;
	--dn;
	if (dn >= 0 && dn < N) {
		cout << endl << endl << "FIO: " << S[dn].Fam << " " << S[dn].Name << " " << S[dn].Patronymic << endl;
		cout << "SEX: " << S[dn].Sex << endl;
		cout << "Group: " << S[dn].Group << endl;
		cout << "Id in group: " << S[dn].idInGroup << endl;
		cout << "GRADES: ";
		for (int j = 0; j < 8; j++) {
			cout << " " << S[dn].Grades[j];
		}
		cout << endl;

		cout << endl << "___________________NEW___________________";
		cout << endl << endl << "NEW Surname: ";
		cin >> S[dn].Fam;
		cout << endl << "NEW Name: ";
		cin >> S[dn].Name;
		cout << endl << "NEW Patronymic: ";
		cin >> S[dn].Patronymic;
		cout << endl << "NEW Sex (M/F): ";
		cin >> S[dn].Sex;
		cout << endl << "NEW Group: ";
		cin >> S[dn].Group;
		cout << endl << "NEW Id in group: ";
		cin >> S[dn].idInGroup;
		cout << endl << "NEW Grades: ";
		for (int j = 0; j < 8; j++) {
			cin >> S[dn].Grades[j];
		}
		cout << endl;

		cout << "\t\tData changed" << endl << endl;
	}
	else {
		cout << "Student not found, please try again" << endl;
	}

	ofstream record("Input.txt"); // открытие файла для ввода

	if (record) {
		record << N << endl;
		for (int i = 0; i < N; i++) {
			record << S[i].Fam << endl;
			record << S[i].Name << endl;
			record << S[i].Patronymic << endl;
			record << S[i].Sex << endl;
			record << S[i].Group << endl;
			record << S[i].idInGroup << endl;
			for (int j = 0; j < 8; j++) {
				record << S[i].Grades[j] << " ";
			}
			record << endl;
		}
	}
	else {
		cout << "Открыть файл не удалось! \n";
	}

	record.close();

}

void AddStudent()
{

	cout << "\t\tВведите данные студента";
	cout << endl << endl << "Surname: ";
	cin >> S.Fam;
	cout << endl << "Name: ";
	cin >> S.Name;
	cout << endl << "Patronymic: ";
	cin >> S.Patronymic;
	cout << endl << "Sex (M/F): ";
	cin >> S.Sex;
	cout << endl << "Group: ";
	cin >> S.Group;
	cout << endl << "Id in group: ";
	cin >> S.idInGroup;
	cout << endl << "8 grades per semester: ";
	for (int j = 0; j < 8; j++) {
		cin >> S.Grades[j];
	}

	int temp = 0;
	for (int i = 0; i < 8; i++)
	{
		if (S.Grades[i] == 2)
			temp++;
	}
	if (temp == 0)
	{
		int N = AmountOfStudent() + 1;
		ofstream _record("Input.txt", ios::out | ios::in);
		if (_record) {
			_record << N << endl;
		}
		else {
			cout << "Ошибка открытия файла!\n";
		}
		_record.close();

		ofstream record("Input.txt", ios::app);
		if (record) {
			record << endl;


			record << S.Fam << endl;
			record << S.Name << endl;
			record << S.Patronymic << endl;
			record << S.Sex << endl;
			record << S.Group << endl;
			record << S.idInGroup << endl;
			for (int j = 0; j < 8; j++) {
				record << S.Grades[j] << " ";
			}
			record << endl;
			record.close();
			cout << endl << "______________________Data added______________________\n\n";
		}
		else {
			cout << "Открыть файл не удалось! \n";
		}

	}

	else
		cout << '\n' << "The profile will not be saved in the database.\n\n";


}

void studOfGroup(Student* S)
{
	readFile(S);

	int N = AmountOfStudent();
	int cnt = 0;
	cout << "Введите номер группы:" << " ";
	int k;
	cin >> k;
	bool ExitFlag = false;
	system("cls");
	cout << "\t\tStudents of group  " << k << ":" << endl << endl;
	for (int i = 0; i < N; i++) {
		if (S[i].Group == k && k >= 0) {
			cnt++;

			cout << "Student №" << i + 1 << ":" << endl;
			cout << "FIO: " << S[i].Fam << " " << S[i].Name << " " << S[i].Patronymic << endl;
			cout << "SEX:" << S[i].Sex << endl;
			cout << "GROUP: " << S[i].Group << endl;
			cout << "ID IN GROUP: " << S[i].idInGroup << endl;
			cout << "GRADES: ";
			for (int j = 0; j < 8; j++) {
				cout << " " << S[i].Grades[j];
			}
			cout << endl;
			cout << "_______________________________________" << endl;
		}

	}
	if (cnt == 0) {
		cout << "Такой группы нет!\n\n\n";
	}
}

void studOfId(Student* S)
{
	readFile(S);
	int cnt = 0;
	int N = AmountOfStudent();
	cout << "Введите номер студента в группе:" << " ";
	int id;
	cin >> id;
	system("cls");
	cout << "\t\tStudents with number  " << id << ":" << endl << endl;
	for (int i = 0; i < N; i++) {
		if (S[i].idInGroup == id && id >= 0) {
			cnt++;
			cout << "Student №" << i + 1 << ":" << endl;
			cout << "FIO: " << S[i].Fam << " " << S[i].Name << " " << S[i].Patronymic << endl;
			cout << "SEX:" << S[i].Sex << endl;
			cout << "GROUP: " << S[i].Group << endl;
			cout << "ID IN GROUP: " << S[i].idInGroup << endl;
			cout << "GRADES: ";
			for (int j = 0; j < 8; j++) {
				cout << " " << S[i].Grades[j];
			}
			cout << endl;
			cout << "_______________________________________" << endl;
		}
	}
	if (cnt == 0) {
		cout << "Студента с таким номером нет!\n\n\n";
	}
}

void topOfStud(Student* S)
{
	readFile(S);
	int N = AmountOfStudent();
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < 8; j++) {
			sum += S[i].Grades[j];
		}
		S[i].avg = (float)sum / 8;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (S[j].avg < S[j + 1].avg) {
				swap(S[j], S[j + 1]);
			}
		}
	}
	cout << "\t\t\t\tTop 3 students:\n\n";
	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << "_______________________ # " << i + 1 << " whith avg = (" << S[i].avg << ")_______________________" << endl;;
		cout << "Student №" << i + 1 << ":" << endl;
		cout << "FIO: " << S[i].Fam << " " << S[i].Name << " " << S[i].Patronymic << endl;
		cout << "SEX:" << S[i].Sex << endl;
		cout << "GROUP: " << S[i].Group << endl;
		cout << "ID IN GROUP: " << S[i].idInGroup << endl;
	}
	cout << endl << endl;
}

void sortBySex(Student* S)
{
	readFile(S);
	int N = AmountOfStudent();
	int m = 0, w = 0;
	for (int i = 0; i < N; i++) {
		if (S[i].Sex == 'M') {
			m += 1;
		}
		else {
			w += 1;
		}
	}
	cout << "\t\t\t\tNUMBER OF STUDENTS _ " << N << endl << endl;
	cout << "\tNumber of male = " << m << '\n' << '\n';
	cout << "\tNumber of female = " << w << endl << endl << endl;

}

void sortByGrades(Student* S, int l)
{
	readFile(S);
	int N = AmountOfStudent();
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int grade = 5;
		for (int j = 0; j < 8; j++)
			grade = min(S[i].Grades[j], grade);

		if (grade == l) {
			cnt++;
			cout << "Student №" << i + 1 << ":" << endl;
			cout << "FIO: " << S[i].Fam << " " << S[i].Name << " " << S[i].Patronymic << endl;
			cout << "SEX:" << S[i].Sex << endl;
			cout << "GROUP: " << S[i].Group << endl;
			cout << "ID IN GROUP: " << S[i].idInGroup << endl;
			cout << "GRADES: ";
			for (int j = 0; j < 8; j++) {
				cout << " " << S[i].Grades[j];
			}
			cout << endl;
			cout << "_______________________________________" << endl;
		}
	}
	if (cnt == 0) {
		cout << "Студент не найден!\n\n\n";
	}

}




int main()
{
	int amountOfStudent = AmountOfStudent();
	Student* S = new Student[amountOfStudent];

	int cnt = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		int choice;
		cout << "Кол-во Студентов:\t" << AmountOfStudent() << endl << endl;
		cout << "Введите номер меню:" << endl;
		cout <<
			"0.Выход\n"
			"1.Вывести все данные\n"
			"2.Добавить данные студента\n"
			"3.Изменить данные студента\n"
			"4.Вывести студентов группы N\n"
			"5.Вывести студента с номером k\n"
			"6.Вывести топ 3 студента\n"
			"7.Вывести кол-во мужчин и женщин\n"
			"8.Вывести по успеваемости\n" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			cout << "Выход из программы...\n\n\n";
			return 0;

		case 1:
			system("cls");
			Print();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			AddStudent();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			changeStudent(S);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			studOfGroup(S);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			studOfId(S);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			topOfStud(S);
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			sortBySex(S);
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			int us;
			cout << endl <<
				"3. Students without a scholarship\n"
				"4. Students which got 4s and 5s\n"
				"5. Students which got only 5s\n";
			cin >> us;
			switch (us) {
			case 3:
				system("cls");
				sortByGrades(S, us);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				sortByGrades(S, us);
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				sortByGrades(S, us);
				system("pause");
				system("cls");
				break;
			}
			break;
		default:
			system("cls");
			cout << "Неверно выбран номер меню!\n\n";
			system("pause");
			system("cls");
			break;

		}


	}
}