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
    setShortDescription("The lookout hollow");
    addFeature("/lib/environment/features/landforms/hill.c", "northwest");

    addExit("south", "/areas/eledhel/west-rural-two/24x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"fisher","muskrat","ruffian","outlaw","badger","boar"}));
}
