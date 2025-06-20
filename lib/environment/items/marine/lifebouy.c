//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lifebuoy");
    addAdjectives(({ "bright", "painted", "ring-shaped", "safety", "floating" }));

    addDescriptionTemplate("a ##Adjective## lifebuoy hanging from a post at the dock's edge");

    addTimeOfDayDescription("dawn", ({
        ". The lifebuoy hangs on its post, dew beading on the painted surface",
        ". At dawn, the lifebuoy is checked by the harbormaster",
        ". The ring glistens as the sun rises over the water"
        }));
    addTimeOfDayDescription("night", ({
        ". The lifebuoy is barely visible in the darkness",
        ". The air is cool, and the lifebuoy hangs ready for emergency",
        ". Lanterns cast dim light on the ring, its shape easy to spot"
        }));
    addTimeOfDayDescription("evening", ({
        ". The lifebuoy is checked as dusk falls, ready for use",
        ". The ring's paint glows in the fading light",
        ". The air is filled with the scent of salt and rope"
        }));

    addSeasonDescription("spring", ({
        " with the lifebuoy freshly painted for the new season",
        " as the ring is checked after winter storms",
        " with the air fresh and the lifebuoy hanging ready"
        }));
    addSeasonDescription("summer", ({
        " with the lifebuoy in constant use, drying quickly in the sun",
        " as the sun warms the dock, the ring is a common sight",
        " with the air thick with the scent of salt and rope"
        }));
    addSeasonDescription("autumn", ({
        " with the lifebuoy shining through drifting fog",
        " as the air turns crisp and the ring is checked for wear",
        " with the dock quieter, but the lifebuoy still hangs ready"
        }));
    addSeasonDescription("winter", ({
        " with the lifebuoy rimed with frost, rope stiff with cold",
        " as only the hardiest workers brave the chill to check the ring",
        " with the lifebuoy hanging through the long, dark nights"
        }));

    addNearDarkDescriptionTemplate(
        "a lifebuoy hangs from a post at the dock's edge"
    );
    addLowLightDescriptionTemplate(
        "a lifebuoy is visible in the gloom, its paint bright"
    );
    addDimLightDescriptionTemplate(
        "a sturdy lifebuoy hangs ready, rope coiled beside it"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept lifebuoy hangs from a post, ready for emergency"
    );
}
