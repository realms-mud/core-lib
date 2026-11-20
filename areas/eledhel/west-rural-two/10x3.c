//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south");
    setShortDescription("The stone shelf above the falls");
    addFeature("/lib/environment/features/landforms/hillock.c", "west");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");
    addFeature("/lib/environment/features/landforms/mound.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c", "west");

    addExit("south", "/areas/eledhel/west-rural-two/10x2.c");

    addRandomCreature(({"outlaw", "porcupine", "gray squirrel", "skeleton"}));
}
