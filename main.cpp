#include <iostream>
#include "MathOperator.hpp"





int main() {
	setlocale(LC_ALL, "ru");

	const MathOperator<float> f(1.,2.);
	std::cout << f.Summ() << '\n';
	//f.SetLeft(6); для константного контекста невозможно вызвать неконстантный метод

	std::cout << f.Get_left() << '+' << f.Get_Right() << '=' << f.Summ() << '\n';
	// остально взаимодействие аналогично любым другим объектам класса

	MathOperator<float> f2(1.4, 2.3);
	std::cout << f2.Summ() << '\n';

	f2.Set_Right(f2.Get_Right() + 1.3);
	std::cout << f2.Get_left() << '+' << f2.Get_Right() << '=' << f2.Summ() << '\n';

	//MathOperator<bool> b;
	
	std::cout << 4 << '*' << 9 << '=' << MathOperator<int>(4,9).Multiply() << '\n';
	//при работе с шаблонными классами нет запретов на использование анонимных объектов
	//при создании анонимного объекта от шаблонного класса так же указывается его специализация


	PrintSumm(MathOperator<int>(4, 9));

	const MathOperator<int> int_m(1, 54);
	PrintSumm(int_m);
	//PrintSumm(f2); невозможно т.к. в функции упомянута конкретная реализация

	PrintMultiply(f);
	PrintMultiply(int_m);
	PrintMultiply(MathOperator<char>('4', '*'));
	PrintMultiply(MathOperator<bool>(true,false));


	return 0;
}