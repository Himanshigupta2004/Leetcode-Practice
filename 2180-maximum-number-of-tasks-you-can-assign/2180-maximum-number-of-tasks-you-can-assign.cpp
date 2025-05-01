class Solution {
public:
    bool canassigntask(vector<int>& tasks, vector<int>& workers, int pills, int strength,int k){
        multiset<int> availableworkers(workers.end()-k,workers.end());
        int pillsused=0;
        for(int i=k-1;i>=0;i--){
            int task=tasks[i];
            auto it=availableworkers.lower_bound(task);//find the worker in availableworkers set where the value is greater than or equal to task
            if(it!=availableworkers.end()){
                availableworkers.erase(it);
            }
            else{
                it=availableworkers.lower_bound(task-strength);
                if(it==availableworkers.end() || pillsused>=pills){
                    return false;
                }
                else{
                    availableworkers.erase(it);
                    pillsused++;
                }
            }

        }
        return true;

    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int n=tasks.size(),m=workers.size();
        int left=0,right=min(n,m);
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canassigntask(tasks,workers,pills,strength,mid)){
            ans=mid;
            left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};