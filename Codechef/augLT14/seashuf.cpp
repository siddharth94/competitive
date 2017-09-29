#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
#define pii pair <int, int>
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void print(int n)
{
	register int a1,a2,a3,a4,a5,a6,a7,a8,a9,r;
	r=n;
	a1 = r%10;
	r/=10;
	if (r!=0)
	{
		a2 = r%10;
		r/=10;
		if (r!=0)
		{
			a3 = r%10;
			r/=10;
			if (r!=0)
			{
				a4 = r%10;
				r/=10;
				if (r!=0)
				{
					a5 = r%10;
					r/=10;
					if (r!=0)
					{
						a6 = r%10;
						r/=10;
						if (r!=0)
						{
							a7 = r%10;
							r/=10;
							if (r!=0)
							{
								a8 = r%10;
								r/=10;
								if (r!=0)
									pc(r+'0');
								pc(a8+'0');
							}
							pc(a7+'0');
						}
						pc(a6+'0');
					}
					pc(a5+'0');
				}
				pc(a4+'0');
			}
			pc(a3+'0');
		}
		pc(a2+'0');
	}
	pc(a1+'0');
	// pc('\n');
}

int a[100005];
int out[300005];

int main()
{
	double mtime = 0;
	clock_t start = clock();

	int n;
	get(n);
	long long diff = 0;
	int half = n>>1;
	int doub = n<<1;
	int tmp;
	int ans = 1;
	out[0]=0;

half--;
doub--;

	F(i,n)
	{
		get(a[i]);
		if (i<=half)
			diff += a[i];
		else diff -= a[i];
	}

	// cout << diff << endl;

	mtime = ((double)(clock()) - (double)(start))/CLOCKS_PER_SEC;

	while (mtime < 00.75)
	{
		if (diff>0)
		{
			for (int j=half+1; j<n && mtime<0.75 && diff>0; j++)
			{
				long long sum = 0;
				int k = j;
				while (k>half && sum<doub)
					sum += a[k--];
				for (int i=half; i>=0 && sum<doub; i--)
				{
					sum += a[i];
					
					if (sum < doub && a[i] > a[j] && a[i]-a[j] < diff)
					{
						tmp = a[j];
						a[j] = a[i];
						a[i] = tmp;
						out[0]++;
						out[ans++] = i+1;
						out[ans++] = j+1;
						diff -= (a[j]-a[i])<<1;
						break;
					}
				}
				mtime = ((double)(clock()) - (double)(start))/CLOCKS_PER_SEC;
			}
		}

		if (diff<0)
		{
			for (int j=half; j>=0 && mtime<0.75 && diff<0; j--)
			{
				long long sum = 0;
				int k = j;
				while (k<=half && sum<doub)
					sum += a[k++];
				for (int i=half+1; i<n && sum<doub;i++)
				{
					sum += a[i];

					if (sum < doub && a[j] < a[i] && a[j]-a[i] > diff)
					{
						tmp = a[j];
						a[j] = a[i];
						a[i] = tmp;
						out[0]++;
						out[ans++] = j+1;
						out[ans++] = i+1;
						diff += (a[j]-a[i])<<1;
						break;
					}
				}
				mtime = ((double)(clock()) - (double)(start))/CLOCKS_PER_SEC;
			}
		}

		mtime = ((double)(clock()) - (double)(start))/CLOCKS_PER_SEC;
	}

	// cout << mtime << endl;
	// cout << diff << endl;

	print(out[0]);
	pc('\n');
	for (int i=1; i<ans; i+=2)
	{
		print(out[i]);
		pc(' ');
		print(out[i+1]);
		pc('\n');
	}
	return 0;
}