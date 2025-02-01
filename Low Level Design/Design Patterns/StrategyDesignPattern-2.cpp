// Example: Drive Strategy System
// Let's say we have different drive methods (Sports Vehicle, Off-road drive), and we want to allow users to choose their drive strategy dynamically.

#include<bits/stdc++.h>
using namespace std;

// Drive Strategy Interface
class DriveStrategy{
public:
    virtual void drive() = 0;
};

// Concrete Strategy 1 : Using SportVehicle class
class SportVehicle : public DriveStrategy{
public:
    void drive(){
        cout << "Driving sports vehicle" << endl;
    }
};

// Concrete Strategy 2 : Using off- road vehicle class
class OffRoadVehicle : public DriveStrategy{
public:
    void drive(){
        cout << "Driving off-road vehicle" << endl;
    }
};

// Context class
class DriveContext{
private:
    unique_ptr<DriveStrategy> strategy;

public:
    void setStrategy(unique_ptr<DriveStrategy> s){
        strategy = move(s);
    }

    void processDrive(){
        if(strategy){
            strategy->drive();
        }else{
            cout << "No strategy set" << endl;
        }
    }
};

int main(){
    DriveContext obj;
    obj.setStrategy(make_unique<SportVehicle> ());
    obj.processDrive();

    obj.setStrategy(make_unique<OffRoadVehicle> ());
    obj.processDrive();

    return 0;
}