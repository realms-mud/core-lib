//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The western end of the Arena Park approach");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addDecorator("east-west road");
    addExit("east", "/areas/eledhel/northern-city/4x6.c");
}
