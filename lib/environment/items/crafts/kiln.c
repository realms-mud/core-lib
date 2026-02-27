//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("kiln");
    addAlias("pottery kiln");
    addAlias("firing kiln");
    addAlias("brick kiln");

    addAdjectives(({ "brick", "domed", "soot-blackened", "hot",
        "massive", "ancient", "thick-walled", "smoking", "sturdy",
        "heat-cracked" }));

    addDescriptionTemplate("a ##Adjective## kiln radiating heat");

    addItemTemplate(
        "The kiln is a domed structure of thick firebrick, its exterior "
        "blackened by years of firing. A heavy iron door seals the front, "
        "and a chimney vents smoke and heat from the top. Even when not "
        "in active use, the bricks radiate a lingering warmth. Shelves "
        "nearby hold finished pottery in various stages of glazing."
    );

    addSomeLightDescriptionTemplate(
        "a domed brick kiln radiates warmth, its chimney trailing wisps "
        "of smoke"
    );
    addDimLightDescriptionTemplate(
        "a domed brick structure radiates heat, its door glowing faintly"
    );
    addLowLightDescriptionTemplate(
        "a large domed shape radiates noticeable warmth"
    );
    addNearDarkDescriptionTemplate(
        "a faint glow and intense warmth emanate from a domed structure"
    );
}
