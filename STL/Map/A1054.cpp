#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> mp;
    int i, j, temp, max, current;
    scanf("%d %d", &i, &j);
    for(int line = 0; line < j; line ++){
        for(int cl = 0; cl < i; cl ++){
            scanf("%d", &temp);
            mp[temp] ++;
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it ++){
        if(it->second > i*j/2) {
            printf("%d", it->first);
        }
    }
    system("pause");
    return 0;
}