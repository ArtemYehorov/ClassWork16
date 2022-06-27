﻿#include"String.h"


String::String() : String("", 80) {}

String::String(const char* text) : String(text, 80) {}

String::String(unsigned int capacity) : String("", capacity) {};

String::String(const String& original) : String(original.text, original.capacity) {};

String::String(const char* text, unsigned int capacity)
{
	SetString(text, capacity);
}

String::~String()
{
	if (text != nullptr)
	{
		delete[] text;
		text = nullptr;
	}
}

// ãåòòåðû-ñåòòåðû
string String::GetString() const
{
	return text;
}

int String::CompareTo(const String& another)
{
	return strcmp(text, another.text);
}

bool String::Equals(const String& another)
{
	if (strcmp(text, another.text) == 0)
	{
		cout << "false" << "\n";
		return false;
	}
	else if (strcmp(text, another.text) == -1)
	{
		cout << "false" << "\n";
		return false;
	}
	else if (strcmp(text, another.text) == 1)
	{
		cout << "true" << "\n";
		return true;
	}
}

String String::Concat(string& another)
{
	String d;
	string a = text;
	delete[] d.text;

	capacity += another.capacity();
	text = new char[capacity];
	for (int i = 0; i < length; i++)
	{
		text[i] = a[i];
	}

	for (int i = 0; i < another.length(); i++)
	{
		text[length + i] = another[i];
	}
	length += another.length();
	text[length] = '\0';

	ShrinkToFit();
	d.text = text;
	d.capacity = capacity;
	d.length = length;
	return d;
}

