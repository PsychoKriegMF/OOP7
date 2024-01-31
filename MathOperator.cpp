#include "MathOperator.hpp"

void PrintSumm(const MathOperator<int>& obj) {
	std::cout << obj.Get_left() << '+' << obj.Get_Right() << '=' << obj.Summ() << '\n';
}