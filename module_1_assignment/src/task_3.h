#ifndef TASK3_H
#define TASK3_H //make the gaurd

#include <iostream> // define all of libraries
#include <vector>
using namespace std; //using std for cout

template<typename D, typename S, typename C> //combine the template with the class
class TempSensor {
public:
    TempSensor(D d1, S d2, C d3) : data1(d1), data2(d2), data3(d3) {} //set the value of argument for the constructor using templates
    void display_sensor();
    
private:
    D data1; //variable of the class
    S data2;
    C data3;
};

template<typename D, typename S, typename C>
void TempSensor<D, S, C>::display_sensor() {
    cout << "TempSensor - Data1: " << data1 << ", Data2: " << data2 << ", Data3: " << data3 << endl;   //method in order to display the data

}

template<typename D, typename S, typename C>
class DistSensor {
public:
    DistSensor(D d1, S d2, C d3) : data1(d1), data2(d2), data3(d3) {}
    void display_sensor();
    
private:
    D data1;
    S data2;
    C data3;
};

template<typename D, typename S, typename C>
void DistSensor<D, S, C>::display_sensor() {
    cout << "DistSensor - Data1: " << data1 << ", Data2: " << data2 << ", Data3: " << data3 << endl;
}

#endif // TASK3_H
