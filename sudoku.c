#include<stdio.h>
#include<stdlib.h>

//read sudoku from a file and determine if the sudoku is complete
int readSudoku(char* filename,int sudoku[][9]){
    FILE* fp=fopen(filename,"r");
    int lineReaded = 0, inComplete = 0;
    while(!feof(fp) && lineReaded != 9){
        char c;
        for(int i = 0; i < 9; ++i){
            c = fgetc(fp);
            if(c == ' '){
                inComplete++;
            }else if(c >= '1' && c <= '9'){
                sudoku[lineReaded][i]=(int)(c-'0');
            }else{
                fprintf(stderr,"error\n");
                fclose(fp);
                exit(-1);
            }   
        }
        fgetc(fp);
        ++lineReaded;
    }
    fclose(fp);
    
    if(lineReaded != 9 || inComplete > 2){
        fprintf(stderr,"error\n");
        exit(-1);
    }
    return inComplete;
}

//check if all the number are unique in every row
int rowCheck(int sudoku[][9]){
    for(int i = 0; i < 9; i++){
        int checkNumber = 1^2^3^4^5^6^7^8^9;
        for(int j = 0; j < 9; j++){
            checkNumber ^= sudoku[i][j];
        }
        if(checkNumber != 0){
            return 0;
        }
    }
    return 1;
}

//check if all the number are unique in every col
int colCheck(int sudoku[][9]){
    for(int i = 0; i < 9; i++){
        int checkNumber = 1^2^3^4^5^6^7^8^9;
        for(int j = 0; j < 9; j++){
            checkNumber ^= sudoku[j][i];
        }
        if(checkNumber != 0){
            return 0;
        }
    }
    return 1;
}

//check if all the number are unique in every 3*3 cell
int cellCheck(int sudoku[][9]){
    for(int i = 0; i < 9; i++){
        int checkNumber = 1^2^3^4^5^6^7^8^9;
        for(int j = 0;j < 9; j++){
            checkNumber ^= sudoku[i/3*3+j/3][i%3*3+j%3];
        }
        if(checkNumber != 0){
            return 0;
        }
    }
    return 1;
}

//check if a complete sudoku is correct
int checkCompleteSudoku(int sudoku[][9]){
    if(rowCheck(sudoku) && colCheck(sudoku) && cellCheck(sudoku)){
        return 1;
    }
    return 0;
}

//print function for debug
//void printSudoku(int sudoku[][9]){
    //for(int i=0;i<9;++i){
        //for(int j=0;j<9;++j){
            //putchar('0'+sudoku[i][j]);
        //}
        //putchar('\n');
    //}
//}

//check if a incomplete sudoku is solvable or not
int checkIncompleteSudoku(int sudoku[][9],int incomplete){
    int* pointer[2];
    int numPointer = 0;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(sudoku[i][j] == 0){
                pointer[numPointer] =& sudoku[i][j];
                numPointer++;
                if(numPointer == incomplete){
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 9; i++){
        if(numPointer == 1){
            *pointer[0] = i;
            if(checkCompleteSudoku(sudoku)){
                return 1;
            }
        }else{
            for(int j = 0; j < 9; j++){
                *pointer[0] = i;
                *pointer[1] = j;
                if(checkCompleteSudoku(sudoku)){
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main(int argc,char** argv){
    if(argc != 2){
        fprintf(stderr,"error\n");
        exit(-1);
    }
    char* filename = argv[1];
    int sudoku[9][9] = {0};
    int type = readSudoku(filename, sudoku);
    if(type == 0){
    	if(checkCompleteSudoku(sudoku) == 1){
    		printf("correct\n");
    	}else{
    		printf("incorrect\n");
    	}
    }else{
    	if(checkIncompleteSudoku(sudoku, type) == 1){
    		printf("solvable\n");
    	}else{
    		printf("unsolvable\n");
    	}
    }
    return 0;
}  
