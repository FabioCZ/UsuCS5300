//
// Created by fabio on 2/27/16.
//
#include "Register.hpp"

namespace FC
{
    std::vector<std::string> Register::reg_pool = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9",
                                                   "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7"};

    std::shared_ptr<Register> Register::Allocate()
    {
        if (reg_pool.size() == 0) throw std::runtime_error("ran out of registers");
        auto n = reg_pool.back();
        reg_pool.pop_back();
        return std::make_shared<Register>(n);
    }
}
