//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hoy");
    addAlias("coastal hoy");
    addAlias("small cargo ship");

    addAdjectives(({ "small", "broad-beamed", "coastal", "cargo", "single-masted" }));
    addDescriptionTemplate("a ##Adjective## hoy moored at the dock");

    addTimeOfDayDescription("dawn", ({
        ". The hoy is shrouded in mist, sail furled and ready",
        ". At dawn, crewmen check the rigging and inspect the hull",
        ". The small ship glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The hoy is loaded with goods, ready for a coastal voyage",
        ". Crewmen stow barrels and crates in the hold",
        ". The ship rocks gently at anchor, awaiting the tide"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the deck, warming the timbers",
        ". The hoy is a hive of activity, crew bustling about their duties",
        ". Sails are checked and the ship is prepared for departure"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The hoy glides through golden light, sail taut with wind",
        ". Crewmen rest in the shade of the rigging, the ship steady and swift",
        ". The ship's wake sparkles in the afternoon sun"
        }));
    addTimeOfDayDescription("evening", ({
        ". The hoy is bathed in sunset hues, sail glowing orange and pink",
        ". Lanterns are lit along the deck as the day winds down",
        ". The ship is quiet, crew gathered for the evening meal"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The hoy is a dark silhouette against the fading sky",
        ". The air cools, and the ship is readied for the night watch",
        ". The last light glints off the polished wood"
        }));
    addTimeOfDayDescription("night", ({
        ". The hoy is quiet, lanterns glowing softly along the deck",
        ". The ship rocks gently at anchor, crew asleep below",
        ". Only the sound of water and creaking timbers breaks the silence"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh rigging for the season's first voyage",
        " as the hoy is loaded with spring goods and supplies",
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
        " with the hoy moored for repairs, sail furled tight",
        " as the deck is rimed with frost and the crew huddles below",
        " with the ship standing silent through the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a hoy is barely visible at anchor"
    );
    addLowLightDescriptionTemplate(
        "a hoy sits in the harbor, its mast and rigging shadowy"
    );
    addDimLightDescriptionTemplate(
        "a small hoy, sail furled, rocks gently in the harbor"
    );
    addSomeLightDescriptionTemplate(
        "a hoy with a single mast and broad hull is ready for sea"
    );
    addItemTemplate(
        "The hoy is a small, broad-beamed coastal cargo vessel with a single "
        "mast and fore-and-aft sail. Its deck is loaded with barrels and "
        "crates, and the hull is built for short journeys along the coast. "
        "The ship is marked with the insignia of its home port."
    );
}
