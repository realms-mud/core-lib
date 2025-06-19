//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ambry");
    addAlias("wall cupboard");
    addAlias("recessed cupboard");
    addAlias("cabinet");

    addAdjectives(({ "small", "wooden", "recessed", "carved", "plain", "old",
        "panelled", "narrow", "shallow", "well-made" }));

    addDescriptionTemplate("a ##Adjective## ambry set into the wall");

    addItemTemplate(
        "This ambry is a small cupboard built into the wall, with a wooden "
        "door and simple latch. The interior is shallow, suitable for storing "
        "valuables, sacred items, or small household goods."
    );

    addSomeLightDescriptionTemplate(
        "a small ambry is set into the wall, its door closed"
    );
    addDimLightDescriptionTemplate(
        "an ambry is visible in the gloom, its outline narrow and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of an ambry can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests an ambry is present, but details are lost in "
        "the darkness"
    );
}
