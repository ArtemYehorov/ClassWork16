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

	// метода SetLength не должно быть!

	void Concat(const String& another);
	String Concat(string& another);
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
	void Ensure(size_t required);

	String operator+(const String& other);
	String& operator+=(const String& other);
	String operator+(const char* text);
	String& operator+=(const char* text);
	char& operator[](int index);
};