/* ���� ��� ������ ����������� ��� �������� ����� Foo � ������� foo_says.
 * �� ����� ��� ����������������� �/��� ������.
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

// ��� ����� ���������� ������� get_foo, ��� ������� � �������,
// ����� �������������� � ������� ��� ��������� ��������� ���:
//
// foo_says(get_foo("Hello!"));


?? get_foo(const char *msg) {

}