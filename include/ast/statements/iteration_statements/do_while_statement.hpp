#pragma once

#include "../../node.hpp"

class DoWhileStatement : public Node {

public:

    DoWhileStatement(Node* s, Node* c) : statement(s), condition(c) {}

    ~DoWhileStatement() {
        delete condition;
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen
        // Update context.continue_label and context.break_label.
    }

    Node* condition;
    Node* statement;

};