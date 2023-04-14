#pragma once

#include <string>
#include <vector>
#include <deque>

using namespace std;


/**
* Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:  
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        vector<string> vecs;
        const string kFlag("null");
        deque<TreeNode*> deq;
        if (root == NULL)
        {
            vecs.push_back(kFlag);
            string result("[");            
            result.append(kFlag);
            result.append("]");
            return result;
        }
        else 
        {  
            char buffer[16];
            deq.push_back(root);
            while (!deq.empty()) 
            {
                TreeNode* tmp = deq.front();
                deq.pop_front();

                if (tmp != NULL)
                {
                    memset(buffer, 0, sizeof(char) * 16);
                    snprintf(buffer, 16, "%d", tmp->val);
                    vecs.push_back(buffer);
                }
                else 
                {
                    vecs.push_back(kFlag);
                    continue;
                }
                
                if (tmp->left)
                    deq.push_back(tmp->left);
                else
                    deq.push_back(NULL);
                
                if (tmp->right)
                    deq.push_back(tmp->right);
                else
                    deq.push_back(NULL);
            }
        }

        auto it = vecs.end() - 1;
        while (it != vecs.begin()) 
        {
            if (*it == kFlag)
                it--;
            else
                break;
        }

        vecs.erase(it + 1, vecs.end());

        string result("[");
        for (size_t i = 0; i < vecs.size(); ++i) 
        {
            result.append(vecs[i]);
            if (i != vecs.size() - 1)
                result.append(",");
        }
        result.append("]");

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<TreeNode*> vect;
        const string kFlag("null");
        
        size_t start = data.find("[");
        start = start + 1;
        size_t pos = start;

        while (pos < data.size()) 
        {
            if (data[pos] == ',' || data[pos] == ']')
            {
                string sub = data.substr(start, pos - start);

                TreeNode* node = NULL;
                if (sub != kFlag)
                {
                    int val = atoi(sub.c_str());
                    node = new TreeNode(val);
                }
                vect.push_back(node);

                pos++;
                start = pos;
            }
            else
            {
                pos++;
            }
        }

        TreeNode* root = vect[0];        
        for (size_t i = 0; i < vect.size() / 2; ++i) 
        {
            TreeNode* cur = vect[i];
            cur->left = vect[2 * i + 1];
            cur->right = vect[2 * i + 2];
        }

        return root;
    }
};
