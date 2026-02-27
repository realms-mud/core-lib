//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("well");
    addAlias("village well");
    addAlias("stone well");
    addAlias("draw well");

    addAdjectives(({ "stone", "deep", "mossy", "old", "sturdy", "round",
        "ancient", "weathered", "reliable", "cool" }));

    addDescriptionTemplate("a ##Adjective## well with a wooden winch and bucket");

    addItemTemplate(
        "The well is ringed with fitted stones worn smooth by generations of "
        "hands. A sturdy wooden frame supports a winch and rope, from which "
        "hangs a battered iron-banded bucket. The stones around the base are "
        "dark with spilled water, and a faint echo rises from the depths below."
    );

    addSomeLightDescriptionTemplate(
        "a stone well stands in the open, its wooden frame and dangling bucket "
        "clearly visible"
    );
    addDimLightDescriptionTemplate(
        "a well is visible, the glint of water far below barely perceptible"
    );
    addLowLightDescriptionTemplate(
        "the outline of a well's frame can be made out in the gloom"
    );
    addNearDarkDescriptionTemplate(
        "the faint creak of a rope and the distant echo of water suggest a "
        "well is nearby"
    );
}
