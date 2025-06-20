//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("caravel");
    addAlias("exploration caravel");
    addAlias("ship");

    addAdjectives(({ "sleek", "lateen-rigged", "exploration", "two-masted", "fast" }));
    addDescriptionTemplate("a ##Adjective## caravel with lateen sails and a high stern");

    addTimeOfDayDescription("dawn", ({
        ". The caravel is shrouded in mist, sails furled and ready",
        ". At dawn, crewmen check the rigging and inspect the hull",
        ". The sleek ship glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The caravel is loaded with supplies, ready for a long voyage",
        ". Crewmen stow barrels and crates in the hold",
        ". The ship rocks gently at anchor, awaiting the tide"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the deck, warming the timbers",
        ". The caravel is a hive of activity, crew bustling about their duties",
        ". Sails are checked and the ship is prepared for departure"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The caravel glides through golden light, sails taut with wind",
        ". Crewmen rest in the shade of the rigging, the ship steady and swift",
        ". The ship's wake sparkles in the afternoon sun"
        }));
    addTimeOfDayDescription("evening", ({
        ". The caravel is bathed in sunset hues, sails glowing orange and pink",
        ". Lanterns are lit along the deck as the day winds down",
        ". The ship is quiet, crew gathered for the evening meal"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The caravel is a dark silhouette against the fading sky",
        ". The air cools, and the ship is readied for the night watch",
        ". The last light glints off the polished wood"
        }));
    addTimeOfDayDescription("night", ({
        ". The caravel is quiet, lanterns glowing softly along the deck",
        ". The ship rocks gently at anchor, crew asleep below",
        ". Only the sound of water and creaking timbers breaks the silence"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh rigging for the season's first voyage",
        " as the caravel is loaded with spring goods and supplies",
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
        " with the caravel moored for repairs, sails furled tight",
        " as the deck is rimed with frost and the crew huddles below",
        " with the ship standing silent through the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a caravel is barely visible at anchor"
    );
    addLowLightDescriptionTemplate(
        "a caravel sits in the harbor, its masts and rigging shadowy"
    );
    addDimLightDescriptionTemplate(
        "a sleek caravel, sails furled, rocks gently in the harbor"
    );
    addSomeLightDescriptionTemplate(
        "a caravel with lateen sails and a high stern is ready for sea"
    );
    addItemTemplate(
        "The caravel is a sleek, two- or three-masted ship with lateen sails "
        "and a high stern. Its deck is busy with crew, and the ship is built "
        "for speed and exploration. The hull is painted in bold colors, and "
        "the ship is marked with the insignia of its home port."
    );
}
