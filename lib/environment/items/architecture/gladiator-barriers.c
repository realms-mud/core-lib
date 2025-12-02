//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gladiator barriers");
    addAlias("fence");
    addAlias("wooden barriers");
    addAlias("arena barrier");
    addAlias("barricade");

    addAdjectives(({ "protective", "spiked", "sturdy", "blood-marked" }));

    addDescriptionTemplate("##Adjective## wooden barriers separating the "
        "combat arena from the spectator stands");

    addItemTemplate("The barriers are topped with metal spikes to prevent "
        "combatants from escaping or being thrown into the crowd");

    addSomeLightDescriptionTemplate("wooden walls about waist-high encircling "
        "the arena floor, topped with cruel-looking metal spikes");

    addDimLightDescriptionTemplate("a ring of wooden barriers surrounding the "
        "sandy combat area");

    addLowLightDescriptionTemplate("what appears to be a fence or barrier "
        "around the central area");

    addNearDarkDescriptionTemplate("vague shapes that might be barriers "
        "separating sections of the structure");
}
