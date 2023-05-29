class ParkingSystem {
    vector<int> type = vector<int>(3);
    
public:
    ParkingSystem(int big, int medium, int small) {
        type[0] = big;
        type[1] = medium;
        type[2] = small;
    }
    
    bool addCar(int carType) {
        if(type[carType-1] > 0) {
            type[carType-1]--;
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