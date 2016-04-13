
#pragma once


#include <string>

#include <cppexpose/cppexpose_api.h>


namespace cppexpose
{


class AbstractTyped;


/**
*  @brief
*    Base class for properties
*/
class CPPEXPOSE_API AbstractProperty
{
public:
    /**
    *  @brief
    *    Constructor
    */
    AbstractProperty();

    /**
    *  @brief
    *    Constructor
    *
    *  @param[in] name
    *    Name
    */
    AbstractProperty(const std::string & name);

    /**
    *  @brief
    *    Destructor
    */
    virtual ~AbstractProperty();

    /**
    *  @brief
    *    Get name
    *
    *  @return
    *    Name
    */
    std::string name() const;

    /**
    *  @brief
    *    Get this object as AbstractTyped-pointer
    *
    *  @return
    *    Pointer to AbstractTyped interface
    */
    virtual AbstractTyped * asTyped() = 0;

    /**
    *  @brief
    *    Get this object as AbstractTyped-pointer
    *
    *  @return
    *    Pointer to AbstractTyped interface
    */
    virtual const AbstractTyped * asTyped() const = 0;

    /**
    *  @brief
    *    Check if property is a group
    *
    *  @return
    *    'true' if property is a property group, else 'false'
    */
    virtual bool isGroup() const = 0;


protected:
    std::string m_name; ///< Name of the property
};


} // namespace cppexpose