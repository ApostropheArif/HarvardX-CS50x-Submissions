#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get name from user and print it out
    string name = get_string("What's your name? :");
    printf("hello, %s\n", name);
}
