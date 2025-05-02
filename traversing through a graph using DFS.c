#include<stdio.h>
int Graph[100][100];
int vis[100];
void DFS(int node,int *vis,int n){
	vis[node]=1;// whether the node is visited or not -......
	printf("%d ",node);//print the node after making the visted array to zero
	int i=0;
	for(i=0;i<=n;i++){// iterating through rows to conditions given below
	if(vis[i]==0 && Graph[node][i]==1){
		DFS(i,vis,n);
	}
}
}
int main(){
	int n,e;
	//n-->no of nodes and e-->no of edges
	scanf("%d %d",&n,&e);
	int i=0,j=0;
	//makiing all the elements to 0 in the graph
	for(i = 0;i<=n;i++){
		for(j=0;j<=n;j++){
			Graph[i][j]=0;
		}
	}
	//here x,y are the given elements which are connected to each other in the graph are being placed in the matrix
	for(i=0;i<e;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		Graph[x][y]=1;
		Graph[y][x]=1;
	}
	DFS(1,vis,n);//node,vistied array,no of nodes
}
