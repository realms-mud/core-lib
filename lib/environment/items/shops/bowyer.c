//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bowyer interior");

    addItemTemplate(
        "The bowyer's shop is a long, narrow space that smells pleasantly of "
        "wood shavings and beeswax. Finished bows hang from pegs along one "
        "wall - short recurves of layered horn and sinew, tall yew longbows, "
        "and a heavy crossbow with a steel prod. Bundles of arrow shafts "
        "stand in racks, sorted by length and wood type, while trays of "
        "goose-feather fletchings and iron broadheads sit on a side table. "
        "A tillering frame occupies the rear of the shop, holding a half-"
        "finished stave being carefully shaped. Coils of bowstring - linen "
        "and waxed silk - hang from hooks beside pots of glue and string wax."
    );

    addNearDarkDescriptionTemplate(
        "the bowyer's shop is deep in shadow, the hanging bows reduced to "
        "curved lines barely visible against the dark wall"
    );
    addLowLightDescriptionTemplate(
        "the bows on the wall are dim, arching shapes in the gloom, and "
        "the bundles of arrow shafts stand like pale sentinels"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the graceful curves of the hanging bows and "
        "the neatly sorted arrows and fletchings on the side table"
    );
    addSomeLightDescriptionTemplate(
        "the bowyer's shop is bright enough to see the grain of the yew "
        "staves and the careful layering of horn on the recurve bows"
    );
    addDescriptionTemplate(
        "light fills the bowyer's shop, bringing out the warm tones of the "
        "wood and the fine detail of every bow and feathered shaft"
    );
}
