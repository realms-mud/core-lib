//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("flower box");
    addAlias("window box");
    addAlias("planter");
    addAlias("planter box");

    addAdjectives(({ "wooden", "colorful", "overflowing", "neat",
        "weathered", "cheerful", "simple", "painted", "small", "charming" }));

    addDescriptionTemplate("a ##Adjective## flower box beneath a window");

    addItemTemplate(
        "The flower box is a simple wooden trough mounted beneath a window "
        "sill, overflowing with blooms and trailing greenery. The wood is "
        "painted in cheerful colors, though the paint is peeling in places. "
        "Bees and butterflies hover about the blossoms."
    );

    addSomeLightDescriptionTemplate(
        "a flower box bursts with color beneath a window, bees buzzing about"
    );
    addDimLightDescriptionTemplate(
        "a flower box is visible beneath a window, its blooms dark in the gloom"
    );
    addLowLightDescriptionTemplate(
        "something overflows from beneath a window, possibly flowers"
    );
    addNearDarkDescriptionTemplate(
        "the faint scent of flowers drifts from near a window"
    );
}
