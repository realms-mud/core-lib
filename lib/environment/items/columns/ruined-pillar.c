//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruined marble pillar");
    addAlias("pillar");
    addAlias("marble pillar");
    addAlias("ruined pillar");

    addAdjectives(({ "a once-grand, but now fallen in disrepair ",
        "a crumbling pale, gray-blue",
        "a disintegrating, but still imposing",
        "a long-neglected" }));

    addNearDarkDescriptionTemplate("a darker shadow");
    addLowLightDescriptionTemplate("a large, dark object");
    addDimLightDescriptionTemplate("a pillar");
    addSomeLightDescriptionTemplate("##Adjective## stone pillar");
    addDescriptionTemplate("##Adjective## marble pillar");
}
