#define MOTOR_A 0
#define MOTOR_B 1

#define FORWARD  0
#define BACKWARD 1

const byte PWMA = 3;  // PWM control (speed) for motor A
const byte PWMB = 11; // PWM control (speed) for motor B
const byte DIRA = 2; // Direction control for motor A
const byte DIRB = 4; // Direction control for motor B

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  setupArdumoto();

}

void loop() {
  // put your main code here, to run repeatedly:
int leftPinRdg = analogRead(0);
int centerPinRdg = analogRead(1);
int rightPinRdg = analogRead(2);

Serial.print(leftPinRdg);
Serial.print("\t");
Serial.print(centerPinRdg);
Serial.print("\t");
Serial.print(rightPinRdg);
Serial.print("\t");

if(leftPinRdg>=900 && centerPinRdg<900 && rightPinRdg<900)
  {
  driveArdumoto(MOTOR_A,FORWARD,100);
  driveArdumoto(MOTOR_B,BACKWARD,75);  
  }

  if(leftPinRdg>=900 && centerPinRdg>=900 && rightPinRdg<900)
  {
  driveArdumoto(MOTOR_A,FORWARD,70);
  driveArdumoto(MOTOR_B,FORWARD,25);  
  }

  if(leftPinRdg<900 && centerPinRdg>=900 && rightPinRdg<900)
  {
  driveArdumoto(MOTOR_A,FORWARD,75);
  driveArdumoto(MOTOR_B,FORWARD,75);  
  }

  if(leftPinRdg<900 && centerPinRdg>=900 && rightPinRdg>=900)
  {
  driveArdumoto(MOTOR_A,FORWARD,25);
  driveArdumoto(MOTOR_B,FORWARD,70); 
  }

  if(leftPinRdg<900 && centerPinRdg<900 && rightPinRdg>=900)
  {
  driveArdumoto(MOTOR_A,BACKWARD,75);
  driveArdumoto(MOTOR_B,FORWARD,100);  
  }

}

void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}

// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}


void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}
