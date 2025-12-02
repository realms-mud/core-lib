//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef castleComponents_h
#define castleComponents_h

#include "castle-buildings.h"
#include "castle-keeps.h"
#include "castle-towers.h"
#include "castle-walls.h"
#include "motte-buildings.h"
#include "motte-towers.h"

protected string *ComponentTypes = ({
    "building",
    "keep",
    "moat",
    "tower",
    "wall"
});

protected mapping CastleComponents = CastleBuildings + CastleKeeps +
    CastleTowers + CastleWalls + MotteBuildings + MotteTowers + ([]);

#endif
