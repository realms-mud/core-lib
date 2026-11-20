//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalFarm();
    addDecorator("farm track east-west");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "north");

    addExit("east", "/areas/argalen-keep/patrol-coast/12x2.c");
    addExit("west", "/areas/argalen-keep/patrol-coast/10x2.c");
}
