//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gladiator ring");
    setFloorPlanType("gladiator ring");

    addDescriptionTemplate("a wooden arena for holding gladiatorial combat");
}
