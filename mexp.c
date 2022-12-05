#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		return 0;
	}
	int size, n; //size and power
	fscanf(fp, "%d\n", &size);//scan for the size
	
	/* pre processing - allocate to each row(int*) */
	int i, j, z;
	int** matr1 = (int**)malloc(sizeof(int*) * size);
	int** matr2 = (int**)malloc(sizeof(int*) * size);
	int** temp = (int**)malloc(sizeof(int*) * size);
	int** resmatr = (int**)malloc(sizeof(int*) * size);
	for(i = 0; i < size; i++){
		matr1[i] = (int*)malloc(sizeof(int) * size);
		matr2[i] = (int*)malloc(sizeof(int) * size);
		temp[i] = (int*)malloc(sizeof(int) * size);
		resmatr[i] = (int*)malloc(sizeof(int) * size);
	}
	

	/* scan for the matrix and copy that */
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			fscanf(fp, "%d", &matr2[i][j]);
			matr1[i][j] = matr2[i][j];
		}
	}

	fscanf(fp, "%d", &n);//scan for the power
	fclose(fp);

	
	
	/* multiplication */

	/* case 1: power = 0 */
	if(n == 0){//matrix M^0 = I(mxm)
		for(i = 0; i < size; i++){
			for(j = 0; j < size; j++){
				resmatr[i][j] = 0;
				if(i == j){
					resmatr[i][j] = 1;
				}
			}
		}
		/* print the final matrix */
		// for(i = 0; i < size; i++){
		// 	for(j = 0; j < size; j++){
		// 		if(j == size - 1){
		// 			printf("%d", resmatr[i][j]);
		// 		}else{
		// 			printf("%d ", resmatr[i][j]);
		// 		}
		// 	}
		// 	printf("\n");
		// }
	}

	/* case 2: power = 1 */
	if(n == 1){//matrix M equal to itself
		for(i = 0; i < size; i++){
			for(j = 0; j < size; j++){
				resmatr[i][j] = matr1[i][j];
			}
		}
		/* print the final matrix */
		// for(i = 0; i < size; i++){
		// 	for(j = 0; j < size; j++){
		// 		if(j == size - 1){
		// 			printf("%d", resmatr[i][j]);
		// 		}else{
		// 			printf("%d ", resmatr[i][j]);
		// 		}
		// 	}
		// 	printf("\n");
		// }
	}

	/* case 3: power > 1 */
	int sum;
	int p;
	if(n > 1){//two matrix calculation; power > 1
		for(p = 0; p < n - 1; p++){
			for(i = 0; i < size; i++){
				for(j = 0; j < size; j++){
					sum = 0;
					for(z = 0; z < size; z++){
						sum += matr1[i][z] * matr2[z][j];
						//resmatr[i][j] = sum;
					}
					temp[i][j] = sum;
					//sum = 0;
				}
			}
			for(i = 0; i < size; i++){
				for(j = 0; j < size; j++){
					matr1[i][j] = temp[i][j];
					resmatr[i][j] = matr1[i][j];
				}
			}
		}

		/* print the final matrix */
		// for(i = 0; i < size; i++){
		// 	for(j = 0; j < size; j++){
		// 		if(j == size - 1){
		// 			printf("%d", resmatr[i][j]);
		// 		}else{
		// 			printf("%d ", resmatr[i][j]);
		// 		}
		// 	}
		// 	printf("\n");
		// }
	}

	/* print the final matrix */
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			if(j == size - 1){
					printf("%d", resmatr[i][j]);
			}else{
					printf("%d ", resmatr[i][j]);
			}
		}
		printf("\n");
	}

	/* final part - post processing */
	for(i = 0; i < size; i++){//free for int*
		free(matr1[i]);
		free(matr2[i]);
		free(temp[i]);
		free(resmatr[i]);
	}
	free(matr1);
	free(matr2);
	free(temp);
	free(resmatr);
	return EXIT_SUCCESS;
}