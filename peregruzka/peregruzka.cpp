#include <stdio.h>
#include <iostream>
using namespace std;

void foo(char) { std::cout << "char" << std::endl; }
void foo(signed char) { std::cout << "signed char" << std::endl; }
void foo(unsigned char) { std::cout << "unsigned char" << std::endl; }

int main()
{
	cout<<"foo('a'): "<<endl;
	foo('a');
	//cout<<"foo(97): "<<endl;
	//foo(97);
	
	return 0;
}