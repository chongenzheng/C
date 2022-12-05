#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    //argv[1] - manipulate each character by 13
    //Ascii
    //end of string character\0
    int pos = 0;
    while(argv[1] == NULL){
        //printf("%c\n", argv[1][pos]);
        return EXIT_SUCCESS;
    }
    while(argv[1][pos] != '\0'){
        if ((int)argv[1][pos] >= 65 && (int)argv[1][pos] <= 90){
            //argv[1][pos] += 13;
            if((int)argv[1][pos] >= 65 && (int)argv[1][pos] <= 82){
                argv[1][pos] += 13;
                if(argv[1][pos] > 90){//如果+13超出范围
                    argv[1][pos] = 64 + (argv[1][pos] - 90);
                }
            }else{
                argv[1][pos] = 64 + 13 - (90 - argv[1][pos]);
            }  
                // if(argv[1][pos] > 90){//如果+13超出范围
                //     argv[1][pos] = 64 + (argv[1][pos] - 90);
                // }
                printf("%c", argv[1][pos]);
        }
        else if((int)argv[1][pos] >= 97 && (int)argv[1][pos] <= 122){
            if((int)argv[1][pos] >= 97 && (int)argv[1][pos] <= 114){
                argv[1][pos] += 13;
                if(argv[1][pos] > 122){//如果+13超出范围
                    argv[1][pos] = 96 + (argv[1][pos] - 122);
                }
            }else{
                argv[1][pos] = 96 + 13 - (122 - argv[1][pos]);
            }   
            printf("%c", argv[1][pos]);
        }
        else if((int)argv[1][pos] < 65 || (int)argv[1][pos] > 122 || ((int)argv[1][pos] < 97 && (int)argv[1][pos] > 90)){
            printf("%c", argv[1][pos]);
        }
        pos++;
    }
    printf("\n");
    //printf("%c\n", argv[1][pos]);
    return EXIT_SUCCESS;
}
