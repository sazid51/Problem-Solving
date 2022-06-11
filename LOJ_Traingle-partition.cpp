#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
double ab,bc,ac,r;
void optimize()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

double triangleRatio(double x)
{
    double rat,ae,de,s1,s2,largeTriangle,smallTriangle,trapizoid;
    rat=x/ab;
    ae=rat*ac;
    de=rat*bc;
    s1=0.5*(ab+bc+ac);
    s2=0.5*(x+ae+de);
    largeTriangle = sqrt(s1*(s1-ab)*(s1-bc)*(s1-ac));
    smallTriangle=sqrt(s2*(s2-x)*(s2-ae)*(s2-de));
    trapizoid=largeTriangle-smallTriangle;
    return smallTriangle/trapizoid;
}

int main()
{
    optimize();
    int t;
    cin>>t;
    int j=1;
    cout<<fixed<<setprecision(10);
    while(t--)
    {
        cin>>ab>>bc>>ac>>r;
        double lo=0,hi=ab,mid;
        while(hi-lo>1e-10)
        {
            mid=(hi+lo)/2.0;
            if(triangleRatio(mid)>r) hi=mid;
            else lo=mid;
        }
        cout<<"Case "<<j<<": "<<mid<<endl;
        ++j;
    }
}
