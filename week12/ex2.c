#include<linux/input.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
    int file = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event event;

    while(1)
    {
        int bytes = read(file, &event, sizeof(struct input_event));
        if(bytes < sizeof(struct input_event) || event.type != EV_KEY)
            continue;

        if(!event.value) // released
        {
            printf("RELEASED 0x%x (%d)\n", event.code, event.code);
        }
        else if (event.value == 1) // pressed
        {
            printf("PRESSED 0x%x (%d)\n", event.code, event.code);
        }
    }

    return 0;
}