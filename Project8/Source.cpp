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
    cout << "������� ����� :\n";
    cin >> number;
    while (number < 1 || number > 100)
    {
        cout << "�� ����� ����� ������ 1 ��� ������ 100, ������� ����� �����: \n";
        cin >> number;
    }
    cout << "\n  � ������� ������� = " << InRim(number) << endl;
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

// ������� �������� �� ���� ��� ��������� ���� ������: ������ �������� �������, ������ �������� ������� � ������ �������� �������,
// � ���� ���������� �������������� ���� ������ ���� � ������ 10 (����� ������ �������)
std::string SwitchRim(const char juniorCategory, const char middleCategory, const char seniorCategory, const int Category)
{
    /* ����� ��������
     *
     * �������              - 1
     * 2*�������            - 2
     * 3*�������            - 3
     *
     * ������� + �������    - 4
     * �������              - 5
     *
     * ������� * �������    - 6
     * ������� + 2*�������  - 7
     * ������� + 3*�������  - 8
     *
     * ������� + �������    - 9
     */

    if (Category <= 0) return "";
    if (Category == 10)
    {
        std::cout << "����� ������� ������ 10, ���-�� ����� �� ���\n";
        return "";
    }
    std::string Answer = "";

    // � ���� ������� �� � ������� ����� ��������� ������ �������� ��������� �������� ������� (������ ����� ��������)
    // ����������: ����� �������� ������ ���� ������ 3, �.�. ������� �������� � ��������� ������: 4,5,9
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

    // �� 3 ��������� ������ �������
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

    // ����� 4 � �� 8 ��������� ������ �������, ������ �� ����� ���������
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
