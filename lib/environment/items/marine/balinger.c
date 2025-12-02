//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("balinger");
    addAdjectives(({ "small", "sturdy", "coastal", "single-masted", "medieval" }));

    addDescriptionTemplate("a ##Adjective## balinger with a single mast and square sail");

    addTimeOfDayDescription("dawn", ({
        ". The balinger is shrouded in mist, sail furled and ready",
        ". At dawn, crewmen check the rigging and inspect the hull",
        ". The small ship glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The balinger is loaded with goods, ready for a coastal voyage",
        ". Crewmen stow barrels and crates in the hold",
        ". The ship rocks gently at anchor, awaiting the tide"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the deck, warming the timbers",
        ". The balinger is a hive of activity, crew bustling about their duties",
        ". Sails are checked and the ship is prepared for departure"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh rigging for the season's first voyage",
        " as the balinger is loaded with spring goods and supplies",
        " with the air alive with the promise of adventure"
        }));
    addSeasonDescription("summer", ({
        " with the sun high overhead, sail bright against the blue sky",
        " as the ship is busy with trade and travel",
        " with the deck bustling and the air thick with salt and tar"
        }));
    addSeasonDescription("autumn", ({
        " with the crew preparing for storms and shorter days",
        " as the ship is loaded with the last cargoes before winter",
        " with the air crisp and the sail trimmed for strong winds"
        }));
    addSeasonDescription("winter", ({
        " with the balinger moored for repairs, sail furled tight",
        " as the deck is rimed with frost and the crew huddles below",
        " with the ship standing silent through the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a balinger is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a balinger sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a small balinger, sail furled, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made balinger is tied to the dock, ready for use"
    );
}
