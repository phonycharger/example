#include <algorithm>                                                  // max()
#include <cmath>                                                      // abs(), pow()
#include <compare>                                                    // weak_ordering
#include <iomanip>                                                    // quoted(), ios::failbit
#include <iostream>                                                   // istream, ostream, ws()
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "GroceryItem.hpp"

/*******************************************************************************
**  Implementation of non-member private types, objects, and functions
*******************************************************************************/
namespace    // unnamed, anonymous namespace
{
  template< typename T,  typename U >
    requires std::is_floating_point_v<std::common_type_t<U, T>>
  constexpr bool floating_point_is_equal(
      T const lhs,
      U const rhs,
      long double const EPSILON1 = 1e-4L,    // or 1e-12L
      long double const EPSILON2 = 1e-8L
  ) noexcept
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
      return (std::fabsl(lhs - rhs) <= EPSILON1)
          || (std::fabsl(lhs - rhs) <= (EPSILON2 * std::max(std::fabsl(lhs), std::fabsl(rhs))));
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }
}    // unnamed namespace

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
///////////////////////// TO-DO (2) //////////////////////////////
GroceryItem::GroceryItem(std::string productName,
                         std::string brandName,
                         std::string upcCode,
                         double      price )
  : _upcCode(std::move(upcCode)),        // Match the order of declared fields
    _brandName(std::move(brandName)),
    _productName(std::move(productName)),
    _price(price)
/////////////////////// END-TO-DO (2) ////////////////////////////
{} // Avoid setting values in body

// Copy constructor
///////////////////////// TO-DO (3) //////////////////////////////
GroceryItem::GroceryItem( GroceryItem const & other )
  : _upcCode(other._upcCode),
    _brandName(other._brandName),
    _productName(other._productName),
    _price(other._price)
/////////////////////// END-TO-DO (3) ////////////////////////////
{}

// Move constructor
///////////////////////// TO-DO (4) //////////////////////////////
GroceryItem::GroceryItem( GroceryItem && other ) noexcept
  : _upcCode(std::move(other._upcCode)),
    _brandName(std::move(other._brandName)),
    _productName(std::move(other._productName)),
    _price(other._price)
/////////////////////// END-TO-DO (4) ////////////////////////////
{}

// Copy Assignment Operator
GroceryItem & GroceryItem::operator=( GroceryItem const & rhs ) &
{
  ///////////////////////// TO-DO (5) //////////////////////////////
  if (this != &rhs)
  {
    _upcCode     = rhs._upcCode;
    _brandName   = rhs._brandName;
    _productName = rhs._productName;
    _price       = rhs._price;
  }
  return *this;
  /////////////////////// END-TO-DO (5) ////////////////////////////
}

// Move Assignment Operator
///////////////////////// TO-DO (6) //////////////////////////////
GroceryItem & GroceryItem::operator=( GroceryItem && rhs ) & noexcept
{
  if (this != &rhs)
  {
    _upcCode     = std::move(rhs._upcCode);
    _brandName   = std::move(rhs._brandName);
    _productName = std::move(rhs._productName);
    _price       = rhs._price;
  }
  return *this;
}
/////////////////////// END-TO-DO (6) ////////////////////////////

// Destructor
///////////////////////// TO-DO (7) //////////////////////////////
GroceryItem::~GroceryItem() noexcept
{
  // no-op
}
/////////////////////// END-TO-DO (7) ////////////////////////////

/*******************************************************************************
**  Accessors
*******************************************************************************/

// upcCode() const (L-value objects)
///////////////////////// TO-DO (8) //////////////////////////////
std::string const & GroceryItem::upcCode() const &
{
  return _upcCode;
}
/////////////////////// END-TO-DO (8) ////////////////////////////

// brandName() const (L-value objects)
std::string const & GroceryItem::brandName() const &
{
  ///////////////////////// TO-DO (9) //////////////////////////////
  return _brandName;
  /////////////////////// END-TO-DO (9) ////////////////////////////
}

// productName() const (L-value objects)
///////////////////////// TO-DO (10) //////////////////////////////
std::string const & GroceryItem::productName() const &
{
  return _productName;
}
/////////////////////// END-TO-DO (10) ////////////////////////////

// price() const (L-value objects)
///////////////////////// TO-DO (11) //////////////////////////////
double GroceryItem::price() const &
{
  return _price;
}
/////////////////////// END-TO-DO (11) ////////////////////////////

