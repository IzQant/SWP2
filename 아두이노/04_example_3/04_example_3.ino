#define PIN_LED 13
unsigned int count, toggle;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println("Hello World!");
  count = toggle = 0;
}

void loop() {
  Serial.println(++count);
  toggle = !toggle;
  digitalWrite(13, toggle);
  delay(1000);
  char ch = ' ';
  if (Serial.available()) {
    ch = Serial.read();
  }
  if (ch == 'q') exit(0);
}
