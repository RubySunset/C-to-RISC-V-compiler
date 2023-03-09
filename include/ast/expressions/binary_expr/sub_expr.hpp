#pragma once

#include "binary_op.hpp"

class SubExpr : public BinaryOp {

public:

    SubExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};