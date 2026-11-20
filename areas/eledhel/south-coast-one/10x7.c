//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("A fold in the meadow shelters sheep from the wind");
    addDecorator("village garden");
    addFeature("/lib/environment/features/trees/oak-stand.c");
    addExit("north", "/areas/eledhel/south-coast-one/10x6.c");
}
