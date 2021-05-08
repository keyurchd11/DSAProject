#ifndef __GUI_C
#define __GUI_C

#include <sys/ioctl.h>
#include <unistd.h>

//gotoxy() function definition
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
void printRed(char *str)
{
    printf("\e[38;5;196m%s", str);
    printf("\e[38;5;15m");
}
void printGreen(char *str)
{
    printf("\e[38;5;118m%s", str);
    printf("\e[38;5;15m");
}
void printBlue(char *str)
{
    printf("\e[38;5;21m%s", str);
    printf("\e[38;5;15m");
}
void printWhite(char *str)
{
    printf("\e[38;5;15m%s", str);
    printf("\e[38;5;15m");
}
void printYellow(char *str)
{
    printf("\e[38;5;190m%s", str);
    printf("\e[38;5;15m");
}

void printPurple(char *str)
{
    printf("\e[38;5;165m%s", str);
    printf("\e[38;5;15m");
}
void blueBG(char *str)
{
    printf("\e[48;5;21m%s", str);
    printf("\033[1;31;49m");
    // printf("\e[48;2;0;0;49m");
}

void border_with_delay()
{
    
    for (int i = 2; i < 22; i++)
    {
        gotoxy(10, i);
        if (i % 2 == 0)
            printRed("*");
        else
            printGreen("*");
        gotoxy(70, i);
        if (i % 2 == 0)
            printRed("*");
        else
            printGreen("*");
    }
    for (int i = 10; i < 71; i++)
    {
        gotoxy(i, 22);
        if (i % 2 == 0)
            printRed("*");
        else
            printGreen("*");
        gotoxy(i, 2);
        if (i % 2 == 0)
            printRed("*");
        else
            printGreen("*");
    }
}

void MidBox()
{
    for (int i = 16; i < 65; i++)
    {
        gotoxy(i, 19);
        if (i % 2 == 0)
            printYellow("_");
        else
            printPurple("_");
        gotoxy(i, 5);
        if (i % 2 == 0)
            printYellow("_");
        else
            printPurple("_");
    }
    for (int i = 6; i < 20; i++)
    {
        gotoxy(15, i);
        if (i % 2 == 0)
            printYellow("|");
        else
            printPurple("|");
        gotoxy(65, i);
        if (i % 2 == 0)
            printYellow("|");
        else
            printPurple("|");
    }
    gotoxy(0, 0);
    printWhite("                   ");
}

#endif