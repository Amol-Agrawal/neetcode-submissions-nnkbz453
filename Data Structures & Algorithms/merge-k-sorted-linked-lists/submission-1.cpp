/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if( n ==0 ) return nullptr;

        
        while (n>1){
            vector<ListNode*> mergedlist;
            for(int i=0 ; i<n ; i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 < n ? lists[i+1] : nullptr ;

                mergedlist.push_back(merge2list(l1 , l2));
            }
            lists = mergedlist;
            n= lists.size();
        }

        return lists[0];
        
        
    }

    ListNode* merge2list(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode (-1);
        ListNode* t1 = l1 ;
        ListNode* t2 = l2;
        if (l1 == nullptr) return l2;
        if ( l2 == nullptr )return l1; 
        ListNode* prev = dummy;
        while(t1 != nullptr && t2 != nullptr){

            if( t1-> val <= t2->val){
                dummy->next = t1;
                t1 = t1-> next;
            }else{
                dummy->next = t2;
                t2 = t2->next;
            }
            dummy = dummy->next;

        }

        if(t1){
            dummy-> next = t1 ;
        }else {
            dummy-> next = t2;
        }

        return prev->next;
    }
};
