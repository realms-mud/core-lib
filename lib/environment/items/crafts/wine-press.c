//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wine press");
    addAlias("grape press");
    addAlias("cider press");
    addAlias("fruit press");

    addAdjectives(({ "wooden", "heavy", "screw-driven", "stained",
        "massive", "old", "oak", "well-used", "juice-stained",
        "functional" }));

    addDescriptionTemplate("a ##Adjective## wine press with a great wooden screw");

    addItemTemplate(
        "The wine press is a massive wooden apparatus with a great screw "
        "mechanism that drives a heavy plate down onto crushed fruit in a "
        "slatted barrel. Juice runs through the gaps and collects in a "
        "stone trough below. The wood is permanently stained dark purple "
        "and the air is sweet with the smell of fermented fruit."
    );

    addSomeLightDescriptionTemplate(
        "a wine press stands ready, its great screw and stained barrel "
        "clearly visible"
    );
    addDimLightDescriptionTemplate(
        "a large wooden apparatus with a vertical screw is visible"
    );
    addLowLightDescriptionTemplate(
        "a massive wooden mechanism with a central screw fills the space"
    );
    addNearDarkDescriptionTemplate(
        "the sweet smell of pressed fruit and fermentation fills the air"
    );
}
