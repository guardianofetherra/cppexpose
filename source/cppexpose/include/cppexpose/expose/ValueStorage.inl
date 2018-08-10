
#pragma once


namespace cppexpose
{


// Non-const type
template <typename Type>
ValueStorage<Type>::ValueStorage()
{
}

template <typename Type>
ValueStorage<Type>::ValueStorage(const AbstractVar & var)
: AbstractTyped<Type>()
, m_value(var.value<Type>())
{
}

template <typename Type>
ValueStorage<Type>::ValueStorage(const Type &, const AbstractVar & var)
: AbstractTyped<Type>()
, m_value(var.value<Type>())
{
}

template <typename Type>
ValueStorage<Type>::ValueStorage(const Type &, const Type & value)
: AbstractTyped<Type>()
, m_value(value)
{
}

template <typename Type>
ValueStorage<Type>::ValueStorage(const Type & defaultValue)
: AbstractTyped<Type>()
, m_value(defaultValue)
{
}

template <typename Type>
ValueStorage<Type>::~ValueStorage()
{
}

template <typename Type>
AbstractVar * ValueStorage<Type>::clone() const
{
    return new Var<Type>(this->value());
}

template <typename Type>
bool ValueStorage<Type>::isConst() const
{
    return false;
}

template <typename Type>
const Type & ValueStorage<Type>::value() const
{
    return m_value;
}

template <typename Type>
void ValueStorage<Type>::setValue(const Type & value)
{
    m_value = value;
}


// Const type
template <typename Type>
ValueStorage<const Type>::ValueStorage()
{
}

template <typename Type>
ValueStorage<const Type>::ValueStorage(const AbstractVar & var)
: AbstractTyped<Type>()
, m_value(var.value<Type>())
{
}

template <typename Type>
ValueStorage<const Type>::ValueStorage(const Type &, const AbstractVar & var)
: AbstractTyped<Type>()
, m_value(var.value<Type>())
{
}

template <typename Type>
ValueStorage<const Type>::ValueStorage(const Type &, const Type & value)
: AbstractTyped<Type>()
, m_value(value)
{
}

template <typename Type>
ValueStorage<const Type>::ValueStorage(const Type & defaultValue)
: AbstractTyped<Type>()
, m_value(defaultValue)
{
}

template <typename Type>
ValueStorage<const Type>::~ValueStorage()
{
}

template <typename Type>
AbstractVar * ValueStorage<const Type>::clone() const
{
    return new Var<const Type>(this->value());
}

template <typename Type>
bool ValueStorage<const Type>::isConst() const
{
    return true;
}

template <typename Type>
const Type & ValueStorage<const Type>::value() const
{
    return m_value;
}

template <typename Type>
void ValueStorage<const Type>::setValue(const Type &)
{
}


} // namespace cppexpose
