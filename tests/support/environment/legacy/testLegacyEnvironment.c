//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/legacy.c");
    setShortDescription("Throne");
    setAdditionalLongDescription(
        "You have entered the throne room of Turgon. The throne itself is\n"
        "made almost fully out of gold- obviously, this man has no shame.\n"
        "Standing beside the throne are two other lesser thrones. In these sit\n"
        "Idril, his daughter; and Tuor (the human), her husband.\n"
        "There are also several statues of the Valar standing about.\n");

    addLegacyItem("throne", "For being made out of gold, it really looks comfy");
    addLegacyItem("statues", "You see statues of the nine valar");

    addExit("north", "/lib/legacy/maeglin/gondolin/tower12");

    addObject("/lib/tests/support/services/mockPlayer.c");
    addObject("/lib/instances/items/weapons/swords/long-sword.c");
    addObject("/lib/tests/support/services/mockNPC.c");
}

/////////////////////////////////////////////////////////////////////////////
protected int alwaysLight()
{
    return 1;
}
