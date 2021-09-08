//Problem source: C. Compressed Bracket Sequence
//https://codeforces.com/contest/1556/problem/C
//Type: brute force, unoptimized
#include<fstream>
using namespace std;
int j,limit=0,total;
long a[1000][2];

//Ham nhap mang va danh dau co the mo rong thanh chuoi hop le khong
void check(int n)
{
	a[limit][2] = a[n-1][1] - a[n][1];
	if(a[n][1] >= a[n-1][1])
	{
		total = total + a[n-1][1];
	} else
	{
		total = total + a[n][1];
	}
}

//Ham su dung du lieu ve kha nang mo rong de tinh cac chuoi con hop le
int extend(int n)
{
	int i, sum=a[n][2],ext;
	ext = 0;
	for(i=n+1;i<=limit;i++)
	{
		ext = ext+1;
		sum = sum + a[i][2];
		if (sum < 0)
		{
			ext = ext + a[n][2];	
			return ext;
			break;
		} else
		{
			if(sum > 0)
			{
				ext = ext +1;
			}
		}
	}
	return ext;
}

int main()
{
	int n,i,j;
	ifstream inp;
	ofstream outp;
	inp.open("BRACKET.INP");
	outp.open("BRACKET.OUT");
	inp >> n;

	for(i=1;i<=n;i++)
	{
		inp >> a[i][1];
		if(i % 2 == 0)
		{
			limit = limit +1;
			check(i);
		}	 
	}

	for(i=1;i<limit;i++)
	{
		if(a[i][2] >=0)
		{
			total = total + extend(i);
		}
	}
	
	outp << total;
	inp.close();
	outp.close();
	return 0;
}
