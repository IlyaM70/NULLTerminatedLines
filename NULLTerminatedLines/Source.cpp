#include<iostream>
#include<Windows.h>

using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);//возвращает размер строки

void to_upper(char str[]);
void to_lower(char str[]);
void capitalize(char str[]);
void shrink(char str[]);

void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);

bool is_int_number(char str[]);
int  to_int_number(char str[]);	

bool is_bin_number(char str[]);
int  bin_to_dec(char str[]);

bool is_hex_number(char str[]);
int  hex_to_dec(char str[]);

bool is_mac_address(char str[]);	
bool is_ip_address(char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");
	//char str[] = { 'H','e','l','l','o',0 };
	/*char str[] = "Hello";
	cout << str << endl;
	cout << sizeof str << endl;*/

	const int n = 20;
	char str[n] = "";
	cout << "Введите строку ";
		InputLine(str, n);
	cout << str << endl;//CP866
	
		
	int i= 0;
	i=StrLen(str);
	cout << i << endl;

	cout << "Что требуется сделать? 1-перевести в верхний регистр, 2-в нижний" << endl
		<< " 3 - сделать первую букву каждого слова в предложении заглавной " << endl
		<< " 4 - убрать из строки лишние пробелы " << endl
		<< " 5 - Определить, является ли строка целым числом " << endl
		<< " 6 - Если строка является числом, то вывести значение этого числа " << endl
	    << " 7 - Определить, является ли строка паледромом " << endl
	    << " 8 - Перевести двоичное число в десятичное  " << endl
	    << " 9 - Перевести шестнадчатиричное число в двоичное " << endl
	    << " 10 - Выяснить является ли строка MAC-адрессом " << endl
	    << " 11 - Выяснить является ли строка ip-адрессом " << endl;
	int answer = 0; cin >> answer;
	if (answer == 1)
	{
		to_upper(str);
	cout << str << endl;
	}

	 else if (answer == 2)
	{
		to_lower(str);
	cout << str << endl;
	}
	 else if (answer == 3)
	{
		capitalize(str);
		cout << str << endl;
	}
	 else if (answer == 4)
	{
		shrink(str);
		cout << str << endl;
	}
	 else if (answer == 5)
	{
		bool int_number = false;
		int_number=is_int_number(str);
		if(int_number==0) cout << "Не является " << endl;
		if (int_number == 1) cout << "Является " << endl;
	}
	 else if (answer == 6) cout << to_int_number(str) << endl;

	 else if (answer ==7) cout << "Строка "<< (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом!"<< endl;
	 
	 else if (answer ==8) cout << bin_to_dec(str) << endl;
	 else if (answer == 9) cout << hex_to_dec(str) << endl;
	 else if (answer == 10) cout << "Строка " << (is_mac_address(str) ? "" : "НЕ ") << "является MAC-адрессом" << endl;
	 else if (answer == 11) cout << "Строка " << (is_ip_address(str) ? "" : "НЕ ") << "является ip-адрессом" << endl;

	else  cout << "error"; 
	
}

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
}
int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	int i = 0;
		for (; str[i]; i++)
	{
		if (str[i]!=char(32))str[i]=int(str[i]) - 32;
		 
	}
	
}
void to_lower(char str[])
{
	int i = 0;
	for (; str[i]; i++)
	{
		if (str[i] != char(32)) str[i] = int(str[i]) + 32;

	}

}
void capitalize(char str[])
{
	int i = 0;
	str[i] = int(str[i]) - 32;
	for (;str[i];i++)
	{
		for (; str[i-1] == ' '; i++)
		{
			str[i] = int(str[i]) - 32;
		}
		
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
}
}
bool is_int_number(char str[])
{
	bool int_number = false;
	int i = 0;
	for (; str[i]; i++)
	{
		if (str[i] >= 48 && str[i] <= 57) int_number = true;
		else int_number = false;

	}
	return  int_number;
}
int  to_int_number(char str[])
{
	if (!is_int_number(str)) return 0;
	int number = 0; // значение числа 
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			number *= 10; // сдвигаем число на 1 разряд влево чтобы освободить младший разряд для следующей цифры
			number += str[i] - 48; //48-ASCII-код симбола 0
		}
	}
	return number;
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}
bool is_palindrome(char str[])
{
	int n = strlen(str);
	char* buffer = new char[n+1]{};
	strcpy_s(buffer,n+1, str);//копирует строку str в строку buffer
	to_lower(buffer);
	remove_symbol(buffer,' ');
	n = strlen(buffer);
	for (int i = 0; i < n; i++)
	{
		if (buffer[i] != buffer[n - 1 - i]) 
		{
			delete[] buffer;
			return false;
		}
			
	}
	delete[] buffer;
	return true;
}
bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int  bin_to_dec(char str[])
{
	if (!is_bin_number(str))return 0;
	int decimal = 0;
	int weight = 1;	//Весовой коэффициент разряда
	remove_symbol(str, ' ');
	int n = strlen(str);
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	}
	
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (( (str[i] >= 48 && str[i] <= 56)||(str[i] >= 65 && str[i] <= 70) )|| ( str[i] == ' '))return true;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return false;
}

int  hex_to_dec(char str[])
{
	if (!is_hex_number(str))return 0;
	int decimal = 0;
	int weight = 1;	//Весовой коэффициент разряда
	remove_symbol(str, ' ');
	int n = strlen(str);
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			if (str[i] >= 48 && str[i] <= 56) decimal += (str[i] - 48) * weight;
			if (str[i] >= 65 && str[i] <= 70) decimal += (str[i] - 55) * weight;
			weight *= 16;
		}
	}

	return decimal;
}

bool is_mac_address(char str[])
{
	int n = strlen(str);
	if (n != 17) return false;
	else
	for (int i = 0; str[i]; i++)
	{
		if (i%3==0 && str[i]=='-' )return true;
		
	}
	
}

bool is_ip_address(char str[])
{
	int dot_count = 0;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '.' && str[i + 1] == '.') return false;
			if (((str[i] <= 48) || (str[i] >= 56))&&(str[i] != '.')) return false;
			if (str[i] == '.') dot_count++;

		}
		if(dot_count==3)return true;
}