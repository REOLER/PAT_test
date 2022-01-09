#include<bits/stdc++.h>
using namespace std;

vector<int> Node[101];
int countN[101] = { 0 };
int level = -1;

void dfs(int index, int layer){
	if( Node[index].size() == 0 ){
		countN[layer] ++;
		level = max(level, layer);
		return;
	}
	for(int i = 0; i < Node[index].size(); i ++){
		dfs( Node[index][i], layer + 1 );
		// if(level < layer + 1) level = layer + 1;
	}
}

int main(){

	 int N, M, K, ID, tmp;
    scanf("%d %d", &N, &M);
    if( N == 0) printf( 0 );
	else{
        for(int i = 0; i < M; i ++){
            scanf("%d %d", &ID, &K);
            for(int j = 0; j < K; j ++){
                scanf(" %d", &tmp);
                Node[ID].push_back(tmp);
            }
        }
		dfs(1, 0);
		printf("%d", countN[0]);
		for(int i = 1; i < level + 1; i ++){
			printf(" %d", countN[i]);
		}

	}
	
	system("pause");
	return 0;
}
