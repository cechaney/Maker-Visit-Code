

//Number of registers
const int REGISTER_COUNT = 8;

//Pin connected to SER
const int SER = 8;

//Pin connected to the OE
const int OUTPUT_ENABLE = 9;

//Pin connected to RCLK
const int REGISTER_CLOCK = 10;

//Pin connected to SRCLK
const int SERIAL_CLOCK = 11;

//Pin connected to SRCLR
const int SERIAL_CLEAR = 12;

/*
//Binary notation for common CATHODE display
const int ZERO[] = {0,0,1,1,1,1,1,1}; 
const int ONE[] = {0,0,0,0,0,1,1,0};
const int TWO[] = {0,1,0,1,1,0,1,1};
const int THREE[] = {0,1,0,0,1,1,1,1};
const int FOUR[] = {0,1,1,0,0,1,1,0};
const int FIVE[] = {0,1,1,0,1,1,0,1};
const int SIX[] = {0,1,1,1,1,1,0,1};
const int SEVEN[] = {0,0,0,0,0,1,1,1};
const int EIGHT[] = {0,1,1,1,1,1,1,1};
const int NINE[] = {0,1,1,0,1,1,1,1};
const int DOT[] = {1,0,0,0,0,0,0,0};
const int OFF[] = {0,0,0,0,0,0,0,0};
*/

//Binary notation for common ANODE display
const int ZERO[] = {1,1,0,0,0,0,0,0}; 
const int ONE[] = {1,1,1,1,1,0,0,1};
const int TWO[] = {1,0,1,0,0,1,0,0};
const int THREE[] = {1,0,1,1,0,0,0,0};
const int FOUR[] = {1,0,0,1,1,0,0,1};
const int FIVE[] = {1,0,0,1,0,0,1,0};
const int SIX[] = {1,0,0,0,0,0,1,0};
const int SEVEN[] = {1,1,1,1,1,0,0,0};
const int EIGHT[] = {1,0,0,0,0,0,0,0};
const int NINE[] = {1,0,0,1,0,0,0,0};
const int DOT[] = {0,1,1,1,1,1,1,1};
const int OFF[] = {1,1,1,1,1,1,1,1};


const int DIGIT_DELAY = 1000;

void disableOutput(){
  digitalWrite(OUTPUT_ENABLE, HIGH);
}

void enableOutput(){
  digitalWrite(OUTPUT_ENABLE, LOW);
}

void clearDisplay(){
  
  disableOutput();

  digitalWrite(SER, LOW);

  digitalWrite(SERIAL_CLEAR, LOW);
  digitalWrite(SERIAL_CLEAR, HIGH);
  
  digitalWrite(REGISTER_CLOCK, HIGH);
  digitalWrite(REGISTER_CLOCK, LOW);
  
  enableOutput();

}

void draw(const int digit[]){

  Serial.println("Drawing...");

  for(int i = 0; i < REGISTER_COUNT; i++){
    Serial.println(digit[i]);
    loadRegister(digit[i]);
  }

  storeData();
 
}

void loadRegister(int value){

  Serial.println("Loading...");

  digitalWrite(SERIAL_CLOCK, LOW);
  digitalWrite(SER, value);
  digitalWrite(SERIAL_CLOCK, HIGH);
  digitalWrite(SERIAL_CLOCK, LOW);
  digitalWrite(SER, LOW);

}

void storeData(){

  digitalWrite(SERIAL_CLOCK, LOW);
  digitalWrite(SER, LOW);
  digitalWrite(REGISTER_CLOCK, HIGH);
  digitalWrite(REGISTER_CLOCK, LOW);

}

void setup() {
  
  //set pins to output because they are addressed in the main loop
  pinMode(SER, OUTPUT);
  pinMode(OUTPUT_ENABLE, OUTPUT);
  pinMode(REGISTER_CLOCK, OUTPUT);
  pinMode(SERIAL_CLOCK, OUTPUT);
  pinMode(SERIAL_CLEAR, OUTPUT);
  
  Serial.begin(9600);

  clearDisplay();

}

void loop() {

  draw(ZERO);
  delay(DIGIT_DELAY);

  draw(ONE);
  delay(DIGIT_DELAY);

  draw(TWO);
  delay(DIGIT_DELAY);

  draw(THREE);
  delay(DIGIT_DELAY);

  draw(FOUR);
  delay(DIGIT_DELAY);

  draw(FIVE);
  delay(DIGIT_DELAY);

  draw(SIX);
  delay(DIGIT_DELAY);

  draw(SEVEN);
  delay(DIGIT_DELAY);

  draw(EIGHT);
  delay(DIGIT_DELAY);               

  draw(NINE);
  delay(DIGIT_DELAY);                 

  draw(DOT);
  delay(DIGIT_DELAY);

}
  

