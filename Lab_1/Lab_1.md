## Лабораторная работа № 1. Представление данных в ЭВМ

## Цель

Изучить форматы представления чисел и символьной информации в ЭВМ

## Задача 1. Размеры типов данных, sizeof

| Размер в байтах | Microsoft 32 | Microsoft 64 | GCC 32 | GCC 64 | 
| --------------- | ------------ | ------------ | -----  | ------ |
| char            | 1            | 1            | 1      | 1      |
| signed char     | 1            | 1            | 1      | 1      |
| unsigned char   | 1            | 1            | 1      | 1      |
| char*           | 4            | 8            | 8      | 8      |
| wchar_t         | 2            | 2            | 2      | 4      |
| wchar_t*        | 4            | 8            | 8      | 8      |
| short           | 2            | 2            | 2      | 2      |
| short*          | 4            | 8            | 8      | 8      |
| int             | 4            | 4            | 4      | 4      |
| int*            | 4            | 8            | 8      | 8      |
| long            | 4            | 4            | 4      | 8      |
| long*           | 4            | 8            | 8      | 8      |
| long long       | 8            | 8            | 8      | 8      |
| long long*      | 4            | 8            | 8      | 8      |
| float           | 4            | 4            | 4      | 4      |
| float*          | 4            | 8            | 8      | 8      |
| double          | 8            | 8            | 8      | 8      |
| double*         | 4            | 8            | 8      | 8      |
| long double     | 8            | 8            | 16     | 16     |
| long double*    | 4            | 8            | 8      | 8      |

## Задача 2 и 4. Интерпретация области памяти, print16() и print32()

Реализации функции print16()

```C++
void print16(void * p)
{
	
	printf("Беззнаковая шеснадцатиричная - %x \n" , *(reinterpret_cast<unsigned short *>(p)));
	printf("Беззнаковая десятичная - %d \n", *(reinterpret_cast<unsigned short *>(p)));
	printf("Знаковая шеснадцатиричная - %x \n", *(reinterpret_cast<short *>(p)));
	printf("Знаковая десятичная - %d \n", *(reinterpret_cast<short *>(p)));
	
}
```

Результат

```
Беззнаковая минимальная
Беззнаковая шеснадцатиричная - 0
Беззнаковая десятичная - 0
Знаковая шеснадцатиричная - 0
Знаковая десятичная - 0

Беззнаковая максимальная
Беззнаковая шеснадцатиричная - ffff
Беззнаковая десятичная - 65535
Знаковая шеснадцатиричная - ffffffff
Знаковая десятичная - -1

Знаковая минимальная
Беззнаковая шеснадцатиричная - 8000
Беззнаковая десятичная - 32768
Знаковая шеснадцатиричная - ffff8000
Знаковая десятичная - -32768

Знаковая максимальная
Беззнаковая шеснадцатиричная - 7fff
Беззнаковая десятичная - 32767
Знаковая шеснадцатиричная - 7fff
Знаковая десятичная - 32767

y
Беззнаковая шеснадцатиричная - 3
Беззнаковая десятичная - 3
Знаковая шеснадцатиричная - 3
Знаковая десятичная - 3

z
Беззнаковая шеснадцатиричная - fff8
Беззнаковая десятичная - 65528
Знаковая шеснадцатиричная - fffffff8
Знаковая десятичная - -8

Расширение в long

y ex
Беззнаковая шеснадцатиричная - 3
Беззнаковая десятичная - 3
Знаковая шеснадцатиричная - 3
Знаковая десятичная - 3

y ex  32
Беззнаковая шеснадцатиричная - 3
Беззнаковая десятичная - 3
Знаковая шеснадцатиричная - 3
Знаковая десятичная - 3

z ex
Беззнаковая шеснадцатиричная - fff8
Беззнаковая десятичная - 65528
Знаковая шеснадцатиричная - fffffff8
Знаковая десятичная - -8

z ex  32
Беззнаковая шеснадцатиричная - fffffff8
Беззнаковая десятичная - -8
Знаковая шеснадцатиричная - fffffff8
Знаковая десятичная - -8

Расширение в unsigned long

y ex un
Беззнаковая шеснадцатиричная - 3
Беззнаковая десятичная - 3
Знаковая шеснадцатиричная - 3
Знаковая десятичная - 3

y ex un 32
Беззнаковая шеснадцатиричная - 3
Беззнаковая десятичная - 3
Знаковая шеснадцатиричная - 3
Знаковая десятичная - 3

z ex un
Беззнаковая шеснадцатиричная - fff8
Беззнаковая десятичная - 65528
Знаковая шеснадцатиричная - fffffff8
Знаковая десятичная - -8

z ex  un 32
Беззнаковая шеснадцатиричная - fffffff8
Беззнаковая десятичная - -8
Знаковая шеснадцатиричная - fffffff8
Знаковая десятичная - -8
```

