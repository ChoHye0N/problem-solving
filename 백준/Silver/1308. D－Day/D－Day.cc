#include <iostream>

using namespace std;

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int year, int month) {
    if (month == 2)
        return is_leap_year(year) ? 29 : 28;

    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

int days_from_year_start(int year, int month, int day) {
    int days = day;
    for (int m = 1; m < month; ++m)
        days += days_in_month(year, m);
    return days;
}

int days_between_dates(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay) {
    int days = 0;

    for (int y = startYear; y < endYear; ++y)
        days += is_leap_year(y) ? 366 : 365;

    days -= days_from_year_start(startYear, startMonth, startDay);
    days += days_from_year_start(endYear, endMonth, endDay);

    return days;
}

int main() {
    int year, mon, day;
    int dYear, dMon, dDay;

    cin >> year >> mon >> day;
    cin >> dYear >> dMon >> dDay;

    if (dYear - year > 1000 || (dYear - year == 1000 && (dMon > mon || (dMon == mon && dDay >= day)))) {
        cout << "gg" << '\n';
        return 0;
    }

    int ans = days_between_dates(year, mon, day, dYear, dMon, dDay);

    cout << "D-" << ans << '\n';

    return 0;
}