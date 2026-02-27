//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("candle mold");
    addAlias("mold rack");
    addAlias("dipping frame");
    addAlias("chandler mold");

    addAdjectives(({ "tin", "multi-wicked", "wax-coated", "well-used",
        "clustered", "hanging", "functional", "old", "dripping", "neat" }));

    addDescriptionTemplate("a ##Adjective## candle mold with wicks strung through");

    addItemTemplate(
        "The candle mold is a rack of tin tubes arranged in neat rows, "
        "each with a wick strung through its center. Melted wax is poured "
        "into the tubes and left to cool, producing uniform taper candles. "
        "Drips of hardened wax coat every surface, and the warm, honeyed "
        "smell of beeswax fills the air."
    );

    addSomeLightDescriptionTemplate(
        "a candle mold sits on the bench, its tin tubes filled with cooling "
        "wax"
    );
    addDimLightDescriptionTemplate(
        "a rack of small tubes coated in wax is visible on the bench"
    );
    addLowLightDescriptionTemplate(
        "a rack of small cylindrical shapes sits on the bench"
    );
    addNearDarkDescriptionTemplate(
        "the warm smell of beeswax and tallow fills the air"
    );
}
