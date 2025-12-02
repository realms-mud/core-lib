//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rocky sea shore");
    addAdjectives(({ "rugged", "windswept", "jagged", "weathered", "imposing" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with rocks just catching the faint dawn light",
        "outlined against the brightening sea",
        "emerging from the morning sea mist",
        "touched by the first rays over the water",
        "silhouetted against the dawn horizon",
        "bathed in the pale morning light"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight gleaming on wet rocks",
        "bright with morning sea spray",
        "alive with morning tide activity",
        "sparkling with reflected morning sun",
        "fresh in the morning sea breeze"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "stark and dramatic at midday",
        "brilliant in the noon sun",
        "casting deep shadows into tide pools",
        "dazzling with sea spray and sunlight",
        "imposing under the high sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waves crashing against the stones",
        "weathered by the afternoon sea",
        "peaceful between the tide cycles",
        "warmed by the gentle afternoon sun",
        "sculptured by countless afternoon storms",
        "serene in the late afternoon calm"
        }));
    addTimeOfDayDescription("evening", ({
        "with rocks glowing in the golden evening light",
        "as the sun sets behind the jagged silhouette",
        "painted in magnificent sunset colors",
        "beautiful against the evening sea",
        "transformed by the golden hour",
        "romantic in the fading seaside light"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming dark silhouettes as dusk settles",
        "mysterious in the gathering sea twilight",
        "outlined against the darkening water",
        "peaceful as night approaches the shore",
        "contemplative in the deepening dusk"
        }));
    addTimeOfDayDescription("night", ({
        "outlined against the moonlit sea",
        "discernable by the crash of waves",
        "silvered by moonlight on the water",
        "mysterious in the seaside darkness",
        "peaceful under the starry sea sky",
        "enchanted by the night ocean sounds"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep sea shadows",
        "hidden in the profound seaside darkness",
        "merged with the dark sea waters",
        "invisible save for crashing waves",
        "embraced by the midnight ocean"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " battered by fierce winter storms",
        " carved by powerful winter swells", " scattered with storm debris",
        " lashed by freezing sea spray", " shaped by winter's fury",
        " enduring the harsh winter seas" }));
    addSeasonDescription("spring", ({ " alive with returning sea life",
        " dotted with hardy coastal plants", " visited by migrating seabirds",
        " refreshed by spring tides", " adorned with sea anemones",
        " renewed by the warming waters" }));
    addSeasonDescription("summer", ({ " bustling with tide pool activity",
        " perfect for summer exploration", " alive with marine creatures",
        " warm from the summer sun", " inviting for seaside adventures",
        " teeming with summer sea life" }));
    addSeasonDescription("autumn", ({ " swept by autumn sea storms",
        " beautiful in the changing light", " marked by dramatic autumn swells",
        " contemplative as seasons change", " sculptured by autumn's power",
        " preparing for winter's approach" }));

    addAlias("rocks");
    addAlias("shore");
    addAlias("sea shore");
    addAlias("coastline");
    addAlias("rocky shore");
    addAlias("rocky coast");

    addDescriptionTemplate("a ##Adjective## rocky sea shore");
    addItemTemplate("The rocky sea shore presents a dramatic tableau of "
        "ancient stone meeting endless water. Weathered granite and "
        "basalt formations create a natural fortress against the "
        "relentless assault of waves and wind. Tide pools nestled "
        "between the rocks teem with colorful marine life - sea "
        "anemones, starfish, and hermit crabs creating miniature "
        "ecosystems. The constant rhythm of waves creates a symphony "
        "of crashes and hisses as water retreats over barnacle-"
        "encrusted stone. Seaweed clings to the lower reaches while "
        "hardy coastal plants find purchase in rocky crevices above "
        "the high tide line.");
}
