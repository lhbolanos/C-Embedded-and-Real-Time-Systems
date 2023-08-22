#ifndef ZELDA_LULLABY_H
#define ZELDA_LULLABY_H

#include <Arduino.h>

// Notes and durations
#define NOTE_B0  31
#define NOTE_C1  33
// Rest of the note declarations...

// Tempo and buzzer pin
extern int tempo;
extern int buzzer;

// Melody and notes
extern int melody[];
extern int notes;
extern int wholenote;
extern int divider;
extern int noteDuration;

// Function declarations
void playZeldaLullaby();

#endif
