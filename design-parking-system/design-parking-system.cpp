class ParkingSystem {
public:
    int big, medium, small;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        int ans = true;
        switch(carType){
            case 1:
                //big space
                if(big == 0){
                    ans = false;
                }
                else{
                    big--;
                }
                break;
            case 2:
                //medium space
                if(medium == 0){
                    ans = false;
                }
                else{
                    medium--;
                }
                break;
            case 3:
                //small space
                if(small == 0){
                    ans = false;
                }
                else{
                    small--;
                }
                break;
        }
        return ans;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */