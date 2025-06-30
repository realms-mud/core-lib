//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rocky lake shore");
    addAdjectives(({ "peaceful", "tranquil", "serene", "gentle", "pristine" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with rocks catching the gentle dawn light",
        "outlined against the calm lake surface",
        "emerging from peaceful morning lake mist",
        "touched by the first rays over still waters",
        "reflected perfectly in the mirror-like lake",
        "bathed in the serene morning light"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on calm lake waters",
        "bright with peaceful morning reflections",
        "alive with gentle morning lake activity",
        "sparkling with soft reflected sun",
        "fresh in the mild morning lake breeze"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the peaceful daylight",
        "warm and inviting at midday",
        "comfortable in the gentle noon sun",
        "perfect for midday contemplation",
        "pleasant under the mild lake sun",
        "inviting in the tranquil noon light"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with gentle ripples lapping the stones",
        "peaceful in the afternoon lake calm",
        "perfect for afternoon reflection",
        "warmed by the gentle afternoon sun",
        "serene in the soft afternoon light",
        "comfortable in the mild afternoon breeze"
        }));
    addTimeOfDayDescription("evening", ({
        "with rocks glowing in gentle evening light",
        "as the sun sets over the peaceful lake",
        "painted in soft sunset reflections",
        "beautiful in the evening lake glow",
        "transformed by the golden lake hour",
        "romantic in the fading lake light"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in peaceful twilight",
        "becoming silhouettes against calm waters",
        "mysterious in the gentle lake dusk",
        "outlined against the darkening lake",
        "peaceful as night approaches the water",
        "contemplative in the quiet twilight"
        }));
    addTimeOfDayDescription("night", ({
        "outlined by moonlight on still waters",
        "discernable by gentle lapping sounds",
        "silvered by moonlight on the calm lake",
        "peaceful in the quiet lake darkness",
        "serene under the starry lake sky",
        "enchanted by gentle night lake sounds"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the peaceful night sky",
        "lost in the gentle lake darkness",
        "hidden in the tranquil midnight",
        "merged with the dark still waters",
        "invisible save for soft water sounds",
        "embraced by the quiet midnight lake"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " frozen along the water's edge",
        " dusted with snow and morning frost", " peaceful in winter's quiet embrace",
        " serene beneath winter's blanket", " still in the winter calm",
        " beautiful in winter's pristine simplicity" }));
    addSeasonDescription("spring", ({ " alive with returning lake life",
        " visited by migrating waterfowl", " adorned with spring wildflowers",
        " refreshed by spring rains", " renewed by warming waters",
        " awakened by spring's gentle touch" }));
    addSeasonDescription("summer", ({ " perfect for summer recreation",
        " warm and inviting for swimming", " ideal for peaceful contemplation",
        " beautiful in summer's gentle light", " alive with summer lake life",
        " perfect for summer relaxation" }));
    addSeasonDescription("autumn", ({ " scattered with colorful autumn leaves",
        " peaceful in the cooling air", " beautiful in autumn's gentle light",
        " marked by departing waterfowl", " contemplative as seasons change",
        " serene in autumn's quiet beauty" }));

    addAlias("rocks");
    addAlias("shore");
    addAlias("lake shore");
    addAlias("lakeside");
    addAlias("rocky shore");
    addAlias("lake coast");

    addDescriptionTemplate("a ##Adjective## rocky lake shore");
    addItemTemplate("The rocky lake shore provides a peaceful contrast "
        "to the surrounding landscape, where ancient stone meets "
        "tranquil waters in perfect harmony. Smooth granite boulders "
        "and weathered limestone formations create natural seating "
        "areas and quiet contemplation spots along the water's edge. "
        "The gentle lapping of lake waters against stone creates a "
        "soothing rhythm, while small fish dart between submerged "
        "rocks in the crystal-clear shallows. Wildflowers find "
        "purchase in rocky crevices, and tall reeds wave gently in "
        "the breeze. This serene shoreline offers a perfect retreat "
        "where time seems to slow and the soul finds peace beside "
        "the mirror-like waters.");
}
