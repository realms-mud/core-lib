//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bread oven");
    addAlias("baking oven");
    addAlias("stone oven");
    addAlias("oven");

    addAdjectives(({ "brick", "domed", "hot", "massive", "soot-blackened",
        "fragrant", "well-used", "ancient", "clay", "crackling" }));

    addDescriptionTemplate("a ##Adjective## bread oven built into the wall");

    addItemTemplate(
        "The bread oven is a domed chamber of thick firebrick built into "
        "the wall, its iron door blackened and warped by years of intense "
        "heat. The bricks around the opening are cracked and repaired in "
        "places, and the air around it shimmers with radiant warmth. The "
        "wonderful aroma of baking bread permeates everything."
    );

    addSomeLightDescriptionTemplate(
        "a bread oven radiates warmth from behind its iron door, the air "
        "fragrant with baking"
    );
    addDimLightDescriptionTemplate(
        "a domed brick oven is built into the wall, warmth radiating from "
        "its door"
    );
    addLowLightDescriptionTemplate(
        "a warm glow seeps from a domed structure in the wall"
    );
    addNearDarkDescriptionTemplate(
        "intense warmth and the aroma of baking bread emanate from the wall"
    );
}
