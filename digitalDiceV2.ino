
const int A = 8; //initialize arduino digital pin 8 as the pin A - 7 of 7 segment display pin
const int B = 7; //initialize arduino digital pin 7 as the pin B - 6 of 7 segment display pin
const int C = 6; //initialize arduino digital pin 6 as the pin C - 4 of 7 segment display pin
const int D = 5; //initialize arduino digital pin 5 as the pin D - 2 of 7 segment display pin
const int E = 4; //initialize arduino digital pin 4 as the pin E - 1 of 7 segment display pin
const int F = 9; //initialize arduino digital pin 9 as the pin F - 9 of 7 segment display pin
const int G = 10; //initialize arduino digital pin 10 as the pin G - 10 of 7 segment display pin
const int DP = 2; //initialize arduino digital pin 2 as the pin DP - 5 of 7 segment display pin
const int BUTTON_PIN = 12; // initialize arduino digital pin 12 as button pin

//create a matrix with the status of each segment display's pin to create numbers 0-9 
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

int randomNum; //create a variable that saves the random number that prints 
int currentButtonState;
int prevButtonState;

//set the status to each pin of segment display
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
  randomSeed(analogRead(A0)); //reads the sound from arduino analog pin A0 so that the numbers are created randomly everytime
  pinMode(BUTTON_PIN, INPUT_PULLUP); //set arduino digital pin 12 as inpur with internal pull-up resistor
  pinMode(A,OUTPUT); //set arduino digital pin 8 as output
  pinMode(B,OUTPUT); //set arduino digital pin 7 as output
  pinMode(C,OUTPUT); //set arduino digital pin 6 as output
  pinMode(D,OUTPUT); //set arduino digital pin 5 as output
  pinMode(E,OUTPUT); //set arduino digital pin 4 as output
  pinMode(F,OUTPUT); //set arduino digital pin 9 as output
  pinMode(G,OUTPUT); //set arduino digital pin 10 as output
  pinMode(DP,OUTPUT); //set arduino digital pin 2 as output
  currentButtonState = digitalRead(BUTTON_PIN); //read the button state
}

void loop() {
  prevButtonState = currentButtonState; //set the previous button state
  currentButtonState = digitalRead(BUTTON_PIN); //read the curren button state
  // if button is pressed start the loop
  if(prevButtonState == HIGH && currentButtonState == LOW)
  {
    //for 20 times print random number to the screen before the last number that will be printed
      for(int i=0; i<20; i++){
      randomNum = random(1,6);
      number(randomNum);
      delay(100);
    }
    //display the final number
    randomNum = random(1,6);
    number(randomNum);
    delay(2000);
  }
  //otherwise blink the DP led while waiting button to be pressed
  else
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
    delay(500);
    digitalWrite(DP, LOW);
    delay(500);
  }
}
