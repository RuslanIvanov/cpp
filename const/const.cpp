#include <stdio.h>
#include <iostream>
using namespace std;

int a = 10;
const int * p1 = &a; // ��������� �� ���������
int const * p2 = &a; // ��������� �� ���������

const int ii(1);
int const jj(1);
int const kk=1;
/*
const char * a = "a";
a="b";// ������ ����� ���������� � 'a' �� ������ ������!

char const * c = "a";
c="b";// ������ ����� ���������� � 'a' �� ������ ������!

char * const g = "a";
g="b"; // <-- �� ��������

*a = 'Y';// �������� ������������ ��������������, ����������� ��������
*/
int main()
{

//	*p1 = 20; // ������
	p2 = 0; // ��
//-------------------------------
	int M = 10; int N = 4; 
	const int * const *m = new int*[N]; // � �� const int** m; ( ? ������)
	for(int i=0;i<N;i++)
		m[i] = new int[M]; // error!


	for(int i=0;i<N;i++)
		for(int j = 0; j<M; j++)
			m[i][j] = i+j;

	for(int i = 0; i<N; i++)
		delete [] m[i];
	delete [] m;
	
	m=0;

	return 0;
}