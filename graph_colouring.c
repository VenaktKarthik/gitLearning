#include<stdio.h>
#include<stdbool.h>
#define node 4

int graph[node][node]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};

int chromaticnum(int arr[],int n){
    int c=1;
    for(int i=1;i<n;i++){
        int j=0;
        for(j=0;j<n;j++){
            if(arr[i]==arr[j])
                break;
        }
        if(i==j){
            c++;
        }
    }
    return c;
}

void graphcolouring(){
    int colour[node];
    bool colourused[node];
    colour[0]=0;
    for(int i=1;i<node;i++)
        colour[i]=-1;
    for(int i=0;i<node;i++)
        colourused[i]=false;
    for(int u=1;u<node;u++){
        for(int v=0;v<node;v++){
            if(graph[u][v]){
                if(colour[v]!=-1)
                    colourused[colour[v]]=true;
            }
        }
        int col;
        for(col=0;col<node;col++)
            if(!colourused[col])
                break;
        colour[u]=col;
        for(int v=0;v<node;v++){
            if(graph[u][v]){
                if(colour[v]!=-1)
                    colourused[colour[v]]=false;
            }
        }
    }
    for(int u=0;u<node;u++)
        printf("Node %d Assigned with colour %d\n",u+1,colour[u]);
    int count=chromaticnum(colour,node);
    printf("Chromatic Number to colour the four nodes is: %d",count);
}

int main(){
    //works;
    graphcolouring();
    return 0;
}