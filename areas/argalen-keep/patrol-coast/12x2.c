//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalFarm();
    addDecorator("farm track T-west");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/paths/trail.c", "south");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addItem("/lib/environment/items/objects/signPost.c", "east");

    addExit("north", "/areas/argalen-keep/patrol-coast/12x1.c");
    addExit("south", "/areas/argalen-keep/patrol-coast/12x3.c");
    addExit("west", "/areas/argalen-keep/patrol-coast/11x2.c");
}
