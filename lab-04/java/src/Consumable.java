public class Consumable extends BaseItem {
    private final int effect;
    private final EffectType type;

    public Consumable(String name, int effect, EffectType type) {
        super(name);

        if(effect < 0) {
            System.out.println("ОШИБКА: эффект не может быть отрицательным. Значение установлено 0");
            this.effect = 0;
        } else {
            this.effect = effect;
        }

        this.type = type;
    }

    public Consumable() {
        super();
        this.effect = 0;
        this.type = EffectType.HEALTH_RESTORATION;
    }

    private static String effectTypeToString(EffectType type) {
        switch (type) {
            case HEALTH_RESTORATION:
                return "Восстановление здоровья";
            case DEAL_DAMAGE:
                return "Нанесение урона";
            case INCREASE_ATTACK:
                return "Увеличение атаки";
            case DECREASE_ATTACK:
                return "Уменьшение атаки";
            default:
                return "Неизвестный эффект";
        }
    }

    @Override
    public void use() {
        System.out.println("Вы использовали расходный предмет: " + name);
        System.out.println("Эффект: " + effectTypeToString(type) + " " + effect);
    }

    @Override
    public String describe(){
        return "Расходный предмет: " + name + ", эффект: " + effectTypeToString(type) + ", значение: " + effect;
    }
}