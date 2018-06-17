// Setup Motor A (front and rear) pins
#define PIN_R1 5
#define PIN_R2 6
#define PIN_R_enable 3

// Setup Motor B (front and rear) pins
#define PIN_L1 9
#define PIN_L2 10
#define PIN_L_enable 11


//line follower
#define r_sensor A0
#define m_sensor A1
#define l_sensor A2
#define MAX 90
#define kp 15
#define kd 5

int speedA =MAX ;int speedB =MAX;
int lasterror = 0;
int error = 0;

void setup() {
  // Configure the pin modes for each drive motor
  pinMode (PIN_R1, OUTPUT);
  pinMode (PIN_R2, OUTPUT);
  pinMode (PIN_L1, OUTPUT);
  pinMode (PIN_L2, OUTPUT);
  pinMode (PIN_R_enable, OUTPUT);
  pinMode (PIN_L_enable, OUTPUT);
  digitalWrite (PIN_L_enable, HIGH);
  digitalWrite (PIN_R_enable, HIGH);
  //line follower setup
  pinMode (r_sensor, INPUT);
  pinMode (m_sensor, INPUT);
  pinMode (l_sensor, INPUT);
}

void loop() {
followLine();     
     
}
// Create motor functions

void motorAforward(int speed) {
  analogWrite (PIN_R1, speed);
  digitalWrite (PIN_R2, LOW);
}
void motorBforward(int speed) {
  digitalWrite (PIN_L1, LOW);
  analogWrite (PIN_L2, speed);
}
void motorAbackward(int speed) {
  digitalWrite (PIN_R1, LOW);
  analogWrite (PIN_R2, speed);
}
void motorBbackward(int speed) {
  analogWrite (PIN_L1, speed);
  digitalWrite (PIN_L2, LOW);
}
void motorAstop() {
  digitalWrite (PIN_R1, HIGH);
  digitalWrite (PIN_R2, HIGH);
}
void motorBstop() {
  digitalWrite (PIN_L1, HIGH);
  digitalWrite (PIN_L2, HIGH);
}
void motorAcoast() {
  digitalWrite (PIN_R1, LOW);
  digitalWrite (PIN_R2, LOW);
}
void motorBcoast() {
  digitalWrite (PIN_L1, LOW);
  digitalWrite (PIN_L2, LOW);
}

// Setup movement functions

void forward (int duration, int speed) {
  motorAforward(speed);
  motorBforward(speed);
  delay (duration);
}
void backward (int duration, int speed) {
  motorAbackward(speed);
  motorBbackward(speed);
  delay (duration);
}
void left (int duration, int speedA, int speedB) {
  motorAbackward(speedA);
  motorBforward(speedB);
  delay (duration);
}
void right (int duration, int speedA, int speedB) {
  motorAforward(speedA);
  motorBbackward(speedB);
  delay (duration);
}
void coast (int duration) {
  motorAcoast();
  motorBcoast();
  delay (duration);
}
void breakRobot (int duration) {
  motorAstop();
  motorBstop();
  delay (duration);
}
void followLine(){
 int sensor_R = digitalRead(r_sensor);
  int sensor_M = digitalRead(m_sensor);
  int sensor_L = digitalRead(l_sensor);
  lasterror = error;
   if(error == -1){
      right(1,speedA,speedB);
    }
    else if (error == 1 ){
      left(1,speedA,speedB);
    }
    else if(error == 0){
      forward(1,MAX);
    }
  if(sensor_R == 1 && sensor_M == 1 && sensor_L == 0){
    error = 2;
  }else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 0){
    error = 1;
  }else if(sensor_R == 1 && sensor_M == 0 && sensor_L == 1){
    error = 0;
  }else if(sensor_R == 0 && sensor_M == 0 && sensor_L == 1){
    error = -1;
  }else if(sensor_R == 0 && sensor_M == 1 && sensor_L == 1){
    error = -2;
  }else if(sensor_R == 1 && sensor_M == 1 && sensor_L == 1){
    error = 0;}
  if(error == -1){
      right(1,speedA,speedB);
    }
    else if (error == 1 ){
      left(1,speedA,speedB);
    }
    else if(error == 0){
      forward(1,MAX);
    }
  
  
 ////////////////////////////////  INVERTED LOGIC     MOTORA --- > right
 speedA = MAX - error*kp - kd*lasterror;
 speedB = MAX + error*kp + kd*lasterror;  
    }
