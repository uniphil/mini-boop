#define DEMUX_A 10
#define DEMUX_B 9
#define DEMUX_EN 8

#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3

const uint8_t rows[4] = {ROW1, ROW2, ROW3, ROW4};


void setup() {
  pinMode(DEMUX_A, OUTPUT);
  pinMode(DEMUX_B, OUTPUT);
  pinMode(DEMUX_EN, OUTPUT);
  digitalWrite(DEMUX_EN, HIGH);

  pinMode(ROW1, OUTPUT);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    bool flash = millis() & 0b10000000;
    digitalWrite(DEMUX_A, i & 0b01);
    digitalWrite(DEMUX_B, i & 0b10);
    for (int r = 0; r < 4; r++) {
      pinMode(rows[r], INPUT);
      if (flash && digitalRead(rows[r])) {
        pinMode(rows[r], OUTPUT);
      }
    }
    delay(1);
  }
}
