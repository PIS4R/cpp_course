
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

template <typename Key, typename Val> class Map {
    private:

        std::vector<Key> keys;
        std::vector<Val> values;
        

    public:
        Map() {}
        ~Map() {}
        //operator przypisania
        Map& operator =( const Klasa & prawy )
        {
            if( & prawy != this )
            {
                //przypisz składowe
            }
            return * this;
        }

        void add(Key t_key, Val t_Employee){

            keys.insert(keys.end(), t_key);
            try{
                values.insert(values.end(), t_Employee);
            } catch(...) {
                keys.erase(--keys.end());
                throw;
            }
        }
        Val* find(Key t_key)  {

            for(auto i = 0; i < this->keys.size(); i++){
                if (keys[i] == t_key){
                    Val* temp1;
                    temp1 = this->values.data();

                    return temp1+i;
                }
            }
            
        }

        friend std::ostream& operator<< (std::ostream& os, const Map& obj){



            for(auto i = 0; i < obj.keys.size(); i++){
                Employee temp;
                temp = obj.values[i];
                os << "key: " << obj.keys[i] << " name: " << temp.name << " position: " << temp.position << " age: " << temp.age << " " << endl;

            }

            return os;
        }
       
};