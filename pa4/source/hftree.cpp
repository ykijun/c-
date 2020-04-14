#include "hftree.h"
#define COUNT 4


HuffmanTree::HuffmanTree() : hfTree(NULL) {}

void HuffmanTree::loadMap(map<char, int> frequency_table)
{
    // create an minimum priority queue in STL
    // insert your code here ...
    class cmp {
    public:
    	char subTreeLookup(const HuffmanTreeNode* node, char chr){
    		if (node == NULL)
    			return '\0';
    		char rc = node->key;
    		char left = subTreeLookup(node->leftChild,rc);
    		char right = subTreeLookup(node->rightChild,rc);

    		if (left == '\0' && right == '\0'){
    			rc = node->key;
    		}
    		if (left < right && left !='\0'){
    			rc = left;
    		}
			if (left > right && right !='\0'){
				rc = right;
			}
    		return rc;
    	};

        bool operator()(const HuffmanTreeNode* a, const HuffmanTreeNode* b) {
        	if (a->weight == b->weight){
        		return subTreeLookup(a, a->key)>subTreeLookup(b,b->key);
        	}
				return a->weight > b->weight;
			};
    };

	priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,cmp> pq;
    for (map<char,int>::iterator itr = frequency_table.begin(); itr != frequency_table.end();itr++){
    	HuffmanTreeNode* a = new HuffmanTreeNode;
    	a->key = itr->first;
    	a->weight = itr->second;
    	pq.push(a);
    }


    while (pq.size() >= 2) {
        HuffmanTreeNode* left = pq.top(); pq.pop();
        HuffmanTreeNode* right = pq.top(); pq.pop();
        HuffmanTreeNode* combined = new HuffmanTreeNode;
    	mergeTree(left,right, combined);
        pq.push(combined);
    }

    this->hfTree = pq.top();
}

void HuffmanTree::mergeTree(HuffmanTreeNode *bt1, HuffmanTreeNode *bt2,
                       HuffmanTreeNode *pt)
{
    // insert your code here ...
	pt->key = '\0';
	pt->weight = bt1->weight + bt2->weight;
	pt->leftChild = bt1;
	pt->rightChild = bt2;
}


void HuffmanTree::encode(map<char, string>& encoded_table)
{
    // go through every path from root to leaf, then get the encoding of each character(leaf node)
    // you are NOT allowed to use any recursive method here, otherwise you'll get no marks for this function
    // try level-order traversal on this Huffman Tree
    // result encoded_table: char -- character set, string -- encoding of leaf node, like "00", "1001"...

    // insert your code here ...
    
	if (this->hfTree == NULL) return;

	queue<HuffmanTreeNode *> enq;
	enq.push(hfTree);


	while (!enq.empty()){
		HuffmanTreeNode* node_counter = enq.front();
		if(node_counter->key != '\0')
			encoded_table[node_counter->key]= node_counter->huffman_code;
		enq.pop();

		if (node_counter->leftChild != NULL){
			node_counter->leftChild->huffman_code = node_counter->huffman_code + "0";
			enq.push(node_counter->leftChild);
		}
		if (node_counter->rightChild != NULL){
			node_counter->rightChild->huffman_code = node_counter->huffman_code + "1";
			enq.push(node_counter->rightChild);
		}
	}

}

string HuffmanTree::decode(const string& bin_str)
{
    // decode a binary string to plaintext
    // insert your code here ...
	HuffmanTreeNode * node = this->hfTree;
    string s = "";
    int i = 0;
    while (bin_str[i]){
    	if (bin_str[i]== '1')
    		node= node->rightChild;

    	if(bin_str[i]== '0')
    		node= node->leftChild;

    	if(node->key){
    		s += node->key;
    		node= this->hfTree;
    	}
		i++;
    }

    return s;
}

void HuffmanTree::release()
{
    // release all tree nodes in post-order
    // you must use non-recursive traversal to release the tree
    // you need to print out the weight of nodes with post-order when you delete the node
    // hint: try to use stack
    // if you use recursive deletion, you will lose partial marks of this PA

    cout << "[start releasing the huffman tree...]" << endl;
    if (hfTree == NULL)
        return;

    // store the nodes in vector path with post-order first
    vector<HuffmanTreeNode*> path;

    // insert your code here ...
    
    stack <HuffmanTreeNode*> HTstk1, HTstk2;
    HTstk1.push(hfTree);
    HuffmanTreeNode* node;

    while (!HTstk1.empty()){
    	node = HTstk1.top();
    	HTstk1.pop();
    	HTstk2.push(node);
        if (node->leftChild)
            HTstk1.push(node->leftChild);
        if (node->rightChild)
            HTstk1.push(node->rightChild);
    }

    while (!HTstk2.empty()) {
        path.push_back(HTstk2.top());
        HTstk2.pop();
    }

    for (unsigned int i = 0; i < path.size(); i++) {
        if (i != path.size() - 1)
            cout << dec << path[i]->weight << " ";
        else
            cout << dec << path[i]->weight << endl;

        // delete the node
        delete path[i];
    }
    cout << "[successfully released.]" << endl;
}

