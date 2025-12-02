//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small frigate");
    addAlias("frigate");
    addAlias("ship");

    addAdjectives(({ "sleek", "two-masted", "armed", "naval", "fast" }));
    addDescriptionTemplate("a ##Adjective## small frigate with crisp sails and cannons");

    addTimeOfDayDescription("dawn", ({
        ". The small frigate is shrouded in morning mist, sails furled tight",
        ". At dawn, crewmen move quietly on deck, preparing for the day's voyage",
        ". The hull glistens with dew as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The frigate's sails are unfurled, catching the fresh morning breeze",
        ". Crewmen scrub the deck, their voices carrying over the water",
        ". The ship rocks gently at anchor, ready for orders"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the deck, warming the timbers",
        ". The frigate is a hive of activity, crew bustling about their duties",
        ". Sails billow as the ship prepares to leave the harbor"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The frigate glides through golden light, sails taut with wind",
        ". Crewmen rest in the shade of the rigging, the ship steady and swift",
        ". The ship's wake sparkles in the afternoon sun"
        }));
    addTimeOfDayDescription("evening", ({
        ". The frigate is bathed in sunset hues, sails glowing orange and pink",
        ". Lanterns are lit along the deck as the day winds down",
        ". The ship is quiet, crew gathered for the evening meal"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The frigate is a dark silhouette against the fading sky",
        ". The air cools, and the ship is readied for the night watch",
        ". The last light glints off the polished brass fittings"
        }));
    addTimeOfDayDescription("night", ({
        ". The frigate is quiet, lanterns glowing softly along the deck",
        ". The ship rocks gently at anchor, crew asleep below",
        ". Only the sound of water and creaking timbers breaks the silence"
        }));

    addSeasonDescription("spring", ({
        " with fresh paint and new sails for the season's first voyage",
        " as the crew prepares for long journeys and fair winds",
        " with the air alive with the promise of adventure"
        }));
    addSeasonDescription("summer", ({
        " with the sun high overhead, sails bright against the blue sky",
        " as the ship is busy with trade and patrols",
        " with the deck bustling and the air thick with salt and tar"
        }));
    addSeasonDescription("autumn", ({
        " with the crew preparing for storms and shorter days",
        " as the ship is loaded with the last cargoes before winter",
        " with the air crisp and the sails trimmed for strong winds"
        }));
    addSeasonDescription("winter", ({
        " with the frigate moored for repairs, sails furled tight",
        " as the deck is rimed with frost and the crew huddles below",
        " with the ship standing silent through the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a small frigate is barely visible at anchor"
    );
    addLowLightDescriptionTemplate(
        "a small frigate sits in the harbor, its masts and rigging shadowy"
    );
    addDimLightDescriptionTemplate(
        "a sleek small frigate, sails furled, rocks gently in the harbor"
    );
    addSomeLightDescriptionTemplate(
        "a small frigate with crisp sails and polished wood is ready for sea"
    );
    addItemTemplate(
        "The small frigate is a sleek, two-masted warship with crisp white "
        "sails and polished wood. Its deck is busy with crew, and the ship is "
        "armed with a row of cannons. The hull is painted in bold colors, and "
        "the figurehead at the prow is carved in the shape of a leaping dolphin. "
        ""
    );
}
