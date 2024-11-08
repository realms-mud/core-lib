//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

object region;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");

    addExit("south", "/tutorial/temple/environment/rooms/pedestal-1x1.c");
    
    addDecorator("ruined interior south entry alcove");
    addDecorator("ruined interior south wall", "resistance rune placed");
    addDecorator("ruined interior south wall", "first test");
    addDecorator("ruined interior south wall", "second test");
    addDecorator("ruined interior south wall", "third test");
    addDecorator("ruined interior south wall", "fourth test");
    addDecorator("ruined interior south wall", "fifth test");
    addDecorator("ruined interior south wall", "sixth test");
    addDecorator("ruined interior south wall", "seventh test");

    region = clone_object("/lib/environment/region.c");
    region->setRegionName("temple of obedience");
    region->setRegionType("tol-dhurath");
    region->setDimensions(7, 8);

    region->setCoordinate(0, 7,
        "/tutorial/temple/environment/rooms/entry-to-pedestal.c", "none");
    region->setCoordinate(1, 7,
        "/tutorial/temple/environment/rooms/pedestal-0x2.c", "none");
    region->setCoordinate(2, 7,
        "/tutorial/temple/environment/rooms/pedestal-0x3.c", "none");
    region->setCoordinate(3, 7,
        "/tutorial/temple/environment/rooms/pedestal-0x4.c", "none");
    region->setCoordinate(4, 7,
        "/tutorial/temple/environment/rooms/pedestal-0x5.c", "none");
    region->setCoordinate(5, 7,
        "/tutorial/temple/environment/rooms/pedestal-0x6.c", "none");

    region->setCoordinate(0, 6,
        "/tutorial/temple/environment/rooms/pedestal-1x1.c", "none");
    region->setCoordinate(1, 6, 
        "/tutorial/temple/environment/rooms/pedestal-1x2.c", "none");
    region->setCoordinate(2, 6,
        "/tutorial/temple/environment/rooms/pedestal-1x3.c", "none");
    region->setCoordinate(3, 6,
        "/tutorial/temple/environment/rooms/pedestal-1x4.c", "none");
    region->setCoordinate(4, 6,
        "/tutorial/temple/environment/rooms/pedestal-1x5.c", "none");
    region->setCoordinate(5, 6,
        "/tutorial/temple/environment/rooms/pedestal-square.c", "none");

    region->setCoordinate(0, 5,
        "/tutorial/temple/environment/rooms/pedestal-2x1.c", "none");
    region->setCoordinate(1, 5,
        "/tutorial/temple/environment/rooms/pedestal-2x2.c", "none");
    region->setCoordinate(2, 5,
        "/tutorial/temple/environment/rooms/pedestal-2x3.c", "none");
    region->setCoordinate(3, 5,
        "/tutorial/temple/environment/rooms/pedestal-2x4.c", "none");
    region->setCoordinate(4, 5,
        "/tutorial/temple/environment/rooms/pedestal-2x5.c", "none");
    region->setCoordinate(5, 5,
        "/tutorial/temple/environment/rooms/pedestal-pilon.c", "none");

    region->setCoordinate(0, 4,
        "/tutorial/temple/environment/rooms/pedestal-3x1.c", "none");
    region->setCoordinate(1, 4,
        "/tutorial/temple/environment/rooms/pedestal-3x2.c", "none");
    region->setCoordinate(2, 4,
        "/tutorial/temple/environment/rooms/pedestal-3x3.c", "none");
    region->setCoordinate(3, 4,
        "/tutorial/temple/environment/rooms/pedestal-3x4.c", "none");
    region->setCoordinate(4, 4,
        "/tutorial/temple/environment/rooms/pedestal-3x5.c", "none");
    region->setCoordinate(5, 4,
        "/tutorial/temple/environment/rooms/chamber-of-sacrifice.c", "none");

    region->setCoordinate(0, 3,
        "/tutorial/temple/environment/rooms/pedestal-4x1.c", "none");
    region->setCoordinate(1, 3,
        "/tutorial/temple/environment/rooms/pedestal-4x2.c", "none");
    region->setCoordinate(2, 3,
        "/tutorial/temple/environment/rooms/pedestal-4x3.c", "none");
    region->setCoordinate(3, 3,
        "/tutorial/temple/environment/rooms/pedestal-4x4.c", "none");
    region->setCoordinate(4, 3,
        "/tutorial/temple/environment/rooms/pedestal-4x5.c", "none");
    region->setCoordinate(5, 3,
        "/tutorial/temple/environment/rooms/rod-chamber.c", "none");

    region->setCoordinate(0, 2,
        "/tutorial/temple/environment/rooms/pedestal-5x1.c", "none");
    region->setCoordinate(1, 2,
        "/tutorial/temple/environment/rooms/pedestal-5x2.c", "none");
    region->setCoordinate(2, 2,
        "/tutorial/temple/environment/rooms/pedestal-5x3.c", "none");
    region->setCoordinate(3, 2,
        "/tutorial/temple/environment/rooms/pedestal-5x4.c", "none");
    region->setCoordinate(4, 2,
        "/tutorial/temple/environment/rooms/pedestal-5x5.c", "none");
    region->setCoordinate(5, 2,
        "/tutorial/temple/environment/rooms/chamber-of-targets.c", "none");

    region->setCoordinate(0, 1,
        "/tutorial/temple/environment/rooms/pedestal-6x1.c", "none");
    region->setCoordinate(1, 1,
        "/tutorial/temple/environment/rooms/pedestal-6x2.c", "none");
    region->setCoordinate(2, 1,
        "/tutorial/temple/environment/rooms/pedestal-6x3.c", "none");
    region->setCoordinate(3, 1,
        "/tutorial/temple/environment/rooms/pedestal-6x4.c", "none");
    region->setCoordinate(4, 1,
        "/tutorial/temple/environment/rooms/pedestal-6x5.c", "none");
    region->setCoordinate(5, 1,
        "/tutorial/temple/environment/rooms/pedestal-6x6.c", "none");
}
