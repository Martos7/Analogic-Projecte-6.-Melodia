/******************************************************************************
**                                                                           **
**                              Projecte 6. Melodia                          **
**                                                                           **
**           c=DO, d=RE, e=MI, f=FA, g=SOL, a=LA, b=SI, C=DO' D=RE'          **
**                                                                           **
*******************************************************************************/
// Raúl Martos


const int speaker = 9; // Speaker pin 9
int time = 100;

// Himno del Real Madrid
int length = 60; 
 char notes[] = "efga Cbag fgbagfedegfedcefga Cbag fgbagfedegfedcefgaaaabbabC ";
 int beats[]={1,3,1,4,7,1,3,1,4,8,3,1,3,1,3,1,4,3,1,3,1,3,1,3,1,3,1,4,7,1,3,1,4,8,3,1,3,1,3,1,4,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,8};


void setup() {
  // make the pin output
  pinMode(speaker, OUTPUT); // speaker SALIDA
}


void loop() {
    for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * time);
    } else {
      playNote(notes[i], beats[i] * time);
    }
    
    delay(time / 2); // delay entre notes
  }
}
//****** Funcions *************************************************************
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speaker, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speaker, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' , 'D'};                     // Freqüència la qual es transforma en les lletres que nosaltres escribim
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 840};

  // play the tone corresponding to the note name
  for (int i = 0; i < 9; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

// Programa que reprodueix l'himne del Real MAdrid


