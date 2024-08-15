#include <iostream> //include libraries
#include <vector>

using namespace std; //using std for namespace
namespace R1{
class Robot{  //namespace  with class which contains all of the class methods
    public:
    Robot(string name,int speed,const vector<int> physical){

        cout <<"Robot name "<<name<<endl;
        cout <<"Robot speed "<<speed<<endl;
        //cout <<"Robot ps "<<physical<<endl;

        //for (int num:physical)
        cout <<"Robot weight "<<physical[1]<<endl;
        cout <<"Robot size "<<physical[2]<<endl;
        cout <<"Robot num sensor "<<physical[3]<<endl;
    };
    void MoveForward(int speed){

        cout <<"Move  "<<speed<<endl;

    };
     void MoveBackward(int speed){

        cout <<"Move Backward "<<speed<<endl;

    };
     void Stopping(int stop){

        cout <<"Stop "<<stop<<endl;

    };
    
    private:
        int stop;
        int speed;
        string name;

};
}

namespace R2{
class Robot{
    public:
    Robot(string name,int speed,const vector<int> physical){

        cout <<"Robot name "<<name<<endl;
        cout <<"Robot speed "<<speed<<endl;
        //cout <<"Robot ps "<<physical<<endl;

        //for (int num:physical)
        cout <<"Robot weight "<<physical[1]<<endl;
        cout <<"Robot size "<<physical[2]<<endl;
        cout <<"Robot num sensor "<<physical[3]<<endl;
    };
    void MoveForward(int speed){

        cout <<"Move Forward "<<speed<<endl;

    };
     void MoveBackward(int speed){

        cout <<"Move Backward "<<speed<<endl;

    };
     void Stopping(int stop){

        cout <<"Stopping "<<stop<<endl;

    };
    
    private:
        int stop;
        int speed;
        string name;

};
}

int main(){
    vector<int> spec = {2,10,4}; //{weight,size,number sensor}
    //int spec = 1;
    R1::Robot robot_1("rover",10,spec); //using 2 robots with same spec and different name and action
    robot_1.MoveForward(10);

    R2::Robot robot_2("Jbot",20,spec);
    robot_2.Stopping(10);


}