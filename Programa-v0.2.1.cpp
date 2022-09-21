//Firmaware development by @guiruyz
int pwm_out1 = 3;
int transd_pin = A1;
int var_pwm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char *msg = (char *)malloc(16); 
}

void loop() {
  // put your main code here, to run repeatedly:
  char *msg = (char *)malloc(16); 
  var_pwm = 255; 
  while (1){
  int value = analogRead(transd_pin);
  pinMode (pwm_out1 , OUTPUT);
  if (value >= 600 ) {
    var_pwm = 65;
  }
  analogWrite(pwm_out1, var_pwm);
  snprintf(msg, 16 , "Value: %d \n", value);
  Serial.print(msg);
  }
}