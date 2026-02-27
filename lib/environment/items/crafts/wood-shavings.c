//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wood shavings");
    addAlias("shavings");
    addAlias("curls of wood");

    addAdjectives(({ "pale", "fragrant", "curling", "scattered",
        "fresh", "dry", "ankle-deep", "fine", "spiraling", "soft" }));

    addDescriptionTemplate("##Adjective## wood shavings littering the floor");

    addItemTemplate(
        "The floor is carpeted with curling wood shavings in shades of "
        "cream and gold, spiraling ribbons left behind by the plane and "
        "drawknife. They crunch underfoot and fill the air with the "
        "sweet scent of freshly worked timber."
    );

    addSomeLightDescriptionTemplate(
        "wood shavings litter the floor, pale curls catching the light"
    );
    addDimLightDescriptionTemplate(
        "pale shavings are scattered across the floor"
    );
    addLowLightDescriptionTemplate(
        "something pale and soft covers the floor"
    );
    addNearDarkDescriptionTemplate(
        "the sweet scent of fresh wood and the crunch underfoot suggest "
        "shavings covering the floor"
    );
}
