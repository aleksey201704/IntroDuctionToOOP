#include <iostream>
#include <Windows.h>

using namespace std;

int StringLength(const char* str);

//#define NULL_TERMINATED_LINES

class String
{
	int size; // ������ ������
	char* str; // E��������� �� ������ � ������������ ������
public:
	explicit String(int size = 80)
	{
		// ��������� ��������� size ��������� ��������� �� ����� ���������� ������
		// �������� �������
		this->size = size;
		this->str = new char[size] {};
		cout << "Default constractor: " << this << endl;
	}

	String(const char *str)
	{
		this-> size = StringLength(str)+1; // ��������� ������ � ������
		// � ������
		this->str = new char[size]  {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "Copy Constructor";
	}
	~String()
	{
		delete[] this->str; // ���� ����������� �������� ������ ��� ������ new
		// �� ��������� ���������� ������ ����������� ��� ������ ���������� delete
		// � ��������� ������ ����� ��������� ������ ������.
	}

				// Operators:
	String& operator=(const String& other)
	{
		if (this == &other) return *this; // ���� ���������� ��������

		delete[] this->str; // �������� ������ ��������
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "Copy Assigment: \t";
		return *this;
	}

	void print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}
};

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
#ifdef NULL_TERMINATED_LINES
	/*char str[] = { 'H','r','e','\0'};
	char str1[] = "RTYR";
	cout << str1 << endl;

	char* str2 = "Wolrd";*/

	const int SIZE = 20;
	char str[SIZE] = {};

	cout << "������"; /*cin >> str;*/
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(1251);
	cout << str << endl;
#endif // NULL_TNULL_TERMINATED_LINES

	String str1;
	str1.print();

	// String str2=25; // �������������� int � string ���������
	String str2(25); // explicint ���������� ����� ������� ������ ���
	str2.print();

	//cout << "StringLength:\t"  << StringLength("Hello");

	String str3 = "HEllo";
	str3.print();

	str3 = str3;

	String str4 = str3; // �������� Copy Constructor
	str4.print();

	String str5;
	str5 = str4; // CopyAssign
	str5.print();
}

int StringLength(const char* str) 
{
	
	int t = 0;
	while (str[t] != 0)
	{
		t++;
	}
	
	return t;
}