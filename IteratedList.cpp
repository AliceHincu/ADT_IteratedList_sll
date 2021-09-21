
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
    this->linkedList.head = nullptr;
    this->sizeList = 0;
}

int IteratedList::size() const {
	return this->sizeList;
} // Theta(1)

bool IteratedList::isEmpty() const {
	if (this->sizeList == 0)
        return true;
	return false;
} // Theta(1)

ListIterator IteratedList::first() const {
	return ListIterator(*this);
} // Theta(1)

TElem IteratedList::getElement(ListIterator pos) const {
	return pos.getCurrent();
} // Theta(1)

TElem IteratedList::remove(ListIterator& pos) {
	// check if valid
    if (!pos.valid())
        throw std::exception();

    TElem elem = pos.currentElement->data;

    // search for prev node
    SLLNode* currentNode = this->linkedList.head;
    SLLNode* prevNode = nullptr;

    while (currentNode != nullptr && currentNode != pos.currentElement){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    // remove the current node
    if (currentNode != nullptr && prevNode == nullptr) // delete the head
        this->linkedList.head = this->linkedList.head->next;
    else if (currentNode != nullptr){
        prevNode->next = currentNode->next;
        currentNode->next = nullptr;
    }

    this->sizeList--;
    return elem;
} //BC: pos is not valid, Theta(1). WC: we go to the end: Theta(n) => complexity: O(n)


ListIterator IteratedList::search(TElem e) const{
    ListIterator it = this->first();
    while (it.currentElement != nullptr) {
        if (it.currentElement->data != e)
            it.next();
        else
            break;
    }
    return it;
} // Complexity: O(n)


TElem IteratedList::setElement(ListIterator pos, TElem e) {
    if (!pos.valid())
        throw std::exception();
    TElem old = pos.getCurrent();
    pos.currentElement->data = e;
	return old;
} // Theta(1)

void IteratedList::addToBeginning(TElem e){
    this->sizeList++;

    // create new node
    SLLNode* temp = new SLLNode;
    temp->data = e;
    temp->next = nullptr;

    // add it
    SLLNode* auxHead = linkedList.head;
    linkedList.head = temp;
    temp->next = auxHead;
} // Theta(1)

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    if (!pos.valid())
        throw std::exception();

    this->sizeList++;
    // create new node
    SLLNode* temp = new SLLNode;
    temp->data = e;
    temp->next = nullptr;

    // add it
    temp->next = pos.currentElement->next;
    pos.currentElement->next = temp;
    pos.next();
} // Theta(1)

void IteratedList::addToEnd(TElem e) {
    this->sizeList++;
    //create new node
    SLLNode* temp = new SLLNode;
    temp->data = e;
    temp->next = nullptr;

    // add it
    if(linkedList.head == nullptr) { // empty list becomes the new node
        linkedList.head = temp;
        return;
    } else { // find tail and link the new node
        SLLNode* last = linkedList.head;
        while(last->next) last=last->next;
        last->next = temp;
    }
} //BC:theta(1), WC:theta(size)=>Complexity: O(n)

IteratedList::~IteratedList() {
	SLLNode* current = this->linkedList.head;
	while (current != nullptr){
	    SLLNode* next = current->next;
	    delete current;
	    current = next;
	}
} //BC:theta(1), WC:theta(size)=>Complexity: O(n)

// returns the last index of a given element
// if the element is not in the list it returns an invalid TPosition
ListIterator IteratedList::lastIndexOf(TElem elem) const {
    ListIterator it = this->first();
    ListIterator aux = this->first();
    aux.currentElement = nullptr;

    while (it.currentElement != nullptr) {
        if (it.currentElement->data == elem)
            aux.currentElement = it.currentElement;
        it.next();
    }
    return aux;
} // Best case: Theta(1) , when the list is empty. Worst case: Theta(size), when is not in the list.
// => Complexity O(size) < O(n)
