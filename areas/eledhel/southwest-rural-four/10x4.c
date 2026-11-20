//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("A spring-fed trough waters the drove road");
    addDecorator("village tree");
    addFeature("/lib/environment/features/water/spring.c", "none");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("north", "/areas/eledhel/southwest-rural-four/10x3.c");
}
