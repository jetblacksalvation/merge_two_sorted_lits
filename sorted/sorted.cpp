#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* create_list(std::initializer_list<int>list) {

    ListNode* temp = new ListNode(*list.begin());

    ListNode* root = temp;

    
    for (int x = 1; x != list.size(); x++) {
        
        temp->next = new ListNode(*(list.begin() + x));
        temp = temp->next;
    }
    return root;
}
//list2 sorted lists = list1 sorted list
ListNode* sorted2(ListNode* list1, ListNode* list2) {
    ListNode* ret; //= new ListNode();
    if (list1 == 0 || list2 == 0) {
        ret = (list1 !=0) ? list1 : list2;//return which ever isn't null, than return that 
        return ret;
    }
    //if neither is null than start computation, both lists are sorted 
    ListNode* temp_list1 = list1;
    ListNode* temp_list2 = list2;

    ret = (temp_list1->val <= temp_list2->val) ? new ListNode(temp_list1->val) : new ListNode(temp_list2->val);
    ListNode* temp_ret = ret;
    
    if (temp_list1->val <= temp_list2->val) {
        temp_list1 = temp_list1->next;
    }
    else {
        temp_list2 = temp_list2->next;
    }
    //increment these 
    while (1) {

        if (!temp_list2 && temp_list1) {
            temp_ret->next = temp_list1;
            return ret;
        }
        else if (temp_list2 && !temp_list1) {
            temp_ret->next = temp_list2;
            return ret;
        }
        else if (!temp_list2 && !temp_list1) {
            return ret;
        }
        //most important evals ^^^^
        temp_ret->next = (temp_list1->val <= temp_list2->val) ? new ListNode(temp_list1->val) : new ListNode(temp_list2->val);
        if (temp_list1->val <= temp_list2->val) {
            temp_list1 = temp_list1->next;
        }
        else {
            temp_list2 = temp_list2->next;
        }

        temp_ret = temp_ret->next;
    }

}



int main(void) {
    ListNode* list1 = create_list({2});
    ListNode* list2 = create_list({ 1 });

    ListNode* res = sorted2(list1, list2);

    while (res != NULL) {
        std::cout << res->val<<std::endl;
        res = res->next;
    }
}

