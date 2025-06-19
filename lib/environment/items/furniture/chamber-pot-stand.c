//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chamber pot stand");
    addAlias("pot stand");
    addAlias("stand");
    addAlias("wooden stand");

    addAdjectives(({ "small", "wooden", "plain", "old", "sturdy", "upright",
        "functional", "worn", "round", "short" }));

    addDescriptionTemplate("a ##Adjective## chamber pot stand by the bed");

    addItemTemplate(
        "This small stand is made from wood, with a round opening in the top "
        "to hold a chamber pot. The legs are sturdy, and a small shelf below "
        "can hold a pitcher or cloth."
    );

    addSomeLightDescriptionTemplate(
        "a wooden chamber pot stand sits by the bed, its top empty"
    );
    addDimLightDescriptionTemplate(
        "a chamber pot stand is visible in the gloom, its outline small and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a chamber pot stand can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a chamber pot stand is present, but details are "
        "lost in the darkness"
    );
}
