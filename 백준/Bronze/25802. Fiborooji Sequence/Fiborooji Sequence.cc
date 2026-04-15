#include <iostream>
using namespace std;

int main() {
    int firstNum, secondNum, length = 2;
    cin >> firstNum >> secondNum;

    int prevNum = firstNum, currNum = secondNum;

    while (1) {
        int nextNum = (prevNum + currNum) % 10;

        prevNum = currNum;
        currNum = nextNum;
        length++;

        if (prevNum == firstNum && currNum == secondNum)
            break;
    }

    cout << length << '\n';

    return 0;
}