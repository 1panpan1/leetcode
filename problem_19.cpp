#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
    ListNode * removeNthFromEnd(ListNode *head, int n){
        vector<ListNode *> addresses;
        ListNode * p = head;
        while(p != NULL){
            addresses.push_back(p);
            p=p->next;
        }
        int list_length = addresses.size();
        if((list_length - n) > 0){
            ListNode * before = addresses[list_length - n - 1];
            ListNode * cur = addresses[list_length - n];
            before->next = cur->next;
            // free(cur);
        }else if((list_length - n) == 0){
            ListNode * tmp = addresses[list_length - n];
            head = tmp->next;
            // free(tmp);
        }
        return head;
    }
};

ListNode * createList(){
    // 0->1->2->3->4->5
    int i = 1;
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    while(i < 6){
        p -> next = new ListNode(i);
        p = p->next;
        i++;
    }
    return head;
}

void printList(ListNode *head){
    ListNode * p = head;
    while(p && p->next != NULL){
        cout << p->val<<"->";
        p = p->next;
    }
    cout<<p->val<<endl;
}

int main(){
    ListNode * head = createList();
    Solution solu = Solution();
    int point = 7;
    printList(head);
    head = solu.removeNthFromEnd(head, point);
    cout <<"after remove "<<point<<"th element from end"<<endl;
    printList(head);
    return 0;
}