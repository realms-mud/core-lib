//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spice chest");
    addAlias("chest");
    addAlias("spice box");
    addAlias("wooden spice chest");

    addAdjectives(({ "small", "wooden", "carved", "old", "sturdy", "ornate",
        "plain", "functional", "heavy", "compartmented" }));

    addDescriptionTemplate("a ##Adjective## spice chest with many small drawers");

    addItemTemplate(
        "This spice chest is a small, sturdy box made from wood, fitted with "
        "many tiny drawers for storing spices and herbs. The front is carved "
        "with simple patterns."
    );

    addSomeLightDescriptionTemplate(
        "a wooden spice chest sits on the shelf, its drawers closed"
    );
    addDimLightDescriptionTemplate(
        "a spice chest is visible in the gloom, its outline small and boxy"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a spice chest can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a spice chest is present, but details are lost "
        "in the darkness"
    );
}
