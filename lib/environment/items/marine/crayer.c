//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crayer");
    addAlias("coastal crayer");
    addAlias("trading vessel");

    addAdjectives(({ "small", "broad", "coastal", "trading", "single-masted" }));
    addDescriptionTemplate("a ##Adjective## crayer loaded with coastal cargo");

    addTimeOfDayDescription("dawn", ({
        ". The crayer is shrouded in mist, sail furled and ready",
        ". At dawn, crewmen check the rigging and inspect the hull",
        ". The small ship glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The crayer is loaded with goods, ready for a coastal voyage",
        ". Crewmen stow barrels and crates in the hold",
        ". The ship rocks gently at anchor, awaiting the tide"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the deck, warming the timbers",
        ". The crayer is a hive of activity, crew bustling about their duties",
        ". Sails are checked and the ship is prepared for departure"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The crayer glides through golden light, sail taut with wind",
        ". Crewmen rest in the shade of the rigging, the ship steady and swift",
        ". The ship's wake sparkles in the afternoon sun"
        }));
    addTimeOfDayDescription("evening", ({
        ". The crayer is bathed in sunset hues, sail glowing orange and pink",
        ". Lanterns are lit along the deck as the day winds down",
        ". The ship is quiet, crew gathered for the evening meal"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The crayer is a dark silhouette against the fading sky",
        ". The air cools, and the ship is readied for the night watch",
        ". The last light glints off the polished wood"
        }));
    addTimeOfDayDescription("night", ({
        ". The crayer is quiet, lanterns glowing softly along the deck",
        ". The ship rocks gently at anchor, crew asleep below",
        ". Only the sound of water and creaking timbers breaks the silence"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh rigging for the season's first voyage",
        " as the crayer is loaded with spring goods and supplies",
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
        " with the crayer moored for repairs, sail furled tight",
        " as the deck is rimed with frost and the crew huddles below",
        " with the ship standing silent through the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a crayer is barely visible at anchor"
    );
    addLowLightDescriptionTemplate(
        "a crayer sits in the harbor, its mast and rigging shadowy"
    );
    addDimLightDescriptionTemplate(
        "a small crayer, sail furled, rocks gently in the harbor"
    );
    addSomeLightDescriptionTemplate(
        "a crayer with a single mast and broad hull is ready for sea"
    );
    addItemTemplate(
        "The crayer is a small, broad-beamed coastal trading vessel with a "
        "single mast and square sail. Its deck is loaded with barrels and "
        "crates, and the hull is built for short journeys along the coast. "
        "The ship is marked with the insignia of its home port."
    );
}
