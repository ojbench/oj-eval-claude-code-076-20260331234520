#include <iostream>
#include <string>
#include "mylist.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    MyList<int>* lists = new MyList<int>[n];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;

        if (op == "push_back") {
            int listId, value;
            cin >> listId >> value;
            lists[listId].push_back(value);
        } else if (op == "pop_back") {
            int listId;
            cin >> listId;
            lists[listId].pop_back();
        } else if (op == "push_front") {
            int listId, value;
            cin >> listId >> value;
            lists[listId].push_front(value);
        } else if (op == "pop_front") {
            int listId;
            cin >> listId;
            lists[listId].pop_front();
        } else if (op == "front") {
            int listId;
            cin >> listId;
            cout << lists[listId].front() << endl;
        } else if (op == "back") {
            int listId;
            cin >> listId;
            cout << lists[listId].back() << endl;
        } else if (op == "insert") {
            int listId, index, value;
            cin >> listId >> index >> value;
            lists[listId].insert(index, value);
        } else if (op == "erase") {
            int listId, index;
            cin >> listId >> index;
            lists[listId].erase(index);
        } else if (op == "size") {
            int listId;
            cin >> listId;
            cout << lists[listId].size() << endl;
        } else if (op == "empty") {
            int listId;
            cin >> listId;
            cout << (lists[listId].empty() ? "true" : "false") << endl;
        } else if (op == "clear") {
            int listId;
            cin >> listId;
            lists[listId].clear();
        } else if (op == "link") {
            int listId1, listId2;
            cin >> listId1 >> listId2;
            lists[listId1].link(lists[listId2]);
        } else if (op == "cut") {
            int listId1, index, listId2;
            cin >> listId1 >> index >> listId2;
            lists[listId2] = lists[listId1].cut(index);
        } else if (op == "print") {
            int listId;
            cin >> listId;
            for (int j = 0; j < lists[listId].size(); j++) {
                MyList<int> temp = lists[listId];
                int k = 0;
                while (k < j) {
                    temp.pop_front();
                    k++;
                }
                cout << temp.front();
                if (j < lists[listId].size() - 1) cout << " ";
            }
            cout << endl;
        }
    }

    delete[] lists;
    return 0;
}
