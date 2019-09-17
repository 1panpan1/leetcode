#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode * createList(int x){
    ListNode *head = new ListNode(1 + rand() % 3);
    ListNode * p = head;
    int n = 1;
    while(n++ <= x){
        p->next = new ListNode(3 * n + rand() % 3);
        p = p->next;
    }
    return head;
}

void printList(ListNode * head){
    while(head != NULL && head->next != NULL){
        cout<<head->val<<' ';
        head = head->next;
    }
    cout<<head->val<<endl;
}

class Solution{
public:
    ListNode * mergeTwoLists(ListNode *l1, ListNode*l2){
        ListNode* head = new ListNode(-1);
        ListNode * p = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                p->next = l2;
                l2 = l2->next;
            }else{
                p->next = l1;
                l1 = l1->next;
            }
            p = p-> next;
        }
        p->next = l1 == NULL?l2:l1;
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode * head = new ListNode(-1);
        ListNode * p = head;
        ListNode * min_ptr = NULL;
        int min_index = -1;

        // remove NULL list_headers
        for(vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); ++iter){
            if((*iter) == NULL){
                iter = lists.erase(iter);
                --iter;
            }
        }
        while(lists.size() > 0){
            int index = 0;
            int min_val = 0x7fffffff;
            for(vector<ListNode *>::iterator iter = lists.begin(); iter != lists.end();++iter, ++index){
                if((*iter)->val < min_val){
                    min_val = (*iter)->val;
                    min_ptr = *iter;
                    min_index = index;
                }
            }
            p->next = min_ptr;
            p = p->next;
            lists[min_index] = min_ptr->next;
            if(lists[min_index] == NULL)
                lists.erase(lists.begin() + min_index);
        }
        return head->next;
    }
};

int main(){
    vector<ListNode*> lists;
    for(int i = 4; i <= 8; i++){
        lists.push_back(createList(i));
        printList(lists.back());
    }
    Solution solu = Solution();
    ListNode * head = solu.mergeKLists(lists);
    printList(head);
    return 0;
}