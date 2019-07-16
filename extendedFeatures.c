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
void printer()
{
    int i;
    for (i=0;i<32;i++) {
	printf("%d", binaryNum[i]);
    }
    printf("\n");
}


void getCpuID()
{

	int a[10];
		//Execute CPUID with EAX = 0 to get the CPU producer
		__asm__("xor %eax , %eax\n\t");
	    __asm__("xor %ebx , %ebx\n\t");
	    __asm__("xor %ecx , %ecx\n\t");
	    __asm__("xor %edx , %edx\n\t");
		__asm__("mov $0x7 , %eax\n\t");
        __asm__("mov $0 , %ecx\n\t");
		__asm__("cpuid\n\t");
		//MOV EBX to EAX and get the chars one by one by using shift out right bitwise operation.
		__asm__("mov %%ebx, %0\n\t":"=r" (a[0])); //gives model and family
		__asm__("mov %%ecx, %0\n\t":"=r" (a[1])); //gives additional feature info
		__asm__("mov %%edx, %0\n\t":"=r" (a[2])); //feature flags
        decToBinary(a[0]);
        printf ("Output from EBX:");
        printer();
        decToBinary(a[1]);
        printf ("Output from ECX:");
        printer();
        decToBinary(a[2]);
        printf ("Output from EDX:");
        printer();


}


int main(){
    getCpuID();
}
