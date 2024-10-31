            #include <iostream>
            using namespace std;

            class Node {
            private:
                int value;
                Node* next;

            public:
                Node() {
                    this->next = nullptr;
                }

                Node(int v, Node* n) {
                    this->value = v;
                    this->next = n;
                }

                int getValue() {
                    return this->value;
                }

                Node* getNext() {
                    return this->next;
                }

                void setValue(int v) {
                    this->value = v;
                }

                void setNext(Node* n) {
                    this->next = n;
                }
            };

            // Traversal
            void printList(Node* ll) {
                while (ll != nullptr) {
                    cout << ll->getValue() << endl;
                    ll = ll->getNext();
                }
                cout << "_____" << endl;
            }

            // Insertion (after a given node)
            void insertAfter(Node* predecessor, int value) {
                Node* newNode = new Node(value, predecessor->getNext());
                predecessor->setNext(newNode);
            }

            // Deletion (node after a given node)
            void deleteNode(Node* predecessor) {
                Node* toBeRemoved = predecessor->getNext();
                if (toBeRemoved != nullptr) {
                    predecessor->setNext(toBeRemoved->getNext());
                    delete toBeRemoved;
                }
            }

            // Searching (to be implemented by students)
            bool searchForNodeInList(Node* ll, int v) {
                // TODO: Implement this function to search for a node with value `v` in the linked list
                return false;  // Placeholder return
            }

            int main() {
                // Initial linked list: 10 -> 20 -> 25 -> 40 -> nullptr
                Node* llist = new Node(10, new Node(20, new Node(25, new Node(40, nullptr))));
                
                printList(llist);

                Node* pred = llist->getNext()->getNext();  // Node with value 25
                insertAfter(pred, 30);
                printList(llist);

                Node* pred_removed = llist->getNext();  // Node with value 20
                deleteNode(pred_removed);
                printList(llist);

                // Test search functionality after implementation
                // cout << searchForNodeInList(llist, 50) << endl;  // Expected output: 0 (false)
                // cout << searchForNodeInList(llist, 25) << endl;  // Expected output: 1 (true)

                return 0;
            }
