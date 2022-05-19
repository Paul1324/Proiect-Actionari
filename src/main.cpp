#include <Stepper.h>
#include <Arduino.h>
// Defines the number of steps per rotation
// const int stepsPerRevolution = 2038;
int stepsPerRevolution = 509;
const int stepperSpeed = 40;
#define uShapePin 7
#define echoPin 2
#define trigPin 3

const int button1 = 12;
const int button2 = 13;
const int button3 = 4;
const int button4 = 5;

long duration;
int distance;
int prev;
// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
// Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
class Elevator
{
  int firstLevel;
  int secondLevel;
  int thirdLevel;

public:
  Elevator()
  {
    this->firstLevel = 1;
    this->secondLevel = 1;
    this->thirdLevel = 1;
  }

  Elevator(int one, int two, int three)
  {
    this->firstLevel = one;
    this->secondLevel = two;
    this->thirdLevel = three;
  }

  void print()
  {

    Serial.print("-----------Gradul de ocupare al parcarii:-----------\n");
    Serial.print("Locul 1: ");
    if (this->firstLevel == 1)
    {
      Serial.println("Liber");
    }
    else
    {
      Serial.println("Ocupat");
    }
    Serial.print("\nLocul 2: ");
    if (this->secondLevel == 1)
    {
      Serial.println("Liber");
    }
    else
    {
      Serial.println("Ocupat");
    }
    Serial.print("\nLocul 3: ");
    if (this->thirdLevel == 1)
    {
      Serial.println("Liber");
    }
    else
    {
      Serial.println("Ocupat");
    }
    Serial.print("\n-----------------------------------------------------\n");
  }

  void rise(Stepper myStepper, int park, int level = -1)
  {

    if (level == -1)
    {
      if (this->firstLevel == park)
      {
        distance = 120;
        Serial.print("Se asteapta parcarea masinii\n");
        while (distance >= 10)
        {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);

          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);

          duration = pulseIn(echoPin, HIGH);
          distance = duration * 0.034 / 2;
        }
        delay(2000);
        this->firstLevel = 0;
      }
      else if (this->secondLevel == park)
      {
        int k = 0;
        myStepper.setSpeed(stepperSpeed);
        int prev = 1;
        while (k < 1)
        {
          myStepper.step(-stepsPerRevolution);
          int value = digitalRead(uShapePin);
          if (prev == 0 && value == 1)
          {
            k++;
          }
          prev = value;
        }

        Serial.print("Se asteapta parcarea masinii\n");
        distance = 120;
        while (distance >= 10)
        {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);

          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);

          duration = pulseIn(echoPin, HIGH);
          distance = duration * 0.034 / 2;
        }
        delay(2000);

        this->secondLevel = 0;
        Serial.print("Platforma coboara\n");
        fall(2, myStepper);
      }
      else if (this->thirdLevel == park)
      {
        int k = 0;
        myStepper.setSpeed(stepperSpeed);
        int prev = 1;
        while (k < 2)
        {
          myStepper.step(-stepsPerRevolution);
          int value = digitalRead(uShapePin);
          if (prev == 0 && value == 1)
          {
            k++;
          }
          prev = value;
        }
        Serial.print("Se asteapta parcarea masinii\n");
        distance = 120;
        while (distance >= 10)
        {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);

          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);

          duration = pulseIn(echoPin, HIGH);
          distance = duration * 0.034 / 2;
        }
        delay(2000);

        this->thirdLevel = 0;
        Serial.print("Platforma coboara\n");
        fall(3, myStepper);
      }
    }
    else
    {
      if (level == 1)
      {
        Serial.print("Se asteapta iesirea masinii\n");
        distance = 120;
        while (distance >= 10)
        {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);

          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);

          duration = pulseIn(echoPin, HIGH);
          distance = duration * 0.034 / 2;
        }
        delay(2000);
        this->firstLevel = 1;
      }
      else if (level == 2)
      {
        int k = 0;
        myStepper.setSpeed(stepperSpeed);
        int prev = 1;
        while (k < 1)
        {
          myStepper.step(-stepsPerRevolution);
          int value = digitalRead(uShapePin);
          if (prev == 0 && value == 1)
          {
            k++;
          }
          prev = value;
        }

        Serial.print("Se asteapta iesirea masinii\n");
        distance = 120;
        while (distance >= 10)
        {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);

          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);

          duration = pulseIn(echoPin, HIGH);
          distance = duration * 0.034 / 2;
        }
        delay(2000);

        this->secondLevel = 1;
        Serial.print("Platforma coboara\n");
        fall(2, myStepper);
      }
      else if (level == 3)
      {
        int k = 0;
        myStepper.setSpeed(stepperSpeed);
        int prev = 1;
        while (k < 2)
        {
          myStepper.step(-stepsPerRevolution);
          int value = digitalRead(uShapePin);
          if (prev == 0 && value == 1)
          {
            k++;
          }
          prev = value;
        }

        Serial.print("Se asteapta iesirea masinii\n");
        distance = 120;
        while (distance >= 10)
        {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);

          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);

          duration = pulseIn(echoPin, HIGH);
          distance = duration * 0.034 / 2;
        }
        delay(2000);

        this->thirdLevel = 1;
        Serial.print("Platforma coboara\n");
        fall(3, myStepper);
      }
    }
  }

  void fall(int currentLevel, Stepper myStepper)
  {
    if (currentLevel == 2)
    {
      int k = 0;
      myStepper.setSpeed(stepperSpeed);
      int prev = 1;
      while (k < 1)
      {
        myStepper.step(stepsPerRevolution);
        int value = digitalRead(uShapePin);
        if (prev == 0 && value == 1)
        {
          k++;
        }
        prev = value;
      }
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
    }
    else if (currentLevel == 3)
    {
      int k = 0;
      myStepper.setSpeed(stepperSpeed);
      int prev = 1;
      while (k < 2)
      {
        myStepper.step(stepsPerRevolution);
        int value = digitalRead(uShapePin);
        if (prev == 0 && value == 1)
        {
          k++;
        }
        prev = value;
      }
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
    }
  }
};
Elevator lift(1, 1, 1);

void setup()
{

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop()
{

  int valButton1 = digitalRead(button1);
  int valButton2 = digitalRead(button2);
  int valButton3 = digitalRead(button3);
  int valButton4 = digitalRead(button4);

  if (valButton1)
  {

    Serial.print("Parcare masina (locul liber urca la nivelulu solului) \n");
    lift.rise(myStepper, 1);
    lift.print();
  }
  else if (valButton2)
  {
    Serial.print("Eliberare primul loc de parcare\n");
    lift.rise(myStepper, 1, 1);
    lift.print();
  }
  else if (valButton3)
  {

    Serial.print("Eliberare al doilea loc de parcare\n");
    lift.rise(myStepper, 1, 2);
    lift.print();
  }
  else if (valButton4)
  {

    Serial.print("Eliberare al treilea loc de parcare\n");
    lift.rise(myStepper, 1, 3);
    lift.print();
  }
}