// #include <iostream>
// #include <string>

template<class T>
class AVL {
private:
    struct node {
        T val;
        int height;
        node *left;
        node *right;

        node(T v) {
            val = v;
            left = NULL;
            right = NULL;
            height = 1;
        }
    };

    node *root;

    int height(node *p) {
        if (p == NULL)
            return 0;
        return p->height;
    }

    int bfactor(node *p) {
        return height(p->right) - height(p->left);
    }

    void fixheight(node *p) {
        int hl = height(p->left);
        int hr = height(p->right);
        if (hl > hr)
            p->height = hl + 1;
        else
            p->height = hr + 1;
    }

    node *findmin(node *p) {
        if (p->left == nullptr)
            return p;
        return findmin(p);
    }

    node *balance(node *p) {
        if (bfactor(p) == -2) {
            if (bfactor(p->left) > 0)
                p = doubleRightRotate(p);
            else
                p = singleLeftRotate(p);
            fixheight(p);
            return p;
        }
        if (bfactor(p) == 2) {
            if (bfactor(p->right) < 0)
                p = doubleLeftRotate(p);
            else
                p = singleLeftRotate(p);
            fixheight(p);
            return p;
        }
        fixheight(p);
        return p;
    }

    node *removemin(node *p) {
        if (p->left == nullptr)
            return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }

    node *insert(node *p, T v) {
        if (p == nullptr)
            return new node(v);

        if (v < p->val) {
            p->left = insert(p->left, v);
            p = balance(p);
            return p;
        }

        if (v > p->val) {
            p->right = insert(p->right, v);
            p = balance(p);
            return p;
        }

        return p;
    }

    node *singleRightRotate(node *t) {
        if (t->left == nullptr)
            return t;
        node *u = t->left;
        t->left = u->right;
        u->right = t;
        fixheight(t);
        fixheight(u);
        if (t == root)
            root = u;
        return u;
    }

    node *singleLeftRotate(node *t) {
        if (t->right == nullptr)
            return t;
        node *u = t->right;
        t->right = u->left;
        u->left = t;
        fixheight(t);
        fixheight(u);
        if (t == root)
            root = u;
        return u;
    }

    node *doubleLeftRotate(node *t) {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node *doubleRightRotate(node *t) {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node *remove(node *p, T v) {
        if (p == nullptr)
            return nullptr;
        if (v < p->val) {
            p->left = remove(p->left, v);
            return balance(p);
        }
        if (v > p->val) {
            p->right = remove(p->right, v);
            return balance(p);
        }

        node *l = p->left;
        node *r = p->right;
        delete p;
        if (r == nullptr)
            return l;
        node *newp = findmin(r);
        newp->right = removemin(r);
        newp->left = l;
        return balance(newp);
    }

    node *find(node *p, T v) {
        if (p == nullptr)
            return nullptr;
        if (p->val == v)
            return p;
        if (p->val < v)
            return find(p->right, v);
        return find(p->left, v);
    }

public:
    AVL() {
        root = nullptr;
    }

    void insert(T v) {
        root = insert(root, v);
    }

    void remove(T v) {
        root = remove(root, v);
    }

    T *find(T v) {
        return &(find(root, v)->val);
    }
};

// int main() {
//     AVL<int> birch;
//     birch.insert(566);
//     birch.insert(239);
//     birch.insert(1589);
//     std::cout << (birch.find(1589) != nullptr) << '\n';
//     std::cout << (birch.find(30) != nullptr) << '\n';
//     std::cout << (birch.find(239) != nullptr) << '\n';
//     birch.remove(2);
//     birch.remove(1589);
//     birch.insert(179);
//     std::cout << (birch.find(179) != nullptr) << '\n';
//     std::cout << (birch.find(1589) != nullptr) << '\n';

//     std::cout << "##########################################\n";

//     AVL<std::string> oak;
//     std::cout << (oak.find("Kiselev") != nullptr) << '\n';
//     oak.insert("Alexandrov");
//     oak.insert("Karasev");
//     oak.insert("Kiselev");
//     std::cout << (oak.find("Kiselev") != nullptr) << '\n';
//     std::cout << (oak.find("Alexandrov") != nullptr) << '\n';
//     oak.insert("Arutiunov");
//     oak.remove("Alexandrov");
//     std::cout << (oak.find("Arutiunov") != nullptr) << '\n';
//     std::cout << (oak.find("Alexandrov") != nullptr) << '\n';
//     return 0;
// }
