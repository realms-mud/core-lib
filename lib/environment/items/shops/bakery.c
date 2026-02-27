//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bakery interior");

    addItemTemplate(
        "The bakery is warm and fragrant, dominated by a large brick oven "
        "built into the far wall. Its iron door radiates heat, and the air "
        "is thick with the smell of fresh bread, yeast, and cinnamon. Wooden "
        "racks along the walls hold cooling loaves, braided rolls, and trays "
        "of honey cakes. A flour-dusted worktable occupies the center, "
        "scattered with wooden paddles, mixing bowls, and a jar of coarse "
        "salt. Sacks of flour and grain are stacked beside the oven, and a "
        "small display shelf near the door showcases the day's offerings."
    );

    addNearDarkDescriptionTemplate(
        "the bakery is dark save for a thin line of amber light seeping from "
        "the oven door, and the lingering warmth of baking fills the air"
    );
    addLowLightDescriptionTemplate(
        "the glow from the oven casts long shadows across the bakery, "
        "outlining the racks of bread and the flour-dusted worktable"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the rows of cooling loaves and the brick oven's "
        "warm glow, with flour dust hanging faintly in the air"
    );
    addSomeLightDescriptionTemplate(
        "the bakery is bright enough to see the golden crusts of the loaves "
        "and the trays of pastries arranged on the display shelf"
    );
    addDescriptionTemplate(
        "warm light fills the bakery, making the fresh loaves glow golden "
        "and the dusting of flour on the worktable sparkle"
    );
}
