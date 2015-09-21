#ifndef au_raster_h
#define au_raster_h

#include <spellbook/grid/Grid.h>

namespace au {

template <typename T>
void RasterizeLine(
    Grid<2, T>& grid,
    const typename Grid<2, T>::GridIndex& a,
    const typename Grid<2, T>::GridIndex& b,
    const T& fill);

/// \tparam Function 
template <typename T, typename Function>
void RasterizeLine(
    Grid<2, T>& grid,
    typename Grid<2, T>::GridIndex a,
    typename Grid<2, T>::GridIndex b,
    const Function& fn);

} // namespace au

#include "detail/raster.h"

#endif
