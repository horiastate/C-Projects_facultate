#define MAXN 1000 // maximum number of nodes
typedef pair<int,int> pii;

vector<pii> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

void prim(int source) {
    memset(visited, false, sizeof(visited));
    memset(dist, 0x3f, sizeof(dist)); // initialize all distances to INF
    dist[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, w] : adj[u]) {
            if (!visited[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }
}

int printPrim() {
    ifstream f("graf.csv"); // open input file
    ofstream g("Prim.csv"); //output file
    int a,b,cost;
    char comma;
    string line;
    while(getline(f,line))
    {
        stringstream ss(line);
        if(ss >> a >> comma >> b >> comma >> cost) {
            adj[a].push_back({b, cost}); // add edge to adjacency list
            adj[b].push_back({a, cost}); // undirected graph, add edge in both directions
        }
        ss.clear(); // clear stringstream
        ss.str(""); // set stringstream to empty string
        a=0; // reset variables for next line
        b=0;
        cost=0;
    }
    f.close(); // close input file

    prim(1); // run Prim's algorithm starting from node 1

    int totalCost = 0;
    for (int i = 1; i < MAXN; i++) {
        if (visited[i]) totalCost += dist[i];
    }

    g << "The cost of the minimum spanning tree is " << totalCost << endl;

    return 0;
}
