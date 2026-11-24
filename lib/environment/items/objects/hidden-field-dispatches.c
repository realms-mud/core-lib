//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hidden field dispatches");
    addAlias("field dispatches");
    addAlias("dispatches");
    addAlias("sealed reports");

    addAdjectives(({ "sealed", "folded", "coded", "old" }));

    addDescriptionTemplate("a bundle of ##Adjective## Phaedra dispatches");
    addItemTemplate(
        "The dispatches contain field reports, supply tallies, and copied "
        "orders never entered in the public registry. One grease-pencil "
        "note gives the map sequence: turn Serach 45 counterclockwise, "
        "Eledhel 90 clockwise, Serach 135 clockwise, Ethyl Tirath 180 "
        "counterclockwise, Hillgarath 360 clockwise, and Eledhel 180 "
        "counterclockwise. A final line says to press Eledhel."
    );

    addSomeLightDescriptionTemplate(
        "folded reports with a grease-pencil sequence in the margin");
    addDimLightDescriptionTemplate(
        "a bundle of tied papers and field reports");
    addLowLightDescriptionTemplate(
        "the pale edges of several folded dispatches");
    addNearDarkDescriptionTemplate(
        "a small bundle of papers on the shelf");
}
