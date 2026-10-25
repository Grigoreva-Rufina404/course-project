import java.lang.ref.WeakReference;

public class Main {
    public static void main(String[] args) {
        // Агрегация: Item создаются отдельно от Player и Inventory.
        Item sword1 = new Item("Rusty sword", 5);
        Item sword2 = new Item("Sharp blade", 30);
        Item potion = new Item("Regeneration potion", 0);
        Item book = new Item("Tales of the Headless One", 0);

        System.out.println();
        System.out.println("=== Композиция, агрегация, проверка правил ===");

        // Композиция: Player сам создаёт свой Inventory (вместимость 3).
        // Блок try-with-resources закроет игрока и его инвентарь автоматически.
        try (Player player = new Player("Ivan", 100, 3)) {
            // Агрегация: уже существующие Item передаются Player -> Inventory.
            player.addItem(sword1);
            player.addItem(sword2);
            player.addItem(potion);

            System.out.println(player);

            // Попытка нарушить правило вместимости.
            player.addItem(book);
            player.showInventory();

            // Работа с состоянием Player и попытка нарушить границы здоровья.
            player.takeDamage(40);
            player.heal(20);
            player.takeDamage(120);
            player.heal(180);
        }

        System.out.println("Блок try-with-resources завершён, ресурсы освобождены.");

        // Player и его Inventory закрыты, а предметы продолжают существовать.
        book.inspect();
        sword2.use();

        System.out.println();
        System.out.println("=== Ссылки и копии ===");

        Player first = new Player("Knight", 100, 1);
        Player second = first;
        second.takeDamage(30);
        System.out.println("Через first: " + first);
        System.out.println("first == second: " + (first == second));
        first.close();

        System.out.println();
        System.out.println("=== Сборщик мусора ===");

        Item temp = new Item("Temporary item", 1);
        WeakReference<Item> watcher = new WeakReference<>(temp);
        System.out.println("Объект жив: " + (watcher.get() != null));

        temp = null;
        System.out.println("Ссылок не осталось, но GC ещё не вызывали: "
                + (watcher.get() != null));

        System.gc();
        System.out.println("После System.gc(): " + (watcher.get() != null));
    }
}
