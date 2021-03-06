#include "myRect.h"
#include "myString.h"
#include "Bochka.h"
#include <iostream>

#define stop { int a = 1; a+=a; }

int main()
{
using namespace std;

	//Задание 1.Объявление класса. Создание экземпляра класса.
	//Вызов методов класса. 
	//Откройте закладку Class View - (здесь Вы увидите имена методов и
	//данных - классов Rect и MyString)
	//Обратите внимание на пиктограммы слева от имен членов класса - они
	//обозначают спецификатор доступа к каждому члену класса.

	//Какой конструктор вызывается при создании экземпляра класса?
	{
		Rect rect; //констр. по умолчанию
		stop
	}

	//1a. Объявите и определите конструктор с параметрами для
	//инициализации переменных класса. Создайте экземляры класса Rect
	//с помощью конструктора с параметрами. Если компилятор выдает
	//ошибку в предыдущем фрагменте, подумайте - чего ему не
	//хватает? Добейтесь отсутствия ошибок.
	//Выполняя задание с самого начала по шагам, определите:
	//в какой момент происходит вызов конструктора(какого?)?

	//Подсказка: учтите, что пользователь Вашего класса может указывать
	//в качестве параметров любые значения! Например:
	Rect rrr(4,3,2,1);
	

	stop
	//1б. При конструировании объекта посредством конструктора без параметров
	//предусмотрите инициализацию переменных класса, например, нулем

	
	
	stop
	//1в. Объявите, определите и вызовите метод класса InflateRect(), 
	//который увеличивает размеры прямоугольника на заданные приращения
	//(раздвигая стороны от центра - каждую сторону на свое значение).
	//Подсказка: объявить и определить методы можно не только "вручную",
	//но и с помощью Wizard-a Class View. Для этого: откройте закладку
	//ClassView окна проекта, сделайте активным класс Rect и нажмите
	//правую кнопку мыши - в появившемся контекстном меню выберите
	//Add/Add Member Function... С помощью появившейся диалоговой панели
	//"дайте указания" Wizard-у как объявить и определить метод.

	

	
	stop
//*/

	//Задание 2.Перегрузка конструкторов и методов класса.
	//Конструктор копирования.

	//2а.Объявите и определите конструктор копирования в классе Rect.
	//Выполняя задание по шагам, определите, какой
	//конструктор вызывается при создании r1,r2,r3 и r4?
	//Чему равны переменные созданных объектов?
		Rect r1;
		Rect r2(1,2,3,4);
		Rect r3 = r1;// конст. копирования
		Rect r4(r2);// конс. копирования
		stop


  //2б. Объявите и определите в классе Rect метод InflateRect(),
	//который принимает два аргумента, по умолчанию равных 1, и 
	//раздвигает стороны прямоугольника на на заданные приращения.
	//Для каких объектов вызывается функция InflateRect()?
		r1.InflateRect(1,1);	
		r2.InflateRect(2,2);
	//Какая из функций InflateRect() вызывается в каждом из трех случаев?
		r3.InflateRect(2,2,2,2);
		r3.InflateRect(3,3);
		r3.InflateRect(5);
		r3.InflateRect();
	stop
//*/

	
	//Задание 3.Спецификаторы доступа. Инкапсуляция. 
	{
	Rect r;
	//Раскомментируйте следующую строку. Объясните ошибку
	//компилятора

//	int tmp = r.m_left; // доступ закрыт



	//Введите в класс Rect метод void SetAll(...),
	//который присваивают переменным класса передаваемые
	//значения. Вызовите созданный метод, проверьте корректность. 

	r.SetAll(5, 5, 5, 5);

	//Введите в класс Rect парный метод GetAll(...),
	//который "достает" значения private-переменных класса.
	//Вызовите созданный метод, проверьте корректность.
	{
		int ll, rr, tt, bb;
		ll = rr = tt = bb = 0;
		r.GetAll(&ll, &rr, &tt, &bb);// можно ссылками 
		stop
	}
	stop
	}
//*/

	//Задание 4.Передача экземпляра класса в качестве параметра
	//функции. Возвращение объекта класса по значению. Поставив
	//остановы в конструкторе копирования или выполняя фрагмент
	//по шагам, определите: в какой момент происходит обращение
	//к конструктору копирования. 
	//Создайте глобальную функцию 
	// Rect BoundingRect(Rect, Rect);
	//которая принимает два объекта класса Rect по значению и
	//возвращает объект класса Rect, который является прямоугольником,
	//в который вписаны заданные прямоугольники. Как происходит
	//передача параметров и возвращение объекта класса?

	//Замечание*: хорошо было бы учесть тот факт, что прямоугольник
	//может оказаться "ненормализованным", то есть m_left>m_right или/и
	//m_top>m_bottom

	{
		std::cout << "\nmodul 4:" << "\n";
		Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
		r3 = BoundingRect(r1, r2);
		r3.print();
		stop

			std::cout << "modul 4a:" << "\n";
			//Задание 4а. Передача объектов по ссылке.
			//Создайте глобальную функцию BoundingRect2, которая выполняет ту же
			//задачу, принимая параметры по ссылке
			//Вызываются ли конструкторы при передаче параметров?


			r3 = BoundingRect2(r1, r2);
			r3.print();
		stop
	}
	{
		//Задание 4б.Реализуйте ту же задачу (BoundingRect) методом класса
		std::cout << "\nmodul 4b:" << "\n";
		Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
		Rect r4 = r1.BoundingRect(r2); //почем не вызывается конструктор копирования? Из - за доп параметра &r4, кот пердается в функцию?
		r4.print();
		stop
	}
//*/


	//Задание 5. Когда вызываются конструкторы и деструкторы.
	//Объявите и определите
	//явный деструктор класса. Поставьте остановы в 
	//конструкторе (конструкторах) и деструкторе. Определите: когда для
	//каждого из объектов вызывается конструктор, а когда - деструктор?
	{
		std::cout << "\nmodul 5:" << "\n";
		Rect r1;// констр поумолч
		Rect*	pR = new Rect(1,2,1,2);	//констр с параметр
		{
			Rect r2(r1);// констр копий
			Rect arRect[2];// констр по умолчанию
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i) ;// констр с пара на 1_ой итерации
				Rect r4(*pR);// конструктор копий
				Rect r5(i,i,i,i);// на каждой итерации констр с парам
				stop
			}//дестр r4 , r5
		}//  дестр r2 , arRect
		delete pR;	// деструктры pR
		stop
	}//дестр r1, а r3 по завершению программы
