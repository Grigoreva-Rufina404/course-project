// Курсовой проект: Разработка программного игрового приложения на основе сюжетов музыкальных композиций группы «Король и Шут»
// Студент: Григорьева Р. И., группа ПИ-51.

#include "Item.hpp"
#include "Inventory.hpp"

int main() {
	Item sword("Rusty sword", 5);
	Item potion("Regeneration potion", 0);

	Inventory inventory;

	inventory.AddItem(sword);
	inventory.AddItem(potion);

	inventory.ShowInventory();

	inventory.RemoveItem();

	inventory.ShowInventory();

	inventory.RemoveItem();

	inventory.ShowInventory();

	inventory.RemoveItem();

	return 0;
}