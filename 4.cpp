#include <bits/stdc++.h>
using namespace std;

#define mod 1e9 + 7
#define ll long long
#define inf ((ll)1e18 + 1)
#define vl vector<ll>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vll vector<pll>
#define vs vector<string>
#define mll map<ll ll>
#define umll unordered_map<ll ll>
#define fst                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define bcount __builtin_popcount
#define pb push_back
#define pie 3.14159265358979323846
#define all(a) (a).begin(), (a).end()
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define loo(i, a, b) for (i = (a); i < (b); i++)
#define rloo(i, a, b) for (i = (a); i > (b); i--)
#define fin(x) scanf("%d", &x)
#define fout(x) printf("%d", x)
#define pii pair<int, int>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second

struct state{
    int volunteerPosition, cumulativeDistance,totalWeight;
    vector<int> bagWeight,visited,done;
    vector<string>path;
    
    state(int vp, int cd,int tw, vector<int> bw,vector<int> v,vector<int> d,vector<string> p){
        volunteerPosition= vp;
        cumulativeDistance=cd;
        totalWeight=tw;
        bagWeight= bw;
        visited=v;
        done=d;
        path=p;
    }
};

struct comp{
    bool operator()(state* a,state* b)
    {
        if(a->cumulativeDistance > b->cumulativeDistance)
        return true;
        else if(a->cumulativeDistance < b->cumulativeDistance)
        return false;
        else
        return a->path > b->path;
    }
};

int m,n,maxWeight;

vector<string> solve(vector<vector<int> > distances,vector<int> giftWeights,vector<int> to,vector<int> goal){
    state* start= new state(0,0,0,vector<int>(m,0),vector<int>(n+m,0),vector<int>(m,0),vector<string>(1,"0"));
    set< pair<pair<vector<int> ,int>,vector<int> > >closed;
    priority_queue<state*, vector<state*>, comp> frontier;
    
    frontier.push(start);
    while(!(frontier.empty())){
        state* currentState= frontier.top();
        pair<pair<vector<int> ,int>,vector<int> > curr= mp(mp(currentState->bagWeight,currentState->volunteerPosition),currentState->visited);
        if(closed.find(curr)==closed.end()){
            closed.insert(curr);

            if((currentState->volunteerPosition<m )&& (currentState->done==goal)){
                return currentState->path;
            }
            
            for(int i=0;i<m+n;i++){
                 if((i!=currentState->volunteerPosition) && (currentState->totalWeight+giftWeights[i]<=maxWeight) && (currentState->visited[i]==0|| i<m) && (i>=m||currentState->bagWeight[i]!=0)){
                    vector<int>nextVisited= currentState->visited;
                    nextVisited[i]=1;
                    vector<int>nextBag= currentState->bagWeight;
                    vector<string>nextPath= currentState->path;
                    nextPath.pb(to_string(i));
                    
                    state* nextState= new state(i,currentState->cumulativeDistance+distances[currentState->volunteerPosition][i],currentState->totalWeight,nextBag,nextVisited,currentState->done,nextPath);

                    if(nextState->volunteerPosition<m){
                        nextState->totalWeight= currentState->totalWeight-currentState->bagWeight[nextState->volunteerPosition];

                        nextState->done[nextState->volunteerPosition]+=currentState->bagWeight[nextState->volunteerPosition];

                        nextState->bagWeight[nextState->volunteerPosition]=0;     
                    }
                    else{
                        nextState->bagWeight[to[i]]+=giftWeights[i];
                        nextState->totalWeight = currentState->totalWeight + giftWeights[i];
                    }

                    frontier.push(nextState);
                }
            }
        }
        frontier.pop();
    }
    return vector<string>(0); //no solution
}

int main(){
	fst
    int t,i,j;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<vector<int> > distances(m+n, vector<int>(m+n, 0));
        vector<int> giftWeights(m+n, 0),to(m+n,0),goal(m,0);

        loo(i, 0, m+n){
            loo(j, 0, m+n){
                cin>>distances[i][j];
            }
        }
        loo(i, 0, n){
            cin>>giftWeights[i+m]>>to[i+m];
            goal[to[i+m]]+=giftWeights[i+m];
        }

        cin>>maxWeight;
        vector<string>ans= solve(distances,giftWeights,to,goal);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}