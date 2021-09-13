//Problem source: B. Who's Opposite?
//http://codeforces.com/problemset/problem/1560/B
//Type: bruteforce, math, *800
#include<fstream>
#include<stdlib.h>
using namespace std;

int oppo(int i,int j,int k)
{
	int half;
	half = abs(i-j);
	if(k > half*2 || (i > j && j-1 > half-1) || (i < j && i-1 > half-1) || half <=1) 
	{
		return -1;
	} else
	{
		if(k > half)
		{	
			return k-half;
		} else
		{	
			return k+half;
		}
	}
}

int main()
{
	int n,i,a,b,c,re;	
	ifstream inp;
	ofstream outp;
	inp.open("OPPOSITE.INP");
	outp.open("OPPOSITE.OUT");
	
	inp >> n;
	for(i=1;i<=n;i++)
	{
		inp >> a >> b >> c;
		re = oppo(a,b,c);
		outp << re << endl;
	}

	inp.close();
	outp.close();
	return 0;
}
