//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lathe");
    addAlias("wood lathe");
    addAlias("pole lathe");
    addAlias("turning lathe");

    addAdjectives(({ "wooden", "pedal-driven", "well-used", "sturdy",
        "old", "functional", "simple", "spring-pole", "heavy", "precise" }));

    addDescriptionTemplate("a ##Adjective## lathe for turning wood");

    addItemTemplate(
        "The lathe is a spring-pole design, its bed made of heavy oak with "
        "iron fittings. A cord wraps around the workpiece and connects to "
        "a foot pedal below and a springy pole above, allowing the turner "
        "to spin the wood back and forth. Curls of shaved wood litter the "
        "area around it."
    );

    addSomeLightDescriptionTemplate(
        "a wood lathe stands ready for use, its spring pole arched overhead"
    );
    addDimLightDescriptionTemplate(
        "a lathe is visible, its long bed and overhead pole distinctive"
    );
    addLowLightDescriptionTemplate(
        "a long wooden apparatus with an overhead pole is barely visible"
    );
    addNearDarkDescriptionTemplate(
        "a large wooden apparatus occupies part of the room"
    );
}
