 #include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

struct String 
{
	String(const char *str = "");
	String(size_t n, char c);
	void append(String &other);
	void print();
	~String();
	size_t size;
	char *str;
};

String::String(const char *str)
{	
	size = 0;
	for(;;size++)
	{
		if(str[size]=='\0') break;
	}

	this->str = new char[size+1];
	
	for(int i=0;i<(size+1);i++)
	{
		this->str[i] = str[i];
	}
		 
}

String::String(size_t n, char c)
{
	str = new char[n+1];

	size = 0;	
	for(;size<n;size++)
	{
		str[size] = c;	
	}

	str[n]='\0';
}

void String::append(String &other)
{
	//if(this == &other) { return; }

	char* pstr = str;
	//cout<<"-1\n";
	str = new char [other.size+size+1];
	//cout<<"-2\n";
	strcpy(str,pstr);
	//cout<<"-3\n";
	if(this == &other) 
		strcpy(str+size,pstr);
	else
		strcpy(str+size,other.str);
	//cout<<"-4\n";
	size += other.size;
	//cout<<"-5\n";

	delete [] pstr;
}

void String::print()
{
	cout<<"------------------------------------------"<<endl;
	cout<<str<<endl;
	cout<<"------------------------------------------"<<endl;
}

String::~String()
{
	delete [] str;	
}

int main(int,char**)
{
	String s;
	String ss("This is str");
	ss.print();

	String s1("Hello,");
	String s2(" world!");
	s1.append(s2); //s1 is "Hello, world!"
	s1.print();

	String sss("Hello");
	sss.append(sss); // "HelloHello"
	sss.print();

	return 0;
}
