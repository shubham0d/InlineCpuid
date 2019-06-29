#include<stdio.h>

void getCpuID()
{
	//Initialize used variables
	char sysType[13]; //Array consisting of 13 single bytes/characters
	int a[10];
		//Execute CPUID with EAX = 0 to get the CPU producer
		__asm__("mov $0x1 , %eax\n\t");
		__asm__("cpuid\n\t");
		//MOV EBX to EAX and get the chars one by one by using shift out right bitwise operation.
		__asm__("mov %%eax, %0\n\t":"=r" (a[0])); //gives model and family
		__asm__("mov %%ebx, %0\n\t":"=r" (a[1])); //gives additional feature info
		__asm__("mov %%ecx, %0\n\t":"=r" (a[2])); //feature flags
		__asm__("mov %%edx, %0\n\t":"=r" (a[3])); //feature flags
		//__asm__("mov %%al, %0\n\t":"=r" (sysType[0]));
	printf ("%s", &a);
}


int main(){
    getCpuID();
}
