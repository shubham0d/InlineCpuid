#include<stdio.h>

void getCpuID()
{
	//Initialize used variables
	char sysType[13]; //Array consisting of 13 single bytes/characters
	int a[10];
    __asm__("xor %eax , %eax\n\t");
    __asm__("xor %ebx , %ebx\n\t");
    __asm__("xor %ecx , %ecx\n\t");
    __asm__("xor %edx , %edx\n\t");
	__asm__("mov $3, %eax\n\t");
	__asm__("cpuid\n\t");
		//MOV EBX to EAX and get the chars one by one by using shift out right bitwise operation.
	__asm__("mov %%eax, %0\n\t":"=r" (a[0]));
	__asm__("mov %%ebx, %0\n\t":"=r" (a[1]));
	__asm__("mov %%ecx, %0\n\t":"=r" (a[2]));
    __asm__("mov %%edx, %0\n\t":"=r" (a[3]));
		//__asm__("mov %%al, %0\n\t":"=r" (sysType[0]));
    printf("processor serial no is\n" );
	printf ("%d--%d--%d--%d", a[0],a[1],a[2],a[3]);
}


int main(){
    getCpuID();
}
