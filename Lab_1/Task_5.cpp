#include <iostream>
#include <limits>

void printDump(void*, size_t);

int main() {

	setlocale(LC_ALL, "russian");

	int x = 0xA1B2C3D4, y = 3, z = -8;
	int array[] = { x,y,z };
	double dy = y;

	int one = 1;

	std::cout << "One in int:" << std::endl;
	printDump(&one, sizeof(one));

	char str1c[] = "bcdxy";
	char str2c[] = "ёжзий";

	wchar_t str1wc[] = L"bcdxy";
	wchar_t str2wc[] = L"ёжзий";

	std::cout << "x in int:" << std::endl;
	printDump(&x, sizeof(x));

	std::cout << "array[] in int:" << std::endl;
	printDump(&array, sizeof(array));

	std::cout << "str1c in char:" << std::endl;
	printDump(&str1c, sizeof(str1c));

	std::cout << "str2c in char:" << std::endl;
	printDump(&str2c, sizeof(str2c));

	std::cout << "str1wc in char:" << std::endl;
	printDump(&str1wc, sizeof(str1wc));

	std::cout << "str2wc in char:" << std::endl;
	printDump(&str2wc, sizeof(str2wc));

	return 0;
}

void printDump(void *p, size_t N) {

	unsigned char* pbtP = (unsigned char*)(p);

	for (int i = 0; i < N; i++) {

		std::cout << std::hex << (int)*(pbtP + i) << " ";
	}
	std::cout << std::endl;
}
