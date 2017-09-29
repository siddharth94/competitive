#include <string>
#include <iostream>
#include<stdio.h>
#include<set>
#include<iterator>
using namespace std;

#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int breakstring(string sentence, string array[100000])
{
    char c;int i=0,j=1,prev=0,final;
    while(1)
    {
        c=sentence[i];
        if(c=='\0')
        {
            array[j]=sentence.substr(prev,i-prev);
//            cout << "j is " <<j << " " <<endl;
       //     cout<< "j= " << j <<" and " << array[j] << " isvalue " << endl;
         //   cout << "done1" << endl;
            i--;
            break;
        }
        if(c==' ')
        {
            final=i-1;
            array[j]=sentence.substr(prev,final-prev+1);
    //        cout<< "j= " << j <<" and " << array[j] << " isvalue " << endl;
     //       cout << "done" << endl;
            j++;
            while(1)
            {
                i++;
                c=sentence[i];
                if(c!=' ')
                {
                    prev=i;
                    break;
                }
            }
        }
        i++;
    }
    return j;
}

void trim(string& s)
{
   size_t p = s.find_first_not_of(" \t");
   s.erase(0, p);

   p = s.find_last_not_of(" \t");
   if (string::npos != p)
      s.erase(p+1);
}
int main()
{
  int t,i,j,k;string sentence;string array[100000];set <string>myset;
  string word;
  get(t);
  for(i=1;i<=t;i++)
  {
    getline(cin,sentence);
    //cout << sentence <<endl;
    trim(sentence);
    //cout << sentence << endl;
    j=breakstring(sentence,array);
    
    for(k=1;k<=j;k++)
    {
      word=array[k];
      if(word!="")
      myset.insert(word);
    }
    cout << myset.size() << endl;
    myset.clear();
    
  }
}

/**
 * My code
 */

// #include <bits/stdc++.h>
// using namespace std;

// #define gc getchar_unlocked

// void get(int &x)
// {
//     register int c = gc();
//     x = 0;
//     int neg = 0;
//     for(;((c<48 || c>57) && c != '-');c = gc());
//     if(c=='-') {neg=1;c=gc();}
//     for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg) x=-x;
// }

// string array[10009];
// set <string>myset;

// int breakstring(string sentence)
// {
//     char c;int i=0,j=1,prev=0,final;
//     while(1)
//     {
//         c=sentence[i];
//         if(c=='\0')
//         {
//             array[j]=sentence.substr(prev,i-prev);
//             break;
//         }
//         if(c==' ')
//         {
//             final=i-1;
//             array[j]=sentence.substr(prev,final-prev+1);
//             j++;
//             while(1)
//             {
//                 i++;
//                 c=sentence[i];
//                 if(c!=' ')
//                 {
//                		if(c=='\0')
//                		{
//                			i--;
//                			break;
//                		}
//                     prev=i;
//                     break;
//                 }
//             }
//         }
//         i++;
//     }
//     return j;
// }

// void trim(string& s)
// {
//    size_t p = s.find_first_not_of(" \t");
//    s.erase(0, p);

//    p = s.find_last_not_of(" \t");
//    if (string::npos != p)
//       s.erase(p+1);
// }

// int main()
// {
// 	int t,i,j,k;
//   string sentence;
// 	string word;
//   get(t);
// 	// scanf("\n");
// 	for(i=1;i<=t;i++)
// 	{
// 		getline(cin,sentence);
// 		trim(sentence);
// 		j=breakstring(sentence);
		
// 		for(k=1;k<=j;k++)
// 		{
// 			word=array[k];
// 			if(word!="")
// 		  	myset.insert(word);
// 		}
// 		cout << myset.size() << endl;
// 		myset.clear();
// 	}
//   return 0;
// }