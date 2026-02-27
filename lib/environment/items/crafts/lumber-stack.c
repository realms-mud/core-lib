//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lumber stack");
    addAlias("timber");
    addAlias("lumber pile");
    addAlias("stacked timber");

    addAdjectives(({ "neatly-stacked", "rough-sawn", "seasoning",
        "fresh-cut", "weathered", "large", "fragrant", "bark-covered",
        "sorted", "tall" }));

    addDescriptionTemplate("a ##Adjective## stack of lumber set on drying racks");

    addItemTemplate(
        "The lumber stack is a carefully arranged pile of rough-sawn planks "
        "and beams, separated by thin sticks to allow air to circulate for "
        "seasoning. The wood is a mix of oak, pine, and elm, each marked "
        "on the end with a chalk symbol. The scent of fresh-cut timber is "
        "strong."
    );

    addSomeLightDescriptionTemplate(
        "a stack of lumber is arranged on drying racks, neatly sorted"
    );
    addDimLightDescriptionTemplate(
        "a tall stack of lumber is visible, its pale ends catching the light"
    );
    addLowLightDescriptionTemplate(
        "a large rectangular mass suggests stacked timber"
    );
    addNearDarkDescriptionTemplate(
        "the strong scent of cut wood suggests a lumber stack nearby"
    );
}
