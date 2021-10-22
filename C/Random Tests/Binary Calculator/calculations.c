#include <stdio.h>
#include "calculations.h" 

void binary_to_decimal(int number){

}
void decimal_to_binary(int number){
   if(number){
       int current;
       int rest;
       rest = number % 2;
       current = number / 2;
       printf("%d", rest);
       decimal_to_binary(current);
       printf("\n");
   }
}
