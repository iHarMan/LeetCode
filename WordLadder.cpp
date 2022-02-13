static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int same(string &a, string &b){
        int cnt=0;
        for(int i=0; i<a.length(); i++){
            if(a[i]!=b[i]) cnt++;
        }
        return cnt;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // create a graph
        // wordList.push_back(beginWord);
        unordered_map<string, int> listToNum;
        int tt=0;
        bool f=0, g=0;
        for(auto word:wordList){
            listToNum[word] = tt++;
            if(word==endWord) f=1;
            if(word==beginWord) g=1;
        }
        if(!g) {
            wordList.push_back(beginWord);
            listToNum[beginWord] = tt++;
        }
        if(!f) return 0;
        int n=listToNum.size()+1;
        vector<int> adj[n];
        for(int i=0; i<wordList.size(); i++){
            string a = wordList[i];
            for(int j=i+1; j<wordList.size(); j++){
                if(i==j) continue;
                string b = wordList[j];
                if(same(a,b)==1){
                    adj[listToNum[a]].push_back(listToNum[b]);
                    adj[listToNum[b]].push_back(listToNum[a]);
                }
            }
        }
       
        
        // find shortest path between start and endWord
        int dist[n];
        for(int i=0; i<n; i++){
            dist[i]=1e5;
        }
        queue<int> q;
        q.push(listToNum[beginWord]);
        dist[listToNum[beginWord]]=0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it:adj[x]){
                if(dist[x]+1<dist[it]){
                    dist[it]=dist[x]+1;
                    q.push(it);
                }
            }
        }
        if(dist[listToNum[endWord]]==1e5) return 0;
        return dist[listToNum[endWord]]+1;
    }
};