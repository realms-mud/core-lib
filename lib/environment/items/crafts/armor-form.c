//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("armor form");
    addAlias("mannequin");
    addAlias("fitting form");
    addAlias("armor dummy");

    addAdjectives(({ "wooden", "padded", "adjustable", "sturdy",
        "torso-shaped", "well-used", "battered", "old", "tall",
        "functional" }));

    addDescriptionTemplate("a ##Adjective## armor form used for fitting and display");

    addItemTemplate(
        "The armor form is a torso-shaped wooden mannequin on an adjustable "
        "stand, padded with canvas and horsehair to approximate a human "
        "body. It is used for fitting armor plates and testing the hang "
        "of chainmail. Pin holes and hammer marks cover its surface, and "
        "scraps of leather and metal cling to its padding."
    );

    addSomeLightDescriptionTemplate(
        "an armor form stands on its pedestal, padded and pincushioned"
    );
    addDimLightDescriptionTemplate(
        "a torso-shaped figure stands on a pedestal, vaguely human"
    );
    addLowLightDescriptionTemplate(
        "a humanoid shape stands motionless on a stand"
    );
    addNearDarkDescriptionTemplate(
        "a vaguely human shape stands silently nearby"
    );
}
