/**
 * @file List.cpp
 * content: linked list data structure
 */

/*
 * Diese Datei gehört nicht zu Versuch05Teil, sondern wird in Versuch05Teil02 benötigt
 */

#include "List.h"

List::List() :
        head(NULL), tail(NULL)
{
}

void List::enqueue_head(const Student &data)
{
    ListElem* new_element = new ListElem(data, NULL);

    if (tail == NULL)                                       // list empty?
    {
        tail = new_element;
    } else
    {
        new_element->setNext(head);
    }

    head = new_element;
}

bool List::dequeue(Student& data)
{
    ListElem* cursor = head;

    if (head == NULL)                                       // list empty?
    {
        return false;
    } else if (head == tail)                                 // only one element
    {
        data = head->getData();
        delete head;
        head = NULL;
        tail = NULL;
    } else
    {
        while (cursor->getNext() != tail)
        {
            cursor = cursor->getNext();
        }

        data = tail->getData();
        tail = cursor;
        delete cursor->getNext();
        tail->setNext(NULL);
    }

    return true;
}

void List::print_forwards()
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
        cursor->getData().print();

        cursor = cursor->getNext();
    }
}
