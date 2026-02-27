//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ingot mold");
    addAlias("mold");
    addAlias("casting mold");
    addAlias("ingot form");

    addAdjectives(({ "iron", "soot-blackened", "heavy", "well-used",
        "rectangular", "scarred", "functional", "sturdy", "old", "hinged" }));

    addDescriptionTemplate("a ##Adjective## ingot mold sitting on the workbench");

    addItemTemplate(
        "The ingot mold is a hinged iron form with rectangular cavities for "
        "casting metal bars. Its interior is coated with a thin layer of "
        "chalk to prevent sticking, and traces of different metals gleam in "
        "the crevices — copper green, silver white, and iron black."
    );

    addSomeLightDescriptionTemplate(
        "an iron ingot mold sits on the bench, its cavities chalked and ready"
    );
    addDimLightDescriptionTemplate(
        "a heavy iron mold is visible on the workbench"
    );
    addLowLightDescriptionTemplate(
        "a heavy iron object sits on the workbench"
    );
    addNearDarkDescriptionTemplate(
        "something heavy and metallic rests on the bench"
    );
}
