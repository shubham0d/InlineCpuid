void getCpuID()
{

	//Initialize used variables
	char sysType[13]; //Array consisting of 13 single bytes/characters
	int a[10];
    int eaxOutput; //also called signature
		//Execute CPUID with EAX = 0 to get the CPU producer
		__asm__("mov $0x2 , %eax\n\t");
		__asm__("cpuid\n\t");
		//MOV EBX to EAX and get the chars one by one by using shift out right bitwise operation.
		__asm__("mov %%eax, %0\n\t":"=r" (a[0])); //gives model and family
		__asm__("mov %%ebx, %0\n\t":"=r" (a[1])); //gives additional feature info
		__asm__("mov %%ecx, %0\n\t":"=r" (a[2])); //feature flags
		__asm__("mov %%edx, %0\n\t":"=r" (a[3])); //feature flags
		//__asm__("mov %%al, %0\n\t":"=r" (sysType[0]));
        decToBinary(a[0]);
	    outputEax();
        decToBinary(a[1]);
        outputEbx();
        decToBinary(a[2]);
        outputEcx();
        decToBinary(a[3]);
        outputEdx();



}


int main(){
    getCpuID();
}
