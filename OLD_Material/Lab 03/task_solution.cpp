bool search_in_ll(int value, Node* head){
    Node* currentNode = head;
    while(currentNode != NULL){
        if(currentNode->value == value){
            cout<<value<<" is found"<<endl;
            return true;
        }
        currentNode = currentNode->next;
    }
    cout<<value<<" is not found"<<endl;
    return false;
}
