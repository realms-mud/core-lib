//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wax block");
    addAlias("wax");
    addAlias("beeswax block");
    addAlias("tallow block");

    addAdjectives(({ "pale", "heavy", "smooth", "fragrant", "large",
        "yellowish", "honey-colored", "warm", "soft", "clean" }));

    addDescriptionTemplate("a ##Adjective## block of wax on the workbench");

    addItemTemplate(
        "The wax block is a heavy slab of rendered beeswax or tallow, "
        "its surface smooth and slightly translucent. It has a warm, "
        "honey-colored hue and a faint sweet fragrance. Shavings and "
        "curls of wax from previous use litter the bench around it, "
        "and a scoring knife sits nearby."
    );

    addSomeLightDescriptionTemplate(
        "a block of pale wax sits on the bench, translucent and fragrant"
    );
    addDimLightDescriptionTemplate(
        "a pale smooth block sits on the workbench"
    );
    addLowLightDescriptionTemplate(
        "a pale shape sits on the bench"
    );
    addNearDarkDescriptionTemplate(
        "the faint sweet scent of beeswax comes from the bench"
    );
}
