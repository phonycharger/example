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
  // Avoid direct equality comparisons on floating point numbers. Two values are equal if they are "close enough", which is
  // represented by Epsilon.  Usually, this is a pretty small number, but since we are dealing with money (only two, maybe three
  // decimal places) we need to be a bit more tolerant.
  //
  // The two values are "close enough" to be considered equal if the distance between lhs and rhs is less than:
  // o)  EPSILON1, otherwise
  // o)  EPSILON2 percentage of the larger value's magnitude

  template< typename T,  typename U >   requires std::is_floating_point_v<std::common_type_t<U, T> >
  constexpr bool floating_point_is_equal( T const lhs,  U const rhs,  long double const EPSILON1 = /*1e-12L*/ 1e-4L,  long double const EPSILON2 = 1e-8L ) noexcept
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
    return std::abs(lhs - rhs) < EPSILON1 || std::abs(lhs - rhs) < (std::max(std::abs(lhs), std::abs(rhs)) * EPSILON2);
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }
}    // unnamed, anonymous namespace

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
///////////////////////// TO-DO (2) //////////////////////////////
GroceryItem::GroceryItem(std::string productName, std::string brandName, std::string upcCode, double price)
  : _upcCode(std::move(upcCode)),
    _brandName(std::move(brandName)),
    _productName(std::move(productName)),
    _price(price)
{}
/////////////////////// END-TO-DO (2) ////////////////////////////

// Copy constructor
///////////////////////// TO-DO (3) //////////////////////////////
GroceryItem::GroceryItem(const GroceryItem& other)
  : _upcCode(other._upcCode),
    _brandName(other._brandName),
    _productName(other._productName),
    _price(other._price)
{}
/////////////////////// END-TO-DO (3) ////////////////////////////

// Move constructor
///////////////////////// TO-DO (4) //////////////////////////////
GroceryItem::GroceryItem(GroceryItem&& other) noexcept
  : _upcCode(std::move(other._upcCode)),
    _brandName(std::move(other._brandName)),
    _productName(std::move(other._productName)),
    _price(std::move(other._price))
{}
/////////////////////// END-TO-DO (4) ////////////////////////////

// Copy Assignment Operator
GroceryItem & GroceryItem::operator=( GroceryItem const & rhs ) &
{
  ///////////////////////// TO-DO (5) //////////////////////////////
  if (this != &rhs) {
    _upcCode = rhs._upcCode;
    _brandName = rhs._brandName;
    _productName = rhs._productName;
    _price = rhs._price;
  }
  return *this;
  /////////////////////// END-TO-DO (5) ////////////////////////////
}

// Move Assignment Operator
///////////////////////// TO-DO (6) //////////////////////////////
GroceryItem& GroceryItem::operator=(GroceryItem&& rhs) & noexcept {
  if (this != &rhs) {
    _upcCode = std::move(rhs._upcCode);
    _brandName = std::move(rhs._brandName);
    _productName = std::move(rhs._productName);
    _price = rhs._price;
  }
  return *this;
}
/////////////////////// END-TO-DO (6) ////////////////////////////

// Destructor
///////////////////////// TO-DO (7) //////////////////////////////
GroceryItem::~GroceryItem() noexcept = default;
/////////////////////// END-TO-DO (7) ////////////////////////////

/*******************************************************************************
**  Accessors
*******************************************************************************/

// upcCode() const    (L-value objects)
///////////////////////// TO-DO (8) //////////////////////////////
const std::string& GroceryItem::upcCode() const & { return _upcCode; }
/////////////////////// END-TO-DO (8) ////////////////////////////

// brandName() const    (L-value objects)
std::string const & GroceryItem::brandName() const &
{
  ///////////////////////// TO-DO (9) //////////////////////////////
  return _brandName;
  /////////////////////// END-TO-DO (9) ////////////////////////////
}

// productName() const    (L-value objects)
///////////////////////// TO-DO (10) //////////////////////////////
const std::string& GroceryItem::productName() const & { return _productName; }
/////////////////////// END-TO-DO (10) ////////////////////////////

// price() const    (L-value and, because there is no R-value overload, R-value objects)
///////////////////////// TO-DO (11) //////////////////////////////
double GroceryItem::price() const & { return _price; }
/////////////////////// END-TO-DO (11) ////////////////////////////

// upcCode()    (R-value objects)
///////////////////////// TO-DO (12) //////////////////////////////
std::string GroceryItem::upcCode() && { return std::move(_upcCode); }
/////////////////////// END-TO-DO (12) ////////////////////////////

// brandName()    (R-value objects)
///////////////////////// TO-DO (13) //////////////////////////////
std::string GroceryItem::brandName() && { return std::move(_brandName); }
/////////////////////// END-TO-DO (13) ////////////////////////////

// productName()    (R-value objects)
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
GroceryItem& GroceryItem::brandName(std::string newBrandName) & {
  _brandName = std::move(newBrandName);
  return *this;
}
/////////////////////// END-TO-DO (16) ////////////////////////////

// productName(...)
GroceryItem & GroceryItem::productName( std::string newProductName ) &
{
  ///////////////////////// TO-DO (17) //////////////////////////////
  _productName = std::move(newProductName);
  return *this;
  /////////////////////// END-TO-DO (17) ////////////////////////////
}

// price(...)
///////////////////////// TO-DO (18) //////////////////////////////
GroceryItem& GroceryItem::price(double newPrice) & {
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
  ///////////////////////// TO-DO (19) //////////////////////////////
  if (auto cmp = _upcCode <=> rhs._upcCode; cmp != 0) return cmp;
  if (auto cmp = _productName <=> rhs._productName; cmp != 0) return cmp;
  if (auto cmp = _brandName <=> rhs._brandName; cmp != 0) return cmp;
  if (floating_point_is_equal(_price, rhs._price)) return std::weak_ordering::equivalent;
  return _price < rhs._price ? std::weak_ordering::less : std::weak_ordering::greater;
  /////////////////////// END-TO-DO (19) ////////////////////////////
}

// operator==(...)
bool GroceryItem::operator==( const GroceryItem & rhs ) const noexcept
{
  ///////////////////////// TO-DO (20) //////////////////////////////
  return _upcCode == rhs._upcCode && _productName == rhs._productName && _brandName == rhs._brandName && floating_point_is_equal(_price, rhs._price);
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>(...)
std::istream & operator>>( std::istream & stream, GroceryItem & groceryItem )
{
  ///////////////////////// TO-DO (21) //////////////////////////////
  std::string upc, brand, product;
  double price;
  char comma;

  if (stream >> std::ws >> std::quoted(upc) >> std::ws >> comma >> std::ws >> std::quoted(brand) >> std::ws >> comma >> std::ws >> std::quoted(product) >> std::ws >> comma >> price) {
    groceryItem = GroceryItem(product, brand, upc, price);
  } else {
    stream.setstate(std::ios::failbit);
  }
  return stream;
  /////////////////////// END-TO-DO (21) ////////////////////////////
}

// operator<<(...)
std::ostream & operator<<( std::ostream & stream, const GroceryItem & groceryItem )
{
  ///////////////////////// TO-DO (22) //////////////////////////////
  stream << std::quoted(groceryItem.upcCode()) << ",  " << std::quoted(groceryItem.brandName()) << ",  " << std::quoted(groceryItem.productName()) << ",  " << groceryItem.price();
  return stream;
  /////////////////////// END-TO-DO (22) ////////////////////////////
}
