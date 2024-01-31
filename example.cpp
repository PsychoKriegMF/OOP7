#pragma once
#include "example.hpp"


float Example::Workload() const
{
	float result{};
	for (size_t i = 0; i < a; i++)
	{
		result += b;
	}
	return result;
}
