#include <stdio.h>
#include <curses.h>

int main ()
{
    char ch = 0, k = 0;
    while(1)
    {
        ch = getch();
        if(ch == 27)                  // if ch is the escape sequence with num code 27, k turns 1 to signal the next
            k = 1;
        if(ch == 91 && k == 1)       // if the previous char was 27, and the current 91, k turns 2 for further use
            k = 2;
        if(ch == 65 && k == 2)       // finally, if the last char of the sequence matches, you've got a key !
            printf("You pressed the up arrow key !!\n");
        if(ch == 66 && k == 2)                             
            printf("You pressed the down arrow key !!\n");
        if(ch != 27 && ch != 91)      // if ch isn't either of the two, the key pressed isn't up/down so reset k
            k = 0;
        printf("%c - %d", ch, ch);    // pri
    }
    return (0);
}

