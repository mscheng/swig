//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   algorithms/algorithm.hh
 * \author Seth R Johnson
 * \date   Tue Dec 06 11:21:58 2016
 * \brief  algorithm class declaration.
 * \note   Copyright (c) 2016 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//

#ifndef algorithms_algorithm_hh
#define algorithms_algorithm_hh

#include <algorithm>

//---------------------------------------------------------------------------//
/*!
 * \brief Reverse the contents of an arr in-place
 */
template<class T>
void reverse(T* arr, int count)
{
    std::reverse(arr, arr + count);
}

//---------------------------------------------------------------------------//
/*!
 * \brief Sort the contents of an arr in-place
 */
template<class T>
void sort(T* arr, int count)
{
    std::sort(arr, arr + count);
}

//---------------------------------------------------------------------------//
/*!
 * \brief Do a binary search on the arr
 *
 * \return The fortran index (starts with 1) or zero if not found
 */
template<class T>
int find_sorted(const T* arr, int count, T val)
{
    const T* start = arr;
    const T* stop  = arr + count;
    const T* iter  = std::lower_bound(start, stop, val);
    if (iter == stop || *iter != val)
        return 0;

    // Add 1 to convert to Fortran index
    return (iter - start) + 1;
}

//---------------------------------------------------------------------------//
#endif // algorithms_algorithm_hh

//---------------------------------------------------------------------------//
// end of algorithms/algorithm.hh
//---------------------------------------------------------------------------//
