//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cheese press");
    addAlias("press");
    addAlias("curd press");

    addAdjectives(({ "wooden", "heavy", "screw-driven", "stained",
        "well-used", "dripping", "sturdy", "old", "oak", "functional" }));

    addDescriptionTemplate("a ##Adjective## cheese press with weighted boards");

    addItemTemplate(
        "The cheese press is a heavy wooden frame with a large screw "
        "mechanism that forces a weighted board down onto curds packed in "
        "a cloth-lined mold. Whey drips from the bottom into a catch pan "
        "below. The wood is permanently stained white and carries the "
        "sour, sharp smell of pressed curds."
    );

    addSomeLightDescriptionTemplate(
        "a cheese press stands in the dairy, whey dripping from its base"
    );
    addDimLightDescriptionTemplate(
        "a wooden frame with a screw mechanism is visible — a cheese press"
    );
    addLowLightDescriptionTemplate(
        "a heavy wooden frame with a vertical screw stands nearby"
    );
    addNearDarkDescriptionTemplate(
        "the sour smell of curds and the drip of whey suggest a cheese "
        "press nearby"
    );
}
