import java.lang.ref.WeakReference;

public class Main {
    public static void main(String[] args) {
        // 1. Композиция и агрегация, срабатывание проверки правила.
        System.out.println("=== Композиция, агрегация, проверка правила ===");
        Item sword = new Item("Старый меч", 15);   // создан снаружи -> агрегация
        Item potion = new Item("Зелье", 0);

        // Игрок сам создаёт свой инвентарь -> композиция.
        try (Player player = new Player("Странник", 80, 2)) {
            player.addItem(sword);
            player.addItem(potion);
            System.out.println(player);

            try {
                player.addItem(new Item("Лишний щит", 5));
            } catch (IllegalStateException e) {
                System.out.println("Правило сработало: " + e.getMessage());
            }
            System.out.println("Ресурс ещё открыт внутри блока: " + player);
        }
        System.out.println("Блок try-with-resources завершён.");

        // 2. Ссылки и копии.
        System.out.println();
        System.out.println("=== Ссылки и копии ===");
        Player first = new Player("Рыцарь", 100, 3);
        Player second = first;
        second.takeDamage(30);
        System.out.println("Через first: " + first);
        System.out.println("first == second: " + (first == second));
        first.close();

        // 3. Сборщик мусора.
        System.out.println();
        System.out.println("=== Сборщик мусора ===");
        Item temp = new Item("Списанный предмет", 1);
        WeakReference<Item> watcher = new WeakReference<>(temp);
        System.out.println("Объект жив: " + (watcher.get() != null));

        temp = null;
        System.out.println("Ссылок не осталось, но GC ещё не вызывали: "
                + (watcher.get() != null));

        System.gc();
        System.out.println("После System.gc(): " + (watcher.get() != null));
    }
}
