#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head)
    {
        if(head==NULL || head->next==NULL || head->next->next==NULL)return;
          ListNode* temp=head;
          while(1)
          {
              ListNode* temp2=temp->next;
              if(temp2==NULL)break;
              if(temp2->next==NULL)break;
              while(temp2->next->next!=NULL)
              {
                  temp2=temp2->next;
              }
              ListNode * temp3=temp->next;
              temp->next=temp2->next;
              temp2->next->next=temp3;
              temp2->next=NULL;
              temp=temp->next->next;
              if(temp==NULL)break;
          }
    }
};
