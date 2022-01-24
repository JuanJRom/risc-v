#include "proccess.h"

void process_1(/*int *count*/){
    static int8_t count;
    print_s("   |   Proceso uno: ");
    print_i(++count);
    print_s("\n");
}

void process_2(/*int *count_1 */){
    static int8_t count_1;
    print_s("   |   Proceso dos: ");
    print_i(++count_1);
    //print_s("\n");
}


void process_3(/*int *count_2*/ ){
    static int8_t count_2;
    print_s("    |  Proceso tres: ");
    print_i(++count_2);
    //print_s("\n");
}

void process_4(/*int *count_2*/ ){
    static int8_t count_3;
    print_s("Proceso cuatro: ");
    print_i(++count_3);
    //print_s("\n");
}