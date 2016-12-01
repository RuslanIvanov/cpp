/*
 * ����� Cls ��������� ����� ����� �������:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *
 */

#include <stdio.h>
#include <iostream>
using namespace std;

struct Cls 
{
	Cls(char c, double d, int i)
	{
		this->c = c;
		this->d = d;
		this->i = i;
	}

	private:
    char c;
    double d;
    int i;
};


// ��� ������� ������ ������������ ������ � ���� c ������� cls.
// �������� ��������, ��� ������������ ������ �� char, �. �.
// ������ ��������������� �� ������ � ������.
char &get_c(Cls &cls) {
    /* ... */
	 return *(char*)(&cls);
}

// ��� ������� ������ ������������ ������ � ���� d ������� cls.
// �������� ��������, ��� ������������ ������ �� double, �. �.
// ������ ��������������� �� ������ � ������.
double &get_d(Cls &cls) {
    /* ... */
	return *(double*)((char*)(&cls) + 8);
}

// ��� ������� ������ ������������ ������ � ���� i ������� cls.
// �������� ��������, ��� ������������ ������ �� int, �. �.
// ������ ��������������� �� ������ � ������.
int &get_i(Cls &cls) {
    /* ... */
	return *(int*)((char*)(&cls) + 16);
}

int main()
{
	/*3*8=24*/
	
	cout<<"size struct Cls "<<sizeof(struct Cls)<<endl;
	cout<<"size char "<<sizeof(char)<<endl;
	cout<<"size double "<<sizeof(double)<<endl;
	cout<<"size int "<<sizeof(int)<<endl;

	//���������� ���������� �� ������� 8 ���� (?)
	Cls cls('S',2.2,333);

	cout<<get_c(cls)<<endl;
	cout<<get_d(cls)<<endl;
	cout<<get_i(cls)<<endl;
	
	return 0;
}

/*
����������
char &get_c(Cls &cls) {
    return *(char*)(&cls);
}
 
 
double &get_d(Cls &cls) {
    return *(double*)((char*)(&cls) + 8);
}
 
 
int &get_i(Cls &cls) {
    return *(int*)((char*)(&cls) + 16);
}
*/