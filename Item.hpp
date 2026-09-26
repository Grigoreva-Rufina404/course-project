#pragma once

#include <string>

class Item {
private:
	std::string name;
	int damage;

public:
	Item(std::string name, int damage);
	~Item();

	void Inspect();
};