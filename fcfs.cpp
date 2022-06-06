//fcfs scheduling.
//max 10 process
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct process{
int at=0;
int bt=0;
int pr=0;
int ct;
int tat;
int wt;
char pname;
int remtime;
int flag=0;
}p[10];

int main()
{
int num,totalwt=0,totaltat=0,lastct=0;
cout<<"\nenter number of process:";
cin>>num;
for(int i=0;i<num;i++)
{
    cout<<"\nenter the arrival time of the process "<<i<<":";
    cin>>p[i].at;
    cout<<"\nenter the burst time of the process "<<i<<":";
    cin>>p[i].bt;
    p[i].remtime=p[i].bt;
    cout<<"\nenter the name of the process "<<i<<":";
    cin>>p[i].pname;
}
//time loop
int z=0;//process counter
for(int j=0;;j++)
{
    if(j>=p[z].at)
        {
        if(p[z].remtime!=0)
        p[z].remtime--;
        else
        {
        p[z].flag=1;//flag 1 means proc is over;
        p[z].ct=j;
        p[z].tat=p[z].ct-p[z].at;
        totaltat+=p[z].tat;
        p[z].wt=p[z].tat-p[z].bt;
        totalwt+=p[z].wt;
        z++;
            if(p[z].at<=p[z-1].ct)
            {
                    j--;//when another proc is in ready queue for some time,or arrived as soon as one got 
                        //done
            }
        }
        }
    if(p[num-1].flag==1)
    {
    lastct=j;
    break;    
    }    
}
cout<<"\nAT"<<"\tBT"<<"\tCT"<<"\tTAT"<<"\tWT"<<"\tname";
for(int i=0;i<num;i++)
{
    cout<<"\n"<<p[i].at;
    cout<<"\t"<<p[i].bt;
    cout<<"\t "<<p[i].ct;
    cout<<"\t"<<p[i].tat;
    cout<<"\t"<<p[i].wt;
    cout<<"\t"<<p[i].pname;
}
cout<<"\nthe average waiting time is:"<<totalwt/num;
cout<<"\nthe average turn around time is:"<<totaltat/num;
}
