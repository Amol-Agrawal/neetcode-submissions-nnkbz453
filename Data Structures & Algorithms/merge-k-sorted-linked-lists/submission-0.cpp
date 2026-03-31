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
        int i =0 ;
         int j = n-1;  
            while(i<j){
            lists[i]= merge2list( lists[i], lists[j]);
            i++;
            j--;
            }

            n= (n+1)/2;


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
