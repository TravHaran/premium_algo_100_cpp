#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

/*
Implement a class called ParkingSystem. It takes three arguments into its constructor: small: int, medium: int, large: int, specifying how many parking spots of each type are available. A method addCar(cartype: int) -> bool will perform the following function:
-  Checks if a parking space of type cartype is available (1, 2, 3)
-  A car can only park in a spot of its cartype
-  If a spot is unavailable, return false, otherwise put the car in that spot and return true.
*/

// class ParkingLot {
//   private:
//     int TYPES = 3;
//   public:
//     unordered_map<int, int> limits;
//     unordered_map<int, int> lots;
//     ParkingLot(int small, int medium, int large){
//       // initialize limit hashmap
//       limits = {{1, small}, {2, medium}, {3, large}};
//     }

//     bool addCar(int car){
//       // check that the int we add is one of our types
//       if(!limits.count(car)) return false;
//       // if its not in the lot
//       if(!lots.count(car) && limits[car]!=0) lots[car]++;
//       // if it is in lot
//       else {
//         if(lots[car] < limits[car]){ // spot is available
//           lots[car]++;
//           return true;
//         } else return false; // spot unavailable
//       }
//       return true;
//     }
// };

// // To execute C++, please define "int main()"
// int main() {
//   // (0, 1, 3)
//   ParkingLot plot = ParkingLot(0, 1, 3);
//   // test adding a car thats not type
//   cout<<plot.addCar(4)<<endl; // return false
//   // test adding a car that has limit of zero
//   cout<<plot.addCar(1)<<endl; // return false
//   // test adding a car that has limit of zero
//   cout<<plot.addCar(2)<<endl; // return true;
//   cout<<plot.addCar(2)<<endl; // return false
//   // test adding a car that has limit of 3
//   cout<<plot.addCar(3)<<endl; // return true;
//   cout<<plot.addCar(3)<<endl; // return true
//   cout<<plot.addCar(3)<<endl; // return true
//   cout<<plot.addCar(3)<<endl; // return false
//   return 0;
// }


/*
Modify your class to allow small cars to fit into medium and large spots, and medium cars to fit into large spots (please copy+paste your original class and modify the copy).
*/

class ParkingLot {
  private:
    int TYPES = 3;
    vector<int> types;
    unordered_map<int, int> limits;
    unordered_map<int, int> lots;
    unordered_map<int, int> type_idx;
    bool _addCar(int car){
      // check that the int we add is one of our types
      if(!limits.count(car)) return false;
      // if its not in the lot
      if(!lots.count(car) && limits[car]!=0) lots[car]++;
      // if it is in lot
      else {
        if(lots[car] < limits[car]){ // spot is available
          lots[car]++;
          return true;
        } else return false; // spot unavailable
      }
      return true;
    }
  public:
    ParkingLot(int small, int medium, int large){
      // initialize limit hashmap
      limits = {{1, small}, {2, medium}, {3, large}};
      types = {1, 2, 3};
      type_idx = {{1, 0}, {2, 1}, {3, 2}};
    }

    bool addCar(int car){
      if(!limits.count(car)) return false;
      // starting point
      int start = type_idx[car]; 
      for(int i = start; i < types.size(); i++){
        if(_addCar(types[i])) return true;
      }
      return false;
    }
};

// To execute C++, please define "int main()"
int main() {
  ParkingLot plot = ParkingLot(0, 1, 3);
  // test adding a car thats not type
  cout<<plot.addCar(4)<<endl; // return false

  cout<<plot.addCar(1)<<endl; // return true; [1:0, 2:1,  3:0]

  cout<<plot.addCar(2)<<endl; // return true; [1:0, 2:1,  3:1]
  cout<<plot.addCar(1)<<endl; // return true; [1:0, 2:1,  3:2]

  cout<<plot.addCar(3)<<endl; // return true; [1:0, 2:1,  3:3] => PARKING LOT FILLED
  cout<<plot.addCar(3)<<endl; // return false;
  cout<<plot.addCar(2)<<endl; // return false; 
  /**
   * OUTPUT SHOULD BE...
   * 0
   * 1
   * 1
   * 1
   * 1
   * 0
   * 0
   */
  return 0;
}