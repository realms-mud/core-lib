//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("sandy shore");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/water/sandy-sea-beach.c",
        "south");
    addItem("/lib/environment/items/marine/fishing-hut.c", "west");
    addItem("/lib/environment/items/marine/rowboat.c", "south");

    addExit("east", "/areas/argalen-keep/patrol-coast/9x4.c");
}
