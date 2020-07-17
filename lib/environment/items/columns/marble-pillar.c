//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("marble pillar");
    addAlias("pillar");

    addAdjectives(({ "an artistically-sculpted",
        "a pale, gray-blue",
        "an imposing",
        "a towering" }));

    addNearDarkDescriptionTemplate("a darker shadow");
    addLowLightDescriptionTemplate("a large, dark object");
    addDimLightDescriptionTemplate("a pillar");
    addSomeLightDescriptionTemplate("##Adjective## stone pillar");
    addDescriptionTemplate("##Adjective## marble pillar");
}
