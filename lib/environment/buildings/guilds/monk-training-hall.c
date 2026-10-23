//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("training hall");
    setFloorPlanType("trade");
    addDescriptionTemplate("a modest stone training hall with open doors "
        "and the emblem of a balanced hand");
    addNearDarkDescriptionTemplate("the outline of a low building");
    addSourceOfLight(6);
}
