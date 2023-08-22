
// Blynk device template information
#define BLYNK_TEMPLATE_ID           "TMPL2FEVyWppL"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "3e8SJ427t5bXDpBCkXc1ni6jjobGn-lp"

// Blynk prints, can be commented out.
#define BLYNK_PRINT Serial

//Pins for the LEDs
#define BLUE 5
#define RED 6
#define WHITE 7

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

//Baud rate for ESP8266 ((data rate in bits per second))
#define ESP8266_BAUD 115200



#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include "ZeldaLullaby.h"

//WIFI Credentials
char ssid[] = "Verizon-SM-G955U-1B9A";
char pass[] = "llhw778*";

// change this to make the song slower or faster
int tempo = 108;

// change this to whichever pin you want to use
int buzzer = 9;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  
  // Zelda's Lullaby - The Legend of Zelda Ocarina of Time. 
  // Score available at https://musescore.com/user/12754451/scores/2762776
  
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,2, NOTE_C4,8, NOTE_D4,8, 
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,-2,
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D5,2, NOTE_C5,4,
  NOTE_G4,2, NOTE_F4,8, NOTE_E4,8, 
  NOTE_D4,-2,
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,2, NOTE_C4,8, NOTE_D4,8, 
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,-2,
  NOTE_E4,2, NOTE_G4,4,

  NOTE_D5,2, NOTE_C5,4,
  NOTE_G4,2, NOTE_F4,8, NOTE_E4,8, 
  NOTE_F4,8, NOTE_E4,8, NOTE_C4,2,
  NOTE_F4,2, NOTE_E4,8, NOTE_D4,8, 
  NOTE_E4,8, NOTE_D4,8, NOTE_A3,2,
  NOTE_G4,2, NOTE_F4,8, NOTE_E4,8, 
  NOTE_F4,8, NOTE_E4,8, NOTE_C4,4, NOTE_F4,4,
  NOTE_C5,-2, 
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;


int ledState = 0;

//Software Serial for Uno R3
SoftwareSerial EspSerial(2, 3);

//Define baud rate
ESP8266 wifi(&EspSerial);


BlynkTimer timer;


typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
} task;

int delay_gcd;
const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum SM1_States { SM1_INIT, SM1_S0, SM1_S1};
int SM1_Tick(int state){
  switch (state) {  // State transitions
    case SM1_INIT:
      state = SM1_S0;
      break;
    case SM1_S0:
      state = SM1_S0;
      break;
    case SM1_S1:
      break;
  }
  switch (state) {  // State Action
    case SM1_INIT:
      break;
    case SM1_S0:
      Blynk.run();
      break;
    case SM1_S1:
      break;
  }
  return state;
}

enum SM2_States { SM2_INIT, SM2_S0, SM2_S1};
int SM2_Tick(int state){
  switch (state) {  
    case SM2_INIT:
      state = SM2_S0;
      break;
    case SM1_S0:
      state = SM1_S0;
      break;
    case SM2_S1:
      break;
  }
  switch (state) {  
    case SM2_INIT:
      break;
    case SM2_S0:
      timer.run();
      break;
    case SM2_S1:
      break;
  }
  return state;
}


BLYNK_WRITE(V1) {
  ledState = param.asInt(); 
  ledControl();
  Serial.print("ledState after digitalWrite: ");
  Serial.println(ledState);
}

void ledControl(){
  if (ledState == 0) {
    digitalWrite(RED,LOW);
    digitalWrite(BLUE,LOW);
    digitalWrite(WHITE,LOW);
  } else {
    digitalWrite(RED,HIGH);
    digitalWrite(BLUE,HIGH);
    digitalWrite(WHITE,HIGH);
    song();
  }
}

void song(){
    // iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration*0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    
    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void lightShow()
{
  unsigned long previousMillis = 0;  // Variable to store the previous time
  const unsigned long interval = 500;  // Interval between LED state changes (in milliseconds)
  int ledStat = LOW;  // Initial LED state

  while (ledState == 1) {
    unsigned long currentMillis = millis();  // Get the current time

    if (currentMillis - previousMillis >= interval) {
      // It's time to change the LED state
      previousMillis = currentMillis;  // Save the current time

      // Toggle the LED state
      ledStat = (ledStat == LOW) ? HIGH : LOW;

      // Set the LED state for all three LEDs
       if (ledState == 1) {
      digitalWrite(RED, ledStat);
      digitalWrite(BLUE, ledStat);
      digitalWrite(WHITE, ledStat);
       }
    }
  }
  }

void playZeldaLullaby() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
}

void setup()
{


  Serial.begin(115200);
  
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);


  unsigned char i = 0;
  tasks[i].state = SM1_INIT;
  tasks[i].period = 500;
  tasks[i].elapsedTime = tasks[i].period;
  tasks[i].TickFct = &SM1_Tick;
  i++;
  tasks[i].state = SM2_INIT;
  tasks[i].period = 500;
  tasks[i].elapsedTime = tasks[i].period;
  tasks[i].TickFct = &SM2_Tick;

  delay_gcd = 500; 
  
}

void loop()
{

  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
     if ( tasks[i].elapsedTime >= tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = 0; 
     }
     tasks[i].elapsedTime += delay_gcd;
   }
   delay(delay_gcd);


}



