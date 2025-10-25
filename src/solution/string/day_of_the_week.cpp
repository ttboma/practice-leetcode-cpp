#include "solution.hpp"

std::string Solution::dayOfTheWeek(int day, int month, int year) {
    static const std::vector<std::string> weekdays = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                                      "Thursday", "Friday", "Saturday"};
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int f = day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    int weekdayIndex = f % 7;
    return weekdays[(weekdayIndex + 6) % 7];
}
