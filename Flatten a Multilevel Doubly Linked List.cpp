/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* cur = head;
        while(cur){
            // cout<<cur->val<< " ";
            if(cur->child){
                st.push(cur->next);
                cur->next = cur->child;
                cur->child->prev = cur;
                cur = cur->child;
                cur->prev->child = NULL;
                continue;
            }
            if(cur->next == NULL && !st.empty()){
                Node* t = st.top();
                cur->next = t;
                if(t){
                    t->prev = cur;
                    // cur = t;
                    // continue;
                }
                st.pop();
            }
            cur = cur->next;
        }
        return head;
    }
};
