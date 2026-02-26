//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef mapIcons_h
#define mapIcons_h

#include "icons/city-icons.h"
#include "icons/forest-icons.h"
#include "icons/temple-icons.h"
#include "icons/ruined-interior-icons.h"
#include "icons/keep-interior-icons.h"
#include "icons/temple-interior-icons.h"
#include "icons/crypt-interior-icons.h"
#include "icons/village-icons.h"

private mapping MapIcons = CityIcons + TempleIcons + 
    ForestIcons + RuinedInteriorIcons + KeepInteriorIcons + TempleInteriorIcons +
    CryptInteriorIcons + VillageIcons;

#endif
