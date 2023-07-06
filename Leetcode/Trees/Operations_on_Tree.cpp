class LockingTree {
public:
    vector<int> parent;
    vector<int> count;
    vector<int> owner;
    vector<vector<int>> children;

    LockingTree(vector<int>& parent) {
        this->parent = parent;
        count.resize(parent.size());
        owner.resize(parent.size(), -1);
        children.resize(parent.size());
        for (int i = 1; i < parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(owner[num]==-1)
        {
            owner[num]=user;
            while(num!=-1)
            {
                count[num]+=1;
                num=parent[num];
            }
            return true;
        }
        else return false;
    }
    
    bool unlock(int num, int user) 
    {
        if(owner[num]==user)
        {
            owner[num]=-1;
            while(num!=-1)
            {
                count[num]-=1;
                num=parent[num];
            }
            return true;
        }
        else return false;
    }
    
    bool upgrade(int num, int user) 
    {
        if(owner[num]!=-1 || count[num]==0)return false;
        int val = count[num];
        int curr = num;
        while(curr!=-1)
        {
            if(owner[curr]!=-1){
                return false;}
            curr=parent[curr];
        }
        curr = num;
        while(curr!=-1)
        {
            count[curr]-=val-1;
            curr=parent[curr];
        }
        owner[num]=user;
        queue<int> q;
        for( int child: children[num])
            if(count[child])q.push(child);
        while (q.size())
        {
            int child = q.front(); q.pop();
            if (count[child]==0)continue;
            count[child]=0;
            owner[child]=-1;
            for(int kid : children[child])
                if(count[kid])q.push(kid);
        }
        return true;

    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
