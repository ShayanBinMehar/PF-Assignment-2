#include<stdio.h>
#include<string.h>

int BinaryToDecimal (int number) {
	int i = 1, sum = 0;
	while(number != 0) {
		int thisDigit = number % 10;
		if (thisDigit == 1) {
			sum += i;
		}
		i = i * 2;
		number = number / 10;
	}
	return sum;
}

int DecimalToBinary (int number) {
	int sum = 0, i = 1;
	while (number != 0) {
		if (number & 1 == 1) {
			sum += i;
		}
		i = i * 10;
		number = number >> 1;
	}
	return sum;
}

void DecimalToHexadecimal(int number) {
	if (number == 0) {
		printf("0");
		return;	
	}
	
	int myArr[100];
	int i = 0;
	while (number != 0) {
		myArr[i++] = number % 16;
		number /= 16;
	}
	
	for (int j = i - 1; j >= 0; j--) {
		int thisDigit = myArr[j];
		switch(thisDigit) {
			case 10: printf("A"); break;
			case 11: printf("B"); break;
			case 12: printf("C"); break;
			case 13: printf("D"); break;
			case 14: printf("E"); break;
			case 15: printf("F"); break;
			default: printf("%d", myArr[j]); break;
		}
	}
}

void HexadecimalToDecimal(char* hexNumber) {
	int length = strlen(hexNumber), thisDigit, sum = 0;
	for (int i = 0; i < length; i++) {
		int multiple = 1;
		for (int p = length - 1; p > i; p--) {
			multiple *= 16;
		}
		switch (hexNumber[i]) {
			case 'A': thisDigit = 10; break;
			case 'B': thisDigit = 11; break;
			case 'C': thisDigit = 12; break;
			case 'D': thisDigit = 13; break;
			case 'E': thisDigit = 14; break;
			case 'F': thisDigit = 15; break;
			default: thisDigit = hexNumber[i] - '0'; break;
		}
		sum += (multiple * thisDigit);
	}
	printf("%d", sum);
}

void BinaryToHexadecimal (int number) {
	int i = 1, sum = 0, length = 0;
	int temp = number;
	while (temp != 0) {
		temp /= 10;
		length++;
	}
	
	if (length % 4 == 0) length = length / 4;
	else length = (length / 4) + 1;
	
	if (length == 0) length++;
	int myArr[length], point = 0;
	
	if (number == 0) {
		myArr[point] = 0;
	} else {		
		while (number != 0) {
			int thisDigit = number % 10;
			if (thisDigit == 1) {
				sum += i;
			}
			i = i * 2;
			if (i == 16) {
				myArr[point++] = sum;
				i = 1;
				sum = 0;
			}
			number /= 10;
		}
		myArr[point++] = sum;
	}
	
	for (int j = length - 1; j >= 0; j--) {
		switch (myArr[j]) {
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
			default:
				printf("%d", myArr[j]);
				break;
		}
	}
}

void HexadecimalToBinary (char* hexNumber) {
	for (int i = 0; hexNumber[i] != '\0'; i++) {
		int thisDigit;
		switch (hexNumber[i]) {
			case 'A': thisDigit = 10; break;
			case 'B': thisDigit = 11; break;
			case 'C': thisDigit = 12; break;
			case 'D': thisDigit = 13; break;
			case 'E': thisDigit = 14; break;
			case 'F': thisDigit = 15; break;
			default: thisDigit = hexNumber[i] - '0';
		}
				
		int start = 0;
		for (int j = 8; j > 0; j /= 2) {
			if (thisDigit % j == 0 && thisDigit != 0) {
				start = 1;
				printf("1");
				thisDigit = thisDigit % j;
			} else {
				if (thisDigit > j) {
					start = 1;
					printf("1");
					thisDigit = thisDigit % j;
				} else if (start == 1){
					printf("0");	
				}
			}
		}
	}
}



int main () {
	printf("%d\n", BinaryToDecimal(110101111));
	printf("%d\n", DecimalToBinary(431));
	printf("\n");
	BinaryToHexadecimal(110101111);
	printf("\n");
	HexadecimalToBinary("1AF");
	printf("\n");
	DecimalToHexadecimal(431);
	printf("\n");
	HexadecimalToDecimal("1AF");
}