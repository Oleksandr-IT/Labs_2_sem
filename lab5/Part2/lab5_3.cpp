#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

string numInWord(int n) {
    if (n==0) return "нуль";
    string ones[]={"","один","два","три","чотири","п'ять","шість","сім","вісім","дев'ять"};
    string teens[]={"десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять"};
    string tens[]={"","","двадцять", "тридцять", "сорок", "п'ятдесят", "шістдесят", "сімдесят", "вісімьдесят", "дев'яносто"};
    string hundreds[] = {"", "сто", "двісті", "триста", "чотириста", "п'ятсот", "шістсот", "сімсот", "вісімсот", "дев'ятсот"};
    string res = "";

    if (n >= 100) {
        res += hundreds[n / 100] + " ";
        n %= 100;
    }
    if (n >= 10 && n < 20) {
        res += teens[n - 10] + " ";
    } else {
        if (n >= 20) {
            res += tens[n / 10] + " ";
            n %= 10;
        }
        if (n > 0) {
            res += ones[n] + " ";
        }
    }
    return res;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int rad;
    cout<<"Введіть кут у радіанах(число): ";
    cin>>rad;
    cout<<numInWord(rad)<<endl;

    return 0;
}