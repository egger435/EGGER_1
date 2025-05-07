#include <Arduino.h>
#include <SoftwareSerial.h>
#define software_rx 2
#define software_tx 3

const int M1_IN3 = 6; // motor1
const int M1_IN4 = 7;
const int M2_IN1 = 4; // motor2
const int M2_IN2 = 5;

const int M3_IN3 = 10; // motor3
const int M3_IN4 = 11;
const int M4_IN1 = 8; // motor4
const int M4_IN2 = 9;

const int LED = 13;

// 蓝牙串口
SoftwareSerial JDY_16(software_rx, software_tx);
char JDY_dat;

void Forward();
void Back();
void Right();
void Left();
void Sleep();

void setup()
{
  Serial.begin(9600);
  JDY_16.begin(115200);
  pinMode(M1_IN3, OUTPUT);
  pinMode(M1_IN4, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M3_IN3, OUTPUT);
  pinMode(M3_IN4, OUTPUT);
  pinMode(M4_IN1, OUTPUT);
  pinMode(M4_IN2, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (JDY_16.available())
  {
    JDY_dat = JDY_16.read();
    Serial.println("receive data");
    Serial.println(JDY_dat);
    switch (JDY_dat)
    {
    case 'f':
      digitalWrite(LED, HIGH);
      // 前进
      Forward();
      break;
    case 'b':
      digitalWrite(LED, HIGH);
      // 后退
      Back();
      break;
    case 'r':
      digitalWrite(LED, HIGH);
      // 右转
      Right();
      break;
    case 'l':
      digitalWrite(LED, HIGH);
      // 左转
      Left();
      break;
    case 's':
      digitalWrite(LED, LOW);
      // 睡眠（停止）
      Sleep();
      break;
    default:
      break;
    }
  }
}

void Back()
{
  //m1 1 m2 1 m3 1 m4 1
  digitalWrite(M1_IN3, HIGH);
  digitalWrite(M1_IN4, LOW);

  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);

  digitalWrite(M3_IN3, LOW);
  digitalWrite(M3_IN4, HIGH);

  digitalWrite(M4_IN1, HIGH);
  digitalWrite(M4_IN2, LOW);
}

void Forward()
{
  //m1 0 m2 0 m3 0 m4 0
  digitalWrite(M1_IN3, LOW);
  digitalWrite(M1_IN4, HIGH);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);

  digitalWrite(M3_IN3, HIGH);
  digitalWrite(M3_IN4, LOW);

  digitalWrite(M4_IN1, LOW);
  digitalWrite(M4_IN2, HIGH);
}

void Left()
{
  //m1 0 m2 1 m3 0 m4 1
  digitalWrite(M1_IN3, LOW);
  digitalWrite(M1_IN4, HIGH);

  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);

  digitalWrite(M3_IN3, HIGH);
  digitalWrite(M3_IN4, LOW);

  digitalWrite(M4_IN1, HIGH);
  digitalWrite(M4_IN2, LOW);
}

void Right()
{
  //m1 1 m2 0 m3 1 m4 0
  digitalWrite(M1_IN3, HIGH);
  digitalWrite(M1_IN4, LOW);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);

  digitalWrite(M3_IN3, LOW);
  digitalWrite(M3_IN4, HIGH);

  digitalWrite(M4_IN1, LOW);
  digitalWrite(M4_IN2, HIGH);
}

void Sleep()
{
  digitalWrite(M1_IN3, LOW);
  digitalWrite(M1_IN4, LOW);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, LOW);

  digitalWrite(M3_IN3, LOW);
  digitalWrite(M3_IN4, LOW);

  digitalWrite(M4_IN1, LOW);
  digitalWrite(M4_IN2, LOW);
}