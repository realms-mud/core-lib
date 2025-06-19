//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dresser");
    addAlias("chest of drawers");
    addAlias("wooden dresser");
    addAlias("clothes dresser");

    addAdjectives(({ "wooden", "carved", "broad", "sturdy", "old",
        "ornate", "polished", "functional", "heavy" }));

    addDescriptionTemplate("a ##Adjective## dresser with several drawers");

    addItemTemplate(
        "This dresser is made from heavy wood, its drawers fitted "
        "with iron handles. The front is carved with simple patterns, and the "
        "top is broad enough to hold a mirror or personal items."
    );

    addSomeLightDescriptionTemplate(
        "a wooden dresser stands against the wall, its drawers closed and "
        "surface polished"
    );
    addDimLightDescriptionTemplate(
        "a dresser is visible in the gloom, its outline broad and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a dresser can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a dresser is present, but details are lost in "
        "the darkness"
    );
}
