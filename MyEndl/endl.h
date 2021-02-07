#ifndef ENDL_H_
#define ENDL_H_

#include <iostream>
using namespace std;



namespace mySpace
{
    class MyEndl
    {
        private:
            string m_chain;
        public:
            MyEndl(string chain = "\n" ) : m_chain(chain) {};
            string toString()
            {
                return m_chain;
            }
            friend ostream & operator<<(ostream & os, MyEndl & obj)
            {
                return os << obj.toString();
            }
    };
}

#endif