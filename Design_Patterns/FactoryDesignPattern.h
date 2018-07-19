#include <iostream>
using namespace std;

enum vehicle{
    AVENGER,
    DUCATI,
    FZ,
    NANO,
    FARARI,
    INDICA
};

class Vehicle{

private:
    vehicle typeOfVehicle;

public:

    Vehicle(vehicle type){
        typeOfVehicle = type;
        cout << "Vehicle::Constructor" << endl;
    }

    vehicle getTypeOfVechicle() const{
        return typeOfVehicle;
    }

    virtual unsigned short getNumberOfTyres() = 0;
};

class BIKE : public Vehicle{

private:

public:

    BIKE(vehicle type): Vehicle(type){
        cout << "BIKE::Constructor" << endl;
    }

    virtual unsigned short getNumberOfTyres(){
        return 2;
    };

    virtual void WhoAmI() = 0;
};

class CAR : public Vehicle{

private:

public:

    CAR(vehicle type): Vehicle(type){
        cout << "CAR::Constructor" << endl;
    }

    virtual unsigned short getNumberOfTyres(){
        return 4;
    };

    virtual void WhoAmI() = 0;
};


class BIKE_AVENGER : public BIKE{
public:
    BIKE_AVENGER() : BIKE(AVENGER){
        cout << "BIKE_AVENGER::Constructor. Tyres = " << getNumberOfTyres() << endl;
    }

    void WhoAmI(){
        cout << "I am an AVENGER." << endl;
    }
};


class BIKE_DUCATI : public BIKE{
public:
    BIKE_DUCATI() : BIKE(DUCATI){
        cout << "BIKE_DUCATI::Constructor. Tyres = " << getNumberOfTyres() << endl;
    }

    unsigned short getNumberOfTyres(){
        return 3;
    }

    void WhoAmI(){
        cout << "I am a DUCATI." << endl;
    }
};

class BIKE_FZ : public BIKE{
public:
    BIKE_FZ() : BIKE(FZ){
        cout << "BIKE_FZ::::Constructor. Tyres = " << getNumberOfTyres() << endl;
    }

    void WhoAmI(){
        cout << "I am a FZ." << endl;
    }
};

class CAR_FARARI : public CAR{
public:
    CAR_FARARI() : CAR(FARARI){
        cout << "CAR_FARARI::::Constructor. Tyres = " << getNumberOfTyres() << endl;
    }

    void WhoAmI(){
        cout << "I am a FARRARI." << endl;
    }
};

class CAR_NANO : public CAR{
public:
    CAR_NANO() : CAR(NANO){
        cout << "CAR_NANO::::Constructor. Tyres = " << getNumberOfTyres() << endl;
    }

    void WhoAmI(){
        cout << "I am a NANO." << endl;
    }

    unsigned short getNumberOfTyres(){
        return 3;
    }
};

class CAR_INDICA : public CAR{
public:
    CAR_INDICA() : CAR(INDICA){
        cout << "CAR_FARARI::::Constructor. Tyres = " << getNumberOfTyres() << endl;
    }

    void WhoAmI(){
        cout << "I am a INDICA." << endl;
    }
};

class VehicleManager{
public:
    static Vehicle* CreateVehicles(vehicle);
    static void CreateVehiclesUtil();       // This is replica of a call from CLIENT.
};

Vehicle* VehicleManager::CreateVehicles(vehicle vehicleType){
    Vehicle *pVehicle = 0;
    switch(vehicleType){
           case AVENGER:
               pVehicle = new BIKE_AVENGER();
               break;
           case FZ:
               pVehicle = new BIKE_FZ();
               break;
           case DUCATI:
               pVehicle = new BIKE_DUCATI();
               break;
           case NANO:
               pVehicle = new CAR_NANO();
               break;
           case FARARI:
               pVehicle = new CAR_FARARI();
               break;
           case INDICA:
               pVehicle = new CAR_INDICA();
               break;
           default:
               cout << "TYPE NOT DEFINED." << endl;
               break;
    }

    return pVehicle;
}

// This is replica of a call from CLIENT.
void VehicleManager::CreateVehiclesUtil(){
    Vehicle *pVehicle = CreateVehicles(NANO);

    dynamic_cast<CAR_NANO*>(pVehicle)->WhoAmI();

    cout << "I am good." << endl;
}
