#include<iostream>
#include<string>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
	String() : String("", 80) {}

	String(const char* text) : String(text, 80) {}

	explicit String(unsigned int capacity) : String("", capacity) {}

	String(const String& original) : String(original.text, original.capacity) {}

	String(const char* text, unsigned int capacity)
	{
		SetString(text, capacity);
	}

	~String()
	{
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		}
	}

	// геттеры-сеттеры
	string GetString() const
	{
		return text;
	}

	int CompareTo(const String& another)
	{
		return strcmp(text, another.text);
	}

	bool Equals(const String& another)
	{
		if (strcmp(text, another.text) == 0)
		{
			cout << "true" << "\n";
			return true;
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

	void Concat(const String& another)
	{
		string a = text;
		delete[] this->text;

		capacity += another.capacity;
		this->text = new char[capacity];
		for (int i = 0; i < length; i++)
		{
			text[i] = a[i];
		}

		for (int i = 0; i < another.length; i++)
		{
			text[i + length] = another.text[i];
		}
		length += another.length;
		text[length] = '\0';

		ShrinkToFit();
	}

	bool Contains(const String& another) const
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

	void Concat(int num)
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

	bool EndsWith(const String& another) const
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

	bool StartsWith(const String& another) const
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

	void SetString(const char* text, unsigned int capacity = 80)
	{
		length = strlen(text);

		if (capacity <= length)
			capacity = length + 1;
		this->capacity = capacity;

		delete[] this->text;
		this->text = new char[capacity];
		strcpy_s(this->text, length + 1, text);
	}

	int GetLength() const
	{
		return length;
	}

	// метода SetLength не должно быть!

	int GetCapacity() const
	{
		return capacity;
	}

	int LastIndexOf(char symbol) const
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

	int IndexOf(char symbol) const
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

	char GetCharAt(unsigned int index)
	{
		if (index >= length || index < 0)
		{
			cout << "Error!" << "\n";
			return 0;
		}
		return text[index];
	}

	void GetLine()
	{
		cin >> text;
	}

	void Print() const
	{
		cout << text;
	}

	void PrintLn() const
	{
		cout << text << "\n";
	}

	/*const char* const GetCharArray() const
	{
		const char* const ar = text;
		return ar;
	}*/

	const char* const GetCharArray() const
	{
		char* const ar = new char[length];
		for (int i = 0; i < length; i++)
		{
			ar[i] = text[i];
		}
		
		return ar;
	}

	void Clear()
	{
		text[0] = 0;
		length = 0;
	}

	void ShrinkToFit()
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

	void ShowInfo() const
	{
		cout << "Text: " << GetString() << endl;
		cout << "Length: " << GetLength() << endl;
		cout << "Capacity: " << GetCapacity() << endl;
	}
};

int main()
{
	
	String a("Alex");
	String b("Alex1");
	String c("Aererw");
	a.Concat(c);
	a.ShowInfo();
	cout<<a.Contains(b);

}
