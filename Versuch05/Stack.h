#ifndef STACK_H_
#define STACK_H_

#include <iostream> /* cin/cout */
#include "ListElem.h"

/**
 * @brief A stack is a dynamic data structure based on the LIFO principle.
 */
class Stack
{
private:

    /**
     * The pointer to the first element.
     */
    ListElem* head;

    /**
     * The pointer to the last element.
     */
    ListElem* tail;

public:

    /**
     * The default constructor.
     */
    Stack();

    /**
     * @brief Pushes new data onto the stack.
     *
     * This is done by creating a new list element and setting its data to the passed student.
     *
     * @param data The new data that should be added to the stack.
     */
    void push(Student& data);

    /**
     * @brief Removes the last added student from the stack.
     *
     * @data The reference that should hold the removed student.
     * @return True if this operation was successful, false otherwise.
     */
    bool pop(Student& data);

    /**
     * @brief Prints the stack's elements to the console.
     */
    void ausgabe() const;
};

#endif
