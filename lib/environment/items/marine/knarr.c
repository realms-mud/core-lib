//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("knarr");
    addAlias("viking knarr");
    addAlias("cargo ship");

    addAdjectives(({ "broad-beamed", "viking", "cargo", "single-masted", "sturdy" }));
    addDescriptionTemplate("a ##Adjective## knarr with a single square sail and deep hold");

    addTimeOfDayDescription("dawn", ({
        ". The knarr is shrouded in mist, sail furled and cargo lashed tight",
        ". At dawn, crewmen check the ropes and inspect the hull",
        ". The broad-beamed ship glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The knarr is loaded with goods, ready for a long voyage",
        ". Crewmen stow barrels and crates in the hold",
        ". The ship rocks gently at anchor, awaiting the tide"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the deck, warming the timbers",
        ". The knarr is a hive of activity, crew bustling about their duties",
        ". Sails are checked and the ship is prepared for departure"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The knarr glides through golden light, sail taut with wind",
        ". Crewmen rest in the shade of the cargo, the ship steady and slow",
        ". The ship's wake sparkles in the afternoon sun"
        }));
    addTimeOfDayDescription("evening", ({
        ". The knarr is bathed in sunset hues, sail glowing orange and pink",
        ". Lanterns are lit along the deck as the day winds down",
        ". The ship is quiet, crew gathered for the evening meal"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The knarr is a dark silhouette against the fading sky",
        ". The air cools, and the ship is readied for the night watch",
        ". The last light glints off the cargo lashed to the deck"
        }));
    addTimeOfDayDescription("night", ({
        ". The knarr is quiet, lanterns glowing softly along the deck",
        ". The ship rocks gently at anchor, crew asleep below",
        ". Only the sound of water and creaking timbers breaks the silence"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first voyage",
        " as the knarr is loaded with spring goods and supplies",
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
        " with the knarr moored for repairs, sail furled tight",
        " as the deck is rimed with frost and the crew huddles below",
        " with the ship standing silent through the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a knarr is barely visible at anchor"
    );
    addLowLightDescriptionTemplate(
        "a knarr sits in the harbor, its mast and cargo shadowy"
    );
    addDimLightDescriptionTemplate(
        "a broad-beamed knarr, sail furled, rocks gently in the harbor"
    );
    addSomeLightDescriptionTemplate(
        "a knarr with a single square sail and broad hull is ready for sea"
    );
    addItemTemplate(
        "The knarr is a broad-beamed, single-masted cargo ship with a square "
        "sail. Its deck is loaded with barrels and crates, and the hull is "
        "built for long voyages across open water. The ship is marked with "
        "runic carvings and the insignia of its home port."
    );
}
