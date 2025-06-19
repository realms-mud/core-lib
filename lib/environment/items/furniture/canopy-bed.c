//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("canopy bed");
    addAlias("bed");
    addAlias("four-poster bed");
    addAlias("wooden canopy bed");

    addAdjectives(({ "large", "wooden", "ornate", "carved", "canopied", "broad",
        "tall", "old", "draped", "grand" }));

    addDescriptionTemplate("a ##Adjective## canopy bed with heavy curtains");

    addItemTemplate(
        "This canopy bed is built from thick wooden posts supporting a frame "
        "above the mattress. Heavy curtains hang from the canopy, offering "
        "privacy and warmth. The headboard and posts are carved with "
        "decorative patterns."
    );

    addSomeLightDescriptionTemplate(
        "a large canopy bed stands against the wall, its curtains drawn back"
    );
    addDimLightDescriptionTemplate(
        "a canopy bed is visible in the gloom, its posts tall and imposing"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a canopy bed can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a canopy bed is present, but details are lost "
        "in the darkness"
    );
}
