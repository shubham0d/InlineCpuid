#include<stdio.h>
int a[10];
void brandString(int eaxValues)
{
    if (eaxValues == 1) {
    __asm__("mov $0x80000002 , %eax\n\t");
    }
    else if (eaxValues == 2) {
        __asm__("mov $0x80000003 , %eax\n\t");
    }
    else if (eaxValues == 3) {
        __asm__("mov $0x80000004 , %eax\n\t");
    }
    __asm__("cpuid\n\t");
    __asm__("mov %%eax, %0\n\t":"=r" (a[0]));
    __asm__("mov %%ebx, %0\n\t":"=r" (a[1]));
    __asm__("mov %%ecx, %0\n\t":"=r" (a[2]));
    __asm__("mov %%edx, %0\n\t":"=r" (a[3]));
    printf("%s", &a[0]);
}

void getCpuID()
{
    __asm__("xor %eax , %eax\n\t");
    __asm__("xor %ebx , %ebx\n\t");
    __asm__("xor %ecx , %ecx\n\t");
    __asm__("xor %edx , %edx\n\t");
    printf("Brand string is ");
    brandString(1);
    brandString(2);
    brandString(3);
    printf("\n");

}

int main(){
    getCpuID();
}
