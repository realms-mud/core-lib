//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spinning wheel");
    addAlias("wheel");
    addAlias("spinning-wheel");
    addAlias("wooden spinning wheel");

    addAdjectives(({ "wooden", "old", "worn", "functional", "carved", "upright",
        "simple", "broad", "well-used", "plain" }));

    addDescriptionTemplate("a ##Adjective## spinning wheel with a large drive wheel");

    addItemTemplate(
        "This spinning wheel is crafted from wood, with a large drive wheel "
        "and a simple treadle. The spindle and flyer are worn smooth from "
        "years of spinning wool or flax."
    );

    addSomeLightDescriptionTemplate(
        "a wooden spinning wheel stands near the hearth, its wheel ready to turn"
    );
    addDimLightDescriptionTemplate(
        "a spinning wheel is visible in the gloom, its outline upright and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a spinning wheel can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a spinning wheel is present, but details are "
        "lost in the darkness"
    );
}
