#include <iostream>
#include "Item.hpp"

Item::Item(std::string name, int damage)
	: name{name}
	, damage{damage}
{ 
}

Item::~Item() {
	std::cout << "The object is destroyed: " << name << '\n';
}

void Item::Inspect() {
	std::cout << "Item: " << name << '\n';
	std::cout << "Damage: " << damage << '\n';
}

void Item::Use() {
	std::cout << "You used the subject:" << name << '\n';
	std::cout << "Damage has been caused:" << damage << '\n';
}