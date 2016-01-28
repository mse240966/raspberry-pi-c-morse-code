# Raspberry Pi C Morse Code

A little C program written on my Raspberry Pi to brush up on my aging C programming language knowledge, and to learn GPIO output programming in C on the Raspberry PI.  I didn't want to use a third party library, but learn how to control GPIO output manually. So I opted for the 'sysfs interface'. I had already done a small project with four leds, so this time a buzzer and Morse code!

## Example

```bash
$ sudo ./morseCode
Enter a sentance [a-Z,0-9], enter nothing to exit (max 80 characters) ...
sos sos
S ... O --- S ...    S ... O --- S ... 

Enter a sentance [a-Z,0-9], enter nothing to exit (max 80 characters) ...

```

## Circuit
