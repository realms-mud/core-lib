//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("clothesline");
    addAlias("washing line");
    addAlias("laundry line");

    addAdjectives(({ "sagging", "taut", "hemp", "long", "weathered",
        "frayed", "sturdy", "simple", "well-used", "stretched" }));

    addDescriptionTemplate("a ##Adjective## clothesline strung between posts");

    addItemTemplate(
        "A length of hemp rope is strung between two wooden posts, sagging "
        "slightly under the weight of drying laundry. Wooden pegs hold "
        "garments in place, and the fabric flutters and snaps in the breeze. "
        "A wicker basket sits on the ground beneath."
    );

    addSomeLightDescriptionTemplate(
        "a clothesline is strung between posts, laundry drying in the air"
    );
    addDimLightDescriptionTemplate(
        "pale shapes hang from a line, swaying gently in the breeze"
    );
    addLowLightDescriptionTemplate(
        "something pale flutters on a line overhead"
    );
    addNearDarkDescriptionTemplate(
        "the faint flutter of fabric suggests a clothesline nearby"
    );
}
