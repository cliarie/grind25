#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Node {
public:
    int value;
    std::vector<Node*> children;
    bool isSelected;

    Node(int val) : value(val), isSelected(false) {}
};

class Tree {
public:
    Node* root;
    std::unordered_map<int, int> nodeLevels;  // Maps node value to its level
    std::unordered_map<int, Node*> parentMap; // Maps node value to its parent

    Tree(Node* rootNode) : root(rootNode) {}

    void calculateLevels(Node* node, int level) {
        if (!node) return;
        nodeLevels[node->value] = level;
        for (Node* child : node->children) {
            parentMap[child->value] = node;
            calculateLevels(child, level + 1);
        }
    }

    int getNodeLevel(int nodeValue) {
        return nodeLevels[nodeValue];
    }

    std::vector<Node*> getNodesAtLevel(int targetLevel) {
        std::vector<Node*> result;
        for (auto& [nodeValue, level] : nodeLevels) {
            if (level == targetLevel) {
                result.push_back(getNodeByValue(nodeValue));
            }
        }
        return result;
    }

    Node* getNodeByValue(int nodeValue) {
        // BFS to find the node by value
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->value == nodeValue) return current;
            for (Node* child : current->children) {
                q.push(child);
            }
        }
        return nullptr;
    }

    int calculateScoreForLevel(int targetLevel, const std::vector<int>& selectedNodes) {
        int score = 0;
        std::vector<Node*> nodesAtLevel = getNodesAtLevel(targetLevel);

        // Score for selected nodes
        for (Node* node : nodesAtLevel) {
            if (node->isSelected) score += 3;  // Selected node
        }

        // Score for parents of selected nodes
        for (int selectedNodeValue : selectedNodes) {
            Node* parentNode = parentMap[selectedNodeValue];
            if (parentNode && nodeLevels[parentNode->value] == targetLevel) {
                score += 2;  // Parent of selected node
            }
        }

        // Score for siblings of selected nodes
        for (int selectedNodeValue : selectedNodes) {
            Node* parentNode = parentMap[selectedNodeValue];
            if (parentNode) {
                for (Node* sibling : parentNode->children) {
                    if (sibling->value != selectedNodeValue && nodeLevels[sibling->value] == targetLevel) {
                        score += 1;  // Sibling of selected node
                    }
                }
            }
        }

        return score;
    }

    int getMaxScore(int startingNodeValue, int numberOfLevels, const std::vector<int>& selectedNodes) {
        int maxScore = 0;
        int nodeLevel = getNodeLevel(startingNodeValue);

        for (int startLevel = std::max(0, nodeLevel - numberOfLevels + 1); startLevel <= nodeLevel; ++startLevel) {
            int currentScore = 0;
            for (int level = startLevel; level < startLevel + numberOfLevels && level < nodeLevels.size(); ++level) {
                currentScore += calculateScoreForLevel(level, selectedNodes);
            }
            maxScore = std::max(maxScore, currentScore);
        }

        return maxScore;
    }
};

int main() {
    // Create a sample tree
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    Node* child4 = new Node(5);

    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(child3);
    child1->children.push_back(child4);

    Tree tree(root);

    // Calculate the levels of nodes
    tree.calculateLevels(root, 0);

    // Select some nodes
    child1->isSelected = true;  // Node 2 selected
    child4->isSelected = true;  // Node 5 selected

    std::vector<int> selectedNodes = {2, 5};  // Values of selected nodes

    // Calculate the max score for a node with 3 levels considered
    int startingNodeValue = 2;
    int numberOfLevels = 3;
    int maxScore = tree.getMaxScore(startingNodeValue, numberOfLevels, selectedNodes);

    std::cout << "Max score for node " << startingNodeValue << " is: " << maxScore << std::endl;

    return 0;
}