//*/

	//Задание 6.Конструктор + деструктор = функциональное
	// замыкание. Класс MyString
	// Посредством конструктора (конструкторов) и деструктора обеспечьте
	//корректные инициализацию и деактивацию объекта
	//C помощью остановов определите когда происходит
	//захват и освобождение памяти для строки-члена класса
	{
		std::cout << "\nmodul 6:" << "\n";
		MyString	str("It's my string!");
		//Создайте метод GetString(), который обеспечит доступ к хранящейся строке.
		//С помощью cout и метода GetString() распечатайте строку объекта str
		//Замечание: подумайте, как следует корректно реализовать метод GetString().

		//...
		std::cout << "\nstring: '"<<str.GetString()<<"'";
	}
	stop
//*/

	//6a. Раскомментируйте следующий фрагмент. Подумайте - какие
	//неприятности Вас ожидают. Попробуйте исправить положение (как?)
	{
			MyString str1("The first string!");
			MyString str2 = str1;// нужен констр  копирования
	}
		stop

		//6б. Реализуйте метод SetNewString, который будет заменять строку
		// на новую
	{
		std::cout << "\nmodul 6b:" << "\n";
		MyString str2("The two string!");
		str2.SetNewString("new string");
		std::cout << "\nstring: '" << str2.GetString() << "'";
		stop
		str2.SetNewString("new string1+new string2");
		std::cout << "\nstring: '" << str2.GetString() << "'";
	}
	stop

//*/


	//Задание 7.  Решите с помощью классов следующую задачу:
	//даны две бочки известного объема. В одной бочке в начальный момент
	//времени содержится спирт (96%), в другой – вода.
	//Кружкой емкостью 1л переливаем итеративно содержимое из одной бочки
	//в другую следующим способом: на каждой итерации
	//зачерпнули из первой бочки -> вылили во вторую
	//зачерпнули из второй бочки -> вылили в первую.
	//Требуется определить номер итерации, на которой концентрация спирта в
	//первой бочке станет меньше 50%.

	Bochka spirt(4,96);
	Bochka water(100, 0);
	int iter = 0;

	while (spirt.getPercent() > 50)
	{
		spirt.Pereliv(water);
		water.Pereliv(spirt);
		spirt.printV();
		
		iter++;
	}

	std::cout << "iter = " << iter<<"\n";
	stop
	//...
	//	while(концентрация спирта в бочке spirt > 50%)
	//	{
	//		spirt.Pereliv(water); //или spirt.Pereliv(water, объем_кружки);
	//		water.Pereliv(spirt); // аналогично
	//		...

	//	}
return 0;

}//end_main

