//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef buildingComponents_h
#define buildingComponents_h

#include "stone-keep-components.h"
#include "tower-components.h"
#include "wall-components.h"
#include "wooden-keep-components.h"

private mapping BuildingComponents = StoneKeepComponents +
    WoodenKeepComponents + 
    WallComponents +
    TowerComponents + ([]);

#endif
