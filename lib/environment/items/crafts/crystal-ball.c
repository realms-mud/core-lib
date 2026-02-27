//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crystal ball");
    addAlias("scrying orb");
    addAlias("gazing ball");
    addAlias("orb");

    addAdjectives(({ "gleaming", "clouded", "clear", "mysterious",
        "polished", "smoky", "luminous", "ancient", "mesmerizing",
        "large" }));

    addDescriptionTemplate("a ##Adjective## crystal ball on a silver stand");

    addItemTemplate(
        "The crystal ball is a sphere of flawless glass — or perhaps "
        "something more — resting in a stand of tarnished silver wrought "
        "in the form of clutching claws. Staring into its depths reveals "
        "faint swirls of color that move of their own accord, hinting at "
        "visions just beyond the edge of perception."
    );

    addSomeLightDescriptionTemplate(
        "a crystal ball gleams on its silver stand, swirling faintly within"
    );
    addDimLightDescriptionTemplate(
        "a glass sphere faintly glows on a metal stand"
    );
    addLowLightDescriptionTemplate(
        "a faint luminous sphere sits on a stand"
    );
    addNearDarkDescriptionTemplate(
        "a faint, ghostly luminescence emanates from a spherical object"
    );
}
