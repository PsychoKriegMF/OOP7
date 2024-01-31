//при организации шаблонного класса в виде библиотеки требуется весь код, который является шаблоном, оставить в заголовочном файле. \
в файл реализации переносятся только те элементы, которые имеют полное определение. Например функции и вспомогательные клыссы которые не являются шаблонами

#pragma once

#ifndef MATH_OOPERATOR_HPP
#define MATH_OOPERATOR_HPP

#include <iostream>


template <typename Type>
class MathOperator {
public:
	//конструктор по умолчанию
	MathOperator() : operand_1(Type()), operand_2(Type()) {}
	//в создании полей используется Type() для совместимости с любым возможным хранимым типом

	//конструктор с параметром
	MathOperator(Type left, Type right) : operand_1(left), operand_2(right) {}

	//сеттеры принимают аргументы шаблонноготипа данных, это позволяет корректно занести информацию в поля того же шаблонного типа
	void Set_left(Type num) {
		operand_1 = num;
	}
	void Set_Right(Type num) {
		operand_2 = num;
	}

	//геттеры возвращают шаблонный тип чтобы не было конфликтов при возврате полей 
	Type Get_left() const {
		return operand_1;
	}

	Type Get_Right() const {
		return operand_2;
	}

	Type Summ() const {
		return operand_1 + operand_2;
	}

	Type Multiply() const {
		return operand_1 * operand_2;
	}
private:
	Type operand_1;
	Type operand_2;

};


template<>
class MathOperator<bool> {
public:
	MathOperator() : operand_1(false), operand_2(false) {}

	MathOperator(bool left, bool right) : operand_1(left), operand_2(right) {}

	void Set_left(bool num) {
		operand_1 = num;
	}
	void Set_Right(bool num) {
		operand_2 = num;
	}

	//геттеры возвращают шаблонный тип чтобы не было конфликтов при возврате полей 
	bool Get_left() const {
		return operand_1;
	}

	bool Get_Right() const {
		return operand_2;
	}

	bool Summ() const {
		return operand_1 || operand_2;
	}

private:
	bool operand_1;
	bool operand_2;
};

// обработка объектов шаблонного класса

//вариант 1
//обработка конкретной специализации

void PrintSumm(const MathOperator<int>& obj);


//вариант 2
//обработка обобщённого вида
template <typename T>
void PrintMultiply(const MathOperator<T>& obj) {
	std::cout << obj.Get_left() << '*' << obj.Get_Right() << '=' << obj.Multiply() << '\n';
}
//решение проблемы обработкой в специализации шаблона
template <>
void PrintMultiply<bool>(const MathOperator<bool>& obj) {
	//вариант 1 обработки: кидаем исключение
	//throw -1;  если так не делать то проблема с некорректным поведением программы может вылезти в будущем в непредсказуемый момент времени

	//вариант2 обработки: работаем с учетом особенностей входных данных
	std::cout << obj.Get_left() << '*' << obj.Get_Right() << '=' << " not allowed operations" << '\n';
}




#endif // !MATH_OOPERATOR_HPP

