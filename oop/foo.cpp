/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
 * Не нужно его расскоментировать и/или менять.
 *
 * #include <iostream>
 *        
 * struct Foo {
 *     void say() const { std::cout << "Foo says: " << msg << "\n"; }
 * protected:
 *     Foo(const char *msg) : msg(msg) { }
 * private:
 *     const char *msg;
 * };
 * 
 * void foo_says(const Foo &foo) { foo.say(); }
 *
 */

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));

#include <string> 
#include <stdio.h>
#include <iostream>
using namespace std;

struct Foo 
{
   void say() const { std::cout << "Foo says: " << msg << "\n"; }
   protected:
      Foo(const char *msg) : msg(msg) { }
   private:
      const char *msg;
};

struct Foo2: Foo
{
	Foo2(const char* _msg): Foo(_msg) {}
};

Foo/*&*/ get_foo(const char *msg) 
{
	/*static*/ Foo2 f2(msg); 	
	return f2;
}// вернул копию объекта!

void foo_says(const Foo& foo) { foo.say(); }

int main ()
{

	foo_says(get_foo("Hello!"));	
	return 0;
}