// Курсовой проект: Разработка программного игрового приложения на основе сюжетов музыкальных композиций группы «Король и Шут»
// Студент: Григорьева Р. И., группа ПИ-51.

#include "Item.hpp"
#include "Inventory.hpp"
#include "Player.hpp"

int main() {
	Player player("Ivan", 100);
	player.TakeDamage(50);
	player.Heal(30);

	player.TakeDamage(130);
	player.Heal(120);

	return 0;
}