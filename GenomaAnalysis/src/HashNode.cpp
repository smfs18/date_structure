//inlusão dos headers
#include "HashNode.h"
#include <cstring>
//construtor do Nó da Hash
HashNode::HashNode(const char* block) : count(1), next(nullptr) {
    strncpy(key, block, BLOCK_SIZE);
    key[BLOCK_SIZE] = '\0';
}