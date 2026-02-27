//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("potters wheel");
    addAlias("pottery wheel");
    addAlias("throwing wheel");

    addAdjectives(({ "wooden", "clay-spattered", "heavy", "pedal-driven",
        "well-used", "spinning", "old", "sturdy", "low", "simple" }));

    addDescriptionTemplate("a ##Adjective## potters wheel with a lump of clay");

    addItemTemplate(
        "The potters wheel is a heavy wooden disc mounted on a central axle, "
        "driven by a kick-wheel below. Its surface is caked with dried clay "
        "in a dozen shades, and a bucket of water and a collection of wooden "
        "shaping tools sit within arm's reach. A half-formed vessel sits on "
        "the wheel, waiting for the potter's return."
    );

    addSomeLightDescriptionTemplate(
        "a potters wheel sits ready, its surface caked with dried clay"
    );
    addDimLightDescriptionTemplate(
        "a low wheel and stool are visible, surrounded by clay implements"
    );
    addLowLightDescriptionTemplate(
        "a low circular apparatus sits in the work area"
    );
    addNearDarkDescriptionTemplate(
        "the earthy smell of wet clay fills the area"
    );
}
