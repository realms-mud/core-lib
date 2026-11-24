//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("paired climbing ropes");
    addAlias("two climbing ropes");
    addAlias("tied ropes");
    addAlias("climbing ropes");

    addAdjectives(({ "hemp", "knotted", "heavy", "weathered" }));

    addDescriptionTemplate(
        "two ##Adjective## climbing ropes joined end to end");
    addItemTemplate(
        "The two long hemp ropes are knotted together to reach the base "
        "of the steep shaft. One end is fixed around an iron ring; the "
        "other bears fresh fibers where a climber has tested its weight."
    );

    addSomeLightDescriptionTemplate(
        "two climbing ropes knotted together at an iron ring");
    addDimLightDescriptionTemplate(
        "a joined pair of ropes secured to the rock");
    addLowLightDescriptionTemplate(
        "a heavy rope fixed above the climb");
    addNearDarkDescriptionTemplate(
        "a rough rope hangs against the limestone");
}