## Задача 3. Интерпретация области памяти, print32() и print64()

Реализация функции print32()
```C++
void print32(void *p) {

	std::cout << "Hex 32 bit unsigned reinterpret cast is " << std::hex << *(reinterpret_cast<unsigned int *>(p)) << std::endl;
	std::cout << "Hex 32 bit signed reinterpret cast is " << std::hex << *(reinterpret_cast<int *>(p)) << std::endl;
	
	std::cout << "Dec 32 bit unsigned reinterpret cast is " << std::dec << *(reinterpret_cast<unsigned int *>(p)) << std::endl;
	std::cout << "Dec 32 bit signed reinterpret cast is " << std::dec << *(reinterpret_cast<int *>(p)) << std::endl;

	std::cout << std::endl;
}
```

Реализация функции print64()
```C++
void print64(void *p) {

	std::cout << "Hex 64 bit unsigned reinterpret cast is " << std::hex << *(reinterpret_cast<unsigned long long  *>(p)) << std::endl;
	std::cout << "Hex 64 bit signed reinterpret cast is " << std::hex << *(reinterpret_cast<long long *>(p)) << std::endl;
	
	std::cout << "Dec 64 bit unsigned reinterpret cast is " << std::dec << *(reinterpret_cast<unsigned long long  *>(p)) << std::endl;
	std::cout << "Dec 64 bit signed reinterpret cast is " << std::dec << *(reinterpret_cast<long long *>(p)) << std::endl;

	std::cout << "Double 64 bit signed reinterpret cast is " << *(reinterpret_cast<double *>(p)) << std::endl;

	std::cout << std::endl;
}
```

Результат
```
Max unsigned 32 bit print32:
Hex 32 bit unsigned reinterpret cast is ffffffff
Hex 32 bit signed reinterpret cast is ffffffff
Dec 32 bit unsigned reinterpret cast is 4294967295
Dec 32 bit signed reinterpret cast is -1

Min unsigned 32 bit print32:
Hex 32 bit unsigned reinterpret cast is 0
Hex 32 bit signed reinterpret cast is 0
Dec 32 bit unsigned reinterpret cast is 0
Dec 32 bit signed reinterpret cast is 0

Max signed 32 bit print32:
Hex 32 bit unsigned reinterpret cast is 7fffffff
Hex 32 bit signed reinterpret cast is 7fffffff
Dec 32 bit unsigned reinterpret cast is 2147483647
Dec 32 bit signed reinterpret cast is 2147483647

Min signed 32 bit print32:
Hex 32 bit unsigned reinterpret cast is 80000000
Hex 32 bit signed reinterpret cast is 80000000
Dec 32 bit unsigned reinterpret cast is 2147483648
Dec 32 bit signed reinterpret cast is -2147483648

Max unsigned 64 bit print32:
Hex 64 bit unsigned reinterpret cast is 80000000ffffffff
Hex 64 bit signed reinterpret cast is 80000000ffffffff
Dec 64 bit unsigned reinterpret cast is 9223372041149743103
Dec 64 bit signed reinterpret cast is -9223372032559808513
Double 64 bit signed reinterpret cast is -2.122e-314

Min unsigned 64 bit print32:
Hex 64 bit unsigned reinterpret cast is ffffffff00000000
Hex 64 bit signed reinterpret cast is ffffffff00000000
Dec 64 bit unsigned reinterpret cast is 18446744069414584320
Dec 64 bit signed reinterpret cast is -4294967296
Double 64 bit signed reinterpret cast is nan

Max signed 64 bit print32:
Hex 64 bit unsigned reinterpret cast is ffffffff
Hex 64 bit signed reinterpret cast is ffffffff
Dec 64 bit unsigned reinterpret cast is 4294967295
Dec 64 bit signed reinterpret cast is 4294967295
Double 64 bit signed reinterpret cast is 2.122e-314

Min signed 64 bit print32:
Hex 64 bit unsigned reinterpret cast is ffffffff00000000
Hex 64 bit signed reinterpret cast is ffffffff00000000
Dec 64 bit unsigned reinterpret cast is 18446744069414584320
Dec 64 bit signed reinterpret cast is -4294967296
Double 64 bit signed reinterpret cast is nan

Print32 for x in int:
Hex 32 bit unsigned reinterpret cast is a1b2c3d4
Hex 32 bit signed reinterpret cast is a1b2c3d4
Dec 32 bit unsigned reinterpret cast is 2712847316
Dec 32 bit signed reinterpret cast is -1582119980

Print32 for y in int:
Hex 32 bit unsigned reinterpret cast is 3
Hex 32 bit signed reinterpret cast is 3
Dec 32 bit unsigned reinterpret cast is 3
Dec 32 bit signed reinterpret cast is 3

Print32 for z in int:
Hex 32 bit unsigned reinterpret cast is fffffff8
Hex 32 bit signed reinterpret cast is fffffff8
Dec 32 bit unsigned reinterpret cast is 4294967288
Dec 32 bit signed reinterpret cast is -8

Print64 for x in long long:
Hex 64 bit unsigned reinterpret cast is a1b2c3d4
Hex 64 bit signed reinterpret cast is a1b2c3d4
Dec 64 bit unsigned reinterpret cast is 2712847316
Dec 64 bit signed reinterpret cast is 2712847316
Double 64 bit signed reinterpret cast is 1.34032e-314

Print64 for y in long long:
Hex 64 bit unsigned reinterpret cast is 3
Hex 64 bit signed reinterpret cast is 3
Dec 64 bit unsigned reinterpret cast is 3
Dec 64 bit signed reinterpret cast is 3
Double 64 bit signed reinterpret cast is 1.4822e-323

Print64 for z in long long:
Hex 64 bit unsigned reinterpret cast is fffffffffffffff8
Hex 64 bit signed reinterpret cast is fffffffffffffff8
Dec 64 bit unsigned reinterpret cast is 18446744073709551608
Dec 64 bit signed reinterpret cast is -8
Double 64 bit signed reinterpret cast is nan
```

