#include<linux/input.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

#define P 18 
#define E 25
#define A 46
#define C 30

int main()
{
    int file = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event event;

    int buf[3] = {-1,-1,-1};

    while(1)
    {
        int bytes = read(file, &event, sizeof(struct input_event));
        if(bytes < sizeof(struct input_event) || event.type != EV_KEY || !event.value)
            continue;

        if(buf[2]!=-1)
        {
            buf[0] = buf[1];
            buf[1] = buf[2];
            buf[2] = -1;
        }

        for(int i=0; i<3; ++i)
            if(buf[i] == -1)
                buf[i] = event.code;

        if((buf[0] == P && buf[1] == E && buf[2] == -1) ||
           (buf[1] == P && buf[2] == E))
            printf("I passed the Exam!\n");
        if(buf[0] == C && buf[1] == A && buf[2] == P)
            prinf("Get some cappuccino!\n");
        if(buf[0] == P && buf[1] == A && buf[2] == C)
            printf("man\n");
    }

    return 0;
}