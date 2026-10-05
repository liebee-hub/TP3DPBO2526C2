#pragma once

#include <string>

using namespace std;

// Format angka menjadi Rupiah, contoh: 16200 -> "Rp 16.200"
inline string formatRupiah(int amount)
{
    string s = to_string(amount);
    string result = "";
    int count = 0;
    for (int i = (int)s.length() - 1; i >= 0; i--)
    {
        result = s[i] + result;
        count++;
        if (count % 3 == 0 && i != 0)
            result = "." + result;
    }
    return "Rp " + result;
}

// Format jam, contoh: 9 -> "09:00"
inline string formatHour(int hour)
{
    hour = hour % 24;
    return (hour < 10 ? "0" : "") + to_string(hour) + ":00";
}
