/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student &data, ListElem* const next):
    data(data), next(next)
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


Student ListElem::getData() const
{
    return data;
}


ListElem* ListElem::getNext() const
{
    return next;
}
