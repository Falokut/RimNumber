#include <iostream>
#include <string>

std::string InRim(const int number);
std::string RimEds(const int eds)
{
    return SwitchRim('I', 'V', 'X', eds);
}
std::string RimTen(const int ten)
{
    return SwitchRim('X', 'L', 'C', ten);
}
std::string SwitchRim(const char juniorCategory, const char middleCategory, const char seniorCategory, const int Category);

int main()
{
    using namespace std;
    int number;
    setlocale(LC_ALL, "ru");
    cout << "Введите число :\n";
    cin >> number;
    while (number < 1 || number > 100)
    {
        cout << "Вы ввели число меньше 1 или больше 100, введите число снова: \n";
        cin >> number;
    }
    cout << "\n  В римской системе = " << InRim(number) << endl;
    system("pause>nul");
}

std::string InRim(const int number)
{
    if (number == 100) return "C";

    std::string Answer;
    int eds, ten, hun;
    eds = number % 100 % 10;
    ten = number % 100 / 10;

    Answer += RimTen(ten);
    Answer += RimEds(eds);
    return Answer;
}

// Функция получает на вход три параметра типа символ: символ младшего разряда, символ среднего разряда и символ старшего разряда,
// и одну переменную целочисленного типа больше нуля и меньше 10 (число класса разряда)
std::string SwitchRim(const char juniorCategory, const char middleCategory, const char seniorCategory, const int Category)
{
    /* Схема патернов
     *
     * младший              - 1
     * 2*младший            - 2
     * 3*младший            - 3
     *
     * младший + средний    - 4
     * средний              - 5
     *
     * средний * младший    - 6
     * средний + 2*младший  - 7
     * средний + 3*младший  - 8
     *
     * младший + старший    - 9
     */

    if (Category <= 0) return "";
    if (Category == 10)
    {
        std::cout << "число разряда больше 10, что-то пошло не так\n";
        return "";
    }
    std::string Answer = "";

    // В этой функции мы с помощью цикла заполняем массив символов символами младшего разряда (Смотри схему паттерна)
    // Примечание: число итераций должно быть меньше 3, т.к. паттерн меняется в следующих точках: 4,5,9
    auto juniorCycle = [&juniorCategory](const int Count)
    {
        std::string Answer = "";
        if (Count >= 4) return Answer;
        for (int i = 0; i < Count; ++i)
        {
            Answer += juniorCategory;
        }
        return Answer;
    };

    // до 3 действует первый паттерн
    if (Category <= 3)
    {
        Answer = juniorCycle(Category);
        return Answer;
    }

    else if (Category == 4)
    {
        Answer = juniorCategory;
        Answer = +middleCategory;
        return Answer;
    }

    // после 4 и до 8 действует другой паттерн, смотри на схему паттернов
    else if (Category <= 8)
    {
        Answer = middleCategory;
        Answer += juniorCycle(Category - 5);
        return Answer;
    }

    Answer = juniorCategory;
    Answer += seniorCategory;
    return Answer;
}
