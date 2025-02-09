#include <algorithm>                                                  // max()
#include <cmath>                                                      // abs(), pow()
#include <compare>                                                    // weak_ordering
#include <iomanip>                                                    // quoted(), ios::failbit
#include <iostream>                                                   // istream, ostream, ws()
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "GroceryItem.hpp"

namespace {
    template< typename T,  typename U >   requires std::is_floating_point_v<std::common_type_t<U, T> >
    constexpr bool floating_point_is_equal( T const lhs,  U const rhs,  long double const EPSILON1 = 1e-4L,  long double const EPSILON2 = 1e-8L ) noexcept {
        return std::abs(lhs - rhs) < EPSILON1 || std::abs(lhs - rhs) < (std::max(std::abs(lhs), std::abs(rhs)) * EPSILON2);
    }
}

GroceryItem::GroceryItem(std::string productName, std::string brandName, std::string upcCode, double price)
    : _upcCode(std::move(upcCode)),
      _brandName(std::move(brandName)),
      _productName(std::move(productName)),
      _price(price)
{}

GroceryItem::GroceryItem(const GroceryItem& other)
    : _upcCode(other._upcCode),
      _brandName(other._brandName),
      _productName(other._productName),
      _price(other._price)
{}

GroceryItem::GroceryItem(GroceryItem&& other) noexcept
    : _upcCode(std::move(other._upcCode)),
      _brandName(std::move(other._brandName)),
      _productName(std::move(other._productName)),
      _price(std::move(other._price))
{}

GroceryItem& GroceryItem::operator=(const GroceryItem& rhs) & {
    if (this != &rhs) {
        _upcCode = rhs._upcCode;
        _brandName = rhs._brandName;
        _productName = rhs._productName;
        _price = rhs._price;
    }
    return *this;
}

GroceryItem& GroceryItem::operator=(GroceryItem&& rhs) & noexcept {
    if (this != &rhs) {
        _upcCode = std::move(rhs._upcCode);
        _brandName = std::move(rhs._brandName);
        _productName = std::move(rhs._productName);
        _price = rhs._price;
    }
    return *this;
}

GroceryItem::~GroceryItem() noexcept = default;

const std::string& GroceryItem::upcCode() const & { return _upcCode; }
const std::string& GroceryItem::brandName() const & { return _brandName; }
const std::string& GroceryItem::productName() const & { return _productName; }
double GroceryItem::price() const & { return _price; }

std::string GroceryItem::upcCode() && { return std::move(_upcCode); }
std::string GroceryItem::brandName() && { return std::move(_brandName); }
std::string GroceryItem::productName() && { return std::move(_productName); }

GroceryItem& GroceryItem::upcCode(std::string newUpcCode) & { _upcCode = std::move(newUpcCode); return *this; }
GroceryItem& GroceryItem::brandName(std::string newBrandName) & { _brandName = std::move(newBrandName); return *this; }
GroceryItem& GroceryItem::productName(std::string newProductName) & { _productName = std::move(newProductName); return *this; }
GroceryItem& GroceryItem::price(double newPrice) & { _price = newPrice; return *this; }

std::weak_ordering GroceryItem::operator<=>(const GroceryItem& rhs) const noexcept {
    if (auto cmp = _upcCode <=> rhs._upcCode; cmp != 0) return cmp;
    if (auto cmp = _productName <=> rhs._productName; cmp != 0) return cmp;
    if (auto cmp = _brandName <=> rhs._brandName; cmp != 0) return cmp;
    if (floating_point_is_equal(_price, rhs._price)) return std::weak_ordering::equivalent;
    return _price < rhs._price ? std::weak_ordering::less : std::weak_ordering::greater;
}

bool GroceryItem::operator==(const GroceryItem& rhs) const noexcept {
    return _upcCode == rhs._upcCode && _productName == rhs._productName && _brandName == rhs._brandName && floating_point_is_equal(_price, rhs._price);
}

std::istream& operator>>(std::istream& stream, GroceryItem& groceryItem) {
    std::string upc, brand, product;
    double price;
    char comma;

    if (stream >> std::ws >> std::quoted(upc) >> std::ws >> comma >> std::ws >> std::quoted(brand) >> std::ws >> comma >> std::ws >> std::quoted(product) >> std::ws >> comma >> price) {
        groceryItem = GroceryItem(product, brand, upc, price);
    } else {
        stream.setstate(std::ios::failbit);
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const GroceryItem& groceryItem) {
    stream << std::quoted(groceryItem.upcCode()) << ",  " << std::quoted(groceryItem.brandName()) << ",  " << std::quoted(groceryItem.productName()) << ",  " << groceryItem.price();
    return stream;
}
