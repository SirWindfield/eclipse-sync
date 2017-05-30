/**
 * @file List.h
 * content: linked list data structure
 */

/*
 * Diese Datei gehört nicht zu Versuch05Teil, sondern wird in Versuch05Teil02 benötigt
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Student.h"
#include "ListElem.h"

/**
 * @brief doubly linked list data structure
 */
class List
{
private:

    /**
     * The pointer to the first list element.
     */
    ListElem* head;

    /**
     * the pointer to the last element.
     */
    ListElem* tail;

public:

    /**
     * @brief The default constructor.
     */
    List();

    /**
     * @brief Enqueue an element at the beginning of the list.
     *
     * @param data The @ref Student to be added.
     */
    void enqueue_head(const Student &data);

    /**
     * @brief Dequeue an element from the end of the list.
     *
     * This is the single linked version.
     *
     * @param data The data will be stored here.
     * @return bool
     */
    bool dequeue(Student& data);

    /**
     * @brief Prints the content of all elements. Goes from first to last.
     */
    void print_forwards();
};

#endif /*LIST_H_*/
