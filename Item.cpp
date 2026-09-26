#include <iostream>
#include "Item.hpp"

Item::Item(std::string name, int damage)
	: name{name}
	, damage{damage}
{ 
}

void Item::Inspect() {
	std::cout << "Item: " << name << '\n';
	std::cout << "Damage: " << damage << '\n';
}