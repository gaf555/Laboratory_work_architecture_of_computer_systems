#include <iostream>
#include <iomanip>
#include <limits>

void print32(void*);
void print64(void*);

int main() {

	int max32us = std::numeric_limits<unsigned int>::max();
	int min32us = std::numeric_limits<unsigned int>::min();
	int max32s = std::numeric_limits<int>::max();
	int min32s = std::numeric_limits<int>::min();

	std::cout << "Max unsigned 32 bit print32: " << std::endl;
	print32(&max32us);

	std::cout << "Min unsigned 32 bit print32: " << std::endl;
	print32(&min32us);

	std::cout << "Max signed 32 bit print32: " << std::endl;
	print32(&max32s);

	std::cout << "Min signed 32 bit print32: " << std::endl;
	print32(&min32s);

	int max64us = std::numeric_limits<unsigned long long>::max();
	int min64us = std::numeric_limits<unsigned long long>::min();
	int max64s = std::numeric_limits<long long>::max();
	int min64s = std::numeric_limits<long long>::min();

	std::cout << "Max unsigned 64 bit print32: " << std::endl;
	print64(&max64us);

	std::cout << "Min unsigned 64 bit print32: " << std::endl;
	print64(&min64us);

	std::cout << "Max signed 64 bit print32: " << std::endl;
	print64(&max64s);

	std::cout << "Min signed 64 bit print32: " << std::endl;
	print64(&min64s);

	int x1 = 0xA1B2C3D4, y1 = 3, z1 = -8;
	std::cout << "Print32 for x in int:" << std::endl;
	print32(&x1);
	std::cout << "Print32 for y in int:" << std::endl;
	print32(&y1);
	std::cout << "Print32 for z in int:" << std::endl;
	print32(&z1);

	long long x2 = 0xA1B2C3D4, y2 = 3, z2 = -8;
	std::cout << "Print64 for x in long long:" << std::endl;
	print64(&x2);
	std::cout << "Print64 for y in long long:" << std::endl;
	print64(&y2);
	std::cout << "Print64 for z in long long:" << std::endl;
	print64(&z2);

	return 0;
}

void print32(void *p) {

	std::cout << "Hex 32 bit unsigned reinterpret cast is " << std::hex << *(reinterpret_cast<unsigned int *>(p)) << std::endl;
	std::cout << "Hex 32 bit signed reinterpret cast is " << std::hex << *(reinterpret_cast<int *>(p)) << std::endl;
	
	std::cout << "Dec 32 bit unsigned reinterpret cast is " << std::dec << *(reinterpret_cast<unsigned int *>(p)) << std::endl;
	std::cout << "Dec 32 bit signed reinterpret cast is " << std::dec << *(reinterpret_cast<int *>(p)) << std::endl;

	std::cout << std::endl;
}

void print64(void *p) {

	std::cout << "Hex 64 bit unsigned reinterpret cast is " << std::hex << *(reinterpret_cast<unsigned long long  *>(p)) << std::endl;
	std::cout << "Hex 64 bit signed reinterpret cast is " << std::hex << *(reinterpret_cast<long long *>(p)) << std::endl;
	
	std::cout << "Dec 64 bit unsigned reinterpret cast is " << std::dec << *(reinterpret_cast<unsigned long long  *>(p)) << std::endl;
	std::cout << "Dec 64 bit signed reinterpret cast is " << std::dec << *(reinterpret_cast<long long *>(p)) << std::endl;

	std::cout << "Double 64 bit signed reinterpret cast is " << *(reinterpret_cast<double *>(p)) << std::endl;

	std::cout << std::endl;
}
