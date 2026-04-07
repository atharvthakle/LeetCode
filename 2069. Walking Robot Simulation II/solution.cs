public class Robot {

    private int width, height;
    private int x, y;
    private int dir; // 0=East, 1=North, 2=West, 3=South
    private int perimeter;

    public Robot(int width, int height) {
        this.width = width;
        this.height = height;
        this.x = 0;
        this.y = 0;
        this.dir = 0; // East
        this.perimeter = 2 * (width + height) - 4;
    }
    
    public void Step(int num) {
        num %= perimeter;

        // special case
        if (num == 0 && (x == 0 && y == 0)) {
            dir = 3; // South
            return;
        }

        while (num > 0) {
            if (dir == 0) { // East
                int move = Math.Min(num, width - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            }
            else if (dir == 1) { // North
                int move = Math.Min(num, height - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            }
            else if (dir == 2) { // West
                int move = Math.Min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            }
            else { // South
                int move = Math.Min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }
    }
    
    public int[] GetPos() {
        return new int[] { x, y };
    }
    
    public string GetDir() {
        string[] dirs = { "East", "North", "West", "South" };
        return dirs[dir];
    }
}
