//Firmaware development by @guiruyz

// pin definition:
int pwm_out1 = 3;
int transd_pin = A1;
const int pb1 = 4;
const int pb2 = 5;
const int pb3 = 7;
//////////////////////////////////////////////////
int var_pwm;
int loop_v;
int value;
float intensity_pwm;
char *msg = (char *)calloc(16,1);

void manual_pwm(void);
  
void manual_pwm(){
  Serial.print("\n Set paramters: \n Button 1: Increase intensity \n Button 2: Decrease intensity");
  intensity_pwm = 1;
  loop_v = 1;
  while (loop_v == 1){
  	if (((digitalRead(pb1)) == LOW) && (intensity_pwm < 1)) {
  	intensity_pwm = intensity_pwm + 0.25;
  	}
  if (((digitalRead(pb2)) == LOW) && (intensity_pwm > 0)) {
  	intensity_pwm = intensity_pwm - 0.25; 
  	}
  if ((digitalRead(pb3)) == LOW) {
    	loop_v = 0;
  	}
  var_pwm = intensity_pwm * 255;
  analogWrite(pwm_out1, var_pwm);
  snprintf(msg, 16 , "\nValue: %d \n", var_pwm);
  Serial.print(msg);
  delay(500);
  }
}

void auto_pwm() {
  // put your main code here, to run repeatedly: 
  var_pwm = 255; 
  while (loop_v == 1){
  pinMode (pwm_out1 , OUTPUT);
  delay(1000);
  value = analogRead(transd_pin);
  snprintf(msg, 16 , "\nPWM:%d Anl:%d\n", var_pwm, value);
  Serial.print(msg);
  if ((analogRead(transd_pin)) >= 45 ) {
    var_pwm = 15;
  	}
  if ((analogRead(transd_pin)) < 45) {
    var_pwm = 255;
  	}
  if ((digitalRead(pb3)) == LOW) {
    loop_v = 0;
  }
    analogWrite(pwm_out1, var_pwm);
    delay(100);  
  }
}
void loop (){
  loop_v = 1;
  	if ((digitalRead(pb1)) == LOW){
    manual_pwm();
    Serial.print("\nPlease insert mode: \n Button 1: Manual \n Button 2: Auto");
  }
  if (digitalRead(pb2) == LOW) {
    auto_pwm();
	Serial.print("\nPlease insert mode: \n Button 1: Manual \n Button 2: Auto");  
  }
    if (digitalRead(pb3) == LOW) {
      if (var_pwm == 0){
      	var_pwm = 255;
        analogWrite(pwm_out1, var_pwm);
        Serial.print("\n Lights turn on\n");
      }
      else{
      	var_pwm = 0;
        analogWrite(pwm_out1, var_pwm);  
        Serial.print("\n Lights turn off\n");
      }
     delay(1000);
 
  }  
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (pb1, INPUT_PULLUP);
  pinMode (pb2, INPUT_PULLUP);
  pinMode (pb3, INPUT_PULLUP);
  pinMode(transd_pin, INPUT); 
  
  loop_v = 0;
  var_pwm = 0;
  
  Serial.print("Please insert mode: \n Button 1: Manual \n Button 2: Auto \n Button 3: Turn on/Turn off");
}