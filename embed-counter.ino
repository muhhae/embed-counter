const int segments[7] = {14, 27, 33, 25, 26, 12, 13};

void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(segments[i], OUTPUT);
    }
    pinMode(22, INPUT)
    pinMode(23, INPUT)
}

const int pattern[10][7] = {
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 1, 0, 0}  // 9
};

void showNumber(int n) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segments[i], pattern[n][i]);
    }
}

int n = 0;

void loop() {
    if (!digitalRead(22)) {
        n--;
    }
    if (!digitalRead(23)) {
        n++;
    }
    if (n > 9) {
        n = 0;
    }
    if (n < 0) {
        n = 9
    }
    showNumber(n);
}
