/*
Существует особая форма оператора new, называемая Placement new.
Данный оператор не выделяет память, а получает своим аргументом адрес на уже выделенную каким-либо образом память
(например, на стеке или через malloc()). Происходит размещение (инициализация) объекта путём вызова конструктора,
и объект создается в памяти по указанному адресу. Часто такой метод применяют, когда у класса нет конструктора по
умолчанию и при этом нужно создать массив объектов. Пример вызова выглядит следующим образом:
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <new> // Необходим для использования placement new

class A
{
	public:
      	A(int x){ printf("\nA{}"); }
      	~A(){ printf("\n~A()"); }
};

int main ()
{
	const int n = 50;
  	A* placementMemory = static_cast<A*>(operator new[] (n * sizeof(A)));

 	for (int i = 0; i < n; i++)
  	{
		new (placementMemory + i) A(rand()); //здесь память для объекта не выделяется, но инициализируется
  	}

	//!!деинициализация памяти
	for (int i = 0; i < n; i++)
	{
      		placementMemory[i].~A();
  	}

	operator delete[] (placementMemory);
}

/*
Поскольку при выделении памяти тип создаваемого объекта(ов) не был указан, 
компилятор не будет вызывать деструктор для каждого
объекта массива, поэтому это нужно сделать вручную, 
перед освобождением блока памяти.
*/
