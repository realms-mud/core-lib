//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sandy lake beach");
    addAdjectives(({ "tranquil", "peaceful", "gentle", "serene", "secluded" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with sand just catching the faint dawn light",
        "reflecting the calm colors of lake sunrise",
        "emerging from morning lake mist",
        "touched by the first rays over the water",
        "bathed in the peaceful morning light",
        "shimmering as dawn breaks over the lake"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on calm lake waters",
        "warming in the mild morning air",
        "bright with reflected morning sun",
        "fresh in the gentle lake breeze",
        "peaceful in the morning stillness"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "warm under the noon sun",
        "comfortable in the midday warmth",
        "inviting in the gentle noon light",
        "pleasant under the mild sun",
        "ideal for midday relaxation"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with gentle ripples lapping the shore",
        "comfortable in the afternoon warmth",
        "peaceful in the late afternoon calm",
        "perfect for afternoon recreation",
        "warm and inviting in the soft light",
        "serene in the gentle afternoon breeze"
        }));
    addTimeOfDayDescription("evening", ({
        "with sand glowing in the golden evening light",
        "as the sun sets over the peaceful lake",
        "painted in gentle sunset colors",
        "beautiful in the evening lake glow",
        "transformed by the golden hour",
        "romantic in the fading daylight"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the lake twilight",
        "becoming peaceful as dusk settles",
        "serene in the gathering darkness",
        "cool in the evening lake breeze",
        "tranquil as night approaches",
        "contemplative in the deepening dusk"
        }));
    addTimeOfDayDescription("night", ({
        "outlined by moonlight on still waters",
        "peaceful under the quiet night sky",
        "silvered by moonlight on the lake",
        "quiet save for gentle lapping waves",
        "mysterious in the gentle darkness",
        "enchanted by the night lake sounds"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the peaceful night darkness",
        "hidden in the gentle night",
        "merged with the dark lake waters",
        "invisible save for soft water sounds",
        "embraced by the tranquil midnight"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " frozen at the water's edge",
        " dusted with snow and ice", " peaceful in winter's quiet embrace",
        " serene beneath winter's blanket", " still in the winter calm",
        " beautiful in winter's stark simplicity" }));
    addSeasonDescription("spring", ({ " alive with spring lake activity",
        " visited by returning waterfowl", " adorned with spring wildflowers",
        " fresh with seasonal breezes", " renewed by spring warmth",
        " awakening with new lake life" }));
    addSeasonDescription("summer", ({ " perfect for summer recreation",
        " warm and inviting for swimming", " bustling with summer activity",
        " ideal for family gatherings", " alive with summer lake life",
        " perfect for summer relaxation" }));
    addSeasonDescription("autumn", ({ " scattered with fallen autumn leaves",
        " peaceful in the cooler weather", " beautiful in autumn's gentle light",
        " marked by migrating waterfowl", " contemplative as seasons change",
        " serene with autumn's calm beauty" }));

    addAlias("beach");
    addAlias("sand");
    addAlias("sandy beach");
    addAlias("lake shore");
    addAlias("shore");
    addAlias("lakeside");

    addDescriptionTemplate("a ##Adjective## sandy lake beach");
    addItemTemplate("The sandy lake beach curves gently along the "
        "tranquil shoreline, its soft sand warmed by sun and caressed "
        "by gentle lake waters. Small waves lap peacefully at the shore, "
        "creating a soothing rhythm that speaks of serenity and calm. "
        "Cattails and water lilies grow in the shallows, while fish "
        "create subtle ripples as they rise to feed. The beach offers "
        "a perfect retreat from the world's chaos, where time seems to "
        "slow and the soul finds peace. Dragonflies patrol the water's "
        "edge while herons stand motionless in the shallows, creating "
        "a scene of perfect natural harmony and lakeside tranquility.");
}
