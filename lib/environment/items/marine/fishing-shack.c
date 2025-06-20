//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fishing shack");
    addAdjectives(({ "ramshackle", "wooden", "lean-to", "weathered", "coastal" }));

    addDescriptionTemplate("a ##Adjective## fishing shack patched with driftwood and tar");

    addTimeOfDayDescription("dawn", ({
        ". The shack is damp with dew, patched boards glistening",
        ". At dawn, fishermen gather outside, mending nets",
        ". The shack leans slightly, battered by wind and waves"
        }));
    addTimeOfDayDescription("noon", ({
        ". The shack is warm from the sun, door hanging open",
        ". Nets and baskets are piled outside, drying in the light",
        ". The shack is busy with the sounds of cleaning and sorting fish"
        }));
    addTimeOfDayDescription("night", ({
        ". The shack is dark, only faintly lit by lanterns inside",
        ". The air is cool, and the shack is quiet after a long day",
        ". The shack creaks in the night wind"
        }));

    addSeasonDescription("spring", ({
        " with the shack freshly patched for the new season",
        " as the roof is checked after winter storms",
        " with the air fresh and the shack ready for work"
        }));
    addSeasonDescription("summer", ({
        " with the shack in constant use, nets drying in the sun",
        " as the sun beats down, the shack is a common sight",
        " with the air thick with the scent of fish and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the shack checked for leaks before winter",
        " as the air turns crisp and the roof is retarred",
        " with the beach quieter, but the shack still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the shack rimed with frost, wood stiff with cold",
        " as only the hardiest fishermen brave the chill to work",
        " with the shack shuttered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a fishing shack stands by the shore, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a fishing shack glints in the faint light, nets piled outside"
    );
    addDimLightDescriptionTemplate(
        "a ramshackle fishing shack stands by the water, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a patched fishing shack stands by the shore, nets drying outside"
    );
}
