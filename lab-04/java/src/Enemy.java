public class Enemy {
    private final String name;
    private final EnemyStats stats;

    private static int createdEnemies = 0;

    public Enemy(String name, EnemyStats stats) {
        this.name = name;
        this.stats = stats;

        createdEnemies++;
    }

    // Конструктор глубокого копирования
    public Enemy(Enemy other) {
        this(other, true);
    }

    // Конструктор копирования с выбором типа копирования
    public Enemy(Enemy other, boolean deepCopy) {
        this.name = other.name;

        if(deepCopy) {
            this.stats = new EnemyStats(other.stats);
        } else {
            this.stats = other.stats;
        }

        createdEnemies++;
    }

    public String getName() {
        return name;
    }

    public int getDamage() {
        return stats.getDamage();
    }

    public void setDamage(int damage) {
        stats.setDamage(damage);
    }

    public int getDefense() {
        return stats.getDefense();
    }

    public void setDefense(int defense) {
        stats.setDefense(defense);
    }

    public static int getCreatedEnemies() {
        return createdEnemies;
    }

    public void describe() {
        System.out.println("Противник: " + name + ", урон: " + stats.getDamage() + ", защита: " + stats.getDefense());
    }
}