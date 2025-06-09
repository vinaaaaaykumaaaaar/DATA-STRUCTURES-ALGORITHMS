#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
      unordered_map<string , int > grades;

      // directly inserting 
      grades["Vinay Kumar"] = 100;
      grades["Vijay Kumar"] = 0;

      // using insert method
      grades.insert({"Vini",100});
      grades.insert({"Vinay Kumar", 200});
      grades["Vinay Kumar"] = 400;
      

      string name = "Vinay Kumar";


      cout<<grades.count(name)<<endl;
      cout<<grades[name]<<endl;
      return 0;
}

