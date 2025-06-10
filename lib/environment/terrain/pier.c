//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pier");

    addAdjectives(({
        "wooden pier stretching out over the water",
        "weathered pier with creaking planks",
        "medieval pier lined with moored fishing boats",
        "busy pier where merchants unload their wares",
        "quiet pier where gulls wheel overhead",
        "pier with ropes and barrels scattered about",
        "salt-stained pier with nets hanging to dry",
        "pier where the scent of fish and brine fills the air",
        "old pier with lanterns swaying in the breeze",
        "pier bustling with townsfolk and sailors"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the soft light of sunrise",
        " where fishermen prepare their boats for the day",
        " as the water glows with the first light"
        }));

    addTimeOfDayDescription("morning", ({
        " alive with the bustle of merchants and sailors",
        " as the sun rises over the harbor",
        " where the air is filled with the sound of gulls"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the planks are warm and the water sparkles",
        " as ships come and go from the docks"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the water",
        " with long shadows stretching over the pier",
        " where the breeze carries the scent of salt and fish"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the pier quiets and the lanterns are lit",
        " where the sky is painted in hues of orange and gold"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the sound of gentle waves",
        " where the pier is quiet and the water is dark",
        " as lanterns cast pools of light on the planks"
        }));

    addSeasonDescription("winter", ({
        " battered by cold winds and icy spray",
        " where the pier is slick with frost"
        }));

    addSeasonDescription("spring", ({
        " with new boats arriving and the air brisk",
        " as fishermen prepare for the season's catch"
        }));

    addSeasonDescription("summer", ({
        " at its busiest, with ships and townsfolk everywhere",
        " where the sun is hot and the water inviting"
        }));

    addSeasonDescription("autumn", ({
        " with cooler breezes and quieter docks",
        " as the fishing season draws to a close"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy pier where only the lanterns and the sound of water reveal its presence");
    addLowLightDescriptionTemplate("a barely-lit pier where the planks are little more than a pale blur");
    addDimLightDescriptionTemplate("a dimly-lit pier where the water glows faintly in the darkness");
    addSomeLightDescriptionTemplate("a sunlit pier where every boat and barrel is clear");
}
