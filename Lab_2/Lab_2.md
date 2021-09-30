# Лабораторная работа № 2. Отладка кода

## Цель

Научиться использовать инструменты отладки

## Задача 1

Разработайте программу на языке C/C++, вычисляющую целое выражения от целого аргумента 
(в соответствии с вариантом). Переменные ```x```, ```y```, ```result``` — локальные переменные функции ```main()```

| Вариант | Выражение                        |
| ------- | -------------------------------- |
| 1       | `result = f(x, y) = x + y + 177` |

### Вычисление

#### Функция function()
```C++
int function(int digit1, int digit2) { return digit1 + digit2 + 177; }
```
#### Функция main()
```C++
int main() {

    int x = 0;
    int y = 0;
    int result = 0;

    x = SafeIntCin("Enter x: ");
    y = SafeIntCin("Enter y: ");

    result = function(x, y);

    std::cout << "Result is " << result << std::endl;

    return 0;
}
```

#### Функция SafeIntCin
```C++
int SafeIntCin(std::string msg) {

    int x = 0;

    while (true) {

        std::cout << msg;
        std::cin >> x;

        if (std::cin.fail()) {

            std::cout << "Error! Wrong input! Try it again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(99999, '\n');
        } else {

            std::cout << "Success!" << std::endl;
            std::cin.ignore(99999, '\n');
            break;
        }
    }

    return x;
}
```

## Задание 2
Откройте окно «Регистры» и отследите изменение регистров общего назначения и регистра флагов при вычислении `f(x,y)`

### Изменение регистров общего назначения
![изображение](https://user-images.githubusercontent.com/78896451/134811118-264ac4c9-03a9-4136-bd5a-bf138b29a1ce.png)

## Задание 3
Откройте окно «Память» и отследите изменение переменных `x`, `y` и `result`. Сопоставьте адреса локальных нестатических переменных и значение
регистра `sp` (указателя вершины стека: `rsp` в 64-битном режиме и `esp` в 32-битном)

### Отслеживание изменения переменной x (0 -> 1)
![изображение](https://user-images.githubusercontent.com/78896451/134170415-b8640885-36e0-4e29-9f71-56857a48515e.png)

### Отслеживаиние изменения переменной y (0 -> 777777)
![изображение](https://user-images.githubusercontent.com/78896451/134170806-d0277638-4a7f-4ac4-9aa5-d33ab05cc8a4.png)

### Отслеживание изменения переменной result (0 -> 777955)
![изображение](https://user-images.githubusercontent.com/78896451/134171236-43c68224-dce0-44fd-94f2-b05aa617311a.png)


### Изменение регистра стека esp
![изображение](https://user-images.githubusercontent.com/78896451/134811613-0db4f450-5494-4fd3-9dcf-9603b40ad325.png)

### Фрагмент дизассемблированного кода (синтаксис AT&T)

![image](https://user-images.githubusercontent.com/78896451/135437451-4735feaf-ae84-4124-a73e-e66c3a4840b7.png)
