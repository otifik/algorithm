/*假设某次比赛有m人，每组为ng人，不难确定，可以分为group组（group为（m/ng)向上取整），
就是说有group个赢家，剩下的人的排名自然就都是group+1
*/
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int n,m;
queue<int> que;
struct node{
    int rank;
    int weight;
}mouse[1010];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>mouse[i].weight;
    }
    int id;
    for(int i=0;i<n;i++){
        cin>>id;
        que.push(id);
    }
    while(1){
        queue<int> temp;
        int rank = ceil(1.0*que.size()/m)+1;
        while(!que.empty()){
            int maxIndex=que.front();
            int maxWeight=mouse[que.front()].weight;
            for(int i=0;i<m;i++){
                if(!que.empty()){
                    int front = que.front();
                    que.pop();
                    mouse[front].rank=rank;
                    if(mouse[front].weight>maxWeight){
                        maxIndex=front;
                        maxWeight=mouse[front].weight;
                    }
                }
            }
            temp.push(maxIndex);
        }
        if(temp.size()==1){
            mouse[temp.front()].rank=1;
            break;
        }
        que = temp;
    }
    for(int i=0;i<n;i++){
        if(i){
            cout<<" ";
        }
        cout<<mouse[i].rank;
    }
    return 0;
}