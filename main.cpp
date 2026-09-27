// Курсовой проект: Разработка программного игрового приложения на основе сюжетов музыкальных композиций группы «Король и Шут»
// Студент: Григорьева Р. И., группа ПИ-51.

#include "Item.hpp"
#include "Inventory.hpp"

int main() {
	Item sword("Rusty sword", 5);
	Item potion_r("Regeneration potion", 0);

	Inventory inventory;

	inventory.AddItem(sword);
	inventory.AddItem(potion_r);

	Item potion_s("Potion of strength", 0);
	inventory.AddItem(potion_s);

	return 0;
}