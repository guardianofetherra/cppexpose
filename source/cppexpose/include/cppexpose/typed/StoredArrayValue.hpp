
#pragma once


#include <cppexpose/typed/StoredArrayValue.h>


namespace cppexpose
{


// Read/write type
template <typename T>
StoredArrayValue<T>::StoredArrayValue(
    std::function<T ()> getter
  , std::function<void(const T &)> setter
  , std::function<ElementType (int)> elementGetter
  , std::function<void(int, const ElementType &)> elementSetter)
: m_getter(getter)
, m_setter(setter)
, m_elementGetter(elementGetter)
, m_elementSetter(elementSetter)
{
}

template <typename T>
StoredArrayValue<T>::~StoredArrayValue()
{
}

template <typename T>
AbstractTyped * StoredArrayValue<T>::clone() const
{
    return new StoredArrayValue<T>(m_getter, m_setter, m_elementGetter, m_elementSetter);
}

template <typename T>
T StoredArrayValue<T>::value() const
{
    return m_getter();
}

template <typename T>
void StoredArrayValue<T>::setValue(const T & value)
{
    m_setter(value);
}

template <typename T>
typename StoredArrayValue<T>::ElementType StoredArrayValue<T>::getElement(size_t i) const
{
    return m_elementGetter(i);
}

template <typename T>
void StoredArrayValue<T>::setElement(size_t i, const typename StoredArrayValue<T>::ElementType & value)
{
    m_elementSetter(i, value);
}

template <typename T>
StoredArrayValue<T>::StoredArrayValue(
    std::function<T ()> getter
  , std::function<ElementType (int)> elementGetter)
: m_getter(getter)
, m_elementGetter(elementGetter)
{
}


// Read-only type
template <typename T>
StoredArrayValue<const T>::StoredArrayValue(
    std::function<T ()> getter
  , std::function<typename StoredArrayValue<T>::ElementType (int)> elementGetter)
: StoredArrayValue<T>::StoredArrayValue(getter, elementGetter)
{
}

template <typename T>
StoredArrayValue<const T>::~StoredArrayValue()
{
}

template <typename T>
AbstractTyped * StoredArrayValue<const T>::clone() const
{
    return new StoredArrayValue<const T>(
      this->m_getter,
      this->m_setter,
      this->m_elementGetter,
      this->m_elementSetter
    );
}

template <typename T>
bool StoredArrayValue<const T>::isReadOnly() const
{
    // Read-only!
    return true;
}

template <typename T>
void StoredArrayValue<const T>::setValue(const T &)
{
    // Read-only!
}

template <typename T>
void StoredArrayValue<const T>::setElement(size_t, const typename StoredArrayValue<T>::ElementType &)
{
    // Read-only!
}


} // namespace cppexpose