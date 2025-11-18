/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    if (head == NULL) return NULL;

    struct ListNode *temp = head;
    struct ListNode *prev = NULL;


    while (head != NULL && head->val == val) {
        struct ListNode *del = head;
        head = head->next;
        free(del);
    }

    if (head == NULL) return NULL;

    temp = head;    
    prev = NULL;

    
    while (temp != NULL) {

        if (temp->val == val) {
            if (prev != NULL) {
                prev->next = temp->next;
            }

            struct ListNode *del = temp;
            temp = temp->next;
            free(del);
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}
