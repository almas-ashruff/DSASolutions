// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

// https://practice.geeksforgeeks.org/problems/sort-a-stack/1#

void insert(stack<int>&s,int t){

    if(s.size()==0 || t>=s.top()) { 
    //if stack size is equal to zero
    //or elemnet to be inserted is larger(or equal) than its top element then directly insert
        s.push(t);
        return;
    }

    int val=s.top();//if top element is larger then store it in val variable
    s.pop();//and pop it

    insert(s,t);//call it recursively

    s.push(val);//after inserting element push large element back

    return;
}

void SortedStack :: sort() {
    if(s.size()==1) { //one element is already sorted
        return;
    }

    int temp=s.top();//storing top element in temp

    s.pop();//making the input smaller by breaking it

    sort();//calling void sort recurcively again and again until s.size becomes 1

    insert(s,temp);//inserting temp in stack

    return;
}