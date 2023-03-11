#pragma once

#include "node.hpp"
#include "declarator.hpp"

class Declaration : public Node {

public:

    Declaration(std::string t, std::vector<Declarator*> d)
        : type(t), declarators(d) {}

    ~Declaration() {
        for (auto d : declarators) {
            delete d;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        for (auto d : declarators) {
            d->compile(os, dest_reg, context); // Compute intialiser value and store result in dest_reg
            int fp_offset = context.new_variable(type, d->identifier); // Prepare to add new variable to stack
            context.store_reg(os, dest_reg, fp_offset); // Store variable in stack
        }
        // Update this to work with more types (other than int) later.
    }

    std::string type;
    std::vector<Declarator*> declarators;

};