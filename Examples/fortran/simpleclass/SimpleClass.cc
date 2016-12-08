//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   simple_class/SimpleClass.cc
 * \author Seth R Johnson
 * \date   Thu Dec 01 15:07:23 2016
 * \brief  SimpleClass class definitions.
 * \note   Copyright (c) 2016 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//

#include "SimpleClass.hh"

#include <iostream>
using std::cout;
using std::endl;

//---------------------------------------------------------------------------//
namespace
{
int g_counter = 0;
int g_next_id = 0;
SimpleClass g_globalclass(0);
}

//---------------------------------------------------------------------------//
SimpleClass::SimpleClass()
    : d_id(g_next_id++)
    , d_storage(0)
{
    cout << "Constructing " << d_id << " at " << this << endl;
    ++g_counter;
}

SimpleClass::SimpleClass(const SimpleClass& rhs)
    : d_id(rhs.d_id * 10 + (g_next_id++))
    , d_storage(rhs.d_storage + 10)
{
    cout << "Copy-constructing " << rhs.d_id << "=>" << d_id
         << " at " << this << endl;
    ++g_counter;
}

SimpleClass::SimpleClass(double d)
    : d_id(g_next_id++)
    , d_storage(d)
{
    cout << "Constructing " << d_id << " at " << this << endl;
    ++g_counter;
}

SimpleClass& SimpleClass::operator=(const SimpleClass& rhs)
{
    int orig_id = d_id;
    d_id = 10 * rhs.d_id + (g_next_id++);
    cout << "Assigning " << rhs.d_id << "=>" << d_id
         << " at " << this <<  " (replaces " << orig_id << ")" << endl;
}

SimpleClass::~SimpleClass()
{
    --g_counter;
    cout << "Destroying   " << d_id << " at " << this
        << ": " << g_counter << " remaining " << endl;
}

void SimpleClass::set(storage_type val)
{
    d_storage = val;
    // throw std::logic_error("why did you set me");
}

void SimpleClass::double_it()
{
    d_storage *= 2;
}

SimpleClass::storage_type SimpleClass::get() const
{
    return d_storage;
}

SimpleClass::storage_type SimpleClass::get_multiplied(int multiple) const
{
    return d_storage * multiple;
}

//---------------------------------------------------------------------------//
void print_value(const SimpleClass& c)
{
    cout << "Simpleclass at " << &c << " has value " << c.get() << endl;
}

//---------------------------------------------------------------------------//
void dumb_copy(SimpleClass c)
{
    cout << "Copied: ";
    print_value(c);
}

//---------------------------------------------------------------------------//
SimpleClass make_class(SimpleClass::storage_type val)
{
    return SimpleClass(val);
}

void set_class_by_copy(SimpleClass c)
{
    g_globalclass = c;
}

const SimpleClass& get_class()
{
    return g_globalclass;
}


//---------------------------------------------------------------------------//
// end of simple_class/SimpleClass.cc
//---------------------------------------------------------------------------//
