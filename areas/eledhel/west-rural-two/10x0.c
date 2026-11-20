//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    setShortDescription("The brook at the pine slot");
    addFeature("/lib/environment/features/trees/pine-stand.c", "west");
    addFeature("/lib/environment/features/water/canyon-brook.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addExit("north", "/areas/eledhel/west-rural-two/10x1.c");
    addExit("east", "/areas/eledhel/west-rural-two/11x0.c");

    addRandomCreature(({"ruffian", "coyote", "groundhog", "wolverine"}));
}
