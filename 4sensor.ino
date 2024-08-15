#define IRS_1 A0
#define IRS_2 A1
#define IRS_3 A2
#define IRS_4 A3
// #define IRS_L A6
// #define IRS_R A7
#define MS 100  // motor speed

//right motor
const int enRM = 6;
const int RMP_1 = 8;
const int RMP_2 = 7;

//left motor
const int enLM = 5;
const int LMP_1 = 4;
const int LMP_2 = 3;



void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);


  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);


  MR(0, 0);
}



void loop() {
  //IR SENSOR READINGS
  int IR_1_reading = analogRead(IRS_1);
  int IR_2_reading = analogRead(IRS_2);
  int IR_3_reading = analogRead(IRS_3);
  int IR_4_reading = analogRead(IRS_4);


  int x = 200;

  //BLACK LINE
  if (IR_1_reading < x && IR_2_reading < x && IR_3_reading < x && IR_4_reading < x) {
    MR(MS, MS);
  }
  //BLACK LEFT
  else if (IR_1_reading < x && IR_2_reading >= x && IR_3_reading < x && IR_4_reading < x) {
    MR(-MS, MS);
  }
  //BLACK RIGHT
  else if (IR_1_reading < x && IR_2_reading < x && IR_3_reading >= x && IR_4_reading < x) {
    MR(MS, -MS);
  }



  //WHITE LINE
  else if (IR_1_reading >= x && IR_2_reading >= x && IR_3_reading >= x && IR_4_reading >= x) {
    MR(MS, MS);
  }
  //WHITE LINE LEFT
  else if (IR_1_reading >= x && IR_2_reading < x && IR_3_reading >= x && IR_4_reading >= x) {
    MR(-MS, MS);
  }
  //WHITE LINE RIGHT
  else if (IR_1_reading >= x && IR_2_reading >= x && IR_3_reading < x && IR_4_reading >= x) {
    MR(MS, -MS);
  }



  // BLACK WHITE EDGE FOLLOWER
  else if (IR_1_reading >= x && IR_2_reading >= x && IR_3_reading < x && IR_4_reading < x) {
    MR(MS, MS);
  }
  //BLACK WHITE EDGE FOLLOWER (LEFT)
  else if (IR_1_reading >= x && IR_2_reading < x && IR_3_reading < x && IR_4_reading < x) {
    MR(-MS, MS);
  }
  //BLACK WHITE EDGE FOLLOWER (RIGHT)
  else if (IR_1_reading >= x && IR_2_reading >= x && IR_3_reading >= x && IR_4_reading < x) {
    MR(MS, -MS);
  }



  // WHITE BLACK EDGE FOLLOWER
  else if (IR_1_reading < x && IR_2_reading < x && IR_3_reading >= x && IR_4_reading >= x) {
    MR(MS, MS);
  }
  //WHITE BLACK EDGE FOLLOWER (LEFT)
  else if (IR_1_reading < x && IR_2_reading >= x && IR_3_reading >= x && IR_4_reading >= x) {
    MR(-MS, MS);
  }
  //WHITE BLACK EDGE FOLLOWER (RIGHT)
  else if (IR_1_reading < x && IR_2_reading < x && IR_3_reading < x && IR_4_reading >= x) {
    MR(MS, -MS);
  }


  // TROUBLESHOOTING

  else if (IR_1_reading < x && IR_2_reading >= x && IR_3_reading < x && IR_4_reading >= x) {
    MR(MS, MS);
  } else if (IR_1_reading >= x && IR_2_reading < x && IR_3_reading >= x && IR_4_reading < x) {
    MR(MS, MS);
  } else if (IR_1_reading < x && IR_2_reading >= x && IR_3_reading >= x && IR_4_reading < x) {
    MR(MS, MS);
  } else if (IR_1_reading >= x && IR_2_reading < x && IR_3_reading < x && IR_4_reading >= x) {
    MR(MS, MS);
  }

  else {
    MR(0, 0);
  }

  delay(3);


  int z = analogRead(A4);
  int y = analogRead(A5);
  int m = analogRead(A6);
  int n = analogRead(A7);
  if(z<=720 || y<=720){
    digitalWrite(9, HIGH);
  }
  else{
    digitalWrite(9, LOW);
  }

  if(m<=720 || n<= 720){
      digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10, LOW);
  }
}



void MR(int RMS, int LMS) {  //right motor speed

  if (RMS < 0) {
    digitalWrite(RMP_1, LOW);
    digitalWrite(RMP_2, HIGH);
    // analogWrite(enRM, 20);
    // analogWrite(enRM, abs(RMS));
  } else if (RMS > 0) {
    digitalWrite(RMP_1, HIGH);
    digitalWrite(RMP_2, LOW);
    // analogWrite(enRM, abs(RMS));
  } else {
    digitalWrite(RMP_1, LOW);
    digitalWrite(RMP_2, LOW);
    // analogWrite(enRM, abs(RMS));
  }


  if (LMS < 0) {
    digitalWrite(LMP_1, LOW);
    digitalWrite(LMP_2, HIGH);
    // analogWrite(enLM, 20);
    // analogWrite(enLM, abs(LMS));
  } else if (LMS > 0) {
    digitalWrite(LMP_1, HIGH);
    digitalWrite(LMP_2, LOW);
    // analogWrite(enLM, abs(LMS));
  } else {
    digitalWrite(LMP_1, LOW);
    digitalWrite(LMP_2, LOW);
    // analogWrite(enLM, abs(LMS));
  }
  // if(RMS<0&&LMS>0||RMS>0&&LMS<0){

  // analogWrite(enRM, MS-30);
  // analogWrite(enLM, MS-30);
  // }
  // else if(LMS == 0 && RMS==0){
  //   analogWrite(enRM, 0);
  //   analogWrite(enLM, 0);
  // }
  // else{
  //   analogWrite(enRM, MS);
  //   analogWrite(enLM, MS);
  // }
  analogWrite(enRM, abs(MS));
  analogWrite(enLM, abs(MS));
}
