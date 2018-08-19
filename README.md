# 8-bit-pic-muc-IO
Set and read digital IO pins easily in 8-bit pic microcontrollers.


To use these functions download headerfile and include in youre project
```c
#include<pinc.h>
```

## USAGE
Example:

Set pin as output or input
```c
//pin numbers are related to port starting from 0
pinMode(TRISB,5,INPUT);
pinMode(TRISB,6,OUTPUT);
```
Set pin value in digital

```c
setPin(TRISB,5,HIGH);
setPin(TRISC,6,LOW);
```
Read pin value in digital

```c
unsigned char dValue= readPin(TRISB,5);
```
