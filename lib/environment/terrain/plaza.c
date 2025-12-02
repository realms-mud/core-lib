//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("plaza");

    addAdjectives(({
        "broad stone plaza at the heart of the town",
        "open plaza surrounded by shops and taverns",
        "plaza paved with worn cobblestones",
        "bustling plaza where merchants set up their stalls",
        "quiet plaza with a central fountain",
        "plaza where townsfolk gather for festivals",
        "sunlit plaza where children play and dogs bark",
        "plaza lined with benches and flowerbeds",
        "market plaza filled with the scent of fresh bread",
        "plaza where the town crier announces the news"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the soft light of sunrise",
        " where the plaza is quiet and empty",
        " as the first merchants begin to set up"
        }));

    addTimeOfDayDescription("morning", ({
        " alive with the bustle of townsfolk and traders",
        " as the sun rises over the rooftops",
        " where the air is filled with the sounds of commerce"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the plaza is crowded and lively",
        " as the market is at its busiest"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the plaza",
        " with long shadows stretching over the stones",
        " where the air is filled with laughter and shouts"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the plaza quiets and the lanterns are lit",
        " where the sky is painted in hues of orange and gold"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the glow of lanterns",
        " where the plaza is quiet except for the distant sound of revelry",
        " as the stones are bathed in moonlight"
        }));

    addSeasonDescription("winter", ({
        " with snow dusting the stones and the air crisp and cold",
        " where the plaza is quieter and the market smaller"
        }));

    addSeasonDescription("spring", ({
        " with flower stalls and new leaves on the trees",
        " as the plaza comes alive with color and scent"
        }));

    addSeasonDescription("summer", ({
        " at its busiest, with festivals and open markets",
        " where the days are long and the air is warm"
        }));

    addSeasonDescription("autumn", ({
        " golden with falling leaves and harvest fairs",
        " as the plaza prepares for the coming winter"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy plaza where only the glow of lanterns reveals its presence");
    addLowLightDescriptionTemplate("a barely-lit plaza where the stones are little more than shapes in the gloom");
    addDimLightDescriptionTemplate("a dimly-lit plaza where the market stalls are painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit plaza where every stone and stall is clear");
}
