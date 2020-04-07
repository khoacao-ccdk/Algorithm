#include <iostream>
using namespace std;

class Box
{
private:
    int l;
    int h;
    int b;

public:
    Box()
    {
        l = 0;
        b = 0;
        h = 0;
    }
    Box(int length, int breadth, int height)
    {
        l = length;
        b = breadth;
        h = height;
    }
    Box(Box &x)
    {
       l=x.l;
       b=x.b;
       h=x.h;
    }

    int getLength()
    {
        return l;
    }

    int getBreadth()
    {
        return b;
    }

    int getHeight()
    {
        return h;
    }

    long long CalculateVolume()
    {
        return (long long) l*b*h;
    }


friend bool operator<(Box&a, Box &b)
{
    if ((a.l < b.l) || ((a.b<b.b) && (a.l == b.l)) || ((a.b < b.h) && (a.l==b.l) && (a.b==b.b)))
        return true;
    else
        return false;
}

friend ostream& operator<<(ostream& out, Box& B)
{
    out << B.l <<" " << B.b << " " << B.h;
    return out;
}
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}



