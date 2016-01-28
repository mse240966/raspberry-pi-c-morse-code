#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "morse.h"
#include "gpio/gpio.h"

static const int MAX_SENTANCE_LENGTH = 80;
static void getSentance(char *sentance);

/*
 * Program main entry point
 */
int main()
{
    // No buffering for standard out
    setbuf(stdout, NULL);

    // Set up GPIO 18
    if (gpioExportAndDirection(GPIO_PIN_18, GPIO_OUTPUT) != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    int returnStatus = EXIT_SUCCESS;
    bool outputMorse = true;
    char *sentance = malloc(sizeof(char) * MAX_SENTANCE_LENGTH + 1);

    while(outputMorse == true && returnStatus == EXIT_SUCCESS)
    {
        // Get user input sentance
        getSentance(sentance);

        // Ouput morse code for entered sentance
        if (strlen(sentance) > 1)
        {
            returnStatus = outputMorseCodeSentance(GPIO_PIN_18, sentance);
        }

        // Nothing entered, so exit
        (strlen(sentance) ==  1) ? outputMorse = false : printf("\n\n");
    }

    // Tidy up GPIO 18
    returnStatus = gpioWrite(GPIO_PIN_18, GPIO_LOW);
    returnStatus = gpioUnexport(GPIO_PIN_18);

    return returnStatus;
}

/*
 * Get a sentance of no more than 80 charaters from user input
 */
void getSentance(char *sentance)
{
    printf("Enter a sentance [a-Z,0-9], enter nothing to exit (max %d characters) ...\n", MAX_SENTANCE_LENGTH);
    fgets(sentance, MAX_SENTANCE_LENGTH + 1, stdin);
}
