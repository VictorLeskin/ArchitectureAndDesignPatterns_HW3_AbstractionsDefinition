#include <gtest/gtest.h>

#include "AbstractionsDefinition.hpp"

// clang-format off

// gTest grouping class
class test_cVector : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cVector : public cVector
  {
  public:
    // add here members for free access.
    using cVector::cVector; // delegate constructors
  };

};

// gTest grouping class
class test_cMove : public ::testing::Test
{
public:
    // additional class to access to member of tested class
    class Test_cMove : public cMove
    {
    public:
        // add here members for free access.
        using cMove::cMove; // delegate constructors
    };

    // additional class to access to member of tested class
    class Test_cMovable : public cMovable
    {
    public:
        // add here members for free access.
        using cMovable::cMovable; // delegate constructors
    };

    // additional class to access to member of tested class
    class Test_cMovableThrowExceptions : public cMovable
    {
    public:
        bool getPosition_throwsException = false;
        bool getVelocity_throwsException = false;
        bool setPosition_throwsException = false;

    public:
        // add here members for free access.
        using cMovable::cMovable; // delegate constructors

        const cVector& Position() const override { if( true == getPosition_throwsException ) throw cException( "getPosition throw me"); return position; }
        const cVector& Velocity() const override { if( true == getVelocity_throwsException ) throw cException( "getVelocity throw me"); return velocity; }
        void Position(const cVector& pos) override { if( true == setPosition_throwsException ) throw cException( "setPosition throw me"); position = pos; }
        void Velocity(const cVector& vel) override { velocity = vel; }

    };

};

// gTest grouping class
class test_cRotate : public ::testing::Test
{
public:
    // additional class to access to member of tested class
    class Test_cRotate : public cRotate
    {
    public:
        // add here members for free access.
        using cRotate::cRotate; // delegate constructors
    };

    // additional class to access to member of tested class
    class Test_cRotatable : public cRotatable
    {
    public:
        // add here members for free access.
        using cRotatable::cRotatable; // delegate constructors
    };

    // additional class to access to member of tested class
    class Test_cRotatableThrowExceptions : public cRotatable
    {
    public:
        bool getDirection_throwsException = false;
        bool getAngularVelocity_throwsException = false;
        bool setDirection_throwsException = false;

    public:
        // add here members for free access.
        using cRotatable::cRotatable; // delegate constructors

        double Direction() const override { if (true == getDirection_throwsException) throw cException("getDirection throw me"); return direction; }
        double  AngularVelocity() const override { if (true == getAngularVelocity_throwsException) throw cException("getAngularVelocity throw me"); return angularVelocity; }
        void Direction(double dir) override { if (true == setDirection_throwsException) throw cException("setDirection throw me"); direction = dir; }
        void AngularVelocity(double vel) override { angularVelocity = vel; }
   };

};


TEST_F(test_cMove, test_RegularMoving )
{
    Test_cMovable t0(cVector(12, 5), cVector(-7, 3));
    Test_cMove t(t0);

    t.Execute();
    EXPECT_EQ( cVector(5,8), t0.Position());
}

TEST_F(test_cMove, test_getPosition_throwsException)
{
    Test_cMovableThrowExceptions t0(cVector(12, 5), cVector(-7, 3));
    t0.getPosition_throwsException = true;

    Test_cMove t(t0);

    try
    {
        t.Execute();
    }
    catch (const std::exception& expected)
    {
        ASSERT_STREQ("getPosition throw me", expected.what());
    }
}

TEST_F(test_cMove, test_getVelocity_throwsException)
{
    Test_cMovableThrowExceptions t0(cVector(12, 5), cVector(-7, 3));
    t0.getVelocity_throwsException = true;

    Test_cMove t(t0);

    try
    {
        t.Execute();
    }
    catch (const std::exception& expected)
    {
        ASSERT_STREQ("getVelocity throw me", expected.what());
    }
}

TEST_F(test_cMove, test_setPosition_throwsException)
{
    Test_cMovableThrowExceptions t0(cVector(12, 5), cVector(-7, 3));
    t0.setPosition_throwsException = true;

    Test_cMove t(t0);

    try
    {
        t.Execute();
    }
    catch (const std::exception& expected)
    {
        ASSERT_STREQ("setPosition throw me", expected.what());
    }
}

TEST_F(test_cRotate, test_RegularRotating)
{
    Test_cRotatable t0( 60, 30 );
    Test_cRotate t(t0);

    t.Execute();
    EXPECT_EQ( 90, t0.Direction());
}

TEST_F(test_cRotate, test_getDirection_throwsException)
{
    Test_cRotatableThrowExceptions t0(60, 30);
    t0.getDirection_throwsException = true;

    Test_cRotate t(t0);

    try
    {
        t.Execute();
    }
    catch (const std::exception& expected)
    {
        ASSERT_STREQ("getDirection throw me", expected.what());
    }
}

TEST_F(test_cRotate, test_getAngularVelocity_throwsException)
{
    Test_cRotatableThrowExceptions t0(60, 30);
    t0.getAngularVelocity_throwsException = true;

    Test_cRotate t(t0);

    try
    {
        t.Execute();
    }
    catch (const std::exception& expected)
    {
        ASSERT_STREQ("getAngularVelocity throw me", expected.what());
    }
}

TEST_F(test_cRotate, test_setDirection_throwsException)
{
    Test_cRotatableThrowExceptions t0(60, 30);
    t0.setDirection_throwsException = true;

    Test_cRotate t(t0);

    try
    {
        t.Execute();
    }
    catch (const std::exception& expected)
    {
        ASSERT_STREQ("setDirection throw me", expected.what());
    }
}


