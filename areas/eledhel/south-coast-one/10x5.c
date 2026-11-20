//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("A cold hearth marks the charcoal camp");
    addDecorator("village tree");
    addFeature("/lib/environment/features/trees/oak-stand.c");
    addExit("north", "/areas/eledhel/south-coast-one/10x4.c");
    addRandomCreature(({ "outlaw", "boar", "coyote" }));
}
