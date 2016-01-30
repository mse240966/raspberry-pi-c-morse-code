# Raspberry Pi C Morse Code

A little C program written on my Raspberry Pi to brush up on my aging C programming language knowledge, and to learn GPIO output programming in C on the Raspberry PI.  I didn't want to use a third party library, but learn how to control GPIO output manually. So I opted for the 'sysfs interface'. I had already done a small project with four leds, so this time a buzzer and Morse code!

![buzzer](https://github.com/mse240966/raspberry-pi-c-morse-code/blob/master/docs/buzzer.png "Buzzer")

## How to clone (with GPIO sub module)

```bash
git clone --recursive https://github.com/mse240966/raspberry-pi-c-morse-code.git
```

## Example

```bash
$ sudo ./morseCode
Enter a sentance [a-Z,0-9], enter nothing to exit (max 80 characters) ...
sos sos
S ... O --- S ...    S ... O --- S ... 

Enter a sentance [a-Z,0-9], enter nothing to exit (max 80 characters) ...

```

## Circuit