bool String::Contains(const String& another) const
{
	string a = text;
	string b = another.text;
	if (a.find(b) != EOF)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void String::Ensure(size_t required) {
	if (required <= capacity) {
		return;
	}
	size_t new_capacity = max(2 * capacity, capacity + required);
	char* new_buf = new char[new_capacity];
	memcpy(new_buf, text, length + 1);
	delete[] text;
	text = new_buf;
	capacity = new_capacity;
}

void String::Concat(const String& another) {
	Ensure(length + another.length + 1);
	memcpy(text + length, another.text, another.length);
	length += another.length;
	text[length] = '\0';
}

void String::Concat(int num)
{
	string copy = text;
	string s = to_string(num);
	int a = 0;
	do
	{
		num = num / 10;
		a++;
	} while (num > 0);

	delete[] this->text;

	capacity += a;
	this->text = new char[capacity];
	copy = copy.append(s);
	for (int i = 0; i < length + a; i++)
	{
		text[i] = copy[i];
	}
	length += a;
	text[length] = '\0';

	ShrinkToFit();
}

/*string NumberToString(double Number)
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}*/
/*void Concat(double num)
{
	string copy = text;
	string s = NumberToString(num);
	int a = 0;
	do
	{
		num = num - 1;
		a++;
	} while (num > 0);
	delete[] this->text;
	capacity += a;
	this->text = new char[capacity];
	copy.append(s);
	for (int i = 0; i < length; i++)
	{
		text[i] = copy[i];
	}
	length += a;
	text[length] = '\0';
}*/

bool String::EndsWith(const String& another) const
{
	string a = text;
	if (a.rfind(another.text) != -1 && a[length] == another.text[another.length])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::StartsWith(const String& another) const
{
	string a = text;
	if (a.find(another.text) != -1 && a[0] == another.text[0])
	{
		return true;
	}
	else
	{
		return false;
	}

}

void String::SetString(const char* text, unsigned int capacity)
{
	length = strlen(text);

	if (capacity <= length)
		capacity = length + 1;
	this->capacity = capacity;

	delete[] this->text;
	this->text = new char[capacity];
	strcpy_s(this->text, length + 1, text);
}

int String::GetLength() const
{
	return length;
}

// ìåòîäà SetLength íå äîëæíî áûòü!

int String::GetCapacity() const
{
	return capacity;
}

int String::LastIndexOf(char symbol) const
{
	string a = text;
	if (a.rfind(symbol) != 1)
	{
		return a.find(symbol);
	}
	else
	{
		return -1;
	}
}

int String::IndexOf(char symbol) const
{
	string a = text;
	if (a.find(symbol) != -1)
	{
		return a.find(symbol);
	}
	else
	{
		return -1;
	}
}

char String::GetCharAt(unsigned int index)
{
	if (index >= length || index < 0)
	{
		cout << "Error!" << "\n";
		return 0;
	}
	return text[index];
}

void String::GetLine()
{
	cin >> text;
}

void String::Print() const
{
	cout << text;
}

void String::PrintLn() const
{
	cout << text << "\n";
}

/*const char* const GetCharArray() const
{
	const char* const ar = text;
	return ar;
}*/

const char* const String::GetCharArray() const
{
	char* const ar = new char[length];
	for (int i = 0; i < length; i++)
	{
		ar[i] = text[i];
	}

	return ar;
}

void String::Clear()
{
	text[0] = 0;
	length = 0;
}

void String::ShrinkToFit()
{
	if (length + 1 <= capacity)
	{
		return;
	}

	capacity = length + 1;
	char* temp = new char[capacity];
	strcpy_s(temp, capacity, text);
	delete[] text;
	text = temp;
}

void String::ShowInfo() const
{
	cout << "Text: " << GetString() << endl;
	cout << "Length: " << GetLength() << endl;
	cout << "Capacity: " << GetCapacity() << endl;
}

String String::operator+(const String& other)
{
	String copy(length + other.length + 80);
	copy.length = length + other.length;

	int n = 0;

	for (int i = 0; i < length; i++)
	{
		copy.text[n] = text[i];
		n++;
	}
	for (int i = 0; i < other.length; i++)
	{
		copy.text[n] = other.text[i];
		n++;
	}

	copy.text[n] = '\0';

	return copy;
}

String& String::operator+=(const String& other)
{
	if (capacity > length + other.length)
	{
		for (int i = 0; i < other.length; i++)
		{
			text[length + i] = other.text[i];
		}
		length += other.length;
		text[length] = '\0';

		return *this;
	}
	else 
	{
		capacity = length + other.length + 80;
		char* str = new char[capacity];
		int n = 0;

		for (int i = 0; i < length; i++)
		{
			str[n] = text[i];
			n++;
		}
		for (int i = 0; i < other.length; i++) 
		{
			str[n] = other.text[i];
			n++;
		}

		length += other.length;

		text[length] = '\0';
		delete[] text;
		str = text;

		return *this;
	}
}

String String::operator+(const char* text)
{
	String copy(length + strlen(text) + 80);

	copy.length = length + strlen(text);

	int n = 0;

	for (int i = 0; i < length; i++)
	{
		copy.text[n] = text[i];
		n++;
	}
	for (int i = 0; i < strlen(text); i++) 
	{
		copy.text[n] = text[i];
		n++;
	}

	copy.text[n] = '\0';

	return copy;
}

String& String::operator+=(const char* str)
{
	if (capacity > length + strlen(str))
	{
		for (int i = 0; i < strlen(str); i++)
			text[length + i] = str[i];
		length += strlen(str);
		text[length] = '\0';
		return *this;
	}
	else 
	{
		capacity = length + strlen(str) + 80;
		char* text1 = new char[capacity];
		int n = 0;

		for (int i = 0; i < length; i++)
		{
			text1[n] = text[i];
			n++;
		}
		for (int i = 0; i < strlen(text); i++)
		{
			text1[n] = str[i];
			n++;
		}
		length += strlen(str);
		text1[length] = '\0';
		delete[] text;
		text = text1;
		return *this;
	}
}

char& String::operator[](int index)
{
	if (index >= 0 && index < length) return text[index];
	else
	{
		throw exception("out of memory!!!");
	}
}

String& String::operator=(const String& other)
{
	if (text == other.text) return *this;
	capacity = other.capacity;
	length = other.length;
	text = new char[capacity];

	for (int i = 0; i < length; i++)
		text[i] = other.text[i];
	text[length] = '\0';

	return *this;
}

String& String::operator=(const char* str)
{
	if (strlen(str) < capacity) 
	{

		for (int i = 0; i < strlen(str); i++)
		{
			text[i] = str[i];
		}
		text[strlen(str)] = '\0';
		length = strlen(str);
	}
	else 
	{
		while (capacity <= strlen(str))
		{
			capacity += 80;
		}
		delete[] text;
		text = new char[capacity];

		for (int i = 0; i < strlen(str); i++)
		{
			text[i] = str[i];
		}
		text[strlen(str)] = '\0';
		length = strlen(str);
	}

	return *this;
}
