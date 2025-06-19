//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mirror stand");
    addAlias("mirror");
    addAlias("looking glass");
    addAlias("wooden mirror stand");

    addAdjectives(({ "wooden", "upright", "carved", "old", "polished", "plain",
        "functional", "tall", "broad", "well-made" }));

    addDescriptionTemplate("a ##Adjective## mirror stand with a polished surface");

    addItemTemplate(
        "This mirror stand is made from wood, with a polished metal or glass "
        "mirror set in a carved frame. The stand is upright and stable, "
        "allowing one to view their reflection."
    );

    addSomeLightDescriptionTemplate(
        "a wooden mirror stand stands near the wall, its surface gleaming"
    );
    addDimLightDescriptionTemplate(
        "a mirror stand is visible in the gloom, its outline upright and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a mirror stand can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a mirror stand is present, but details are lost "
        "in the darkness"
    );
}