## Задача 5. Изучение расположения байтов в памяти

Реализация функции printDuno()
```C++
void printDump(void *p, size_t N) {

	unsigned char* pbtP = (unsigned char*)(p);

	for (int i = 0; i < N; i++) {

		std::cout << (int)*(pbtP + i) << std::endl;
	}
	std::cout << std::endl;
}
```

Результат
```
x in int:
212
195
178
161

array[] in int:
212
195
178
161
3
0
0
0
248
255
255
255

str1c in char:
98
99
100
120
121
0

str2c in char:
209
145
208
182
208
183
208
184
208
185
0

str1wc in char:
98
0
99
0
100
0
120
0
121
0
0
0

str2wc in char:
81
4
54
4
55
4
56
4
57
4
0
0
```

## Контрольные вопросы

1. Как представляются целые числа со знаком и без знака? Знаковый бит
2. Как перевести число в дополнительный код? Инвертировать бинарный код и прибавить единицу
3. Что такое расширение чисел со знаком и без знака? Добавление незначащих нулей к записи. Для чего нужны операции расширения? Приведение типов
4. Для чего нужно знать порядок следования байтов на вашем компьютере? Для корректной интерпретации информации по адресам
5. Как располагаются в памяти элементы массива? Последовательно
6. Как найти размер массива, зная размер элемента и их количество? Перемножить
7. Как представляется символьная информация в компьютере в кодах ASCII, расширениях ASCII и различных кодировках ```Unicode```? ```ASCII``` - 7 бит на символ, алфавит 127; 
расширенная ```ASCII``` - 8 бит на символ, алфавит 256; ```Unicode``` - 2 байта на символ, алфавит ```2^31```. ```UTF-8 / UTF-16``` - стандарт кодирования, преобразующий номера ячеей таблицы Юникод в бинарные коды с импользованием переменного количества бит: ```8, 16, 24, 32 / 16, 32```
8. Как хранятся русские буквы в "классических" и "широких" строках? Байт на символ в расширенной кодировке ```ASCII``` (требуется установка локали) и 2 байта в кодировке ```Unicode```
9. Как строковые функции ```libc (stdlib)``` определяют конец строки? Детерминирующий ноль сигнализирует о конце строки
10. Сколько символов (для узких строк - узких символов ```char```, для широких - ```wchar_t```) необходимо для представления строки из 5 символов? 6 для char ```(5 + 1)``` и ```11 (5*2 + 1)``` для ```wchar_t```
