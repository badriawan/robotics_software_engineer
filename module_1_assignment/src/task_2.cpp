#include <iostream> //incude libraries
#include <cstdlib> 
#include <vector>

using namespace std; //using std for namespace
class Robot{      //robot class with 3 methods
    public:
    Robot(string name){

        cout <<"Robot name "<<name<<endl;

    };
    void Temperature(int temp){

        cout <<"Temperature is  "<<temp<<" Celcius"<<endl;

    };
     void DistanceSensor(int sensorreading){

        int distance = sensorreading*100; //convert to cm
        cout <<"Distance = "<<distance<<" cm"<<endl;

    };
     
    private:
        int stop;
        string name;

};



int main(){

    int N = 100; //set the variable values
    int temp = 0;
    int sensorreading = 0;
    srand(time(0)); 
    temp = rand()%N; //random values
    sensorreading = rand()%N;
   
   Robot robot_1("Rover"); //class object declaration
   robot_1.Temperature(temp); //method of object
   robot_1.DistanceSensor(sensorreading);


}