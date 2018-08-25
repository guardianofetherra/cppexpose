
#pragma once


#include <cppassist/string/conversion.h>


namespace cppexpose
{


template <typename Type>
template <typename... Args>
TypedUnsignedIntegral<Type>::TypedUnsignedIntegral(Args&&... args)
: AbstractNumber<Type>(Type(0u), std::forward<Args>(args)...)
{
}

template <typename Type>
TypedUnsignedIntegral<Type>::~TypedUnsignedIntegral()
{
}

template <typename Type>
bool TypedUnsignedIntegral<Type>::isIntegral() const
{
    return true;
}

template <typename Type>
bool TypedUnsignedIntegral<Type>::isSignedIntegral() const
{
    return false;
}

template <typename Type>
bool TypedUnsignedIntegral<Type>::isFloatingPoint() const
{
    return false;
}

template <typename Type>
bool TypedUnsignedIntegral<Type>::canConvertFromVar(const AbstractVar & value)
{
    return (value.canConvertToLongLong()  ||
            value.canConvertToULongLong() ||
            value.canConvertToDouble()    ||
            value.canConvertToBool()      ||
            value.canConvertToString());
}

template <typename Type>
void TypedUnsignedIntegral<Type>::fromVar(const AbstractVar & value)
{
    if (value.canConvertToULongLong()) {
        this->setValue(static_cast<Type>(value.toULongLong()));
    } else if (value.canConvertToLongLong()) {
        this->setValue(static_cast<Type>(value.toLongLong()));
    } else if (value.canConvertToDouble()) {
        this->setValue(static_cast<Type>(value.toDouble()));
    } else if (value.canConvertToBool()) {
        this->setValue(static_cast<Type>(value.toBool()));
    } else if (value.canConvertToString()) {
        this->setValue(cppassist::string::fromString<Type>(value.toString()));
    } else if (value.canConvertToObject()) {
        // Cannot convert from object to number
    } else if (value.canConvertToArray()) {
        // Cannot convert from array to number
    }
}


} // namespace cppexpose
