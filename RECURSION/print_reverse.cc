#include <iostream>
using namespace std;

void printN(int n)
{
    if (n == 0)
        return;
    printN(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;

    printN(n);

    return 0;
}


/*
printTillN(5)
 -> printTillN(4)
  -> printTillN(3)
   -> printTillN(2)
    -> printTillN(1)
     -> printTillN(0) -> return
    <- cout << 1
   <- cout << 2
  <- cout << 3
 <- cout << 4
<- cout << 5
*/