#include<bits/stdc++.h>
using namespace std;

/*
1、目的：分别统计各层的叶节点的总数并输出
2、解读： 
	N为节点总数；M为非叶节点的个数
	接着输入M行非叶节点信息，每行为 ID K ID[1] ID[2] ... ID[K] 
		ID 为非叶节点编号 
		K 为ID的孩子个数
		ID[1] ID[2] ... ID[K] 为ID的孩子
3、层序遍历法：
	从根节点开始层序遍历
        若该节点为非叶节点（有孩子）
            将它移出队列，并将它的孩子加入到队列中
        若该节点为叶子节点（无孩子）
            将它移出队列，并将它所处层次的叶节点计数+1
*/

struct node{
    int layer;
    vector<int> child;
}Node[101];

int level = 1;
int countN[101] = { 0 };

// 层序遍历root为根节点的树
void LayerOrder(int root){
    queue<int> q;
    q.push(root);
    while( !q.empty() ){
        int it = q.front();
        q.pop();
        if( Node[it].child.size() != 0 ){
            for(int i = 0; i < Node[ it ].child.size(); i ++){
                int x = Node[ it ].child[i];
                q.push( x );
                Node[ x ].layer = Node[ it ].layer + 1;
                if( level < Node[ x ].layer ) level = Node[ x ].layer;
            }
        }
        else{
            countN[ Node[ it ].layer ]++;
        }
    }
}

int main(){

    int N, M, K, ID, tmp;
    scanf("%d %d", &N, &M);
    if( N == 0) printf( 0 );
	else{
        Node[1].layer = 1;
        for(int i = 0; i < M; i ++){
            scanf("%d %d", &ID, &K);
            for(int j = 0; j < K; j ++){
                scanf(" %d", &tmp);
                Node[ID].child.push_back(tmp);
            }
        }

        LayerOrder(1);

        for(int i = 1; i <= level; i ++){
            if( i == 1 ) printf("%d", countN[i] );
            else printf(" %d", countN[i] );
        }
    }

    // // 测试例子
    // Node[1].layer = 0;
    // Node[1].child.push_back(2);
    // Node[1].child.push_back(3);
    // Node[1].child.push_back(4);
    // Node[2].layer = 1;    
    // Node[3].layer = 1;
    // Node[3].child.push_back(5);
    // Node[3].child.push_back(6);
    // Node[3].child.push_back(7);
    // Node[4].layer = 1;
    // Node[5].layer = 2;
    // Node[6].layer = 2;
    // Node[6].child.push_back(8);
    // Node[7].layer = 2;
    // Node[8].layer = 3;
    // LayerOrder(1);
    // for(int i = 0; i < level; i ++){
    //     if( i == 0 ) printf("%d", countN[i] );
    //     else printf(" %d", countN[i] );
    // }


	system("pause");
	return 0;
}

