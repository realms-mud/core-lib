//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sandy shoreline");

    addAdjectives(({
        "sandy shoreline with gentle waves lapping at the beach",
        "broad stretch of golden sand meeting the sea",
        "sun-warmed beach where footprints mark the shore",
        "shoreline where dunes rise above the tideline",
        "coastline dotted with seashells and driftwood",
        "beach where the surf leaves foamy trails on the sand",
        "shoreline where seabirds hunt for food in the shallows",
        "open beach with soft sand and a salty breeze",
        "shore where the sun sparkles on wet sand",
        "peaceful shoreline where the sea meets the land"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the soft light of sunrise",
        " where the sand is cool and the air is fresh",
        " as the first waves wash away the night"
        }));

    addTimeOfDayDescription("morning", ({
        " with the sun rising over the water",
        " as the beach comes alive with birds and crabs",
        " where the sand glows in the morning light"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the sand is hot and the sea sparkles",
        " as the waves break gently on the shore"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the beach",
        " with long shadows stretching over the sand",
        " where the breeze carries the scent of salt and seaweed"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the tide comes in and the beach grows quiet",
        " where the sky is painted in hues of pink and gold"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the sound of gentle waves",
        " where the sand is cool and the air is still",
        " as the moonlight shimmers on the water"
        }));

    addSeasonDescription("winter", ({
        " with cold winds and empty beaches",
        " where the sand is damp and the sea is rough",
        " as storms sometimes lash the coast"
        }));

    addSeasonDescription("spring", ({
        " with new grasses sprouting on the dunes",
        " as shorebirds return to nest",
        " where the air is brisk and the sea lively"
        }));

    addSeasonDescription("summer", ({
        " at its warmest, with sunbathers and swimmers",
        " where the sand is hot and the water inviting",
        " as the beach is alive with activity"
        }));

    addSeasonDescription("autumn", ({
        " with cooler breezes and quieter shores",
        " as the beach is strewn with seaweed and shells",
        " where the sunsets are especially vivid"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy sandy shoreline where only the sound of waves reveals the beach");
    addLowLightDescriptionTemplate("a barely-lit sandy shoreline where the sand is little more than a pale blur");
    addDimLightDescriptionTemplate("a dimly-lit sandy shoreline where the surf glows faintly in the darkness");
    addSomeLightDescriptionTemplate("a sunlit sandy shoreline where every shell and ripple is clear");
}
