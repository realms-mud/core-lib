//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("anchor");
    addAdjectives(({ "heavy", "iron", "rusted", "massive", "fluked" }));

    addDescriptionTemplate("a ##Adjective## anchor with thick chains coiled nearby");

    addTimeOfDayDescription("dawn", ({
        ". The anchor is slick with dew, iron glinting in the early light",
        ". At dawn, the anchor rests on the dock, ready for use",
        ". The chain clinks softly as the tide shifts"
        }));
    addTimeOfDayDescription("noon", ({
        ". The anchor is warm from the sun, iron dark against the planks",
        ". Dockhands check the anchor before departure",
        ". The anchor's flukes are caked with dried mud"
        }));
    addTimeOfDayDescription("night", ({
        ". The anchor is barely visible in the darkness",
        ". The air is cool, and the anchor is cold to the touch",
        ". Lanterns cast dim light on the anchor, its shape easy to spot"
        }));

    addSeasonDescription("spring", ({
        " with the anchor freshly cleaned for the new season",
        " as the iron is checked after winter storms",
        " with the air fresh and the anchor gleaming in the sun"
        }));
    addSeasonDescription("summer", ({
        " with the anchor in constant use, chain clinking on the dock",
        " as the sun warms the iron, the anchor is a common sight",
        " with the air thick with the scent of salt and rust"
        }));
    addSeasonDescription("autumn", ({
        " with the anchor shining through drifting fog",
        " as the air turns crisp and the iron is checked for rust",
        " with the dock quieter, but the anchor still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the anchor rimed with frost, iron stiff with cold",
        " as only the hardiest workers brave the chill to move the anchor",
        " with the anchor gleaming through the long, dark nights"
        }));

    addNearDarkDescriptionTemplate(
        "an anchor rests on the dock, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "an anchor glints in the faint light, chain coiled beside it"
    );
    addDimLightDescriptionTemplate(
        "a heavy iron anchor lies on the dock, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept anchor rests on the dock, chain coiled nearby"
    );
}
