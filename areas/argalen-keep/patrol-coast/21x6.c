//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addItem("/lib/environment/items/marine/lighthouse.c", "north");
    addItem("/lib/environment/items/marine/harbor-lantern.c", "west");

    addExit("north", "/areas/argalen-keep/patrol-coast/21x5.c");
}
