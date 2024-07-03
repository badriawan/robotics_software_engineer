#include "task_3.h" //include the header files

int main() {
    TempSensor<int, double, string> tempSensor(10, 20.5, "temp");
    tempSensor.display_sensor();  // Output: TempSensor - Data1: 10, Data2: 20.5, Data3: temp

    DistSensor<int, double, string> distSensor(15, 30.7, "dist");
    distSensor.display_sensor();  // Output: DistSensor - Data1: 15, Data2: 30.7, Data3: dist

    return 0;
}
