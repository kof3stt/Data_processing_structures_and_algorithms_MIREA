#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <chrono>

const int d = 256; // константа для размерности алфавита
using namespace std;

int input_file(string& str, string file_name)
{
	ifstream ifs(file_name);
	if (ifs.is_open())
	{
		str = "";
		while (!ifs.eof())
		{
			str = "";
			getline(ifs, str);
		}
		ifs.close();
		return 0;
	}
	return 1;
}

int Rabin_Karp(string sub, string text) 
{
	auto start = chrono::high_resolution_clock::now();
	int compare = 0;
	int q = 127, p = 0, t = 0, h = 1;
	int cnt = 0;
	// Вычисляем хеш-функцию sub и первую хеш-функцию text
	for (int i = 0; i < sub.size() - 1; i++)
	{
		h = (h * d) % q;
		compare++;
	}
	compare++;

	for (int i = 0; i < sub.size(); i++)
	{
		compare++;
		p = (d * p + sub[i]) % q;
		t = (d * t + text[i]) % q;
	}
	compare++;

	// Проходимся по тексту и ищем совпадения хеш-функций
	for (int i = 0; i <= text.size() - sub.size(); i++)
	{
		compare+=2;
		// Если хеш-функции совпадают, проверяем посимвольно
		if (p == t) 
		{
			int j;
			compare++;
			for (j = 0; j < sub.size(); j++)
			{
				compare++;
				if (text[i + j] != sub[j])
					break;
			}
			compare++;
			if (j == sub.size()) //Если все символы совпали, увеличиваем счетчик вхождений слова в текст
				cnt++;
		}
		// Вычисляем хеш-функцию следующей подстроки текста
		compare++;
		if (i < text.size() - sub.size())
		{
			t = (d * (t - text[i] * h) + text[i + sub.size()]) % q;
			
			// Если результат вычисления хеш-функции отрицательный, добавляем q
			compare++;
			if (t < 0)
				t = (t + q);
		}
	}
	compare++;
	auto end = chrono::high_resolution_clock::now();
	auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
	cout << "Количество операций сравнения: " << compare << endl;
	return cnt;
}

void search(string str)
{
	cout << " Введите слова через пробел: \n";
	string words;
	cin.ignore();
	getline(cin, words);
	string temp;
	for (int i = 0; i < words.length(); i++) 
	{
		if (words[i] != ' ')
		{
			temp += words[i];
		}
		else
		{
			cout << " Слово " << temp << " встретилось в исходном тексте " << Rabin_Karp(temp, str) << " раз" << endl;
			temp = "";
		}
	}
	if (temp.length() != 0)
	{
		cout << " Слово " << temp << " встретилось в исходном тексте " << Rabin_Karp(temp,str) << " раз" << endl;
	}
}

void car_number(string str)
{
	regex r("[АВСЕКНМОРТХУ]\\d{3}[АВСЕКНМОРТХУ]{2}\\d{2,3}");
	smatch m;
	regex_search(str, m, r);
	for (auto x : m)
	{
		cout << x << endl;
	}
}

void car(string str)
{
	regex reg("[АВСЕКНМОРТХУ]\\d{3}[АВСЕКНМОРТХУ]{2}\\d{2,3}");
	sregex_iterator currentMatch(str.begin(), str.end(), reg);
	sregex_iterator lastMatch;
	int c = 0;
	while (currentMatch != lastMatch)
	{
		smatch match = *currentMatch;
		cout << match.str() << endl;
		c++;
		currentMatch++;
	}
	if (c == 0)
		cout << " Нет номеров\n";
}

int main()
{
	system("chcp 1251");
	string str,substr;
	int pos, number, n;
	while (true)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << " Меню\n";
		cout << " 1. Ввести текст с клавиатуры\n";
		cout << " 2. Ввести текст из файла\n";
		cout << " 3. Вывести текст\n";
		cout << " 4. Определить, сколько раз каждое слово входит в текст\n";
		cout << " 5. Найти автомобильный номер в исходном тексте\n";
		cout << " 6. Завершить выполнение программы\n";
		cin >> number;
		switch (number)
		{
		case 1:
		{
			cout << " Введите текст: \n";
			cin.ignore();
			getline(cin, str);
			break;
		}
		case 2:
		{
			if (input_file(str, "Text.txt") == 1)
			{
				cout << " Произошла ошибка при чтении из файла\n";
			}
			else
			{
				if (str.length() == 0)
				{
					cout << " Пустая строка\n";
				}
				break;
			}
			break;
		}
		case 3:
		{
			if (str.length() != 0)
			{
				cout << str << endl;
			}
			else
			{
				cout << " Пустая строка\n";
			}
			break;
		}
		case 4:
		{
			search(str);
			break;
		}
		case 5:
		{
			car(str);
			break;
		}
		case 6:
		{
			return 0;
		}
		default:
			cout << " Нет такого пункта\n";
		}
	}
}