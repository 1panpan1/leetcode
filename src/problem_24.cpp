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
    ListNode * swapPairs(ListNode * head){
        ListNode * new_head = new ListNode(-1);
        new_head->next = new ListNode(-1);
        new_head->next->next = head;
        ListNode * p = new_head;
        ListNode * q, *r;

        while(p!=NULL && p->next != NULL){
            q = p->next;
            r = q->next;
            if(r == NULL || r->next == NULL)
                p->next = r;
            else
                p->next = r->next;
            q->next = p;
            p = r;
        }
        return new_head->next;
    }

    // recursive
    ListNode * swapPairs2(ListNode * head){
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode * tmp = head->next;
        head->next = swapPairs2(tmp->next);
        tmp->next = head;
        return tmp;
    }
};

int main(){
    ListNode * head = createList(10);
    printList(head);
    Solution solu = Solution();
    head = solu.swapPairs2(head);
    printList(head);
    return 0;
}