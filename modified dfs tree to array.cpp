<snippet>
	<content><![CDATA[

int timer=0 , n;
vector<int> start,endx , brr ,c; 
vector<vector<int>> arr;
 
void dfs(int root,int par){
    // cerr<<root<<"x ";
    start[root] = timer;
    timer++;
    brr.push_back(c[root]);
 
    for(auto &x:arr[root]){
        if(x!=par){
            //   cerr<<x<<"y ";
            dfs(x,root);
        }
    }
 
    endx[root] = timer;
    timer++;
    brr.push_back(c[root]);
}



]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>modified dfs tree to array</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
