public class Weapon extends BaseItem {
    private final int damage;

    public Weapon(String name, int damage) {
        super(name);

        if (damage < 0) {
            System.out.println("ОШИБКА: урон не может быть отрицательным. Урон установлен 0");
            this.damage = 0;
        } else {
            this.damage = damage;
        }
    }

    public Weapon() {
        super();
        this.damage = 5;
    }

    @Override
    public void use() {
        System.out.println("Использовано оружие: " + name + ", урон: " + damage);
    }

    @Override
    public String describe() {
        return super.describe() + ", урон: " + damage;
    }

    public int getDamage() {
        return damage;
    }
}