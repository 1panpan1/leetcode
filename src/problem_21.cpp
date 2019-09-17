#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode * creatList(int end){
    // end is an integer larger than 1
    ListNode * head = new ListNode(1);
    ListNode * p = head;
    int i = 1;
    while(i <= end){
        p->next = new ListNode(i);
        p = p->next;
        i += 2;
    }
    return head;
}

void printList(ListNode * head){
    while(head && head->next != NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<head->val<<endl;
}

class Solution{
public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2){
        ListNode * head = new ListNode(-1);
        ListNode * cur = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == NULL?l2:l1;
        return head->next;
    }
};

int main(){
    ListNode * h1 = creatList(5);
    ListNode * h2 = creatList(6);
    printList(h1);
    printList(h2);
    Solution solu = Solution();
    ListNode * head = solu.mergeTwoLists(h1, h2);
    printList(head);
    return 0;
}