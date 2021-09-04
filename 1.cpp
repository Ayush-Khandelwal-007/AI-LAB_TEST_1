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
    int volunteerPosition, cumulativeDistance, bagWeight;
    vector<int>deliveries;
    
    state(int vp, int cd, int bw, vector<int>d){
        volunteerPosition= vp;
        cumulativeDistance=cd;
        bagWeight= bw;
        deliveries= d;
    }
};

struct comp{
    bool operator()(state* a,state* b)
    {
        return a->cumulativeDistance > b->cumulativeDistance;
    }
};

int n,maxWeight;

int solve(vector<vector<int> > distances,vector<int> giftWeights){

    auto start= new state(0,0,0,vector<int>(n,0));
    vector<int>goal(n,1);
    set< pair<pii,vector<int> > >closed;
    priority_queue<state*, vector<state*>, comp> frontier;
    
    frontier.push(start);
    while(!(frontier.empty())){
        auto currentState= frontier.top();
        auto curr= mp(mp(currentState->bagWeight,currentState->volunteerPosition),currentState->deliveries);
        
        if(closed.find(curr)==closed.end()){

            closed.insert(curr);

            if((currentState->deliveries==goal) && currentState->volunteerPosition==0)return currentState->cumulativeDistance;
            if(currentState->volunteerPosition==0)currentState->bagWeight=0;
            
            for(int i=0;i<n;i++){
                if((i!=currentState->volunteerPosition) && (currentState->deliveries[i]==0 || i==0) && (currentState->bagWeight+giftWeights[i]<=maxWeight)){
                    vector<int>nextDelivery= currentState->deliveries;
                    nextDelivery[i]=1;
                    
                    state* nextState= new state(i,currentState->cumulativeDistance+distances[currentState->volunteerPosition][i],currentState->bagWeight+giftWeights[i],nextDelivery);
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
        cin>>n;
        vector<vector<int> > distances(n, vector<int>(n, 0));
        vector<int> giftWeights(n, 0);

        loo(i, 0, n){
            loo(j, 0, n){
                cin>>distances[i][j];
            }
        }
        loo(i, 1, n){
            cin>>giftWeights[i];
        }
        cin>>maxWeight;

        int ans=solve(distances,giftWeights);
        cout<<ans<<endl;
    }
    return 0;
}