#ifndef STACK_H
#define STACK_H


class Stack
{
    private:
        // defines node structure
        struct Node
        {
            char data;
            Node *next;
        };

        // class variables
        int size;
        Node *head, *tail;


    public:
        Stack();
        ~Stack();

        void add(char item);
        char remove();
};

#endif // STACK_H
