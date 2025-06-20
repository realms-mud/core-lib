//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tide marker");
    addAdjectives(({ "weathered", "carved", "stone", "measuring", "upright" }));

    addDescriptionTemplate("a ##Adjective## tide marker set at the water's edge");

    addTimeOfDayDescription("dawn", ({
        ". The tide marker is damp with dew, carvings clear in the light",
        ". At dawn, the marker casts a long shadow over the sand",
        ". The stone is cool to the touch as the sun rises"
        }));
    addTimeOfDayDescription("noon", ({
        ". The tide marker is warm from the sun, markings easy to read",
        ". The beach is quiet, the marker standing tall above the tide",
        ". The stone is bleached pale in the bright light"
        }));
    addTimeOfDayDescription("night", ({
        ". The tide marker is barely visible in the darkness",
        ". The air is cool, and the stone is damp with dew",
        ". Lanterns cast dim light on the marker, carvings faint"
        }));

    addSeasonDescription("spring", ({
        " with the marker freshly cleaned for the new season",
        " as the stone is checked after winter storms",
        " with the air fresh and the marker standing tall"
        }));
    addSeasonDescription("summer", ({
        " with the marker in constant use, readings taken daily",
        " as the sun beats down, the marker is a common sight",
        " with the air thick with the scent of salt and sand"
        }));
    addSeasonDescription("autumn", ({
        " with the marker checked for wear before winter",
        " as the air turns crisp and the stone is retouched",
        " with the beach quieter, but the marker still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the marker rimed with frost, stone stiff with cold",
        " as only the hardiest workers brave the chill to read it",
        " with the marker covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a tide marker stands at the water's edge, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a tide marker glints in the faint light, carvings visible"
    );
    addDimLightDescriptionTemplate(
        "a weathered tide marker stands upright, ready to measure the tide"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept tide marker stands at the water's edge"
    );
}
