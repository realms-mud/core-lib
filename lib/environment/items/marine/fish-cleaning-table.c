//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fish cleaning table");
    addAdjectives(({ "sturdy", "well-used", "wooden", "slatted", "dockside" }));

    addDescriptionTemplate("a ##Adjective## fish cleaning table stained with scales and brine");

    addTimeOfDayDescription("dawn", ({
        ". The table is slick with dew, knives and scales glinting in the light",
        ". At dawn, fishermen gather to clean the morning's catch",
        ". The scent of fresh fish and salt fills the air"
        }));
    addTimeOfDayDescription("morning", ({
        ". The table is busy, fish being cleaned and sorted for market",
        ". Gulls gather nearby, hoping for scraps",
        ". The air is filled with the sound of knives on wood"
        }));
    addTimeOfDayDescription("noon", ({
        ". The table is washed down, sunlight drying the wet planks",
        ". The air is warm, and the table is covered in scales and water",
        ". Fishermen rest nearby, their work nearly done"
        }));

    addSeasonDescription("spring", ({
        " with the table cleaned for the new season's catch",
        " as the first fish of spring are cleaned and sorted",
        " with the air fresh and the table glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the table in constant use, drying quickly in the sun",
        " as the sun warms the dock, the table is a common sight",
        " with the air thick with the scent of fish and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the table packed for the last big catches before winter",
        " as the air turns crisp and the table is checked for wear",
        " with the dock quieter, but the table still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the table rimed with frost, wood stiff with cold",
        " as only the hardiest workers brave the chill to clean fish",
        " with the table stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a fish cleaning table stands at the dock's edge, barely visible"
    );
    addLowLightDescriptionTemplate(
        "a fish cleaning table glints in the faint light, knives on its surface"
    );
    addDimLightDescriptionTemplate(
        "a sturdy table is stained with scales and brine, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-used fish cleaning table stands at the dock, knives and scales ready"
    );
}
