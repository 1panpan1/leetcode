#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
    ListNode * addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode * ptr1 = l1,* ptr2 = l2;
        ListNode * head = NULL,* ptr = NULL;
        int carry_flag = 0, value = 0;
        for(;ptr1 != NULL || ptr2 != NULL;){
            int sum = 0;
            if(ptr1 != NULL){
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            if(ptr2 != NULL){
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            value = (sum + carry_flag) % 10;
            carry_flag = (sum + carry_flag)/10;
            ListNode *newnode = new ListNode(value);
            if(head == NULL){
                head = newnode;
                ptr = head;
            }else{
                ptr->next = newnode;
                ptr = ptr->next;
            }
        }
        /*注意进位!!!为1的话最高位要补1*/
        if(carry_flag != 0){
            ptr->next = new ListNode(1);
        }
        return head;
    }
};

int main(){
    Solution so = Solution();
//    for(int i =1; i<=3; i++){
//        ListNode newnode = LIst
//    }
    ListNode l1 = ListNode(5);
    //l1.next = new ListNode(2);
    //l1.next->next = new ListNode(3);
    ListNode l2 = ListNode(5);
    //l2.next = new ListNode(5);
    //l2.next->next =new ListNode(6);
    ListNode * l3 = so.addTwoNumbers(&l1, &l2);
    ListNode *p = l3;
    while(p != NULL){
        cout<<p->val<<' ';
        p = p->next;
    }
    return 0;
}