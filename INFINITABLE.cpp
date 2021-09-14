#include<fstream>
#include<tuple>
using namespace std;

std::tuple<int,int> pos(int n)
{
	int i,j,k,sum;
	i = 0;
	sum = 1;
	while(sum < n)
	{
		i = i+1;
		sum = sum +(2*i) +1;
	}
	
	j = sum -n +1;
	if( j > i+1)
	{
		j = i+1;
		k = sum -j +1;
		i = j-(k -n +1) +1;
	} else
	{
		i = i +1;
	}	
	
	return std::make_tuple(i,j);
}

int main()
{
	int i,t,k,x,y;
	ifstream inp;
	ofstream outp;
	inp.open("INFINITABLE.INP");
	outp.open("INFINITABLE.OUT");

	inp >> t;
	for(i=1;i<=t;i++)
	{
		inp >> k;
		if(k == 1)
		{
			outp << 1 << " " << 1 << endl;
		} else
		{
			tie(x,y) = pos(k);
			outp << x << " " << y << endl;
		}
	}

	inp.close();
	outp.close();
	return 0;
}
