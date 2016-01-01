#ifndef MORSE_H_INCLUDED
#define MORSE_H_INCLUDED

int outputMorseCodeSentance(int gpioPin, char *sentance);

static const char DOT[1] = ".";
static const char DASH[1] = "-";
static const char SPACE[1] = " ";

static const char MORSE_CODE[][6] =
{
    " ",        // Space = 32
    "", "", "", "", "", "", "", // Not used
    "", "", "", "", "", "", "", // Not used
    "",                         // Not used
    "-----",    // 0 = 48
    ".----",    // 1
    "..---",    // 2
    "...--",    // 3
    "....-",    // 4
    ".....",    // 5
    "-....",    // 6
    "--...",    // 7
    "---..",    // 8
    "----.",    // 9 = 57
    "", "", "", "", "", "", "", // Not used
    ".-",       // A = 65
    "-...",     // B
    "-.-.",     // C
    "-..",      // D
    ".",        // E
    "..-.",     // F
    "--.",      // G
    "....",     // H
    "..",       // I
    ".---",     // J
    "-.-",      // K
    ".-..",     // L
    "--",       // M
    "-.",       // N
    "---",      // O
    ".--.",     // P
    "--.-",     // Q
    ".-.",      // R
    "...",      // S
    "-",        // T
    "..-",      // U
    "...-",     // V
    ".--",      // W
    "-..-",     // X
    "-.--",     // Y
    "--.."      // Z = 90
};

#endif // MORSE_H_INCLUDED
