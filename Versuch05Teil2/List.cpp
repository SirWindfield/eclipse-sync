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

/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_head(const Student &pData)
{
    ListElem* new_element = new ListElem(pData, NULL);

    if (tail == NULL)                                       // list empty?
    {
        tail = new_element;
    } else
    {
        // HERE
        head->setPrevious(new_element);
        new_element->setNext(head);
    }

    head = new_element;
}

/**
 * @brief Dequeue an element from the end of the list.
 *
 * This is the single linked version.
 *
 * @param pData The data will be stored here.
 * @return bool
 */
bool List::dequeue(Student& pData)
{
    ListElem* cursor = head;

    if (head == NULL)                                       // list empty?
    {
        return false;
    } else if (head == tail)                                 // only one element
    {
        pData = head->getData();
        delete head;
        head = NULL;
        tail = NULL;
    } else
    {
        while (cursor->getNext() != tail)
        {
            cursor = cursor->getNext();
        }

        pData = tail->getData();
        tail = cursor;
        delete cursor->getNext();
        tail->setNext(NULL);
    }

    return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards()
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
        cursor->getData().print();
        cursor = cursor->getNext();
    }
}

// TODO clean-up
bool List::deleteByID(unsigned int id)
{
    for (ListElem* cursor = head; cursor != NULL; cursor = cursor->getNext())
    {
        Student data = cursor->getData();
        if (data.getMatNr() == id)
        {
            // delete element
            std::cout << "Student " << cursor->getData().getName()
                    << " will get deleted!" << std::endl;

            // reset head or tail if possible
            if (cursor == head)
            {
                // reset head and relink previous to NULL
                ListElem* element = cursor->getNext();
                element->setPrevious(NULL);
                head = element;
            } else if (cursor == tail)
            {
                // reset tail. Redo link to previous element
                ListElem* element = cursor->getPrevious();
                element->setNext(NULL);
                tail = element;
            } else
            {
                // delete element
                ListElem* prev = cursor->getPrevious();
                ListElem* next = cursor->getNext();

                prev->setNext(next);
                next->setPrevious(prev);
            }
            delete cursor;

            return true;
        }
    }
    return false;
}

void List::print_backwards()
{
    for (ListElem* cursor = tail; cursor != NULL; cursor =
            cursor->getPrevious())
    {
        cursor->getData().print();
    }
}

void List::enqueue_tail(const Student &data)
{
    ListElem* new_element = new ListElem(data, NULL);
    if (tail != NULL)
    {
        tail->setNext(new_element);
        new_element->setPrevious(tail);
    }
    tail = new_element;
}
