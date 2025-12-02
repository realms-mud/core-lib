//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crow's nest");
    addAdjectives(({ "high", "wooden", "perched", "lookout", "circular" }));

    addDescriptionTemplate("a ##Adjective## crow's nest atop the main mast");

    addTimeOfDayDescription("dawn", ({
        ". The crow's nest is shrouded in mist, high above the deck",
        ". At dawn, the lookout scans the horizon for sails",
        ". The wood is cool and damp as the sun rises"
        }));
    addTimeOfDayDescription("noon", ({
        ". The crow's nest basks in the midday sun, offering a clear view",
        ". The lookout shields their eyes from the glare",
        ". The nest sways gently as the ship moves"
        }));
    addTimeOfDayDescription("night", ({
        ". The crow's nest is barely visible in the darkness",
        ". The air is cool, and the lookout stands watch under the stars",
        ". Lanterns below cast faint light up the mast"
        }));

    addSeasonDescription("spring", ({
        " with the crow's nest freshly cleaned for the new season",
        " as the lookout keeps watch for the first ships of spring",
        " with the air fresh and the nest ready for duty"
        }));
    addSeasonDescription("summer", ({
        " with the crow's nest in constant use, lookout scanning the horizon",
        " as the sun beats down, the nest is a breezy perch",
        " with the air thick with the scent of salt and tar"
        }));
    addSeasonDescription("autumn", ({
        " with the crow's nest checked for wear before winter",
        " as the air turns crisp and the lookout wraps up warm",
        " with the deck quieter, but the nest still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the crow's nest rimed with frost, wood stiff with cold",
        " as only the hardiest sailors brave the chill to climb it",
        " with the nest empty, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a crow's nest perches atop the mast, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a crow's nest glints in the faint light, high above the deck"
    );
    addDimLightDescriptionTemplate(
        "a wooden crow's nest sits atop the mast, ready for a lookout"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept crow's nest perches high above the deck"
    );
}
