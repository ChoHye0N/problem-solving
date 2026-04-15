#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double method1(int distance, const vector<double>& times) {
    double total_time = 0.0;
    for (double time : times) {
        total_time += time;
    }
    return distance / total_time * 10;
}

double method2(int distance, const vector<double>& times) {
    double total_speed = 0.0;
    for (double time : times) {
        total_speed += distance / time;
    }
    return total_speed / times.size();
}

int main() {
    int african_distance, european_distance;
    cin >> african_distance >> european_distance;

    vector<double> african_times, european_times;
    for (int i = 0; i < 20; ++i) {
        char type;
        double time;
        cin >> type >> time;

        if (type == 'a' || type == 'A') {
            african_times.push_back(time);
        }
        else if (type == 'e' || type == 'E') {
            european_times.push_back(time);
        }
    }

    cout << "Method 1" << '\n';
    cout << "African: " << fixed << setprecision(2) << method1(african_distance, african_times) << " furlongs per hour" << '\n';
    cout << "European: " << fixed << setprecision(2) << method1(european_distance, european_times) << " furlongs per hour" << '\n';

    cout << "Method 2" << '\n';
    cout << "African: " << fixed << setprecision(2) << method2(african_distance, african_times) << " furlongs per hour" << '\n';
    cout << "European: " << fixed << setprecision(2) << method2(european_distance, european_times) << " furlongs per hour";

    return 0;
}