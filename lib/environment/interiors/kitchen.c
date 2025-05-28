//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("kitchen");

    addAdjectives(({
        "spacious kitchen with a massive hearth and rows of hanging copper pots",
        "bustling kitchen where cooks prepare feasts on long wooden tables",
        "warm chamber filled with the aroma of baking bread and roasting meat",
        "stone-walled kitchen with shelves lined with jars of herbs and spices",
        "busy kitchen where servants hurry between simmering cauldrons and ovens",
        "well-stocked kitchen with barrels of flour and baskets of fresh produce",
        "noisy kitchen where knives chop, spoons stir, and fires crackle",
        "high-ceilinged kitchen with smoke-blackened beams and drying herbs",
        "orderly kitchen where the head cook oversees every detail of the meal",
        "ancient kitchen where soot stains the walls and the floor is worn smooth"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy kitchen where only the faint glow of embers in the hearth "
        "reveals the outlines of tables and hanging pots"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit kitchen, where the flicker of firelight casts long shadows "
        "across stone walls and wooden worktables"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the glow from the hearth and lanterns "
        "revealing shelves of ingredients and the gleam of copper cookware"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through high windows to "
        "illuminate the busy worktables, hanging herbs, and bustling cooks"
    );
}
