package countStick;

public class Stick extends Laser{
    private final int end;

    public Stick(int start, int end)
    {
        super(start);
        this.end = end;
    }

    public int getEnd()
    {
        return end;
    }
}
