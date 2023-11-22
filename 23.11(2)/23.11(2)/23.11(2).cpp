#include <iostream>
#include <ctime>
using namespace std;
//1.Я генерирую дату покупки
//2.Герерирую дату конца гарантии 
//3.Ввожу сам сегодняшнюю дату и если она больше,чем дата конца гарантии,то гарантия окончена,а если меньше,то наоброт-не окончена
struct DataBuy {
    int day;
    int month;
    int year;
};

struct DataSell {
    int daydevice;
    int monthdevice;
    int yeardevice;
};

struct Device {
    string devicetype;
    string devicename;
    string devicemodel;
    string brand;
    float price;
    DataSell device;
    DataBuy guarantee;
    int daytoday;
    int monthtoday;
    int yeartoday;
};

void RandomDevice(Device& d)
{
    cout << "Enter device type: ";
    cin >> d.devicetype;
    cout << "Enter device name: ";
    cin >> d.devicename;
    cout << "Enter device model: ";
    cin >> d.devicemodel;
    cout << "Enter device brand: ";
    cin >> d.brand;
    cout << "Enter price: ";
    cin >> d.price;
    if (d.price < 0)
    {
        cout << "Oops, inccorrect price! " << "\n";
        throw "ERROR  PRICE!!!!!";
    }
    //Ввожу сам сегодняшнюю дату и делаю проверку
    cout << "Enter day: ";
    cin >> d.daytoday;
    if (d.daytoday < 0 || d.daytoday > 31)
    {
        cout << "Oops, inccorrect day! " << "\n";
        throw "ERROR  DAY!!!!!";
    }
    cout << "Enter month: ";
    cin >> d.monthtoday;
    if (d.monthtoday< 0 || d.monthtoday > 12)
    {
        cout << "Oops, inccorrect month! " << "\n";
        throw "ERROR  MONTH!!!!!";
    }
    cout << "Enter month: ";
    cin >> d.yeartoday;
    if (d.yeartoday < 0)
    {
        cout << "Oops, inccorrect year! " << "\n";
        throw "ERROR  YEAR!!!!!";
    }
    //Герерирую дату конца гарантии 
    d.guarantee.day = rand() % 28 + 1;
    d.guarantee.month = rand() % 12 + 1;
    d.guarantee.year = rand() % 4 + 2021;
    //генерирую дату покупки
    d.device.daydevice = rand() % 28 + 1;
    d.device.monthdevice = rand() % 12 + 1;
    d.device.yeardevice = rand() % 3 + 2020;
}

void PrintDevice(const Device& d)
{
    cout << d.devicetype << "\n";
    cout << d.devicename << "\n";
    cout << d.devicemodel << "\n";
    cout << d.brand << "\n";
    cout << d.price << "$" << "\n";
    cout << "Buy: " << d.device.daydevice << "." << d.device.monthdevice << "." << d.device.yeardevice << "\n";
    cout << "Garanty: " << d.guarantee.day << "." << d.guarantee.month << "." << d.guarantee.year << "\n";
}

void Garanty(Device& d)
{
    if (d.yeartoday > d.guarantee.year)
    {
        cout << "guarantee is inactive" << "\n";
    }
    else if (d.yeartoday < d.guarantee.year)
    {
        cout << "guarantee is active" << "\n";
    }
    //предусмтариваю,если год будет совпадать 
    else if (d.yeartoday == d.guarantee.year and d.monthtoday < d.guarantee.month and d.daytoday < d.guarantee.day)
    {
        cout << "guarantee expires" << "\n";
    }
    else if (d.yeartoday == d.guarantee.year and d.monthtoday > d.guarantee.month and d.daytoday > d.guarantee.day)
    {
        cout << "guarantee is inactive" << "\n";
    }
}
int main()
{
    srand(time(NULL));
    Device e;
    RandomDevice(e);
    PrintDevice(e);
    Garanty(e);
}