// upcCode() (R-value objects)
///////////////////////// TO-DO (12) //////////////////////////////
std::string GroceryItem::upcCode() &&
{
  return std::move(_upcCode);
}
/////////////////////// END-TO-DO (12) ////////////////////////////

// brandName() (R-value objects)
///////////////////////// TO-DO (13) //////////////////////////////
std::string GroceryItem::brandName() &&
{
  return std::move(_brandName);
}
/////////////////////// END-TO-DO (13) ////////////////////////////

// productName() (R-value objects)
std::string GroceryItem::productName() &&
{
  ///////////////////////// TO-DO (14) //////////////////////////////
  return std::move(_productName);
  /////////////////////// END-TO-DO (14) ////////////////////////////
}

/*******************************************************************************
**  Modifiers
*******************************************************************************/

// upcCode(...)
GroceryItem & GroceryItem::upcCode( std::string newUpcCode ) &
{
  ///////////////////////// TO-DO (15) //////////////////////////////
  _upcCode = std::move(newUpcCode);
  return *this;
  /////////////////////// END-TO-DO (15) ////////////////////////////
}

// brandName(...)
///////////////////////// TO-DO (16) //////////////////////////////
GroceryItem & GroceryItem::brandName( std::string newBrandName ) &
{
  _brandName = std::move(newBrandName);
  return *this;
}
/////////////////////// END-TO-DO (16) ////////////////////////////

// productName(...)
GroceryItem & GroceryItem::productName( std::string newProductName ) &
///////////////////////// TO-DO (17) //////////////////////////////
{
  _productName = std::move(newProductName);
  return *this;
}
/////////////////////// END-TO-DO (17) ////////////////////////////

// price(...)
///////////////////////// TO-DO (18) //////////////////////////////
GroceryItem & GroceryItem::price( double newPrice ) &
{
  _price = newPrice;
  return *this;
}
/////////////////////// END-TO-DO (18) ////////////////////////////

/*******************************************************************************
**  Relational Operators
*******************************************************************************/

// operator<=>(...)
std::weak_ordering GroceryItem::operator<=>( const GroceryItem & rhs ) const noexcept
{
  // Explanation of the design choice omitted for brevity

  ///////////////////////// TO-DO (19) //////////////////////////////
  auto cmpUpc = _upcCode <=> rhs._upcCode;
  if (cmpUpc != 0) return cmpUpc;

  auto cmpProd = _productName <=> rhs._productName;
  if (cmpProd != 0) return cmpProd;

  auto cmpBrand = _brandName <=> rhs._brandName;
  if (cmpBrand != 0) return cmpBrand;

  if (floating_point_is_equal(_price, rhs._price))
    return std::weak_ordering::equivalent;
  return (_price < rhs._price) ? std::weak_ordering::less : std::weak_ordering::greater;
  /////////////////////// END-TO-DO (19) ////////////////////////////
}

// operator==(...)
bool GroceryItem::operator==( const GroceryItem & rhs ) const noexcept
{
  ///////////////////////// TO-DO (20) //////////////////////////////
  return  (_upcCode     == rhs._upcCode)
       && (_productName == rhs._productName)
       && (_brandName   == rhs._brandName)
       && floating_point_is_equal(_price, rhs._price);
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>(...)
std::istream & operator>>( std::istream & stream, GroceryItem & groceryItem )
{
  char delimiter = '\x{00}';  // c++23 escape for char(0)
  ///////////////////////// TO-DO (21) //////////////////////////////
  std::string upc, brand, product;
  double priceVal{};
  if( stream
      >> std::ws
      >> std::quoted(upc)
      >> delimiter
      >> std::ws
      >> std::quoted(brand)
      >> delimiter
      >> std::ws
      >> std::quoted(product)
      >> delimiter
      >> std::ws
      >> priceVal )
  {
    GroceryItem temp(std::move(product),
                     std::move(brand),
                     std::move(upc),
                     priceVal);
    groceryItem = std::move(temp);
  }
  else
  {
    stream.setstate(std::ios::failbit);
  }
  return stream;
  /////////////////////// END-TO-DO (21) ////////////////////////////
}

// operator<<(...)
std::ostream & operator<<( std::ostream & stream, const GroceryItem & groceryItem )
{
  ///////////////////////// TO-DO (22) //////////////////////////////
  stream << std::quoted(groceryItem.upcCode())
         << ", "
         << std::quoted(groceryItem.brandName())
         << ", "
         << std::quoted(groceryItem.productName())
         << ", "
         << groceryItem.price();
  return stream;
  /////////////////////// END-TO-DO (22) ////////////////////////////
}
