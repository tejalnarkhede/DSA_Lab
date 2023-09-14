#include <iostream>
#include <stack>

using namespace std;

struct Exnode {
    char data{};
    Exnode *left = nullptr;
    Exnode *right = nullptr;
};

class Extree {
public:
    char *add(Exnode **temp, char *arr) {
        if (*arr == '\0')
            return nullptr;

        while (true) {
            char *q;
            if (*temp == nullptr) {
                Exnode *n = (Exnode *) malloc(sizeof(Exnode));
                n->data = *arr;
                n->left = nullptr;
                n->right = nullptr;
                *temp = n;
            } else {
                if ((*arr >= 'a' && *arr <= 'z') || (*arr >= 'A' && *arr <= 'Z')) {
                    return arr;
                }
                q = add(&(*temp)->left, arr + 1);
                q = add(&(*temp)->right, q + 1);
                return q;
            }
        }
    }

    void postorder(Exnode *temp) {
        if (temp != nullptr) {
            stack<Exnode *> s;
            s.push(temp);
            stack<char> out;
            while (!s.empty()) {
                Exnode *curr = s.top();
                s.pop();
                out.push(curr->data);
                if (curr->left) {
                    s.push(curr->left);
                }
                if (curr->right) {
                    s.push(curr->right);
                }
            }
            while (!out.empty()) {
                cout << out.top() << " ";
                out.pop();
            }
        } else {
            cout << "Tree is empty!" << endl;
        }
    }

};

int main() {
    int ch;
    char a[20];
    Extree obj;
    Exnode *s = nullptr;
    cout << "1. Insert\n2. Display\n3. Delete tree\n4. Exit" << endl;
    do {
        cout << "\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter Prefix Expression: ";
                cin >> a;
                //char a[] = "+--a*bc/def";
                obj.add(&s, a);
                break;
            case 2:
                obj.postorder(s);
                break;
            case 3:
                s = nullptr;
                cout << "Tree Successfully Deleted";
                break;
            case 4:
                cout << "\nExiting..." << endl;
                exit(0);
            default:
                cout << "Incorrect Choice!!";
        }
    } while (ch != 7);
    return 0;
}
