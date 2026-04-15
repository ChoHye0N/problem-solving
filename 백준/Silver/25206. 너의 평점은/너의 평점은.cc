#include <bits/stdc++.h>

using namespace std;

int main() 
{
    double totalGrade = 0., avg = 0.;
    unordered_map<string, double> ranks = {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0}
    };
    
    for (int i = 0; i < 20; i++){
        string name, rank;
        double grade;
        cin >> name >> grade >> rank;
        
        if (ranks.count(rank)){
            totalGrade += grade;
            avg += grade * ranks[rank];
        }
    }
    
    printf("%.6f", avg / totalGrade);
    
    return 0;
}