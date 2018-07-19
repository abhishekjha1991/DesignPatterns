#include <iostream>

#include "FactoryDesignPattern.h"
using namespace std;

void testFactoryDesignPattern(){
    cout << "------------ FACTORY DESIGN PATTERN  -------------- " << endl;
    VehicleManager::CreateVehiclesUtil();
}

int main(){
    cout << "Let us learn some basic design patterns? Shall we?" << endl;
    testFactoryDesignPattern();
    return 0;
}
