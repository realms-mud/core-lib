//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("market stall");
    addAlias("stall");
    addAlias("vendor stall");
    addAlias("market stand");

    addAdjectives(({ "wooden", "canvas-topped", "rickety", "colorful",
        "busy", "weathered", "simple", "well-stocked", "modest",
        "makeshift" }));

    addDescriptionTemplate("a ##Adjective## market stall displaying wares");

    addItemTemplate(
        "The market stall is a simple wooden frame draped with canvas to "
        "keep off sun and rain. Its counter is a rough plank laid across "
        "two trestles, and the goods are arranged in baskets and on "
        "cloth-covered boards. The canvas flaps and snaps in the breeze."
    );

    addSomeLightDescriptionTemplate(
        "a market stall stands with its wares on display under a canvas awning"
    );
    addDimLightDescriptionTemplate(
        "a market stall is visible, its canvas top casting deep shadow below"
    );
    addLowLightDescriptionTemplate(
        "a canvas-topped structure suggests a market stall"
    );
    addNearDarkDescriptionTemplate(
        "the flutter of canvas overhead suggests a stall or tent"
    );
}
