#include"assign2.cpp"
#include<iostream>
#include<cstring>
#include<Windows.h>
#include<iomanip>  
#include<vector>

int comp(uint64_t a, uint64_t b);
void inorder(BST * const bst, std::string *);
void preorder(BST * const bst, std::string *);
bool judge_splay(BST *bst, int &tree_count);

int main(){
    /*
        This is the test for function add_node. 
    */
    // Part 1 - case 1
    int count = 0;
    {
        tree_node * father = NULL;
        tree_node * child = NULL; 
        assign2_exception::exception e = 0;
        e|=add_node(father, child, CHILD_DIRECTION_LEFT);
        try {
            if (e!=1) throw e;
            count++;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 1, case1!  \033[0m\n";
        }
    }
    // // Part 1 - case 2
    {
        tree_node * father = new tree_node;
        tree_node * child = new tree_node; 
        tree_node * father_left = new tree_node;
        tree_node * child_father = new tree_node;

        father->l_child = father_left;
        child->father = child_father;

        assign2_exception::exception e = 0;
        e|=add_node(father, child, CHILD_DIRECTION_LEFT);
        try {
            if (e!=10) throw e;
            count++;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 1, case2!  \033[0m\n";
            
        }
        delete father;
        delete child;
        delete father_left;
        delete child_father;
    }
    // // Part 1 - case 3
    {
        tree_node * father = new tree_node;
        tree_node * child = new tree_node; 
        tree_node * father_right = new tree_node;

        father->r_child = father_right;
        child->father = NULL;
        assign2_exception::exception e = 0;
        e|=add_node(father, child, CHILD_DIRECTION_RIGHT);
        try {
            if (e!=4) throw e;
            count++;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 1, case3! \033[0m\n";
        }
        delete father;
        delete child;
        delete father_right;
    }

    // // Part 1 - case 4
    {
        tree_node * father = new tree_node;
        tree_node * child = new tree_node; 
        tree_node * father_right = new tree_node;

        father->r_child = father_right;
        child->father = NULL;
        assign2_exception::exception e = 0;
        e|=add_node(father, child, -1);
        try {
            if (e!=16) throw e;
            count++;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 1, case4! \033[0m\n";
        }
        delete father;
        delete child;
        delete father_right;
    }

    // // Part 1 - case 5
    {
        tree_node * father = new tree_node;
        tree_node * l_child = new tree_node; 
        tree_node * r_child = new tree_node;
        father->data=2;
        father->l_child=NULL;
        father->r_child=NULL;
        father->father=NULL;
        father->node_count=1;
        father->tree_count=1;
        l_child->data=1;
        l_child->l_child=NULL;
        l_child->r_child=NULL;
        l_child->father=NULL;
        l_child->node_count=1;
        l_child->tree_count=1;
        r_child->data=3;
        r_child->l_child=NULL;
        r_child->r_child=NULL;
        r_child->father=NULL;
        r_child->node_count=1;
        r_child->tree_count=1;
        assign2_exception::exception e = 0;
        e|=add_node(father, l_child, CHILD_DIRECTION_LEFT);
        e|=add_node(father, r_child, CHILD_DIRECTION_RIGHT);
        try {
            if (father->l_child->data!=1 || father->r_child->data!=3) throw e;
            count++;
            
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 1, case5! \033[0m\n";
        }
        delete father;
        delete l_child;
        delete r_child;
    }
    /*
        This is the test for function judge_child_direction. 
    */
    // // Part 2 - case 1
   {
        tree_node * node;
        node = NULL;
        int *child_direction = new int;

        assign2_exception::exception e = 0;
        e|=judge_child_direction(node, child_direction);
        try {
            if (e!=1) throw e;
            count++;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 2, case1! \033[0m\n";
        }
        delete node;
    }

    // Part 2 - case 2
   {
        tree_node * node;
        tree_node * father = new tree_node;
        node = new tree_node;
        node->father = NULL;
        int *child_direction = new int;

        assign2_exception::exception e = 0;
        e|=judge_child_direction(node, child_direction);
        try {
            if (e!=32) throw e;
            count++;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 2, case2! \033[0m\n";
        }
        delete node;
        delete father;
    }

    // Part 2 - case 3
    {
        tree_node * father = new tree_node;
        tree_node * l_child = new tree_node; 
        tree_node * r_child = new tree_node;
        father->data=2;
        father->l_child=NULL;
        father->r_child=NULL;
        father->father=NULL;
        father->node_count=1;
        father->tree_count=1;
        l_child->data=1;
        l_child->l_child=NULL;
        l_child->r_child=NULL;
        l_child->father=NULL;
        l_child->node_count=1;
        l_child->tree_count=1;
        r_child->data=3;
        r_child->l_child=NULL;
        r_child->r_child=NULL;
        r_child->father=NULL;
        r_child->node_count=1;
        r_child->tree_count=1;

        int *child_direction = new int;
        assign2_exception::exception e = 0;

        e|=add_node(father, l_child, CHILD_DIRECTION_LEFT);
        e|=add_node(father, r_child, CHILD_DIRECTION_RIGHT);
        try {
            e|=judge_child_direction(l_child,  child_direction);
            if (*child_direction != CHILD_DIRECTION_LEFT) throw e;
            e|=judge_child_direction(r_child,  child_direction);
            if (*child_direction != CHILD_DIRECTION_RIGHT) throw e;
            count++;
            
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 2, case3! \033[0m";
        }
        delete father;
        delete l_child;
        delete r_child;
    }

    /*
        This is the test cases for part 3.
    */

    // Part 3 - case 1
    {
        assign2_exception::exception e = 0;
        try {
                BST *bst = new BST;
                tree_node *node = new tree_node;
                node->data=50;
                node->l_child=NULL;
                node->r_child=NULL;
                node->father=NULL;
                node->node_count=1;
                node->tree_count=1;
                bst->root = node;
                bst->comp = comp;
                tree_node *targetnode;
                //std::cout<<"wrong\n";
                insert_into_BST(bst,55,&targetnode);
                insert_into_BST(bst,32,&targetnode);
                insert_into_BST(bst,90,&targetnode);
                insert_into_BST(bst,61,&targetnode);
                insert_into_BST(bst,29,&targetnode);
                insert_into_BST(bst,36,&targetnode);
                insert_into_BST(bst,100,&targetnode);

                std::string *s1 = new std::string, *s2 = new std::string;
                
                preorder(bst, s1);
                //std::cout<<*s1<<"\n";
                
                inorder(bst, s2);
                //std::cout<<*s2<<"\n";
                std::string ans1="501832132911361155149013611110011";
                std::string ans2="291132133611501855146111901310011";
                if (*s1!=ans1 || *s2!=ans2){
                    delete s1;
                    delete s2;
                    throw e;
                }
                count++;
                delete s1;
                delete s2;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 3, case1! \033[0m\n";
        }
    }

    // Part 3 - case 2
    {
        assign2_exception::exception e = 0;
        try {
                BST *bst = new BST;
                tree_node *node = new tree_node;
                node->data=50;
                node->l_child=NULL;
                node->r_child=NULL;
                node->father=NULL;
                node->node_count=1;
                node->tree_count=1;
                bst->root = node;
                bst->comp = comp;
                tree_node *targetnode;
                //std::cout<<"wrong\n";
                insert_into_BST(bst,55,&targetnode);
                insert_into_BST(bst,55,&targetnode);
                insert_into_BST(bst,55,&targetnode);
                insert_into_BST(bst,32,&targetnode);
                insert_into_BST(bst,90,&targetnode);
                insert_into_BST(bst,61,&targetnode);
                insert_into_BST(bst,29,&targetnode);
                insert_into_BST(bst,36,&targetnode);
                insert_into_BST(bst,100,&targetnode);
                insert_into_BST(bst,36,&targetnode);
                insert_into_BST(bst,36,&targetnode);
                insert_into_BST(bst,100,&targetnode);
                insert_into_BST(bst,100,&targetnode);
                //std::cout<<"preorder:\n";
                std::string *s1 = new std::string, *s2 = new std::string;
                //std::cout<<"preorder:\n";
                //std::cout<<"--------------------\n";
                preorder(bst, s1);
                //std::cout<<*s1<<"\n";
                //std::cout<<"inorder:\n";
                inorder(bst, s2);
                //std::cout<<*s2<<"\n";
                // std::cout<<"\n";
                //std::cout<<"-------------------\n";
                std::string ans1="5011432152911363355389015611110033";
                std::string ans2="2911321536335011455386111901510033";
                if (*s1!=ans1 || *s2!=ans2){
                    delete s1;
                    delete s2;
                    throw e;
                }
                count++;
                delete s1;
                delete s2;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 3, case2! \033[0m\n";
        }
    }

    /*
        This is the test case for part 4.
    */
   // Part 4 - case 1
    {
        assign2_exception::exception e = 0;
        try {
                BST *bst = new BST;
                tree_node *node = new tree_node;
                node->data=50;
                node->l_child=NULL;
                node->r_child=NULL;
                node->father=NULL;
                node->node_count=1;
                node->tree_count=1;
                bst->root = node;
                bst->comp = comp;
                tree_node *targetnode;
                //std::cout<<"wrong\n";
                insert_into_BST(bst,55,&targetnode);
                insert_into_BST(bst,32,&targetnode);
                insert_into_BST(bst,90,&targetnode);
                insert_into_BST(bst,61,&targetnode);
                insert_into_BST(bst,29,&targetnode);
                insert_into_BST(bst,36,&targetnode);
                insert_into_BST(bst,100,&targetnode);
                tree_node **target_node = new tree_node*;
                find_in_BST(bst, 1, target_node);
                if (*target_node != NULL) e = 1, throw e; // judgement step 1.
                count++;
                find_in_BST(bst, 50, target_node);
                if (*target_node==NULL || (*target_node)->data !=50) e = 2, throw e; // judgement step 2.
                count++;
                find_in_BST(bst, 55, target_node);
                if (*target_node==NULL || (*target_node)->data !=55) e = 3, throw e; // judgement step 3.
                count++;
                find_in_BST(bst, 90, target_node);
                if (*target_node==NULL || (*target_node)->data !=90) e = 4, throw e; // judgement step 4.
                count++;
                find_in_BST(bst, 61, target_node);
                if (*target_node==NULL || (*target_node)->data !=61) e = 5, throw e; // judgement step 5.
                count++;
                find_in_BST(bst, 29, target_node);
                if (*target_node==NULL || (*target_node)->data !=29) e = 6, throw e; // judgement step 6.
                count++;
                find_in_BST(bst, 36, target_node);
                if (*target_node==NULL || (*target_node)->data !=36) e = 7, throw e; // judgement step 7.
                count++;
                find_in_BST(bst, 32, target_node);
                if (*target_node==NULL || (*target_node)->data !=32) e = 8, throw e; // judgement step 8.
                count++;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 4, case1! Happen in judgement step "<<e<<". \033[0m\n";
        }
    }

    /*
        This is the test case for part 5. 
    */

    // Part 5 - case 1
    {
        assign2_exception::exception e = 0;
        try {
                BST *bst = new BST;
                tree_node *node = new tree_node;
                node->data=50;
                node->l_child=NULL;
                node->r_child=NULL;
                node->father=NULL;
                node->node_count=1;
                node->tree_count=1;
                bst->root = node;
                bst->comp = comp;
                tree_node *targetnode;
                tree_node *test_node_one;
                tree_node *test_node_two;
                tree_node *test_node_three;
                //std::cout<<"wrong\n";
                insert_into_BST(bst,55,&targetnode);
                insert_into_BST(bst,32,&targetnode);
                insert_into_BST(bst,90,&targetnode);
                insert_into_BST(bst,61,&targetnode);
                insert_into_BST(bst,61,&targetnode);
                insert_into_BST(bst,61,&targetnode);
                insert_into_BST(bst,61,&test_node_two);
                insert_into_BST(bst,29,&test_node_one);
                insert_into_BST(bst,36,&targetnode);
                insert_into_BST(bst,36,&test_node_three);
                insert_into_BST(bst,36,&targetnode);
                insert_into_BST(bst,100,&targetnode);
                insert_into_BST(bst,100,&targetnode);
                splay(bst, test_node_one);
                //std::cout<<"------------------\n";
                std::string *s1 = new std::string, *s2 = new std::string;
                //preorder(bst, s1);
                //std::cout<<*s1<<"\n";
                //inorder(bst, s2);
                //std::cout<<*s2<<"\n";
                int tree_c = 0;
                if (!judge_splay(bst, tree_c) || bst->root != test_node_one) throw e=1;
                //std::string ans1="291143211350112363355189017614410022";
                //std::string ans2="291143211336335011255186144901710022";
                
                // if (*s1!=ans1 || *s2!=ans2){      //judegement step 1
                //     delete s1;
                //     delete s2;
                //     e=1;
                //     throw e;
                // }
                count++;
                delete s1;
                delete s2;
                s1 = new std::string;
                s2 = new std::string;
                std::cout<<"------------------\n";
                splay(bst, test_node_two);
                // preorder(bst, s1);
                // //std::cout<<*s1<<"\n";
                // inorder(bst, s2);
                tree_c = 0;
                if (!judge_splay(bst, tree_c) || bst->root!=test_node_two) throw e=2;
                //std::cout<<*s2<<"\n";
                // ans1="6141429173216501536335511901310022";
                // ans2="2917321636335015551161414901310022";
                // if (*s1!=ans1 || *s2!=ans2){    //judgement step 2
                //     delete s1;
                //     delete s2;
                //     e=2;
                //     throw e;
                // }
                count++;
                delete s1;
                delete s2;
                s1 = new std::string;
                s2 = new std::string;
                splay(bst, test_node_three);
                //std::cout<<"------------------\n";
                // preorder(bst, s1);
                // //std::cout<<*s1<<"\n";
                // inorder(bst, s2);
                //std::cout<<*s2<<"\n";
                tree_c = 0;
                if (!judge_splay(bst, tree_c) || bst->root!=test_node_three) throw e=3;
                // ans1="5011432152911363361485511901310022";
                // ans2="2911321536335011455116148901310022";
                // if (*s1!=ans1 || *s2!=ans2){    //judgement step 3
                //     delete s1;
                //     delete s2;
                //     e=3;
                //     throw e;
                // }
                count++;
                delete s1;
                delete s2;
        }
        catch(assign2_exception::exception){
            std::cout<<"\033[41;11m Error in part 5, case1! Happen in judgement step "<<e<<". \033[0m\n";
        }
    }
    std::cout<<"The final result is "<<count<<"/21\n";
    std::cout<<"If you have patience, you can read my code and add some new test cases.\n";
    std::cout<<"Hope you a good score!\n";
    std::cout<<"If you find any bug or any , please contact us.\n";
}


int comp(uint64_t a, uint64_t b){
    if (a == b) return 0;
    else if (a > b) return 1;
    else return -1; 
};

void inorder(BST * const bst, std::string *s){
    if (bst->root != NULL){
        if (bst->root->l_child != NULL) {
            BST *new_bst = new BST;
            new_bst->comp = bst->comp;
            new_bst->root = bst->root->l_child;
            inorder(new_bst, s);
            delete new_bst;
            new_bst = NULL;
        }
        //std::cout<<bst->root->data<<" "<<bst->root->node_count<<" "<<bst->root->tree_count<<"\n";
        s->append(std::to_string(bst->root->data));
        s->append(std::to_string(bst->root->node_count));
        s->append(std::to_string(bst->root->tree_count));
        if (bst->root->r_child != NULL) {
            BST *new_bst = new BST;
            new_bst->comp = bst->comp;
            new_bst->root = bst->root->r_child;
            inorder(new_bst, s);
            delete new_bst;
            new_bst = NULL;
        }
    }
    else return;
};

void preorder(BST * const bst, std::string *s){
    if (bst->root != NULL){
        //std::cout<<bst->root->data<<" "<<bst->root->node_count<<" "<<bst->root->tree_count<<"\n";
        s->append(std::to_string(bst->root->data));
        s->append(std::to_string(bst->root->node_count));
        s->append(std::to_string(bst->root->tree_count));
        if (bst->root->l_child != NULL) {
            BST *new_bst = new BST;
            new_bst->comp = bst->comp;
            new_bst->root = bst->root->l_child;
            preorder(new_bst, s);
            delete new_bst;
            new_bst = NULL;
        }
        if (bst->root->r_child != NULL) {
            BST *new_bst = new BST;
            new_bst->comp = bst->comp;
            new_bst->root = bst->root->r_child;
            preorder(new_bst, s);
            delete new_bst;
            new_bst = NULL;
        }
    }
    else return;
};

bool judge_splay(BST *bst, int &tree_c){
    if (bst->root != NULL){
        //std::cout<<bst->root->data<<" "<<bst->root->node_count<<" "<<bst->root->tree_count<<"\n";
        tree_c += bst->root->node_count;
        if (bst->root->l_child != NULL) {
            if (bst->comp(bst->root->data, bst->root->l_child->data) < 0) return false;
            BST *new_bst = new BST;
            new_bst->comp = bst->comp;
            new_bst->root = bst->root->l_child;
            judge_splay(new_bst, tree_c);
            delete new_bst;
            new_bst = NULL;
        }
        if (bst->root->r_child != NULL) {
            if (bst->comp(bst->root->data, bst->root->r_child->data) > 0) return false;
            BST *new_bst = new BST;
            new_bst->comp = bst->comp;
            new_bst->root = bst->root->r_child;
            judge_splay(new_bst, tree_c);
            delete new_bst;
            new_bst = NULL;
        }
        if (bst->root->tree_count != tree_c) return false; 
     }
    else return true;
    return true;
}
/*
    author: 
        灵犀
    co-author:
        方艺钧
*/
