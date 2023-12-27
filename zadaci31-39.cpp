#include <iostream>
#include <limits>
#include <math.h>
#include <iomanip>
#include <cmath>


void program31() //Задание 31. Расписание звонков
{
    int h, m, k, l, b, s;
    std::cout << "Enter the beginning time in H and M\n";

    if ((!(std::cin >> h >> m)) || (std::cin.peek() != '\n')) {
        std::cerr << "Input error. Not an integer number or too great number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (h < 0 || h > 23 || m < 0 || m > 59) {
        std::cerr << "There are no such numbers on the clock.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter the amount of lessons, their length in M and break length in M\n";

    if ((!(std::cin >> k >> l >> b)) || (std::cin.peek() != '\n')) {
        std::cerr << "Input error. Not an integer number or too great number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (k < 1 || l < 0 || b < 0) {
        std::cerr << "Numbers must be natural.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    for (int i = 1; i <= k; i++)
    {
        if (m < 10) {
            std::cout << i << ". " << h << ":" << 0 << m << " - ";
        }
        else {
            std::cout << i << ". " << h << ":" << m << " - ";
        }
        s = m * 60 + h * 3600;
        s += l * 60;
        h = (s / 3600) % 24;
        m = (s % 3600) / 60;
        if (m < 10) {
            std::cout << h << ":" << 0 << m << "\n";
        }
        else {
            std::cout << h << ":" << m << "\n";
        }
        s = m * 60 + h * 3600;
        s += b * 60;
        h = (s / 3600) % 24;
        m = (s % 3600) / 60;
    }
    return;
}

void program32() //Задание 32. Простые числа меньше N
{
    int n;
    bool flag;
    std::cout << "Enter natural number N. Program will write all the simple numbers less than N\n";

    if ((!(std::cin >> n)) || (std::cin.peek() != '\n')) {
        std::cerr << "Input error. Not an integer number or too great number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (n < 3) {
        std::cerr << "There's no simple numbers less than " << n << "\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    for (int i = 2; i < n; i++)
    {
        flag = 0;
        for (int j = 2; j < n; j++)
        {
            if ((i != j) && (i % j == 0))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            std::cout << i << " ";
        }
    }
    return;
}

void program33() //Задание 33. Сумма последовательности
{
    int n, k = 1;
    double x, s = 0;
    std::cout << "Enter N and X to find sum of sequense [x - (x^3/3!) + (x^5/5!) -...+-(x^n/n!)]\n";
    if ((!(std::cin >> n >> x)) || (std::cin.peek() != '\n')) {
        std::cerr << "Input error. Not an integer number or too great number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (n < 3 || n > 12) {
        std::cerr << "N is too small or to big.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    if (n % 2 == 0) {
        n -= 1;
        std::cout << "N was even. Rounded to " << n << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        k *= i;
        if (i % 2 == 0) {
            k *= -1;
        }
        else {
            s += (pow(x, i) / k);
            std::cout << "N = " << i << " S = " << s << "\n";
        }
    }
    std::cout << "Sum of sequense equals " << s << "\n";
    return;
}

void program34() //Задание 34. Фибоначчи
{
    int k, f, f1 = 1, f2 = 1;
    std::cout << "Program will write first K numbers in Fibonacci sesuence. Enter natural K.\n";
    if ((!(std::cin >> k)) || (std::cin.peek() != '\n')) {
        std::cerr << "Input error. Not an integer number or too great number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (k < 3 || k > 46) {
        std::cerr << "K is to small or to big to calculate.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << f1 << " " << f2 << " ";
    for (int i = 3; i <= k; i++)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        std::cout << f << " ";
    }
    return;
}

void program35() //Задание 35. Угадай число
{
    int n, k, i;
    std::cout << "Guess the number from 1 to 1000 in 10 tries!\n";
    n = rand() % 1000 + 1;
    //std::cout << n;
    for (i = 0; i < 10; i++)
    {
        if ((!(std::cin >> k)) || (std::cin.peek() != '\n')) {
            std::cerr << "Input error. Not an integer number or too great number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        if (k == n) {
            std::cout << "Right! You guessed on your " << i + 1 << " try.\n";
            return;
        }
        if (k < n) {
            std::cout << "The hidden number is greater >. ";
        }
        else {
            std::cout << "The hidden number is less <. ";
        }
        std::cout << 9 - i << " attempts left!\n";
    }
    std::cout << "Failure!\n";
    return;
}

void program36() //Задание 36. Таблица умножения
{
    int n, k = 0, x, y, sec = 0;
    std::cout << "Guess 10 examples from multiplication.\n";

    for (int i = 0; i < 10; i++)
    {
        x = rand() % 8 + 2;
        y = rand() % 8 + 2;
        std::cout << x << " * " << y << " = ";

        if ((!(std::cin >> n)) || (std::cin.peek() != '\n')) {
            std::cerr << "Input error. Not an integer number or too great number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        if (x * y == n) k++;
    }

    switch (k)
    {
    case 0:case 1:case 2:case 3:case 4:case 5:case 6: std::cout << k << " right answers. Bad."; break;
    case 7:case 8: std::cout << k << " right answers. Ok."; break;
    case 9: std::cout << k << " right answers. Good."; break;
    case 10: std::cout << k << " right answers. Excellent."; break;
    }
    return;
}

void program37() //Задание 37. Римские числа
{
    std::cout << "Enter a number up to 3999 to covert it to roman numeral.\n";
    int n, x;
    char c1, c2, c3;

    if ((!(std::cin >> n)) || (std::cin.peek() != '\n')) {
        std::cerr << "Input error. Not an integer number or too great number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (n < 1 || n > 3999) {
        std::cerr << "N must me less than 4000 and greater than 0.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << n << " = ";

    int d1 = (n % 10);
    int d2 = (n / 10) % 10;
    int d3 = (n / 100) % 10;
    int d4 = (n / 1000);

    for (int i = 0; i < d4; i++)
    {
        std::cout << "M";
    }

    for (int i = 3; i >= 1; i--)
    {
        switch (i)
        {
        case 1: c1 = 'I'; c2 = 'V'; c3 = 'X'; x = d1; break;
        case 2: c1 = 'X'; c2 = 'L'; c3 = 'C'; x = d2; break;
        case 3: c1 = 'C'; c2 = 'D'; c3 = 'M'; x = d3; break;
        }

        switch (x)
        {
        case 1: std::cout << c1; break;
        case 2: std::cout << c1 << c1; break;
        case 3: std::cout << c1 << c1 << c1; break;
        case 4: std::cout << c1 << c2; break;
        case 5: std::cout << c2; break;
        case 6: std::cout << c2 << c1; break;
        case 7: std::cout << c2 << c1 << c1; break;
        case 8: std::cout << c2 << c1 << c1 << c1; break;
        case 9: std::cout << c1 << c3; break;
        }
    }
    '\n';
    return;
}

void program38() //Задание 38. Вывод таблицы умножения
{
    std::cout << "\t|    ";
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << "\t    ";
    }
    std::cout << "\n________|";
    for (int i = 1; i < 80; i++)
    {
        std::cout << "_";
    }
    std::cout << "\n    ";
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << "\t|    ";
        for (int j = 1; j <= 10; j++)
        {
            std::cout << i * j << "\t    ";
        }
        std::cout << "\n\t|\n    ";
    }
    getchar();
    return;
}

void program39() //Задание 39. Мили и километры
{
    std::cout << "Enter how many rows will be in the table: \n";
    int k;
    double m = 1, km = 1;
    if ((!(std::cin >> k)) || (std::cin.peek() != '\n')) {
        std::cerr << "Input error. Not an integer number or too great number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    if (k < 1) {
        std::cerr << "Cannot be less than 1 row!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "_________________________________\n     miles\t\|      km\t|\n________________|_______________|\n    ";
    for (int i = 1; i <= k; i++)
    {
        if (km / 1.6093 < m) {
            std::cout << km / 1.6093 << "\t|    " << km << "\t\t|\n    ";
            km++;
        }
        else {
            std::cout << m << "\t\t|    " << m * 1.6093 << "\t|\n    ";
            m++;
        }
    }
    return;
}

int main()
{
    int x = 1;
    do {

        //program31();
        //program32();
        program33();
        //program34();
        //program35();
        //program36();
        //program37();
        //program38();
        //program39();

        std::cout << '\n';
    } while (x == 1);
    return 0;
}