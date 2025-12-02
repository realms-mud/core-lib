//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("carrack");
    addAlias("merchant carrack");
    addAlias("ship");

    addAdjectives(({ "large", "high-sided", "merchant", "multi-masted", "ocean-going" }));
    addDescriptionTemplate("a ##Adjective## carrack with high fore and aft castles");

    addTimeOfDayDescription("dawn", ({
        ". The carrack is shrouded in mist, sails furled and ready",
        ". At dawn, crewmen check the rigging and inspect the hull",
        ". The high-sided ship glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The carrack is loaded with goods, ready for a long voyage",
        ". Crewmen stow barrels and crates in the hold",
        ". The ship rocks gently at anchor, awaiting the tide"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the deck, warming the timbers",
        ". The carrack is a hive of activity, crew bustling about their duties",
        ". Sails are checked and the ship is prepared for departure"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The carrack glides through golden light, sails taut with wind",
        ". Crewmen rest in the shade of the rigging, the ship steady and swift",
        ". The ship's wake sparkles in the afternoon sun"
        }));
    addTimeOfDayDescription("evening", ({
        ". The carrack is bathed in sunset hues, sails glowing orange and pink",
        ". Lanterns are lit along the deck as the day winds down",
        ". The ship is quiet, crew gathered for the evening meal"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The carrack is a dark silhouette against the fading sky",
        ". The air cools, and the ship is readied for the night watch",
        ". The last light glints off the polished wood"
        }));
    addTimeOfDayDescription("night", ({
        ". The carrack is quiet, lanterns glowing softly along the deck",
        ". The ship rocks gently at anchor, crew asleep below",
        ". Only the sound of water and creaking timbers breaks the silence"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh rigging for the season's first voyage",
        " as the carrack is loaded with spring goods and supplies",
        " with the air alive with the promise of adventure"
        }));
    addSeasonDescription("summer", ({
        " with the sun high overhead, sails bright against the blue sky",
        " as the ship is busy with trade and exploration",
        " with the deck bustling and the air thick with salt and tar"
        }));
    addSeasonDescription("autumn", ({
        " with the crew preparing for storms and shorter days",
        " as the ship is loaded with the last cargoes before winter",
        " with the air crisp and the sails trimmed for strong winds"
        }));
    addSeasonDescription("winter", ({
        " with the carrack moored for repairs, sails furled tight",
        " as the deck is rimed with frost and the crew huddles below",
        " with the ship standing silent through the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a carrack is barely visible at anchor"
    );
    addLowLightDescriptionTemplate(
        "a carrack sits in the harbor, its masts and rigging shadowy"
    );
    addDimLightDescriptionTemplate(
        "a high-sided carrack, sails furled, rocks gently in the harbor"
    );
    addSomeLightDescriptionTemplate(
        "a carrack with high fore and aft castles is ready for sea"
    );
    addItemTemplate(
        "The carrack is a large, high-sided merchant ship with three or four "
        "masts and a mix of square and lateen sails. Its deck is busy with "
        "crew, and the ship is built for long ocean voyages. The hull is "
        "painted in bold colors, and the ship is marked with the insignia of "
        "its home port."
    );
}
