#include <stdio.h>

int main(){
	
	int array1[5], temp;
	
	for (int x = 0; x < 5; x++){
		
		printf("Enter the value for the array, value must be less then 9999 : ");
		scanf("%d", &array1[x]);
		
		if (array1[x] > 9999){
			printf("Enter the valid number in the range, you have entered value out of range. ");
			x--;
		}
	}
	
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j < 5; j++){
			
			if(array1[i] > array1[j]){
				temp = array1[i];
				array1[i] = array1[j];
				array1[j] = temp;
			}
		}
	}
	printf("Second lowest number in the array is in index 2 = %d", array1[1]);
	return 0;
	
	
}