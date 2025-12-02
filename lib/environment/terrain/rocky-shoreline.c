//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rocky shoreline");

    addAdjectives(({
        "rocky shoreline with jagged stones and tide pools",
        "windswept coast where waves crash against boulders",
        "shoreline strewn with driftwood and slick rocks",
        "craggy beach where sea spray mists the air",
        "rugged coastline with barnacle-encrusted stones",
        "shoreline where gulls wheel above the surf",
        "rock-strewn shore with hidden crevices and pools",
        "coastline where the land meets the sea in a tumble of rocks",
        "shoreline where kelp clings to the rocks at low tide",
        "wild shore where the sound of the surf is ever-present"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the pink glow of sunrise",
        " where the first light glistens on wet stones",
        " as seabirds call to greet the day"
        }));

    addTimeOfDayDescription("morning", ({
        " with the sun rising over the waves",
        " as the tide recedes, revealing new pools",
        " where the air is fresh with the scent of salt"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the rocks are warm and the sea sparkles",
        " as the surf pounds steadily against the shore"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the water",
        " with long shadows stretching over the rocks",
        " where the wind picks up, sending spray inland"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the golden light of sunset",
        " as the tide returns and the rocks grow slick",
        " where the sky is painted in hues of orange and purple"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the sound of waves",
        " where the rocks are cool and the air is damp",
        " as the moonlight glints off the wet stones"
        }));

    addSeasonDescription("winter", ({
        " battered by cold winds and crashing waves",
        " where ice sometimes forms on the rocks",
        " as storms lash the coastline"
        }));

    addSeasonDescription("spring", ({
        " with new seaweed growing in the pools",
        " as migratory birds return to the shore",
        " where the air is brisk and the sea lively"
        }));

    addSeasonDescription("summer", ({
        " at its warmest, with sunbathers on the rocks",
        " where the tide pools teem with life",
        " as the sea sparkles under a clear sky"
        }));

    addSeasonDescription("autumn", ({
        " with cooler winds and rougher seas",
        " as the shoreline is strewn with fallen leaves and driftwood",
        " where the sunsets are especially vivid"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy rocky shoreline where only the sound of waves reveals the coast");
    addLowLightDescriptionTemplate("a barely-lit rocky shoreline where boulders are little more than shapes in the gloom");
    addDimLightDescriptionTemplate("a dimly-lit rocky shoreline where the surf glows faintly in the darkness");
    addSomeLightDescriptionTemplate("a sunlit rocky shoreline where every stone and pool is clear");
}
