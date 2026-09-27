// Курсовой проект: Разработка программного игрового приложения на основе сюжетов музыкальных композиций группы «Король и Шут»
// Студент: Григорьева Р. И., группа ПИ-51.

#include "Item.hpp"
#include "Inventory.hpp"
#include "Player.hpp"

int main() {
	Inventory inventory(3);
	Item sword("f", 4);
	Item item("g", 0);
	Item it("k", 7);
	Item itemitem("l", 9);

	inventory.AddItem(sword);
	inventory.AddItem(item);
	inventory.AddItem(it);
	inventory.AddItem(itemitem);

	sword.Inspect();
	return 0;
}