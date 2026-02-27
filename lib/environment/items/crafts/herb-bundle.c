//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("herb bundle");
    addAlias("herbs");
    addAlias("dried herbs");
    addAlias("hanging herbs");

    addAdjectives(({ "fragrant", "dried", "hanging", "bundled",
        "aromatic", "colorful", "dusty", "tied", "varied", "fresh" }));

    addDescriptionTemplate("##Adjective## bundles of herbs hanging from the rafters");

    addItemTemplate(
        "Bundles of dried herbs hang from the rafters and ceiling hooks, "
        "tied with twine at their stems. Lavender, rosemary, sage, thyme, "
        "and dozens of less familiar plants dangle in various stages of "
        "drying. The air is thick with their mingled fragrances — sweet, "
        "sharp, bitter, and earthy all at once."
    );

    addSomeLightDescriptionTemplate(
        "bundles of dried herbs hang from the rafters, filling the air "
        "with fragrance"
    );
    addDimLightDescriptionTemplate(
        "dried plant bundles hang from the ceiling, their scent filling "
        "the room"
    );
    addLowLightDescriptionTemplate(
        "things hang from the ceiling, rustling faintly"
    );
    addNearDarkDescriptionTemplate(
        "the rich mingled scent of dried herbs pervades the air"
    );
}
