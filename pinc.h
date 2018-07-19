
#ifndef PINC_HEADER // #include guarde
#define PINC_HEADER 5

#define INPUT 1 //define input bit
#define OUTPUT 0 //define output bit
#define HIGH 1 // define logic high
#define LOW 0 // define logic low

/*
 * set specific pin in a port as a output or input.
 * It should be passed address of TRIS register as parameter for <code>volatile unsigned char *tris</code>
 * <code>volatile unsigned char pin</code> is pin number of specific port 0 to 7
 * Last parameter is passed as type INPUT or OUTPUT
 */

void pinMode(volatile unsigned char *tris,unsigned char pin,unsigned char io)
{
    
    if(io==1)
    {
        unsigned char v=0b00000001;
        v<<=pin;
        *tris |=v;
    }
    else
    {
        unsigned char v=0b11111110;
        unsigned char v1=0b00000001;
        v1<<=pin;
        v1=(unsigned char)~v1;
        v<<=pin;
        v|=v1;
        *tris & = v;
    }
}

void setPin(volatile unsigned char *port,unsigned char pin,unsigned char value )
{
    if(value==1)
    {
        unsigned char v=0b00000001;
        v<<=pin;
        *port |=v;
    }
    else
    {
        unsigned char v=0b11111110;
        unsigned char v1=0b00000001;
        v1<<=pin;
        v1=(unsigned char)~v1;
        v<<=pin;
        v|=v1;
        *port & = v;
    }
}

unsigned char readPin(volatile unsigned char *port,unsigned char pin)
{
    unsigned char v=0b00000001;
    
    if(((v<<pin)&(*port))>0)
        return 1;
    else
        return 0;
}

unsigned char updatePin(volatile unsigned char *port,unsigned char pin,bool force)
{
   if(value==1 && force)
    {
        unsigned char v=0b00000001;
        v<<=pin;
        *port |=v;
    }
    else
    {
        unsigned char v=0b11111110;
        unsigned char v1=0b00000001;
        v1<<=pin;
        v1=(unsigned char)~v1;
        v<<=pin;
        v|=v1;
        *port & = v;
    }
}

#endif //PINC_HEADER
