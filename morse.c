#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "morse.h"
#include "gpio.h"

/*
 * Dot = 1 unit
 * Dash = 3 units
 * Space between parts of same letters = 1 unit
 * Space between letters = 3 units
 * Space between words = 7 units
 *
 * So 'HELLO' is where '*' is one unit
 *
 * HHHHHHH   E   LLLLLLLLL   LLLLLLLLL   OOOOOOOOOOO
 * . . . .   .   . --- . .   . --- . .   --- --- ---
 * *************************************************
 */

static int outputMorseCharacter(int gpioPin, char *character);
static int outputBuzzer(int gpioPin, char dotDash);
static int setGPIOPin(int gpioPin, int microSeconds);
static bool isValidMorseCodeCharacter(char *character);

static int UNIT_MICRO_SECONDS = 100000;

/*
 * Output a morse code sentance
 */
int outputMorseCodeSentance(int gpioPin, char *sentance)
{
    int sentanceLength = strlen(sentance);
    for(int charIndex=0; charIndex<sentanceLength; charIndex++)
    {
        if (outputMorseCharacter(gpioPin, (char*)toupper(sentance[charIndex])) != EXIT_SUCCESS)
        {
            return EXIT_FAILURE;
        }
        usleep(UNIT_MICRO_SECONDS * 3); // Space between letters = 3 units
    }

    return EXIT_SUCCESS;
}

/*
 * Output a morse code character
 */
int outputMorseCharacter(int gpioPin, char *character)
{
    if (isValidMorseCodeCharacter(character) == false)
    {
        return EXIT_SUCCESS;
    }

    putchar((int)character);
    putchar(*SPACE);

    int morseIndex = (int)character - 32;
    int morseCodeLength = strlen(MORSE_CODE[morseIndex]);
    for(int charIndex=0; charIndex<morseCodeLength; charIndex++)
    {
        if (MORSE_CODE[morseIndex][charIndex] == *SPACE)
        {
            usleep(UNIT_MICRO_SECONDS * 7); // Space between words = 7 units
            continue;
        }

        if (outputBuzzer(gpioPin, MORSE_CODE[morseIndex][charIndex]) != EXIT_SUCCESS)
        {
            return EXIT_FAILURE;
        }

        usleep(UNIT_MICRO_SECONDS); // Space between parts of same letters = 1 unit
    }

    putchar(*SPACE);

    return EXIT_SUCCESS;
}

/*
 * Output the dot or dash from the buzzer
 */
int outputBuzzer(int gpioPin, char dotDash)
{
    if (dotDash == *DOT)
    {
        putchar(*DOT);
        return setGPIOPin(gpioPin, UNIT_MICRO_SECONDS); // Dot = 1 unit
    }

    if (dotDash == *DASH)
    {
        putchar(*DASH);
        return setGPIOPin(gpioPin, UNIT_MICRO_SECONDS * 3); // Dash = 3 units
    }

    printf("Error cannot determine if dot or dash.");

    return EXIT_FAILURE;
}

/*
 * Set GPIO pin to high then low for a length of micro seconds
 */
int setGPIOPin(int gpioPin, int microSeconds)
{
    if (gpioWrite(gpioPin, GPIO_HIGH) != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    usleep(microSeconds);

    if (gpioWrite(gpioPin, GPIO_LOW) != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/*
 * Validate if we support the entered character
 */
bool isValidMorseCodeCharacter(char *character)
{
    int charIndex = (int)character;

    if (charIndex >= 65 && charIndex <= 90)
    {
        return true;    // Alphabet character
    }

    if (charIndex >= 48 && charIndex <= 57)
    {
        return true;    // Numeric character
    }

    if (charIndex == 32)
    {
        return true;    // Spaces
    }

    return false;
}

