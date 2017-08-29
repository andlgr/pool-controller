/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 22, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/common/factory/fxt_ut_factory.h"

namespace test_ut {

TEST_F(TestUtFactory, Create_Product_0_Arguments) {
  // Product
  std::shared_ptr<ProductInterface0Arg> product;
  ASSERT_EQ(nullptr, product.get());
  // Factory
  std::unique_ptr<
      FactoryInterface0Arg<ProductInterface0Arg> > factory;
  factory.reset(new Factory0Arg<ProductInterface0Arg, Product0Arg>());
  // Create Product using Factory
  ASSERT_EQ(ERROR_NO, factory->Create(product));
  ASSERT_NE(nullptr, product.get());
}

TEST_F(TestUtFactory, Create_Product_1_Arguments) {
  int expected_arg1 = 50;
  // Product
  std::shared_ptr<ProductInterface1Arg> product;
  ASSERT_EQ(nullptr, product.get());
  // Factory
  std::unique_ptr<
      FactoryInterface1Arg<ProductInterface1Arg, int> > factory;
  factory.reset(new Factory1Arg<ProductInterface1Arg, Product1Arg, int>());
  // Create Product using Factory
  ASSERT_EQ(ERROR_NO, factory->Create(product, expected_arg1));
  ASSERT_NE(nullptr, product.get());
  // Check arguments
  ASSERT_EQ(expected_arg1, static_cast<Product1Arg*>(product.get())->arg1_);
}

TEST_F(TestUtFactory, Create_Product_2_Arguments) {
  int expected_arg1 = 80;
  int expected_arg2 = 100;
  // Product
  std::shared_ptr<ProductInterface2Arg> product;
  ASSERT_EQ(nullptr, product.get());
  // Factory
  std::unique_ptr<
      FactoryInterface2Arg<ProductInterface2Arg, int, int> > factory;
  factory.reset(new Factory2Arg<ProductInterface2Arg, Product2Arg, int, int>());
  // Create Product using Factory
  ASSERT_EQ(ERROR_NO, factory->Create(product, expected_arg1, expected_arg2));
  ASSERT_NE(nullptr, product.get());
  // Check arguments
  ASSERT_EQ(expected_arg1, static_cast<Product2Arg*>(product.get())->arg1_);
  ASSERT_EQ(expected_arg2, static_cast<Product2Arg*>(product.get())->arg2_);
}

}  // namespace test_ut
