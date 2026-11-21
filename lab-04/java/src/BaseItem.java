
public abstract class BaseItem {
    protected final String name;

    protected BaseItem(String name) {
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Название предмета не может быть пустым");
        }

        this.name = name;

        System.out.println("Создан объект: " + name);
    }

    protected BaseItem() {
        this("Объект по умолчанию");
    }

    protected BaseItem(BaseItem other) {
        this(other.name);
    }

    public String getName() {
        return name;
    }

    public abstract void use();

    public String describe() {
        return "Предмет: " + name;
    }

    public void inspect() {
        System.out.println(describe());
    }

    @Override
    public String toString() {
        return describe();
    }
}

