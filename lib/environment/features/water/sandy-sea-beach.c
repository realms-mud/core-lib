//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sandy sea beach");
    addAdjectives(({ "pristine", "windswept", "endless", "sun-warmed", "glistening" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with sand just catching the faint dawn light",
        "reflecting the soft colors of sunrise",
        "emerging from the morning sea mist",
        "touched by the first rays of morning",
        "bathed in the pale light of dawn",
        "shimmering in the early morning glow"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on wet sand",
        "gleaming in the fresh morning air",
        "warming in the climbing sun",
        "bright with morning reflections",
        "sparkling with dew and sea spray"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "brilliant white in the noon sun",
        "radiating heat at midday",
        "dazzling in the intense sunlight",
        "stark and bright under the blazing sun",
        "shimmering with heat waves"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with footprints marking the warm sand",
        "basking in the afternoon warmth",
        "comfortable in the gentle afternoon sun",
        "dotted with afternoon beachcombers",
        "peaceful in the late day calm",
        "golden in the softening light"
        }));
    addTimeOfDayDescription("evening", ({
        "with sand glowing in the golden evening light",
        "as the sun sets over the water",
        "painted in sunset colors",
        "magnificent in the evening glow",
        "transformed by the golden hour",
        "romantic in the fading daylight"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming shadowy as dusk settles",
        "mysterious in the gathering twilight",
        "cool in the evening breeze",
        "peaceful as day turns to night",
        "serene in the deepening dusk"
        }));
    addTimeOfDayDescription("night", ({
        "outlined by moonlight on the waves",
        "discernable by the sound of surf",
        "silvered by the moon's reflection",
        "peaceful under the starry sky",
        "quiet save for the rhythm of waves",
        "mysterious in the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep shadows of night",
        "hidden in the darkness",
        "merged with the night sea",
        "invisible save for the sound of waves",
        "swallowed by midnight's embrace"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " scoured by winter storms",
        " scattered with storm debris", " lashed by fierce winter waves",
        " empty of summer visitors", " marked by high tide lines",
        " carved by powerful winter surf" }));
    addSeasonDescription("spring", ({ " dotted with early wildflowers",
        " visited by migrating shorebirds", " adorned with spring blossoms",
        " alive with returning wildlife", " decorated with sea shells",
        " fresh with spring breezes" }));
    addSeasonDescription("summer", ({ " bustling with summer activity",
        " warm beneath bare feet", " dotted with colorful umbrellas",
        " alive with beach life", " perfect for summer recreation",
        " inviting in the warm sunshine" }));
    addSeasonDescription("autumn", ({ " swept by autumn winds",
        " scattered with autumn leaves", " peaceful in the cooler weather",
        " marked by migrating birds", " beautiful in autumn's light",
        " contemplative as seasons change" }));

    addAlias("beach");
    addAlias("sand");
    addAlias("sandy beach");
    addAlias("shore");
    addAlias("coastline");
    addAlias("seashore");

    addDescriptionTemplate("a ##Adjective## sandy sea beach");
    addItemTemplate("The sandy sea beach stretches in a graceful curve "
        "along the coastline, its fine sand shifting and reshaping with "
        "each tide. Gentle waves lap at the shore's edge, leaving behind "
        "intricate patterns of foam and scattered seashells. Driftwood "
        "lies bleached white by sun and salt, while seaweed marks the "
        "high tide line. The beach serves as a natural boundary between "
        "land and sea, constantly changed by wind and wave. Sandpipers "
        "scurry along the water's edge, and the rhythmic sound of surf "
        "provides a timeless soundtrack to this coastal paradise.");
}
