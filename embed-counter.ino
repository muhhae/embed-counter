const int segments[7] = {32, 33, 21, 19, 18, 26, 25};

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 7; i++) {
        pinMode(segments[i], OUTPUT);
    }
    pinMode(22, INPUT);
    pinMode(23, INPUT);
}

const int patterns[10][7] = {
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
        digitalWrite(segments[i], patterns[n][i]);
    }
}

int n = 0;
bool changed = false;

void loop() {
    changed = false;
    Serial.printf("%d %d\n", digitalRead(22), digitalRead(23));
    if (digitalRead(22) == LOW) {
        n--;
        changed = true;
    } else if (digitalRead(23) == LOW) {
        n++;
        changed = true;
    }

    if (n > 9) {
        n = 0;
    } else if (n < 0) {
        n = 9;
    }

    showNumber(n);
    if (changed) delay(200);
}
