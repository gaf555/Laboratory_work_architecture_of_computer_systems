# Лабораторная работа № 3. Использование ассемблерных вставок на С++

## Навигация

1. [Назад (Отладка кода)](https://github.com/konsilerinos/ACS-labs/blob/main/Lab_2/Lab_2.md)
2. [На главную](https://github.com/konsilerinos/ACS-labs)
3. [Вперёд (Модули и функции на ассемблере)](https://github.com/konsilerinos/ACS-labs/blob/main/Lab_4/Lab_4.md)

## Цель

Научиться вставлять в программы на языке высокого уровня ассемблерные фрагменты

## Задачи

1. Реализуйте расчёт беззнакового целочисленного выражения как ассемблерную вставку в программу на C/C++, помещая временные значения в регистры общего назначения `A`, `B`, `C` (в зависимости от разрядности данных — `eax`, `ecx`, `edx` или `rax`, `rcx`, `rdx`) : `z = (x + 79) / y` и `w = (x + 79) % y`
2. Реализовать задание 1, передав вставке в качестве входных параметров не значения `x` и `y`, а указатели `p = &x` и `q = &y`

## Отчёт

| Номер задачи | Ссылка на файл                                                                        |
| ------------ | ------------------------------------------------------------------------------------- |
| 1            | [Task-1.c](https://github.com/konsilerinos/ACS-labs/blob/main/Lab_3/Sources/Task-1.c) |
| 2            | [Task-2.c](https://github.com/konsilerinos/ACS-labs/blob/main/Lab_3/Sources/Task-2.c) |
| 3            | [Task-3.c](https://github.com/konsilerinos/ACS-labs/blob/main/Lab_3/Sources/Task-3.c) |
| 4            | [Task-4.c](https://github.com/konsilerinos/ACS-labs/blob/main/Lab_3/Sources/Task-4.c) |
| 5            | [Task-5.c](https://github.com/konsilerinos/ACS-labs/blob/main/Lab_3/Sources/Task-5.c) |

### Задание 1. Ассемблерные вставки
```C++
// z = (x + 79) / y
asm
(
    "movl    %[x], %%eax\n"
    "addl    $79, %%eax\n"
    "movl    %[y], %%ecx\n"
    "cltd\n"
    "idivl   %%ecx\n"
    "movl    %%eax, %[z]\n"
    :[z]"=rm"(z)
    :[x]"g"(x), [y]"g"(y), "[z]"(z)
);
```
```C++
// w = (x + 79) % y
asm
(
    "movl   %[x], %%eax\n"
    "addl   $79, %%eax\n"
    "cltd\n"
    "idivl  %[y]\n"
    "movl   %%edx, %[w]\n"
    :[w]"=rm"(w)
    :[x]"g"(x), [y]"g"(y), "[w]"(w)
);
```

### Задание 2. Ассемблерная вставка
```C++

```

### Задание 3. Ассемблерная вставка
```C++

```

### Задание 4. Ассемблерная вставка
```C++
// mas[k] = x
asm
(
    "movl	-84(%rbp), %edx\n"
    "movl	-88(%rbp), %ecx\n"
    "movq	-80(%rbp), %rax\n"
    "movslq	%edx, %rdx\n"
    "movl	%ecx, (%rax,%rdx,4)\n"
);
```

### Задание 5. Ассемблерная вставка
```C++

```

## Контрольные вопросы

