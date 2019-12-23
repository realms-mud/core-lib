//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");

    setAdditionalLongDescription("\nThis is the default start location.\n"
        "If you go north, you can test out an (incomplete) background story.\n"
        "If you go south, you will be placed in the (incomplete) city of Eledhel.\n");

    addExit("north", "/tutorial/rooms/battleScene.c");
    addExit("south", "/areas/eledhel/southern-city/12x2.c");
}
