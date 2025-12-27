static void deleteNumber(struct ListNode* number)
{
    struct ListNode *figure;

    if (number == NULL) {
        return;
    }

    while (number) {
        figure = number;
        number = number->next;
        free(figure);
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL;
    struct ListNode *p = result;
    int carry = 0;

    while (l1 || l2) {
        if (p) {
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (p->next == NULL) {
                deleteNumber(result);
                return NULL;
            }
            p = p->next;
        } else {
            result = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = result;
            if (p == NULL) {
                deleteNumber(result);
                return NULL;
            }
        }

        p->val = carry;
        if (l1) {
            p->val += l1->val;
        }
        if (l2) {
            p->val += l2->val;
        }
        carry = p->val / 10;
        p->val %= 10;
        p->next = NULL;

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry) {
        if (p) {
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (p->next == NULL) {
                deleteNumber(result);
                return NULL;
            }
            p = p->next;
        } else {
            result = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = result;
            if (p == NULL) {
                deleteNumber(result);
                return NULL;
            }
        }
        p->val = carry;
        p->next = NULL;
    }

    return result;
}