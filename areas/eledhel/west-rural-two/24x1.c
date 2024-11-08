//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "northwest");

    addExit("south", "/areas/eledhel/west-rural-two/24x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"fisher","muskrat","ruffian","outlaw","badger","boar"}));
}
