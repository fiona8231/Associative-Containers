#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;
int main() {

    set<int> set1 {4,2,3,9,1,0,5,10};
//if you want to go through all the elements
    for(int i: set1){
        cout << i << endl;
    } // the result 0 1 2 3 4 5 9 10, which is automatically sorted.

    //erase value
    //set1.erase(5);

    //Erase last2
    //new a iterator
   // void advance (InputIterator& it, Distance n);
    set<int>::iterator itr1;
    itr1 = set1.end();
    advance(itr1, -2);
    //set1.erase(itr1);//0 1 2 3 4 5 10  itr1 point to last 2, only delete one element

    //if want to delete last 2 element .erase(begin, end)
    set1.erase(itr1, set1.end()); //0 1 2 3 4 5

   //find value
    auto value = set1.find(2);
    cout << "Found: " << *value << endl; //Found: 2

    // Get iterator to value
    //Returns an iterator pointing

    auto itrlow = set1.lower_bound(1);
    cout << "1 :" << *itrlow << endl;
    auto itrup  = set1.upper_bound(3);

    set1.erase(itrlow, itrup); // get rid of element 1-3

    //get values with an iterator
    //here itr is a pointer
    for(itr1 = set1.begin(); itr1!= set1.end(); itr1++ ){
        cout << *itr1 << " " ;
    }

    // ------------------//

    set<int> set2 {3,5,6,0};
    set1.swap(set2); //after swap set1: 0 3 5 6

    cout << endl << "after swap set1: ";
    for(itr1 = set1.begin(); itr1!= set1.end(); itr1++ ){
        cout << *itr1 << " " ;

    }
// ----- END OF SET -----

// ----- MULTISET -----
    // Stores duplicate values in sorted order
    // Other than that it is the same as set
    std::multiset<int> mset1 {1,1,2,3,4};

    // Insert value
    mset1.insert(4);
    mset1.insert(0);

    if(!mset1.empty()){
        for(int i : mset1)
            std::cout << i << "\n";
    }

    // ----- MAP -----
    // Stores using key value pairs and you
    // can't have duplicate keys
     map<int, string> map1;

    map1.insert(pair <int, string>(1, "Cat"));
    map1.insert(pair<int, string> (2,"Dog"));
    map1.insert(pair<int, string> (3, "Fish"));

    //go through the element in map -> have to use iterator
    map<int, string>:: iterator itr3;

    for(itr3 = map1.begin(); itr3 != map1.end(); itr3 ++){
      //cout << *itr3 << " " //wrong way
      cout << "int: " << itr3->first << " ";
      cout << "String: " << itr3->second << " ";

    }

    //find value by key -> using iterator
    cout << endl;

    auto itr4 = map1.find(1); // also itr4 is a pointer
    cout << "Found key1 value is: " << itr4->second << endl;

    // Get iterator to value
    auto bart = map1.lower_bound(1);
    std::cout << "LB : " << bart->second << "\n"; //LB : Cat

    // Get next iterator
    auto lisa = map1.upper_bound(1);
    std::cout << "UB : " << lisa->second << "\n"; //UB : Dog

    // ----- QUEUE -----
    // Provides an interface for storing elements in a FIFO
    // format

    queue<string> queue1;
    queue1.push("Lily");
    queue1.push("Spot");
    queue1.push("Sayoli");
    int size = queue1.size();
    for(int i = 0; i< size ; i++){
        cout << queue1.front() << " " << endl;

        // Delete last value entered
       queue1.pop();

    }

    // ----- PRIORITY QUEUE -----
    // Elements are organized with the largest first
   priority_queue<int> queue2;
    queue2.push(3);
    queue2.push(6);
    queue2.push(8);

    int size2 = queue2.size();

    for(int i = 0 ; i < size2; i++){
        cout << queue2.top() << " " ;
        queue2.pop(); //8 6 3
    }



    return 0;
}