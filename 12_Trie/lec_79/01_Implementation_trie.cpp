#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption: Word will be in uppercase
        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            // Mark the node as non-terminal
            if (root->isTerminal) {
                root->isTerminal = false;
                // Check if the current node has no children
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Can't delete the node
                    }
                }
                return true; // Node can be deleted
            }
            return false; // Word doesn't exist
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            return false; // Word doesn't exist
        }

        // Recursively remove the rest of the word
        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            // Delete the child node
            delete child;
            root->children[index] = NULL;

            // Check if the current node has any children or is terminal
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Can't delete the node
                    }
                }
                return true; // Node can be deleted
            }
        }

        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    // INSERTION TC O(L)
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    // SEARCH TC O(L)
    cout << "Present or Not (ARM): " << t->search("ARM") << endl;

    // REMOVE
    t->removeWord("ARM");
    cout << "Present or Not (ARM after removal): " << t->search("ARM") << endl;

    t->removeWord("TIME");
    cout << "Present or Not (TIME after removal): " << t->search("TIME") << endl;

    return 0;
}
