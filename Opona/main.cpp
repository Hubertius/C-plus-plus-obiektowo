#include <iostream>
#include "opona.h"

using namespace std;

int main()
{
    
    Opona first__opona; // zgodnie z konstruktorem domyslnym da przebicie = 0
    cout << "Dla pierwszej opony z detka przebicie jest rowne = " << first__opona.Przebicie(8) << endl;
    Opona second_opona; // dla sredniej wiekszej od 10 da przebicie = 1
    cout << "Dla pierwszej opony bez detki przebicie jest rowne = " << first__opona.Przebicie(12) << endl;
    OponaBezdetkowa opona_bez_dedtki; // dla sredniej wiekszej od 20 da przebicie = 1
    cout << "Dla drugiej opony bez detki przebicie jest rowne = " << first__opona.Przebicie(21) << endl;
    return 0;
}