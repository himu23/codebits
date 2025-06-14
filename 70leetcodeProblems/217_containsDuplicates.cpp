//its my current best
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_map<int,int> ump;
            for(int i=0;i<nums.size();i++){
                if(ump[nums[i]]>0){
                    return true;
                }
                ump[nums[i]]++;
            }
            return false;
        }
    };

//sets
