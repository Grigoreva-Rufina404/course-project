import java.util.Objects;

public final class QuestItem extends BaseItem {

    public QuestItem(String name) {
        super(name);
    }

    public QuestItem() {
        super();
    }

    @Override
    public void use() {
        System.out.println("Квестовый предмет использован: " + name);
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj) {
            return true;
        }

        if(obj == null || getClass() != obj.getClass()) {
            return false;
        }

        QuestItem other = (QuestItem) obj;
        return Objects.equals(name, other.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}