//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The southern fields begin beyond Anor's last lane");
    addDecorator("village garden");
    addFeature("/lib/environment/features/plants/common-grain-strips.c");
    addExit("north", "/areas/anor/12x8.c");
}
