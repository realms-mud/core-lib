//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ship's bell");
    addAdjectives(({ "brass", "polished", "engraved", "heavy", "ringing" }));

    addDescriptionTemplate("a ##Adjective## ship's bell mounted on a wooden frame");

    addTimeOfDayDescription("dawn", ({
        ". The bell glistens with dew, ready to mark the start of the watch",
        ". At dawn, the bell rings out over the quiet harbor",
        ". The brass is cool to the touch as the sun rises"
        }));
    addTimeOfDayDescription("noon", ({
        ". The bell gleams in the midday sun, its sound clear and bright",
        ". The deck bustles as the bell marks the change of watch",
        ". The bell's chime echoes across the water"
        }));
    addTimeOfDayDescription("night", ({
        ". The bell is silent, only faintly lit by lanterns",
        ". The air is cool, and the bell stands ready to sound the hour",
        ". Shadows flicker across the bell in the night breeze"
        }));

    addSeasonDescription("spring", ({
        " with the bell freshly polished for the new season",
        " as the bell is checked after winter storms",
        " with the air fresh and the bell ready to ring"
        }));
    addSeasonDescription("summer", ({
        " with the bell in constant use, warm from the sun",
        " as the sun beats down, the bell is a focal point on deck",
        " with the air thick with the scent of salt and brass"
        }));
    addSeasonDescription("autumn", ({
        " with the bell polished for the last voyages before winter",
        " as the air turns crisp and the bell is checked for cracks",
        " with the deck quieter, but the bell still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the bell rimed with frost, brass stiff with cold",
        " as only the hardiest sailors brave the chill to ring it",
        " with the bell covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a ship's bell hangs from a frame, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a ship's bell glints in the faint light, brass shining"
    );
    addDimLightDescriptionTemplate(
        "a sturdy ship's bell hangs from a wooden frame, ready to ring"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept ship's bell hangs at the bow, ready to sound the hour"
    );
}
