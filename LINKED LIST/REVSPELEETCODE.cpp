
# include<iostream>
using namespace  std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
      ListNode* temp=head;
      if(head==NULL) return head;
      if(left==right)return head;
      int count=0;
      while(count!=left-1)
      {
          if(count>0)temp=temp->next;
          count++;  
      }
      ListNode* prev=temp;
      ListNode* cur=temp->next;
      ListNode* post=cur->next;
      while(1)
      {
          cur->next=prev;
          count++;
          if(count==right-1)break;
          prev=cur;
          cur=post;
          
          post=post->next;
      }
      (temp->next)->next=post;
      temp->next=cur;
      return head;
    }
};