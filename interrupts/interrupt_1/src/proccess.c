#include "proccess.h"

void process_1(int *count){
    print_s("                 |    Proceso uno: ");
    print_i(++*count);
    print_s("\n");
}

void process_2(int *count_1 ){
    print_s("Proceso dos: ");
    print_i(++*count_1);
    //print_s("\n");
}