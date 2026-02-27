//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ladder");
    addAlias("wooden ladder");
    addAlias("step ladder");

    addAdjectives(({ "wooden", "tall", "rickety", "sturdy", "weathered",
        "leaning", "rough-hewn", "splinter-ridden", "long", "old" }));

    addDescriptionTemplate("a ##Adjective## ladder leaning against the wall");

    addItemTemplate(
        "The ladder is a simple affair of two long rails with rungs pegged "
        "between them. The wood is weathered and the rungs are worn thin "
        "in the middle from years of climbing boots. It leans at a "
        "precarious angle against the wall."
    );

    addSomeLightDescriptionTemplate(
        "a wooden ladder leans against the wall, its rungs worn with use"
    );
    addDimLightDescriptionTemplate(
        "a ladder leans against the wall, its rungs casting thin shadows"
    );
    addLowLightDescriptionTemplate(
        "a long shape leans diagonally against the wall"
    );
    addNearDarkDescriptionTemplate(
        "something long and narrow leans against the wall nearby"
    );
}
