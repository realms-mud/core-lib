//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("counterweight lever");
    addAlias("lever");
    addAlias("release lever");

    addAdjectives(({ "iron", "long", "worn", "weighted" }));

    addDescriptionTemplate("a ##Adjective## lever beside the gears");
    addItemTemplate(
        "The lever is linked to a chain running up into the ceiling. "
        "Its travel is marked by two notches: one holds the stair shut, "
        "the other lowers the weights and turns the hidden gears."
    );

    addSomeLightDescriptionTemplate(
        "a long iron lever with two notches in its travel");
    addDimLightDescriptionTemplate(
        "a lever fixed beside the counterweights");
    addLowLightDescriptionTemplate(
        "a metal handle beside the gears");
    addNearDarkDescriptionTemplate(
        "a short handle set into the wall");
}
