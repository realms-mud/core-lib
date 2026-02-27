//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stocks");
    addAlias("pillory");
    addAlias("punishment stocks");

    addAdjectives(({ "wooden", "weathered", "stained", "grim", "old",
        "heavy", "iron-hinged", "splinter-ridden", "sturdy", "ominous" }));

    addDescriptionTemplate("a ##Adjective## set of stocks for public punishment");

    addItemTemplate(
        "The stocks are a heavy wooden frame with hinged boards cut with "
        "holes for the head and hands. The wood is darkened with age and "
        "stained by the indignities visited upon its occupants. Iron hinges "
        "and a heavy padlock secure the upper board. The ground in front "
        "is littered with the dried remains of thrown produce."
    );

    addSomeLightDescriptionTemplate(
        "a set of wooden stocks stands in the open, mercifully empty"
    );
    addDimLightDescriptionTemplate(
        "the grim shape of punishment stocks is visible, its holes gaping"
    );
    addLowLightDescriptionTemplate(
        "a heavy wooden frame with holes suggests a set of stocks"
    );
    addNearDarkDescriptionTemplate(
        "a dark heavy shape low to the ground has a distinctly ominous feel"
    );
}
