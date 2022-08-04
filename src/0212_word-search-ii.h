#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  char c = ' ';
  TrieNode* parent{nullptr};
  bool end_of_word{false};
};

class Trie {
 public:
  TrieNode root;
  Trie(vector<string>& vs) {
    for (auto& s : vs) {
      auto current_node = &root;
      for (char c : s) {
        if (current_node->children[c] == nullptr) {
          current_node->children[c] = new TrieNode;
          current_node->children[c]->parent = current_node;
          current_node->children[c]->c = c;
        }
        current_node = current_node->children[c];
      }
      current_node->end_of_word = true;
    }
  }
  static string GetWord(TrieNode* node) {
    string word;
    auto tnode = node;
    while (tnode && tnode->c != ' ') {
      word.push_back(tnode->c);
      tnode = tnode->parent;
    }
    reverse(word.begin(), word.end());
    return word;
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, TrieNode* trie_node,
                           int i, int j) {
    vector<string> ret;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
        !trie_node) {
      return ret;
    }

    if (trie_node->children.find(board[i][j]) == trie_node->children.end()) {
      return ret;
    }
    auto child_node = trie_node->children[board[i][j]];
    if (child_node->end_of_word) {
      ret.push_back(Trie::GetWord(child_node));
      child_node->end_of_word = false;
    }

    if (!child_node->children.empty()) {
      board[i][j] = -board[i][j];
      vector<string> x;
      x = findWords(board, child_node, i + 1, j);
      ret.insert(ret.end(), x.begin(), x.end());
      x = findWords(board, child_node, i, j + 1);
      ret.insert(ret.end(), x.begin(), x.end());
      x = findWords(board, child_node, i - 1, j);
      ret.insert(ret.end(), x.begin(), x.end());
      x = findWords(board, child_node, i, j - 1);
      ret.insert(ret.end(), x.begin(), x.end());
      board[i][j] = -board[i][j];
    } else {
      auto parent = child_node->parent;
      parent->children.erase(child_node->c);
      delete child_node;
    }
    return ret;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ret;
    if (board.empty() || board[0].empty()) {
      return ret;
    }

    Trie trie{words};

    vector<vector<pair<int, int>>> start_locations{26};
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        auto x = findWords(board, &(trie.root), i, j);
        ret.insert(ret.end(), x.begin(), x.end());
      }
    }

    return ret;
  }
};
