//enum
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/*
0 - нет данных
1 - один красный огонь;
2 - один зеленый огонь;
3 - стрелка движение на лево;
4 - стрелка движение на право;
5 - красный мигающий;
6 - зеленый мигающий;
7 - стрелка движение на лево;
8 - стрелка движение на лево;
0xD – огни погашены.
*/
namespace SIGN_SVETOFOR 
{
	//Коды сигнальных показаний светофоров
	//режим АБ: 
	enum SIGNALS_SVET 
	{ 
		SIGN_SVET_ND, 
		SIGN_SVET_RED, 
		SIGN_SVET_GREEN,
//		SIGN_SVET_YELLOW,   
		SIGN_SVET_GREEN_LEFT,
		SIGN_SVET_GREEN_RIGHT,
		SIGN_SVET_RED_BLINK,
		SIGN_SVET_GREEN_BLINK,
//		SIGN_SVET_YELLOW_BLINK, 
		SIGN_SVET_GREEN_LEFT_BLINK,
		SIGN_SVET_GREEN_RIGHT_BLINK,
		SIGN_OTKL_DEIST = 0x11,
		SIGN_SVET_OFF = 0xD		
	};

};

SIGN_SVETOFOR::SIGNALS_SVET SIGN_SVET;

class	SVETOFOR
{
	int a;
	int b;
	SVETOFOR * pNext;

	static unsigned char m_count;
	static const int MAX_KOL_OGN_BUSF = 10;
	static const int MAX_KOL_SIGN_SVET = 16;

	int m[SVETOFOR::MAX_KOL_OGN_BUSF];
	int m2[MAX_KOL_OGN_BUSF];

	unsigned char m_nsv;

public:
	enum SIGNALS_SVET 
	{ 
		SIGN_SVET_ND, 
		SIGN_SVET_RED, 
		SIGN_SVET_GREEN,
//		SIGN_SVET_YELLOW,   
		SIGN_SVET_GREEN_LEFT,
		SIGN_SVET_GREEN_RIGHT,
		SIGN_SVET_RED_BLINK,
		SIGN_SVET_GREEN_BLINK,
//		SIGN_SVET_YELLOW_BLINK, 
		SIGN_SVET_GREEN_LEFT_BLINK,
		SIGN_SVET_GREEN_RIGHT_BLINK,
		SIGN_OTKL_DEIST = 0x11,
		SIGN_SVET_OFF = 0xD		
	};

	SVETOFOR() {a=b=0;   m_nsv = (++m_count); }
	SVETOFOR(int _a,int _b = 0) { a=_a; b=_b;   m_nsv = (++m_count); }

	unsigned char GetNum() { return m_nsv; }
	int fRet() { return SIGN_SVET_OFF; }

public:
	void f(int) { printf("f: '%d' '%d' ",/*SVETOFOR::*/SIGN_SVET_RED,/*SVETOFOR::*/SIGN_OTKL_DEIST); }
	
};

class Car
{
	public:

   	enum Color
   	{
      	RED,
      	BLUE,
      	WHITE
   	};

  	void SetColor( Car::Color color )
   	{
      		_color = color;
   	}

   	Car::Color GetColor() const
   	{
      		return _color;
   	}

private:

   	Car::Color _color;

};

//using namespace SIGN_SVETOFOR;

unsigned char SVETOFOR::m_count;

int main()
{
 	SVETOFOR s; SVETOFOR s2(1); SVETOFOR s3(1,2);
	int a ; 
	printf(": '%d' '%d' ",SIGN_SVETOFOR::SIGN_SVET_RED,SIGN_SVETOFOR::SIGN_SVET_OFF);
	printf(": '%d' '%d' ",SVETOFOR::SIGN_SVET_RED,SVETOFOR::SIGN_SVET_OFF);
	s.f(1);
	printf("num color: %d",s.fRet());

	printf("num: %d",s.GetNum());

	int reqs[] = {7,8,11};

	printf("\nSTART init JSON DB\n");

	for(int i=0;i<(sizeof(reqs)/sizeof(reqs[0])); i++)
	{
	switch(reqs[i])
	{
		case 8:  printf("case: %d",reqs[i] );  break;
		case 7:  printf("case: %d",reqs[i] ); break;
		case 11: printf("case: %d",reqs[i]);  break;
	}}

	getchar();
  	return 0;
}
