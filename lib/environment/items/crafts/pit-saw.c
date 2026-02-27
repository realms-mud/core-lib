//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pit saw");
    addAlias("saw");
    addAlias("great saw");
    addAlias("frame saw");

    addAdjectives(({ "large", "iron-toothed", "heavy", "two-man",
        "well-oiled", "sharp", "long", "old", "sturdy", "fearsome" }));

    addDescriptionTemplate("a ##Adjective## pit saw mounted over a cutting pit");

    addItemTemplate(
        "The pit saw is a massive blade set in a wooden frame, designed "
        "to be worked by two men — one above and one standing in the pit "
        "below. The teeth are large and freshly filed, and the blade is "
        "oiled to prevent rust. Sawdust fills the pit to ankle depth."
    );

    addSomeLightDescriptionTemplate(
        "a large pit saw is mounted over a cutting pit, its teeth gleaming"
    );
    addDimLightDescriptionTemplate(
        "a large saw blade glints faintly in its frame over a pit"
    );
    addLowLightDescriptionTemplate(
        "a metal blade is faintly visible in a wooden frame"
    );
    addNearDarkDescriptionTemplate(
        "the scent of fresh sawdust fills the air"
    );
}
