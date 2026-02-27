//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rain cistern");
    addAlias("cistern");
    addAlias("water barrel");
    addAlias("collection barrel");

    addAdjectives(({ "large", "wooden", "iron-banded", "mossy",
        "brimming", "old", "weathered", "sturdy", "covered", "damp" }));

    addDescriptionTemplate("a ##Adjective## rain cistern set beneath a downspout");

    addItemTemplate(
        "The cistern is a large wooden tub banded with iron hoops, set "
        "beneath a roof's downspout to collect rainwater. A wooden lid "
        "keeps out debris, and the outside is streaked green with algae. "
        "A tap near the bottom allows water to be drawn off."
    );

    addSomeLightDescriptionTemplate(
        "a large rain cistern sits beneath a downspout, its sides green "
        "with algae"
    );
    addDimLightDescriptionTemplate(
        "a large barrel-like cistern is visible beneath a roofline"
    );
    addLowLightDescriptionTemplate(
        "a large round shape sits against a wall"
    );
    addNearDarkDescriptionTemplate(
        "the drip of water into a container suggests a cistern nearby"
    );
}
