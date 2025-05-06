#include <gtest/gtest.h>

#include "AbstractionsDefinition.hpp"

// clang-format off

// gTest grouping class
class test_AbstractionsDefinition : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_AbstractionsDefinition : public cAbstractionsDefinition
  {
  public:
    // add here members for free access.
    using cAbstractionsDefinition::cAbstractionsDefinition; // delegate constructors

  };

};



TEST_F(test_AbstractionsDefinition, test_ctor)
{
  Test_AbstractionsDefinition t;
}
  