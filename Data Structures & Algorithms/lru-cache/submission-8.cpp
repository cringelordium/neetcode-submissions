class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) 
        : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    std::unordered_map<int, Node*> node_ac;
    int cache_capacity;
    Node* dummy_tail;
    Node* dummy_head;

    LRUCache(int capacity) 
    : cache_capacity(capacity), dummy_tail(nullptr), dummy_head(nullptr) {
        dummy_tail = new Node(0, 0);
        dummy_head = new Node(0, 0);
        dummy_tail->prev = dummy_head;
        dummy_head->next = dummy_tail;
        
    }
    
    void insertNode(Node* node) {
        dummy_head->next->prev = node;
        node->next = dummy_head->next;
        node->prev = dummy_head;
        dummy_head->next = node;
    }

    void change_connections(Node* node) {
        Node* node_next = node->next;
        Node* node_prev = node->prev;
        
        node->next->prev = node_prev; 
        node->prev->next = node_next; 
        
    }

    void insert_delete(Node* node) {
        insertNode(node);
        node_ac[node->key] = node;
        Node* lru_node = dummy_tail->prev;
        int lru_key = dummy_tail->prev->key;
        change_connections(lru_node);
        node_ac.erase(lru_key);
        delete lru_node;
    }

    int get(int key) {
        if (!node_ac.count(key)) {
            return -1;
        }

        if (dummy_head->next == node_ac[key]){ 
            return node_ac[key]->value;
        }

        int value = node_ac[key]->value;
        Node* move = node_ac[key];
        
        //перераспредление старого места ноды
        change_connections(move);
        
        //вставка в голову
        insertNode(move);

        return value;
    }
    
    void put(int key, int value) {
        if (!node_ac.count(key)) {
            Node* node = new Node(key, value);
            if (cache_capacity > node_ac.size()) {
                insertNode(node);
                node_ac[key] = node;
            } else {
                insert_delete(node);
            }

        } else {
            Node* node = node_ac[key];
            change_connections(node);
            insertNode(node);
            node_ac[key] = node;
            node->value = value;
        }
    }
};
