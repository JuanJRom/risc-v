#include <stdio.h>
int main(){
    printf("Hello, %s\n", "world");
    return 0;
}
/*
void prints(volatile char* ptr);

int main() {
    char* str = "Hello world";
    prints(str);
    return 0;
}

void prints(volatile char* ptr){ // ptr is passed through register a0
    asm("li a7, 4");
    asm("ecall");
}*/
