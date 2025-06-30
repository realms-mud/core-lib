//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lake shore bluff");
    addAdjectives(({ "peaceful", "scenic", "elevated", "tranquil", "commanding" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with cliffs catching the faint lake dawn",
        "outlined against the peaceful lake horizon",
        "emerging from gentle morning lake mist",
        "touched by the first rays over calm waters",
        "silhouetted against the serene dawn",
        "awakening to overlook the peaceful lake"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight illuminating the lake-facing slope",
        "bright with morning lake reflections",
        "alive with morning lakeside activity",
        "sparkling with reflected lake sun",
        "fresh in the gentle morning lake breeze"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible overlooking the peaceful lake",
        "commanding and scenic at midday",
        "brilliant in the noon lake sun",
        "magnificent under the clear lake sky",
        "dazzling with lake reflections and bright light",
        "impressive under the high sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with gentle lake waters visible far below",
        "peaceful overlooking the afternoon lake",
        "commanding a view of the serene waters",
        "warmed by the gentle afternoon sun",
        "comfortable in the afternoon lake breeze",
        "beautiful in the afternoon lake glow"
        }));
    addTimeOfDayDescription("evening", ({
        "with slopes glowing in lake sunset light",
        "as the sun sets over the peaceful lake",
        "painted in gentle lake sunset colors",
        "beautiful against the evening lake expanse",
        "transformed by the golden lake hour",
        "romantic in the fading lake light"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in lake twilight",
        "becoming silhouettes against the lake dusk",
        "mysterious in the gathering lake darkness",
        "outlined against the darkening lake waters",
        "peaceful as night approaches the lake",
        "contemplative in the lake twilight"
        }));
    addTimeOfDayDescription("night", ({
        "outlined against the moonlit lake expanse",
        "discernable by gentle lake sounds below",
        "silvered by moonlight on the calm lake",
        "peaceful in the lake darkness",
        "serene under the quiet lake night sky",
        "enchanted by the gentle lake symphony"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight lake sky",
        "lost in the gentle lake darkness",
        "hidden in the tranquil lake night",
        "merged with the peaceful dark waters below",
        "invisible save for gentle lake sounds",
        "embraced by the midnight lake serenity"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " overlooking the partially frozen lake",
        " commanding a view of winter's lake beauty", " peaceful above winter's quiet lake",
        " scenic despite winter's stark landscape", " beautiful overlooking winter's frozen lake",
        " standing guard over winter's sleeping lake" }));
    addSeasonDescription("spring", ({ " alive with spring lakeside vegetation",
        " overlooking the lake's spring renewal", " surrounded by budding lakeside plants",
        " commanding a view of spring's lake awakening", " refreshed by spring's lakeside energy",
        " vibrant with spring lakeside life" }));
    addSeasonDescription("summer", ({ " perfect for summer lake observation",
        " surrounded by lush lakeside vegetation", " commanding summer's lake vista",
        " beautiful overlooking summer's active lake", " ideal for summer lake contemplation",
        " magnificent in summer's lakeside glory" }));
    addSeasonDescription("autumn", ({ " overlooking the lake's autumn reflections",
        " surrounded by spectacular lakeside fall colors", " commanding autumn's lake beauty",
        " peaceful above autumn's contemplative lake", " beautiful in autumn's lakeside light",
        " scenic as seasons change over the lake" }));

    addAlias("bluff");
    addAlias("cliff");
    addAlias("cliffs");
    addAlias("lake shore");
    addAlias("shore");
    addAlias("lakeside");

    addDescriptionTemplate("a ##Adjective## lake shore bluff");
    addItemTemplate("The lake shore bluff rises gently but commandingly "
        "above the peaceful lake waters, providing a scenic vantage "
        "point over the tranquil expanse below. Unlike its oceanic "
        "cousins, this elevated shoreline faces calm waters that "
        "lap gently rather than crash violently against its base. "
        "Wildflowers and lakeside vegetation crown the bluff while "
        "songbirds nest in the protected slopes. The elevated "
        "position offers panoramic views across the lake's surface, "
        "where waterfowl glide peacefully and fish rise to feed. "
        "This commanding yet gentle prominence serves as a perfect "
        "spot for contemplation, where visitors can appreciate "
        "both the lake's serenity and the surrounding landscape "
        "in peaceful harmony.");
}
