
#pragma once


#include <cppexpose/reflection/PropertyGroup.h>

#include <cppexpose/function/StaticFunction.h>
#include <cppexpose/function/MemberFunction.h>


namespace cppexpose
{


template <typename T>
DynamicProperty<T> * PropertyGroup::createDynamicProperty(const std::string & name, const T & value)
{
    // Reject properties that have no name or whose name already exists
    if (name == "" || this->propertyExists(name))
    {
        return nullptr;
    }

    // Create property and add it to the group
    auto * property = new DynamicProperty<T>(name, nullptr, value);
    this->addProperty(property, PropertyOwnership::Parent);

    // Return property
    return property;
}

template <typename RET, typename... Arguments>
void PropertyGroup::addFunction(const std::string & name, RET (*fn)(Arguments...))
{
    AbstractFunction * func = new StaticFunction<RET, Arguments...>(fn);
    m_functions.push_back(Method(name, func));
}

template <class T, typename RET, typename... Arguments>
void PropertyGroup::addFunction(const std::string & name, T * obj, RET (T::*fn)(Arguments...))
{
    AbstractFunction * func = new MemberFunction<T, RET, Arguments...>(obj, fn);
    m_functions.push_back(Method(name, func));
}


} // namespace cppexpose
