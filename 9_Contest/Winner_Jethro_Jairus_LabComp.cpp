#include <iostream>

using namespace std;

class inter {
    public:
        inter();
        inter(int a, int b, inter *p = 0) {
            lower = a;
            upper = b;
            next = p;
        }
        
        int upper;
        int lower;
        
        inter *next;
};

class interSet {
    public:
        interSet() {
            head = tail = NULL;
            numEl = 0;
        }
        
        void printSet();
        bool overlaps(int , int );
        void Make(int , int );
        void Merge(int , int , int );
        void Split(int , int , int );
        inter * Catch(int );
        
        inter *head;
        inter *tail;
        int numEl; 
};

int main(void) {
    interSet Set;
    
    Set.Make(4, 7);
    Set.Make(7, 9);
    Set.Make(1, 3);
    Set.Make(12, 19);
    
    Set.printSet();
    
    Set.Merge(4, 7, 9);
    
    Set.printSet();
    
    Set.Split(12, 19, 15);
    
    Set.printSet();
    
    inter *test;
    int k = 99;
    test = Set.Catch(k);
    
    if(test)
        cout << "Interval: [" << test->lower << ", " << test->upper << ") contains k="<<k << endl;
}

void interSet::printSet() {
    cout << "\n{";
    for(inter *p = head; p != NULL; p = p->next) {
        cout << "[" << p->lower << ", " << p->upper;
        if(p->next != NULL)
            cout << "), ";
        else
            cout << ")";
    }
    cout << "}\n";
    cout << "Number of elements: " << numEl << "\n" << endl;
}

bool interSet::overlaps(int a, int b) {
    bool check = false;
    inter*p = head;
    for(; p != NULL; p = p->next) {
        if((a >= p->lower && a < p->upper) || (b >= p->lower && b < p->upper) || (a <= p->lower && b > p->upper))
            check = true;
    }
    
    return check;
}

void interSet::Make(int a, int b) {
    if(head == NULL) {
        head = tail = new inter(a, b);
        numEl++;
    } else {
        if(overlaps(a, b)) {
            cout << "Error: Overlap with existing interval" << endl;
            return;
        } else {
            if(a < head->lower)
                head = new inter(a, b, head);
            else if(b >= tail->upper) {
                tail->next = new inter(a, b);
                tail = tail->next;
            } else {
                inter *p = head;
                for(; p != NULL; p = p->next) {
                    if(a >= p->upper) {
                        p->next = new inter(a, b, p->next);
                    }
                }
            }
            numEl++;
        }
    }
}

void interSet::Merge(int a, int b, int c) {
    bool mergePossible = false;
    inter *first, *second;
    for(first = head, second = head->next; second != NULL; first = first->next, second = second->next) {
        if(first->upper == b && (first->upper == second->lower)) {
            mergePossible = true;
            break;
        }
    }
    
    if(mergePossible == false) {
        cout << "Error: No merge possible" << endl;
        return;
    } else {
        inter *temp = second->next;
        first->upper = second->upper;
        delete second;
        first->next = temp;
        numEl--;
    }
}

void interSet::Split(int a, int b, int k) {
    bool interExists = false;
    inter *p = head;
    for(; p!= NULL; p = p->next) {
        if(p->lower == a && p->upper == b) {
            interExists = true;
            break;
        }
    }
    
    if(interExists) {
        int temp = p->upper;
        p->upper = k;
        p->next = new inter(k, temp, p->next);
        numEl++;
    } else {
        cout << "Error: Interval not in set" << endl;
    }
}

inter * interSet::Catch(int k) {
    inter *p = head;
    
    for(; p != NULL; p = p->next) {
        if(p->lower <= k && p->upper > k)
            break;
    }
    
    if(p == NULL) {
        cout << "Error: No interval contains k="<<k << endl;
        return p;
    } else
        return p;
}
