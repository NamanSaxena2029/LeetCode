class Robot {
public:
    int w, h, steps;
    Robot(int width, int height) {
        w = width;
        h = height;
        steps = 0;
    }
    void step(int num) {
        int cycle = 2 * (w + h) - 4;
        steps = (steps + num) % cycle;
        if (steps == 0) steps = cycle;
    }
    vector<int> getPos() {
        int s = steps;
        if (s < w) return {s, 0};
        s -= w - 1;
        if (s < h) return {w - 1, s};
        s -= h - 1;
        if (s < w) return {w - 1 - s, h - 1};
        s -= w - 1;
        return {0, h - 1 - s};
    }
    string getDir() {
        int s = steps;
        if (s < w) return "East";
        s -= w - 1;
        if (s < h) return "North";
        s -= h - 1;
        if (s < w) return "West";
        return "South";
    }
};