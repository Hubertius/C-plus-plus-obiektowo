#include <iostream>
using namespace std;

class ExceptionDivideByZero
{
    public:
        void getErrorMessage() { cout << "Cholero nie dziel przez zero!" << endl; };
};

double divide(double a, double b) throw(ExceptionDivideByZero) // zwiększenie przejrzystości kodu przez danie informacji o wyjątku
{
    if( b == 0 )
    {
        throw ExceptionDivideByZero();
    }
    return a / b;
}

int main()
{
    try{
        double score = divide(5.0, 0);
    }
    catch(ExceptionDivideByZero exception) {
        exception.getErrorMessage();
    }
    catch( ... ) {
        cout << "Any other exception!" << endl;
    }
    return 0;
}