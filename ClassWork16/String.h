#include<iostream>
#include<string>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;

#pragma once

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
	String();
	String(const char* text);
	explicit String(unsigned int capacity);
	String(const String& original);
	String(const char* text, unsigned int capacity);

	~String();

	// геттеры-сеттеры
	string GetString() const;
	void SetString(const char* text, unsigned int capacity = 80);
	int GetCapacity() const;
	int GetLength() const;
	const char* const GetCharArray() const;
	void GetLine();
	char GetCharAt(unsigned int index);

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

	// метода SetLength не должно быть!

	void Concat(const String& another);
	void Concat(int num);
	bool Contains(const String& another) const;
	int LastIndexOf(char symbol) const;
	bool Equals(const String& another);
	int IndexOf(char symbol) const;
	int CompareTo(const String& another);
	void Print() const;
	void PrintLn() const;
	void Clear();
	void ShrinkToFit();
	void ShowInfo() const;
	bool EndsWith(const String& another) const;
	bool StartsWith(const String& another) const;
};