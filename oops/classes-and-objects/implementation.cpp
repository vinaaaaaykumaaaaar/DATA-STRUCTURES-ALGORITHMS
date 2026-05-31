#include <bits/stdc++.h>

using namespace std;

class Car
{
public:
    string color;
    string model;

    void startEngine()
    {
        cout << this->color << " " << this->model << endl;
        cout << "Engine Started" << endl;
    }
};

int main()
{

    Car volvo;
    volvo.color = "red";
    volvo.model = "d3";

    volvo.startEngine();
}