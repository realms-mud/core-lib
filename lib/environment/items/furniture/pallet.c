//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pallet");
    addAlias("straw bed");
    addAlias("mat");
    addAlias("simple bed");

    addAdjectives(({ "straw-filled", "simple", "thin", "worn", "old", "plain",
        "narrow", "rough", "low", "functional" }));

    addDescriptionTemplate("a ##Adjective## pallet laid on the floor");

    addItemTemplate(
        "This pallet is a simple bedding of straw stuffed into a rough linen "
        "sack. It is thin and worn, offering little comfort but some warmth."
    );

    addSomeLightDescriptionTemplate(
        "a straw-filled pallet lies on the floor, its surface rough and thin"
    );
    addDimLightDescriptionTemplate(
        "a pallet is visible in the gloom, its outline low and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a pallet can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a pallet is present, but details are lost in "
        "the darkness"
    );
}
