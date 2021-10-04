#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define inf 0x3f3f3f3f
using namespace std;
struct tableNode {
    int endTime;
    int num;
    int isVIP;
};
struct person {
    int arrive,start,time;
    int isVIP;
}tempPerson;
vector<tableNode> table;
vector<person> player;
int n,hour,minute,second;
int k,m;
int flag;
bool cmp1(person a,person b){
    return a.arrive<b.arrive;
}
bool cmp2(person a,person b){
    return a.start<b.start;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d",&hour,&minute,&second);
        tempPerson.arrive=hour*3600+minute*60+second;
        cin>>tempPerson.time;
        if(tempPerson.time>120){
            tempPerson.time=120;
        }
        cin>>tempPerson.isVIP;
        player.push_back(tempPerson);
    }
    cin>>k>>m;
    table.resize(k+1);
    for(int i=1;i<=k;i++){
        table[i].endTime = 8*3600;
    }
    int number;
    for(int i=0;i<m;i++){
        cin>>number;
        table[number].isVIP=1;
    }
    sort(player.begin(),player.end(),cmp1);
    for(int i=0;i<n;i++){
        int minIndex=1;
        int minFinish=inf;
        for(int j=1;j<=k;j++){
            if(table[j].endTime<minFinish){
                minIndex=j;
                minFinish=table[j].endTime;
                if(table[j].endTime<=player[i].arrive){
                    break;
                }
            }
            
        }
        if(!player[i].start){
            if(table[minIndex].endTime<=player[i].arrive){
                player[i].start=player[i].arrive;
                table[minIndex].endTime=player[i].arrive+player[i].time*60;
                
                if(player[i].start<75600){
                    table[minIndex].num++;
                }
            }else {
                if(!table[minIndex].isVIP){
                    player[i].start=table[minIndex].endTime;
                    table[minIndex].endTime+=player[i].time*60;
                    
                    if(player[i].start<75600){
                        table[minIndex].num++;
                    }
                }else {
                    flag=-1;
                    int tempIndex=i;
                    for(int j=tempIndex;j<n;j++){
                        if(player[i].start==0&&player[j].isVIP&&player[j].arrive<table[minIndex].endTime){
                            flag=j;
                            break;
                        }
                    }
                    if(flag==-1){
                        player[i].start=table[minIndex].endTime;
                        table[minIndex].endTime+=player[i].time*60;
                        
                        if(player[i].start<75600){
                            table[minIndex].num++;
                        }
                    }else {
                        player[flag].start=table[minIndex].endTime;
                        table[minIndex].endTime+=player[flag].time*60;
                        
                        if(player[flag].start<75600){
                            table[minIndex].num++;
                        }
                    }
                    i=tempIndex-1;
                }
                
            }
        }else {
            continue;
        }
    }
    sort(player.begin(),player.end(),cmp2);
    for(int i=0;i<n;i++){
        if(player[i].start>=75600){
            break;
        }
        printf("%02d:%02d:%02d %02d:%02d:%02d ",player[i].arrive/3600,player[i].arrive/60%60,player[i].arrive%60,player[i].start/3600,player[i].start/60%60,player[i].start%60);
        double temp = 1.0*(player[i].start-player[i].arrive)/60;
        int res = round(temp);
        printf("%d\n",res);
    }
    for(int i=1;i<=k;i++){
        if(i!=1){
            cout<<" ";
        }
        cout<<table[i].num;
    }
    return 0;
}