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
      return (std::fabsl(lhs - rhs) <= EPSILON1) 
          || (std::fabsl(lhs - rhs) <= (EPSILON2 * std::max(std::fabsl(lhs), std::fabsl(rhs))));
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }
}    // unnamed, anonymous namespace







/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
GroceryItem::GroceryItem( std::string productName, std::string brandName, std::string upcCode, double price )
///////////////////////// TO-DO (2) //////////////////////////////
  : _productName(std::move(productName)),
    _brandName(std::move(brandName)),
    _upcCode(std::move(upcCode)),
    _price(price)
/////////////////////// END-TO-DO (2) ////////////////////////////
{}


// Copy constructor
GroceryItem::GroceryItem( GroceryItem const & other )
///////////////////////// TO-DO (3) //////////////////////////////
  : _upcCode(other._upcCode),
    _brandName(other._brandName),
    _productName(other._productName),
    _price(other._price)
/////////////////////// END-TO-DO (3) ////////////////////////////
{}


// Move constructor
GroceryItem::GroceryItem( GroceryItem && other ) noexcept
///////////////////////// TO-DO (4) //////////////////////////////
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
  if(this != &rhs)
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
GroceryItem & GroceryItem::operator=( GroceryItem && rhs ) & noexcept
///////////////////////// TO-DO (6) //////////////////////////////
{
  if(this != &rhs)
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
GroceryItem::~GroceryItem() noexcept
///////////////////////// TO-DO (7) //////////////////////////////
{
  // no-op
}
/////////////////////// END-TO-DO (7) ////////////////////////////







/*******************************************************************************
**  Accessors
*******************************************************************************/

// upcCode() const    (L-value objects)
std::string const & GroceryItem::upcCode() const &
{
  ///////////////////////// TO-DO (8) //////////////////////////////
  return _upcCode;
  /////////////////////// END-TO-DO (8) ////////////////////////////
}


// brandName() const    (L-value objects)
std::string const & GroceryItem::brandName() const &
{
  ///////////////////////// TO-DO (9) //////////////////////////////
  return _brandName;
  /////////////////////// END-TO-DO (9) ////////////////////////////
}


// productName() const    (L-value objects)
std::string const & GroceryItem::productName() const &
{
  ///////////////////////// TO-DO (10) //////////////////////////////
  return _productName;
  /////////////////////// END-TO-DO (10) ////////////////////////////
}


// price() const    (L-value and R-value objects)
double GroceryItem::price() const &
{
  ///////////////////////// TO-DO (11) //////////////////////////////
  return _price;
  /////////////////////// END-TO-DO (11) ////////////////////////////
}



// upcCode()    (R-value objects)
std::string GroceryItem::upcCode() &&
{
  ///////////////////////// TO-DO (12) //////////////////////////////
  return std::move(_upcCode);
  /////////////////////// END-TO-DO (12) ////////////////////////////
}


// brandName()    (R-value objects)
std::string GroceryItem::brandName() &&
{
  ///////////////////////// TO-DO (13) //////////////////////////////
  return std::move(_brandName);
  /////////////////////// END-TO-DO (13) ////////////////////////////
}


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
GroceryItem & GroceryItem::brandName( std::string newBrandName ) &
///////////////////////// TO-DO (16) //////////////////////////////
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
GroceryItem & GroceryItem::price( double newPrice ) &
///////////////////////// TO-DO (18) //////////////////////////////
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
  ///////////////////////// TO-DO (19) //////////////////////////////
  auto cmpUpc = _upcCode <=> rhs._upcCode;
  if(cmpUpc != 0) return cmpUpc;

  auto cmpProd = _productName <=> rhs._productName;
  if(cmpProd != 0) return cmpProd;

  auto cmpBrand = _brandName <=> rhs._brandName;
  if(cmpBrand != 0) return cmpBrand;

  if( floating_point_is_equal(_price, rhs._price) )
    return std::weak_ordering::equivalent;
  return (_price < rhs._price) ? std::weak_ordering::less : std::weak_ordering::greater;
  /////////////////////// END-TO-DO (19) ////////////////////////////
}


// operator==(...)
bool GroceryItem::operator==( const GroceryItem & rhs ) const noexcept
{
  ///////////////////////// TO-DO (20) //////////////////////////////
  return _upcCode     == rhs._upcCode
      && _productName == rhs._productName
      && _brandName   == rhs._brandName
      && floating_point_is_equal(_price, rhs._price);
  /////////////////////// END-TO-DO (20) ////////////////////////////
}





/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>(...)
std::istream & operator>>( std::istream & stream, GroceryItem & groceryItem )
{
  char delimiter = '\x{00}';  // Not actually used except to show there's a variable
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
    GroceryItem temp{ std::move(product), std::move(brand), std::move(upc), priceVal };
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
