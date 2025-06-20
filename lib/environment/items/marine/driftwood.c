//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("driftwood");
    addAdjectives(({ "bleached", "weathered", "smooth", "salt-stained", "twisted" }));

    addDescriptionTemplate("a ##Adjective## piece of driftwood washed up on the shore");

    addTimeOfDayDescription("dawn", ({
        ". The driftwood is damp with dew, pale in the morning light",
        ". At dawn, gulls perch on the driftwood, calling over the waves",
        ". The wood is cool and smooth to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The driftwood is warm from the sun, surface dry and cracked",
        ". The beach is quiet, driftwood scattered along the tide line",
        ". The wood is bleached almost white in the bright light"
        }));
    addTimeOfDayDescription("night", ({
        ". The driftwood is barely visible in the darkness",
        ". The air is cool, and the wood is damp with dew",
        ". Lanterns cast dim light on the driftwood, shadows flickering"
        }));

    addSeasonDescription("spring", ({
        " with the driftwood freshly washed ashore by spring tides",
        " as the wood is checked for shells and seaweed",
        " with the air fresh and the driftwood gleaming"
        }));
    addSeasonDescription("summer", ({
        " with the driftwood drying quickly in the sun",
        " as the sun beats down, the wood is a common sight",
        " with the air thick with the scent of salt and sand"
        }));
    addSeasonDescription("autumn", ({
        " with the driftwood scattered by autumn storms",
        " as the air turns crisp and the wood is piled by the tide",
        " with the beach quieter, but the driftwood still remains"
        }));
    addSeasonDescription("winter", ({
        " with the driftwood rimed with frost, wood stiff with cold",
        " as only the hardiest beachcombers brave the chill to collect it",
        " with the driftwood covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a piece of driftwood lies on the shore, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "driftwood glints in the faint light, surface pale and smooth"
    );
    addDimLightDescriptionTemplate(
        "a weathered piece of driftwood lies on the sand, ready for collection"
    );
    addSomeLightDescriptionTemplate(
        "a well-bleached piece of driftwood rests on the shore"
    );
}
