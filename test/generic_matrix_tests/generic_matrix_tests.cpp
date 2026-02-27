#include <memory>
#include <gtest/gtest.h>
#include <GenericMatrix.hpp>

TEST(GenericMatrixTest, DefaultConstructorIntTest)
{
    auto matrix = std::make_unique<GenericMatrix<int>>();

    ASSERT_NE(matrix, nullptr);
}
