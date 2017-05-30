/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student &data, ListElem* const next):
    data(data), next(next), prev(NULL)
{
}

void ListElem::setData(const Student &data)
{
    this->data = data;
}


void ListElem::setNext(ListElem* const next)
{
    this->next = next;
}

void ListElem::setPrevious(ListElem* const prev) {
    this->prev = prev;
}

Student ListElem::getData() const
{
    return data;
}


ListElem* ListElem::getNext() const
{
    return next;
}

ListElem* ListElem::getPrevious() const {
    return prev;
}
