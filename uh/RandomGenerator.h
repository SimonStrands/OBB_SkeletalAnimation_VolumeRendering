#pragma once
#include <random>

class random{
public:
	static int getRandomInt(int min, int max){
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
		return (int)dist6(rng);
	}
	static float getRandomFloat(float min, float max){
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
		return (float)dist6(rng);
	}
};



