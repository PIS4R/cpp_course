using namespace std;
#include <string>

#include <cstdio>
#include <ostream>
class Employee {
    
    public:
        string name;
        string position;
        int age;
 
        Employee() {};
        Employee(string t_name, string t_position, int t_age): name{t_name}, position{t_position}, age{t_age} {

        }
        ~Employee() {};


};