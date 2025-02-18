#include "MyObj.h"

int MyObj::compareCount = 0;

MyObj::MyObj(int x, int y, int z)
{
	  a[0] = x;
	  a[1] = y; 
	  a[2] = z;
}

MyObj::MyObj()
{
	  a[0] = rand() % 1000;
	  a[1] = rand() % 1000;
	  a[2] = rand() % 1000;
}

MyObj::MyObj(const MyObj& s)
{
   for (int i = 0; i < 3; i++)
	a[i] = s.a[i];
}


MyObj&  MyObj::operator=(const MyObj& s)
{
    for (int i = 0; i < 3; i++)
	a[i] = s.a[i];
    return *this;
}

bool  MyObj::operator<(const MyObj& s)
{
    compareCount++;
    bool res = false;
    if (a[0] < s.a[0])
	res = true;
    else if ((a[0] == s.a[0]) && (a[1] < s.a[1]))
	res = true;
    else if ((a[0] == s.a[0]) && (a[1] == s.a[1]) && (a[2] < s.a[2]))
	res = true;

    return res; 
}

int MyObj::getCount()
{
    return compareCount;
}

void MyObj::reset()
{
    compareCount = 0;
}

ostream& operator<<(ostream& os, const MyObj& s)
{
   os << "(" << s.a[0] << " " << s.a[1] << " " << s.a[2] << ")";
   return os;
}

istream& operator>>(istream& is, MyObj& s)
{
   is >> s.a[0] >> s.a[1] >> s.a[2];
   return is;
}
