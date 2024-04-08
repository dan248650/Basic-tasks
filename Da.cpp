// Da.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
using namespace std;

int main()
{
    vector <int64_t> v{};
    int64_t number{}, mn{ 1000000000 }, mx{ -10000000000 }, nomer{};
    cin >> number;
    while (mn + mx != number || v.size() <= 1){
        v.push_back(number);
        mx = max(mx, number);
        mn = min(mn, number);
        cin >> number;
    }
    v.push_back(number);
    for (int64_t i = mn; i <= mx; i++) {
        if (count(v.begin(), v.end(), i) > 1) {
            if (nomer == 0) {
                cout << "Repeating numbers: ";
                nomer++;
            }
            cout << i << " ";
        }
    }
    sort(v.begin(), v.end());
    auto new_end = unique(v.begin(), v.end());
    v.erase(new_end, v.end());
    if (nomer == 1) {
        cout << endl;
    }
    cout << "Result: ";
    for (auto elem : v) {
        cout << elem << " ";
    }
}