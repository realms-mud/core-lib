//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef mapIcons_h
#define mapIcons_h

#include "icons/city-icons.h"
#include "icons/coast-icons.h"
#include "icons/cave-icons.h"
#include "icons/forest-icons.h"
#include "icons/farm-icons.h"
#include "icons/hill-icons.h"
#include "icons/temple-icons.h"
#include "icons/ruined-interior-icons.h"
#include "icons/keep-interior-icons.h"
#include "icons/temple-interior-icons.h"
#include "icons/crypt-interior-icons.h"
#include "icons/village-icons.h"

private mapping MapIcons = CityIcons + TempleIcons + ForestIcons +
    FarmIcons + HillIcons + CoastIcons + CaveIcons +
    RuinedInteriorIcons + KeepInteriorIcons + TempleInteriorIcons +
    CryptInteriorIcons + VillageIcons;

#endif
