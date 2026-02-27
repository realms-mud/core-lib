//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tanning rack");
    addAlias("drying rack");
    addAlias("hide rack");
    addAlias("stretching rack");

    addAdjectives(({ "wooden", "tall", "stained", "pungent", "sturdy",
        "well-used", "rough", "weathered", "upright", "functional" }));

    addDescriptionTemplate("a ##Adjective## tanning rack with hides stretched on it");

    addItemTemplate(
        "The tanning rack is a tall wooden frame with pegs and lacing "
        "points for stretching hides. Several skins are laced taut across "
        "it in various stages of drying, their surfaces scraped smooth. "
        "The sharp smell of tanning agents fills the air, and the wood "
        "itself is deeply stained from years of the trade."
    );

    addSomeLightDescriptionTemplate(
        "a tanning rack holds stretched hides, their surfaces pale and smooth"
    );
    addDimLightDescriptionTemplate(
        "a tall frame with something stretched across it is visible"
    );
    addLowLightDescriptionTemplate(
        "a tall frame with pale surfaces stands against the wall"
    );
    addNearDarkDescriptionTemplate(
        "the sharp smell of tanning chemicals fills the air"
    );
}
