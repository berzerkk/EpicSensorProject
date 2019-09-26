int yValues[4] = {0, 10, 20, 30};
int xValues[4] = {265, 360, 462, 560};

//AUTO CALL ON STARTUP
void setup() {
  Serial.begin(9600);
}

// void getMultipiecewise() {

// }

float getTemperature(int value) { 
  int i;
  for (i = 0; value > xValues[i] && i < 4; i++);
  i = i > 0 ? i - 1 : i;
  return yValues[i] + ((value - xValues[i]) / (float)(xValues[i + 1] - xValues[i])) * (yValues[i + 1] - yValues[i]);
  //return map(value, xValues[i], xValues[i + 1], yValues[i], yValues[i + 1]);
}

void loop() {
  int value = analogRead(A0);
  Serial.println(getTemperature(value));
  delay(1);
}