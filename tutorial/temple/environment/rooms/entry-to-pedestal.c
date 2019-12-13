//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/purple-liquid.c");

    setStateMachine("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");

    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c");
    
    object region = clone_object("/lib/environment/region.c");
    region->setRegionName("temple of obedience");
    region->setRegionType("keeper's temple");
    region->setDimensions(7, 7);

    region->setEntryCoordinate(0, 6,
        "/lib/tutorial/temple/environment/rooms/pedestal-1x1.c", "north",
        "/lib/tutorial/temple/environment/rooms/entry-to-pedestal.c");

    region->setCoordinate(1, 6, 
        "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "path");
    region->setCoordinate(2, 6,
        "/lib/tutorial/temple/environment/rooms/pedestal-1x3.c", "path");
    region->setCoordinate(3, 6,
        "/lib/tutorial/temple/environment/rooms/pedestal-1x4.c", "path");
    region->setCoordinate(4, 6,
        "/lib/tutorial/temple/environment/rooms/pedestal-1x5.c", "path");
    region->setCoordinate(5, 6,
        "/lib/tutorial/temple/environment/rooms/pedestal-square.c");

    region->setCoordinate(0, 5,
        "/lib/tutorial/temple/environment/rooms/pedestal-2x1.c", "path");
    region->setCoordinate(1, 5,
        "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "path");
    region->setCoordinate(2, 5,
        "/lib/tutorial/temple/environment/rooms/pedestal-2x3.c", "path");
    region->setCoordinate(3, 5,
        "/lib/tutorial/temple/environment/rooms/pedestal-2x4.c", "path");
    region->setCoordinate(4, 5,
        "/lib/tutorial/temple/environment/rooms/pedestal-2x5.c", "path");
    region->setCoordinate(5, 5,
        "/lib/tutorial/temple/environment/rooms/pedestal-pilon.c");

    region->setCoordinate(0, 4,
        "/lib/tutorial/temple/environment/rooms/pedestal-3x1.c", "path");
    region->setCoordinate(1, 4,
        "/lib/tutorial/temple/environment/rooms/pedestal-3x2.c", "path");
    region->setCoordinate(2, 4,
        "/lib/tutorial/temple/environment/rooms/pedestal-3x3.c", "path");
    region->setCoordinate(3, 4,
        "/lib/tutorial/temple/environment/rooms/pedestal-3x4.c", "path");
    region->setCoordinate(4, 4,
        "/lib/tutorial/temple/environment/rooms/pedestal-3x5.c", "path");

    region->setCoordinate(0, 3,
        "/lib/tutorial/temple/environment/rooms/pedestal-4x1.c", "path");
    region->setCoordinate(1, 3,
        "/lib/tutorial/temple/environment/rooms/pedestal-4x2.c", "path");
    region->setCoordinate(2, 3,
        "/lib/tutorial/temple/environment/rooms/pedestal-4x3.c", "path");
    region->setCoordinate(3, 3,
        "/lib/tutorial/temple/environment/rooms/pedestal-4x4.c", "path");
    region->setCoordinate(4, 3,
        "/lib/tutorial/temple/environment/rooms/pedestal-4x5.c", "path");

    region->setCoordinate(0, 2,
        "/lib/tutorial/temple/environment/rooms/pedestal-5x1.c", "path");
    region->setCoordinate(1, 2,
        "/lib/tutorial/temple/environment/rooms/pedestal-5x2.c", "path");
    region->setCoordinate(2, 2,
        "/lib/tutorial/temple/environment/rooms/pedestal-5x3.c", "path");
    region->setCoordinate(3, 2,
        "/lib/tutorial/temple/environment/rooms/pedestal-5x4.c", "path");
    region->setCoordinate(4, 2,
        "/lib/tutorial/temple/environment/rooms/pedestal-5x5.c", "path");
}
