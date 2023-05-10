#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

// Задача 1. Направление указателя на двумерный динамический массив (Динамическая память).
template <typename T>
void memory_mx(T**& pointer, int rows, int cols) { 
	pointer = new T * [rows];
	for (int i = 0; i < rows; i++)
		pointer[i] = new T[cols]{};
}

// Задача 1. Освобождение памяти, выделенной под двумерный динамический массив.
template <typename T>
void clear_mx(T**& pointer , int rows) {
	for (int i = 0; i < rows; i++)
		delete[] pointer[i];
	delete[] pointer;
	pointer = nullptr;
}

// Задача 2. Заполнение случайными числами.
template<typename T>
void fill_arr(T arr[], const int lenght, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (right - left) + left;
}

// Задача 2. Вывод массивов.
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

// Задача 2.
template<typename T>
T* positive(T arr1[], const int lenght1, T arr2[], const int lenght2, int& var)
{
	T* tmp = new T[lenght1 + lenght2];
	var = 0;

	for (int i = 0; i < lenght1; i++)
		if (arr1[i] > 0) 
			tmp[var++] = arr1[i];		
	
	for (int i = 0; i < lenght2; i++)
		if (arr2[i] > 0) 
			tmp[var++] = arr2[i];

	T* result = new T[var];
	for (int i = 0; i < var; i++)
		result[i] = tmp[i];

	delete[] tmp;
	return result;
}

// Задача 3.
bool filesystem (std::string str, int num) {
	const std::string path = "file.txt";
	std::ofstream out;
	out.open(path, std::ios::app);

	if (out.is_open()) {
		out << str << ' ' << '\n';
		out.close();
		return true;
	}
	else
		out.close();
		return false;
}

// Задача 3. Решение к ней.
bool number_name(int num, std::string file_path) {
	if (num < 10 || num > 99)
		return false;

	static const char* tens[]{
		"двадцать", "тридцать",
		"пятьдесят", "шестьдесят",
		"семьдесят", "восемьдесят", "девяносто"
	};
	static const char* ones[]{
		"",
		" один", " два", " три",
		" четыре", " пять", " шесть",
		" семь", " восемь", " девять"
	};
	static const char* exceps[]{
		"десять", "одинадцать",
		"двенадцать", "тренадцать",
		"четырнадцать", "пятнадцать",
		"шестнадцать", "семнадцать",
		"восемнадцать", "девятнадцать"
	};
	int num1 = num / 10; // Первая цифра.
	int num2 = num % 10; // Вторая цифра.
	
	std::ofstream file;
	file.open(file_path);

	if (num1 == 1) {
		file << exceps[num2] << '\n';
		file.close();
		return true;
	}
	file << tens[num1 - 2] << ones[num2] << '\n';
	file.close();
	return true;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Задача 1. Двумерный динамический массив.
	/*
	std::cout << "Задача 1.\nВведите высоту массива -> ";
	std::cin >> n;
	std::cout << "Введите ширину массива -> ";
	std::cin >> m;
	int** mx = nullptr;

	memory_mx(mx, n, m);
	std::cout << "Итоговый массив: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout << mx[i][j] << '\t';
		std::cout << std::endl;
	}
	clear_mx(mx, n);
	std::cout << '\n';
	*/

	// Задача 2. Массив положительный элементов.
	/*std::cout << "Задача 2.\n\nПервый массив:\n";
	const int size1 = 7, size2 = 6;
	int arr1[size1], arr2[size2];
	fill_arr(arr1, size1, -10, 15);
	fill_arr(arr2, size2, -15, 10);
	print_arr(arr1, size1);
	std::cout << "\nВторой массив:\n";
	print_arr(arr2, size2);
	
	int size3;
	int* arr3 = positive(arr1, size1, arr2, size2, size3);
	
	std::cout << "\nИтоговый массив:\n";
	print_arr(arr3, size3);
	
	delete[] arr3;*/

	// Задача 3.
	/*
	std::string path = "file.txt";

	std::cout << "Задача 3.\nВведите число: ";
	std::string word;
	std::getline(std::cin, word);
	if (filesystem(word))
		std::cout << "Число записано в файл.\n";
	else
		std::cout << "Ошибка выполнения функции.\n";
	*/

	// Задача 3. Решение к ней.

	std::cout << "Задача 3.\nВведите двузначное число -> ";
	std::cin >> n;
	if (number_name(n, "number.txt"))
		std::cout << "Число записано в файл.\n\n";
	else
		std::cout << "Ошибка выполнения функции.\n\n";


	return 0;
}