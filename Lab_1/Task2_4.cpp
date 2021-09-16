#include<stdio.h>
#include<locale.h>

void print16(void*p);
void print32(void * p);
long Extender(void*p);
unsigned long ExtenderUn(void*p);
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");

	printf("Беззнаковая минимальная\n");
	unsigned short unsmin = 0;
	print16(&unsmin);

	printf("\nБеззнаковая максимальная\n");
	unsigned short unsmax = 65535;
	print16(&unsmax);

	printf("\nЗнаковая минимальная\n");
	short min = -32768;
	print16(&min);

	printf("\nЗнаковая максимальная\n");
	short max = 32767;
	print16(&max);

	printf("\ny \n");
	short y = 3;
	print16(&y);

	printf("\nz \n");
	short z = -8;
	print16(&z);

	long y1 = static_cast<long>(y);
	long z1 = static_cast<long>(z);
	unsigned long y2 = static_cast<unsigned long>(y1);
	unsigned long z2 = static_cast<unsigned long>(z1);

	printf("\nРасширение в long \n");

	printf("\ny ex \n");
	print16(&y1);

	printf("\ny ex  32\n");
	print32(&y1);

	printf("\nz ex \n");
	print16(&z1);

	printf("\nz ex  32\n");
	print32(&z1);

	printf("\nРасширение в unsigned long \n");

	printf("\ny ex un \n");
	print16(&y2);

	printf("\ny ex un 32\n");
	print32(&y2);

	printf("\nz ex un \n");
	print16(&z2);

	printf("\nz ex  un 32\n");
	print32(&z2);
	



	return 0;
}

void print16(void * p)
{
	
	printf("Беззнаковая шеснадцатиричная - %x \n" , *(reinterpret_cast<unsigned short *>(p)));
	printf("Беззнаковая десятичная - %d \n", *(reinterpret_cast<unsigned short *>(p)));
	printf("Знаковая шеснадцатиричная - %x \n", *(reinterpret_cast<short *>(p)));
	printf("Знаковая десятичная - %d \n", *(reinterpret_cast<short *>(p)));
	
}

void print32(void * p)
{

	printf("Беззнаковая шеснадцатиричная - %x \n", *(reinterpret_cast<unsigned long *>(p)));
	printf("Беззнаковая десятичная - %d \n", *(reinterpret_cast<unsigned long *>(p)));
	printf("Знаковая шеснадцатиричная - %x \n", *(reinterpret_cast<long *>(p)));
	printf("Знаковая десятичная - %d \n", *(reinterpret_cast<long *>(p)));

}
