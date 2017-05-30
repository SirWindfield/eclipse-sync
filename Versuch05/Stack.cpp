#include "Stack.h"

Stack::Stack() :
        head(NULL), tail(NULL)
{
}

void Stack::push(Student& data)
{
    ListElem* new_element = new ListElem(data, NULL);
    if (head == NULL)
    {
        tail = new_element;
    } else
    {
        new_element->setNext(head);
    }
    head = new_element;
}

void Stack::ausgabe() const
{
    if (head == NULL)													 // list empty?
    {
        std::cout << "Der Stack ist leer." << std::endl;
    } else
    {
        ListElem* element = head;
        while (element != NULL)
        {
            element->getData().print();
            element = element->getNext();
        }
    }
}

bool Stack::pop(Student& data)
{
    if (head == NULL)
    {
        return false;
    } else
    {
        data = head->getData();
        ListElem* element = head;
        head = head->getNext();
        delete element;
    }
    return true;
}
