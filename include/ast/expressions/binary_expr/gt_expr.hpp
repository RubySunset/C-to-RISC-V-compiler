#pragma once

#include "binary_op.hpp"

class GtExpr : public BinaryOp {

public:

    GtExpr(Node* l, Node* r) : BinaryOp(l, r) {
        value = l->value > r->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        auto [reg1, reg2] = eval(os, context);
        // TODO codegen
        std::cout << "sgt " << reg_name[reg1] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
        std::cout << "andi " << reg_name[reg1] << ", " << reg_name[reg1] << ", 0xff" << std::endl;
        std::cout << "mv  " << reg_name[dest_reg] << ", " << reg_name[reg1] << std::endl;
        free(reg1, reg2, context);
    }

};