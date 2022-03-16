class ParkingSystem {
public:
    vector<int> vehicle;
    
    ParkingSystem(int big, int medium, int small) {
        vehicle = {big,medium,small};
    }
    
    bool addCar(int cartype) {
        cartype--;
        if(vehicle[cartype]>0){
            vehicle[cartype]--;
            return true;
        }
        
        return false;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */