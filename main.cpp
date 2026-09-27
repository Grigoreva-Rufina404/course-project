// Курсовой проект: Разработка программного игрового приложения на основе сюжетов музыкальных композиций группы «Король и Шут»
// Студент: Григорьева Р. И., группа ПИ-51.

#include "Item.hpp"
#include "Inventory.hpp"
#include "Player.hpp"

int main() {
	// Агрегация:
	// Item создаются отдельно от Player и Inventory
	Item sword1("Rusty sword", 5);
	Item sword2("Sharp blade", 30);
	Item potion("Regeneration potion", 0);
	Item book("Tales of the Headless One", 0);

	{
		// Композиция:
		// Player содержит Inventory внутри себя с вместимостью 3
		Player player("Ivan", 100, 3);

		// Агрегация:
        // уже существующие Item передаются Player -> Inventory
		player.AddItem(sword1);
		player.AddItem(sword2);
		player.AddItem(potion);

		// Состояние инвентаря
		player.ShowInventory();

		// Попытка нарушить правило вместимости
		player.AddItem(book);

		// Состояние инвентаря
		player.ShowInventory();

		// Работа с состоянием Player
		player.TakeDamage(40);
		player.Heal(20);

		// Попытка нарушить правило наносимого урона/восстановленного здоровья
		player.TakeDamage(120);
		player.Heal(180);
	}
	// Player и его Inventory уничтожены
	// Предметы продолжают существовать
	book.Inspect();
	sword2.Use();

	// Динамический объект
		Item* dynamicItem = new Item("Dynamic sword", 10);
		
		dynamicItem->Inspect();
		
		delete dynamicItem;

	// Динамический массив объектов
		Item* items = new Item[3];

		items[0].Inspect();
		items[1].Use();

		delete[] items;

		// Массив динамических объектов
		Item* itemsPointers[2];

		itemsPointers[0] = new Item("Axe", 8);
		itemsPointers[1] = new Item("Stone", 2);

		itemsPointers[0]->Use();
		itemsPointers[1]->Inspect();

		delete itemsPointers[0];
		delete itemsPointers[1];

	return 0;
}