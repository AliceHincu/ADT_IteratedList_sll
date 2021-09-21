#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	currentElement = list.linkedList.head;
} // theta(1)

void ListIterator::first() {
    currentElement = list.linkedList.head;
} // theta(1)

void ListIterator::next() {
    if (currentElement == nullptr)
        throw std::exception();
    currentElement = currentElement->next;
} // theta(1)

bool ListIterator::valid() const {
	if (currentElement == nullptr)
        return false;
	return true;
} // theta(1)

TElem ListIterator::getCurrent() const {
	if (currentElement == nullptr)
        throw std::exception();
	TElem e = currentElement->data;
	return e;
}


// theta(1)



