#include <iostream>
using namespace std;

class Time {
    int hours, minutes, seconds;
public:
    Time();
    Time(int, int, int);
    Time(const Time &);
    ~Time() {}

    friend istream &operator>>(istream &, Time &);
    friend ostream &operator<<(ostream &, const Time &);

    void normalize();
    int totalSeconds() const;

    Time operator+(const Time &) const;
    Time operator-(const Time &) const;
    bool operator>(const Time &) const;
    bool operator<(const Time &) const;
};

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(const Time &t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds) {}

istream &operator>>(istream &in, Time &t) {
    cout << "\nEnter hours: ";
    in >> t.hours;
    cout << "Enter minutes: ";
    in >> t.minutes;
    cout << "Enter seconds: ";
    in >> t.seconds;
    t.normalize();
    return in;
}

ostream &operator<<(ostream &out, const Time &t) {
    out << "\nTime: " << t.hours << " hours " << t.minutes << " minutes " << t.seconds << " seconds";
    return out;
}

void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
}

int Time::totalSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

Time Time::operator+(const Time &t) const {
    Time result;
    result.seconds = seconds + t.seconds;
    result.minutes = minutes + t.minutes;
    result.hours = hours + t.hours;
    result.normalize();
    return result;
}

Time Time::operator-(const Time &t) const {
    Time result;
    int totSec1 = totalSeconds();
    int totSec2 = t.totalSeconds();
    if (totSec1 < totSec2) {
        result.seconds = 0;
        result.minutes = 0;
        result.hours = 0;
    } else {
        int totSec = totSec1 - totSec2;
        result.hours = totSec / 3600;
        totSec %= 3600;
        result.minutes = totSec / 60;
        result.seconds = totSec % 60;
    }
    return result;
}

bool Time::operator>(const Time &t) const {
    return totalSeconds() > t.totalSeconds();
}

bool Time::operator<(const Time &t) const {
    return totalSeconds() < t.totalSeconds();
}

int main() {
    Time t1, t2;
    
    cout << "t1:\n";
    cin >> t1;
    cout << "t2:\n";
    cin >> t2;
    
    cout << t1;
    cout << t2;

    Time sum = t1 + t2;
    cout << "\n Sum :" << sum;

    Time diff = t1 - t2;
    cout << "\n Difference :" << diff;

    if (t1 > t2) {
        cout << "\nT1 is greater than T2";
    } else if (t1 < t2) {
        cout << "\nT1 is less than T2";
    } else {
        cout << "\nT1 is equal to T2";
    }

    return 0;
}
