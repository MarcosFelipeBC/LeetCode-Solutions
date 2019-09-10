//https://leetcode.com/problems/split-linked-list-in-parts/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector < ListNode* > ans;
        int sizeList = 0;
        ListNode* aux = root;
        while (aux != NULL){
            sizeList++;
            aux = aux->next;
        }
        int blockSize = sizeList/k;
        int remain = sizeList%k;
        int qtd = 0;
        aux = root;
        ListNode *newList = NULL;
        ListNode *last = NULL;
        while (aux != NULL){
            if(qtd == 0){
                ans.push_back(NULL);
            }
            if(qtd < blockSize){
                if(ans[ans.size()-1] == NULL) {
                    ans[ans.size()-1] = new ListNode(aux->val);
                    last = ans[ans.size()-1];
                }
                else {
                    last->next = new ListNode(aux->val);
                    last = last->next;
                }
                qtd++;
                aux = aux->next;
            }
            if(qtd == blockSize){
                if(remain != 0){
                    if(ans[ans.size()-1] == NULL) {
                        ans[ans.size()-1] = new ListNode(aux->val);
                        last = ans[ans.size()-1];
                    }
                    else last->next = new ListNode(aux->val);
                    remain--;
                    aux = aux->next;
                }
                qtd = 0;
                newList = NULL;
                last = NULL;
            }
        }
        for (int i=sizeList; i<k; i++) ans.push_back(NULL);
        return ans;
    }
};
