//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalFarm();
    addDecorator("farm path west dead end");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "west");
    addNonCombatCreature(({ "farmer" }));

    addExit("east", "/areas/argalen-keep/patrol-coast/11x2.c");
}
