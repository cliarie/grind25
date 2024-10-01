#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <climits>

#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll gcd(ll a, ll b){
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

set<ll> prime_factors(ll n)
{
    set<ll> factors;
    while(n%2 == 0){
        factors.insert(2);
        n/=2;
    }
    for(ll i = 3; i*i <= n; i+=2){
        while(n%i == 0){
            factors.insert(i);
            n/=i;
        }
    }
    if(n > 2) factors.insert(n);
    return factors;
}

ll dijkstras(unordered_map<ll, vector<pii>>& graph, ll start, ll end){
    unordered_map<ll, ll> dist;
    for (auto x : graph){
        dist[x.first] = LLONG_MAX;
    }
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()){
        pii top = pq.top();
        pq.pop();
        ll u = top.second;

        if (top.first > dist[u]) continue; // Skip if we already have a better distance

        if (u == end) return dist[u];
        for (pii neighbor : graph[u]){
            ll v = neighbor.first;
            ll weight = neighbor.second;
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end];
}

ll minimal_lcm(ll a, ll b){
    // Build the set of candidate nodes
    set<ll> candidates = {a, b, 2};
    set<ll> factors_a = prime_factors(a);
    set<ll> factors_b = prime_factors(b);

    candidates.insert(factors_a.begin(), factors_a.end());
    candidates.insert(factors_b.begin(), factors_b.end());

    // Build the graph
    unordered_map<ll, vector<pii>> graph;
    for (ll x : candidates){
        graph[x] = vector<pii>(); // Ensure node exists
    }
    for (ll x : candidates){
        for (ll y : candidates){
            if (x != y){
                graph[x].push_back({y, lcm(x, y)});
            }
        }
    }

    // Run Dijkstra's algorithm from 'a' to 'b'
    ll result = dijkstras(graph, a, b);
    return result;
}

int main(){
    #ifdef LOCAL_TESTING
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        ll a, b;
        cin >> a >> b;
        cout << minimal_lcm(a, b) << endl;
    }
}
