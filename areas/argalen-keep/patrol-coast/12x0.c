//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("coast trail north-south");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/paths/trail.c", "south");

    addExit("north", "/areas/argalen-keep/surrounding/12x0.c");
    addExit("south", "/areas/argalen-keep/patrol-coast/12x1.c");
}
