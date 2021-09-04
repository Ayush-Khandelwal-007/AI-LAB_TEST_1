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
    
    state(int vp, int cd,int tw, vector<int> bw,vector<int> v,vector<int> d){
        volunteerPosition= vp;
        cumulativeDistance=cd;
        totalWeight=tw;
        bagWeight= bw;
        visited=v;
        done=d;
    }
};

struct comp{
    bool operator()(state* a,state* b)
    {
        return a->cumulativeDistance > b->cumulativeDistance;
    }
};

int m,n,maxWeight;

int solve(vector<vector<int> > distances,vector<int> giftWeights,vector<int> to,vector<int> goal){
    state* start= new state(0,0,0,vector<int>(m,0),vector<int>(n+m,0),vector<int>(m,0));
    set< pair<pair<vector<int> ,int>,vector<int> > >closed;
    priority_queue<state*, vector<state*>, comp> frontier;
    
    frontier.push(start);
    while(!(frontier.empty())){
        state* currentState= frontier.top();
        cout<<currentState->volunteerPosition<<endl;
        pair<pair<vector<int> ,int>,vector<int> > curr= mp(mp(currentState->bagWeight,currentState->volunteerPosition),currentState->visited);
        if(closed.find(curr)==closed.end()){
            closed.insert(curr);

            if((currentState->volunteerPosition<m )&& (currentState->done==goal)){
                return currentState->cumulativeDistance;
            }
            
            for(int i=0;i<m+n;i++){
                 if((i!=currentState->volunteerPosition) && (currentState->totalWeight+giftWeights[i]<=maxWeight) && (currentState->visited[i]==0|| i<m) && (i>=m||currentState->bagWeight[i]!=0)){
                    vector<int>nextVisited= currentState->visited;
                    nextVisited[i]=1;
                    vector<int>nextBag= currentState->bagWeight;
                    
                    state* nextState= new state(i,currentState->cumulativeDistance+distances[currentState->volunteerPosition][i],currentState->totalWeight,nextBag,nextVisited,currentState->done);

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
    return -1; //no solution
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
        int ans=solve(distances,giftWeights,to,goal);
        cout<<ans<<endl;
    }
    return 0;
}