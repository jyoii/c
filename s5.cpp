#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree(200000);

char choice[200000];
int cost[200000];
int dp[200000][3];       //dp[i][0]: solution of subtree with root i when there is no influence between i and its parent
                        //dp[i][1]: solution of subtree with root i when i is influenced by its parent
                        //dp[i][2]: solution of subtree with root i when i influences its parent
//The function below returns the minimum cost of subtree with root 'u' and state 'state'

//u: current node
//state: 0 - there is no influence between u and its parent
//       1 - u is influenced by its parent
//       2 - u influences its parent

int minCost(int u, int state, int parent){
    int total = 0;
    
    //if dp[u][state] already exists, it means this has been computed before, just return its result
    if (dp[u][state] != INT_MAX){
        return dp[u][state];
    }                                                   

    if(state == 0){
    //compute and return the minimal cost of subtree with root 'u' when there is no influence between u and its parent

        
        int c1 = 0, c2 = 0;
        if(choice[u] != 'Y'){
            //option1: pay 'u', which means u will influence all its children
            c1 += cost[u] + total;
            int op1[200000];
            copy(choice, choice+200000, op1); 
            for (int i = 0; i < tree[u].size(); i++){
                op1[tree[u][i]] = 'Y';
            }
        
            //option2: don't pay 'u', which means there will be no influences between 'u' and any of its children
            c2 += total;

            if (c1 < c2) choice[u] = 'Y';
            total += min(c1, c2);
            //return min(c1, c2);
        }
  
        else{
            //option1: pay 'u', which means 'u' has to be influenced by one of its children and 'u' influences all its other children
            //option2: don't pay 'u', which means 'u' has to be influenced by one of its children and 'u' does not influence its other children
            //minimum cost = min(option1, option2)
        }
        return minCost(u, state, parent); //change arguments
    }

    else if(state == 1){
        //compute and return the minimal cost of subtree with root 'u' when u is influenced by its parent
    }

    else /*(state == 2)*/ {
        //compute and return the minimal cost of subtree with root 'u' when u influences its parent
    }

    return INT_MAX;
}


int main() {
    int N;
    cin >> N; //number of students
    vector<pair<int, int>> vec;
    for (int i = 0; i < (N-1); i++){
        int s1, s2; 
        cin >> s1 >> s2;

        tree[s1].push_back(s2);
        //vec.push_back({0, 0});
        //vec[i].first = s1;
        //vec[i].second = s2;
    }
  
    for (int i = 0; i < N; i++){
        char tmp;
        cin >> tmp;
        choice[i] = tmp;
    }
  
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        cost[i] = tmp;
    }
  
    fill_n(&dp[N][3], N*3, INT_MAX);
}