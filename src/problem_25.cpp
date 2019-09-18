#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode * createList(int x){
    ListNode * head = new ListNode(1);
    ListNode * p = head;
    for(int i = 2; i < x; ++i){
        p->next = new ListNode(i);
        p = p-> next;
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
    ListNode * reverseKGroup(ListNode * head, int k){
        ListNode *p = head, *tail, *next_head, *new_head;
        int l = k;
        while(p != NULL && --l > 0)
            p = p->next;
        if(p != NULL){
            new_head = p;
            next_head = p->next;
            tail = reverse(head, k);
            tail->next = reverseKGroup(next_head, k);
        }else{
            new_head = head;
        }
        return new_head;
    }

    ListNode * reverse(ListNode * cur, int k){
        if(k == 1)
            return cur;
        ListNode* next_node = reverse(cur->next, k - 1);
        next_node->next = cur;
        return cur;
    }
};

int main(){
    ListNode * head = createList(1);
    Solution solu = Solution();
    printList(head);
    head = solu.reverseKGroup(head, 3);
    printList(head);
    return 0;
}