//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("flour sack");
    addAlias("sack of flour");
    addAlias("flour bag");

    addAdjectives(({ "bulging", "white-dusted", "heavy", "canvas",
        "tied", "full", "stacked", "powdery", "sagging", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## flour sack propped against the wall");

    addItemTemplate(
        "The flour sack is a heavy canvas bag tied shut with twine, its "
        "exterior powdered white from the fine flour within. It sags under "
        "its own weight, and a small drift of flour has escaped from a "
        "seam to dust the floor around it."
    );

    addSomeLightDescriptionTemplate(
        "a flour sack leans against the wall, white with powder"
    );
    addDimLightDescriptionTemplate(
        "a pale, sagging sack leans against the wall"
    );
    addLowLightDescriptionTemplate(
        "a pale lumpy shape leans against the wall"
    );
    addNearDarkDescriptionTemplate(
        "the dusty scent of flour comes from nearby"
    );
}
