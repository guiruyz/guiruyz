//Firmaware development by @guiruyz

// pin definition:
int pwm_out1 = 3;
int transd_pin = A5;
int pb_1 = 4; // push button 
int pb_2 = 5; // push button 
int pb_3 = 6; // push button 
//////////////////////////////////////////////////
float var_pwm;
int value = 0;
float intensity_pwm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char *msg = (char *)calloc(16,1);
  pinMode(pb_1, INPUT_PULLUP);
  pinMode(pb_2, INPUT_PULLUP);
  pinMode(pb_3, INPUT_PULLUP);

  wile (1) {
  Serial.print("Please insert mode: \n Button 1: Manual \n Button 2: Auto");
  if (digitalRead(pb_1) == LOW){
    while ((pb_1) == LOW);
    Manual ()
  }
  if (digitalRead(pb_2) == LOW) {
    while ((pb_2) == LOW);
    Auto()
  }
  }  
}
void Manual () {
Serial.print("Set paramters: \n Button 1: Increase intensity \n Button 2: Decrease intensity");
  while (1);
  if (digitalRead(pb_1) == LOW) && (intensity_pwm < 100) {
  intensity_pwm = intensity_pwm + 0.25; 
  }
  if (digitalRead(pb_2) == LOW) && (intensity_pwm > 100) {
  intensity_pwm = intensity_pwm - 0.25; 
  }
  if (digitalRead(pb_3) == LOW) {
  setup()
  }
  var_pwm = intensity _pwm * 255;
  analogWrite(pwm_out1, var_pwm);
  snprintf(msg, 16 , "Value: %d \n", value);
  Serial.print(msg);
}
void Auto() {
  // put your main code here, to run repeatedly:
  char *msg = (char *)malloc(16); 
  var_pwm = 255; 
  while (1){
  value = analogRead(transd_pin);
  pinMode (pwm_out1 , OUTPUT);
  delay(1000);
  if (value >= 890 ) {
    var_pwm = 15;
  }
  if (value < 890) {
    var_pwm = 255;
  }
  analogWrite(pwm_out1, var_pwm);
  snprintf(msg, 16 , "Value: %d \n", value);
  Serial.print(msg);
  }
}































