import java.lang.ref.WeakReference;

public class Main {
    public static void main(String[] args) {
        // Агрегация: Item создаются отдельно от Player и Inventory.
        BaseItem sword1 = new Weapon("Ржавый меч", 5);
        BaseItem sword2 = new Weapon("Острый клинок", 30);
        BaseItem potion = new Consumable("Зелье регенерации", 50, EffectType.HEALTH_RESTORATION);
        BaseItem book = new QuestItem("Сказания о Безголовом");

        System.out.println();
        System.out.println("=== Композиция, агрегация, проверка правил ===");

        // Композиция: Player сам создаёт свой Inventory (вместимость 3).
        // Блок try-with-resources закроет игрока и его инвентарь автоматически.
        try (Player player = new Player("Иван", 100, 3)) {
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

        Player first = new Player("Рыцарь", 100, 1);
        Player second = first;
        second.takeDamage(30);
        System.out.println("Через first: " + first);
        System.out.println("first == second: " + (first == second));
        first.close();

        System.out.println();
        System.out.println("=== Поверхностное и глубокое копирование ===");

        // Создаём характеристики противника.
        EnemyStats originalStats = new EnemyStats();
        originalStats.setDamage(10);
        originalStats.setDefense(5);

        //Создаем исходного противника
        Enemy originalEnemy = new Enemy("Покойник", originalStats);

        //Поверхностная копия
        Enemy shallowCopy = new Enemy(originalEnemy, false);

        //Глубокая копия
        Enemy deepCopy = new Enemy(originalEnemy, true);

        System.out.println("\nИсходный противник:");
        originalEnemy.describe();

        System.out.println("\nПоверхностная копия:");
        shallowCopy.describe();

        System.out.println("\nГлубокая копия:");
        deepCopy.describe();

        System.out.println("\nИзменяем урон поверхностной копии:");
        shallowCopy.setDamage(50);

        System.out.println("Исходный противник:");
        originalEnemy.describe();

        System.out.println("Поверхностная копия:");
        shallowCopy.describe();

        System.out.println("\nИзменяем урон глубокой копии:");
        deepCopy.setDamage(100);

        System.out.println("Исходный противник:");
        originalEnemy.describe();

        System.out.println("Глубокая копия:");
        deepCopy.describe();

        System.out.println("\nВсего создано противников: " + Enemy.getCreatedEnemies());

        System.out.println();
        System.out.println("=== Сравнение объектов ===");

        QuestItem key1 = new QuestItem("Древний ключ");
        QuestItem key2 = new QuestItem("Древний ключ");
        QuestItem key3 = new QuestItem("Волшебная книга");

        System.out.println("key1 == key2: " + (key1 == key2));
        System.out.println("key1.equals(key2): " + key1.equals(key2));
        System.out.println("key1.equals(key3): " + key1.equals(key3));

        System.out.println("Хеш key1: " + key1.hashCode());
        System.out.println("Хеш key2: " + key2.hashCode());

        System.out.println();
        System.out.println("=== Сборщик мусора ===");

        BaseItem temp = new Weapon("Временный предмет", 1);
        WeakReference<BaseItem> watcher = new WeakReference<>(temp);
        System.out.println("Объект жив: " + (watcher.get() != null));

        temp = null;
        System.out.println("Ссылок не осталось, но GC ещё не вызывали: "
                + (watcher.get() != null));

        System.gc();
        System.out.println("После System.gc(): " + (watcher.get() != null));
    }
}
