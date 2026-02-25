//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("smelter interior");

    addItemTemplate(
        "The smelter is a cavernous, sweltering space built around a pair of "
        "towering stone furnaces. Their iron-banded doors glow cherry-red, "
        "and waves of heat roll outward in visible ripples. Channels cut "
        "into the stone floor lead from the furnaces to rows of ingot molds "
        "- some still cooling, their contents shifting from orange to dull "
        "grey. Bins of charcoal and flux stone are stacked near the furnaces, "
        "and long-handled ladles and slag rakes hang from a heavy iron frame. "
        "A quenching cistern of dark water steams in the corner. The air is "
        "brutally hot and thick with the acrid smell of molten metal and "
        "sulfurous slag."
    );

    addNearDarkDescriptionTemplate(
        "the smelter glows with a deep, infernal light from the furnace "
        "doors, casting everything in stark red and black"
    );
    addLowLightDescriptionTemplate(
        "the furnaces paint the smelter in ruddy light and deep shadow, "
        "the ingot molds and channels barely visible on the floor"
    );
    addDimLightDescriptionTemplate(
        "the furnaces' glow combines with dim light to reveal the ingot "
        "molds, the bins of charcoal, and the steaming quenching cistern"
    );
    addSomeLightDescriptionTemplate(
        "the smelter is well-lit between the furnaces and outside light, "
        "the cooling ingots and heavy tools clearly visible"
    );
    addDescriptionTemplate(
        "bright light and the furnaces' blaze illuminate every corner of "
        "the smelter, the heat haze making the air shimmer above the molds"
    );
}
