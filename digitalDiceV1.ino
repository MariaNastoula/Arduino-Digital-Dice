
const int A = 8; //set arduino digital pin 8 to segment display pin A (pin 7)
const int B = 7; //set arduino digital pin 7 to segment display pin B (pin 6) 
const int C = 6; //set arduino digital pin 6 to segment display pin C (pin 4) 
const int D = 5; //set arduino digital pin 5 to segment display pin D (pin 2) 
const int E = 4; //set arduino digital pin 4 to segment display pin E (pin 1) 
const int F = 9; //set arduino digital pin 9 to segment display pin F (pin 9) 
const int G = 10; //set arduino digital pin 10 to segment display pin G (pin 10)
const int DP = 2; //set arduino digital pin 2 to segment display pin DP (pin 5)

//a matrix with the states of each segment to create display 0-9 
const byte segments[10][7] = {
  {LOW,LOW,LOW,LOW,LOW,LOW,HIGH},
  {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH},
  {LOW,LOW,HIGH,LOW,LOW,HIGH,LOW},
  {LOW,LOW,LOW,LOW,HIGH,HIGH,LOW},
  {HIGH,LOW,LOW,HIGH,HIGH,LOW,LOW},
  {LOW,HIGH,LOW,LOW,HIGH,LOW,LOW},
  {LOW,HIGH,LOW,LOW,LOW,LOW,LOW},
  {LOW,LOW,LOW,HIGH,HIGH,HIGH,HIGH},
  {LOW,LOW,LOW,LOW,LOW,LOW,LOW},
  {LOW,LOW,LOW,LOW,HIGH,LOW,LOW}
};

int randomNum; //saves the generated random number

//set the pin states for segment display
void number(int num){
  digitalWrite(A, segments[num][0]);
  digitalWrite(B, segments[num][1]);
  digitalWrite(C, segments[num][2]);
  digitalWrite(D, segments[num][3]);
  digitalWrite(E, segments[num][4]);
  digitalWrite(F, segments[num][5]);
  digitalWrite(G, segments[num][6]);
}

void setup() {
  randomSeed(analogRead(A0)); //reads the noise from arduino analog pin A0 to seed the random number generator
  pinMode(A,OUTPUT); //set arduino digital pin 8 as output
  pinMode(B,OUTPUT); //set arduino digital pin 7 as output
  pinMode(C,OUTPUT); //set arduino digital pin 6 as output
  pinMode(D,OUTPUT); //set arduino digital pin 5 as output
  pinMode(E,OUTPUT); //set arduino digital pin 4 as output
  pinMode(F,OUTPUT); //set arduino digital pin 9 as output
  pinMode(G,OUTPUT); //set arduino digital pin 10 as output
  pinMode(DP,OUTPUT); //set arduino digital pin 2 as output
}

void loop() {
  //display 10 numbers rapidly
    for(int i=0; i<10; i++){
    randomNum = random(1,6);
    number(randomNum);
    delay(100);
  }
  //display the final number - dice result
  randomNum = random(1,6);
  number(randomNum);
  delay(2000);
}
