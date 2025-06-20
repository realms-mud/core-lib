//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fishing hut");
    addAdjectives(({ "small", "weathered", "wooden", "shingled", "coastal" }));

    addDescriptionTemplate("a ##Adjective## fishing hut with nets and gear piled outside");

    addTimeOfDayDescription("dawn", ({
        ". The hut is damp with dew, smoke rising from a small chimney",
        ". At dawn, fishermen gather outside, preparing for the day",
        ". The wood is cool and the air smells of salt and fish"
        }));
    addTimeOfDayDescription("noon", ({
        ". The hut is warm from the sun, door propped open",
        ". Nets and baskets are piled outside, drying in the light",
        ". The hut is busy with the sounds of cleaning and sorting fish"
        }));
    addTimeOfDayDescription("night", ({
        ". The hut is dark, only faintly lit by lanterns inside",
        ". The air is cool, and the hut is quiet after a long day",
        ". Smoke drifts from the chimney as the fishermen rest"
        }));

    addSeasonDescription("spring", ({
        " with the hut freshly repaired for the new season",
        " as the roof is checked after winter storms",
        " with the air fresh and the hut ready for work"
        }));
    addSeasonDescription("summer", ({
        " with the hut in constant use, nets drying in the sun",
        " as the sun beats down, the hut is a common sight",
        " with the air thick with the scent of fish and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the hut checked for leaks before winter",
        " as the air turns crisp and the roof is retarred",
        " with the beach quieter, but the hut still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the hut rimed with frost, wood stiff with cold",
        " as only the hardiest fishermen brave the chill to work",
        " with the hut shuttered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a fishing hut stands by the shore, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a fishing hut glints in the faint light, nets piled outside"
    );
    addDimLightDescriptionTemplate(
        "a weathered fishing hut stands by the water, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept fishing hut stands by the shore, nets drying outside"
    );
}
