#include<stdio.h>

int binaryNum[32];

void decToBinary(int n)
{
    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

}

int outputEax(){
    printf("-------Signature(EAX register):-------");
    printf("\nStepping ID:%d%d%d%d",binaryNum[3],binaryNum[2],binaryNum[1],binaryNum[0]);
    printf("\nModel:%d%d%d%d",binaryNum[7],binaryNum[6],binaryNum[5],binaryNum[4]);
    printf("\nFamily ID:%d%d%d%d",binaryNum[11],binaryNum[10],binaryNum[9],binaryNum[8]);
    printf("\nProcessor Type:%d%d",binaryNum[13],binaryNum[12]);
    printf("\nExtended Model ID:%d%d%d%d",binaryNum[19],binaryNum[18],binaryNum[17],binaryNum[16]);
    printf("\nExtended Family ID:%d%d%d%d",binaryNum[27],binaryNum[26],binaryNum[25],binaryNum[24],binaryNum[23],binaryNum[22],binaryNum[21],binaryNum[20]);
    printf("\n");
    return 0;

}

void getCpuID()
{
	//Initialize used variables
	char sysType[13]; //Array consisting of 13 single bytes/characters
	int a[10];
    int eaxOutput; //also called signature
		//Execute CPUID with EAX = 0 to get the CPU producer
		__asm__("mov $0x1 , %eax\n\t");
		__asm__("cpuid\n\t");
		//MOV EBX to EAX and get the chars one by one by using shift out right bitwise operation.
		__asm__("mov %%eax, %0\n\t":"=r" (a[0])); //gives model and family
		__asm__("mov %%ebx, %0\n\t":"=r" (a[1])); //gives additional feature info
		__asm__("mov %%ecx, %0\n\t":"=r" (a[2])); //feature flags
		__asm__("mov %%edx, %0\n\t":"=r" (a[3])); //feature flags
		//__asm__("mov %%al, %0\n\t":"=r" (sysType[0]));
        decToBinary(a[0]);
	    outputEax();
}


int main(){
    getCpuID();
}
