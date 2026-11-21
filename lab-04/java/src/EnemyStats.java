public class EnemyStats {
    private int damage;
    private int defense;
    private final String description;

    public EnemyStats() {
        this.damage = 0;
        this.defense = 0;
        this.description = "Противник по умолчанию";
    }

    public EnemyStats(EnemyStats other) {
        this.damage = other.damage;
        this.defense = other.defense;
        this.description = other.description;
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    public int getDefense() {
        return defense;
    }

    public void setDefense(int defense) {
        this.defense = defense;
    }

    public String getDescription() {
        return description;
    }
}