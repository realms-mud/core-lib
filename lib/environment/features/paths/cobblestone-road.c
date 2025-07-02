//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cobblestone road");
    addAlias("cobblestone");
    addAlias("road");

    addAdjectives(({ "well-maintained", "moss-covered", "weathered",
        "meandering", "sturdy", "expertly-laid", "worn", "smooth", "elegant" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " glistening with morning dew",
        " highlighted in varying shades",
        " with puddles catching golden light",
        " emerging from gentle fog",
        " emphasized in geometric patterns",
        " releasing wisps of vapor",
        " appearing to glow subtly",
        " dappled with light and shadow",
        " casting exaggerated shadows",
        " marked with bird tracks in moisture"
        }));

    addTimeOfDayDescription("morning", ({
        " drying to reveal varied colors",
        " emphasized in craftsmanship details",
        " bordered by hardy grass and moss",
        " distinct from natural ground",
        " releasing mineral scents",
        " retreating from shadow coverage",
        " occasionally rocking loose stones",
        " efficiently draining morning dew",
        " revealing quartz veins and fossils",
        " noticeably warming in temperature"
        }));

    addTimeOfDayDescription("noon", ({
        " eliminating shadows between stones",
        " revealing intentional design fully",
        " reflecting heat distinctively",
        " sharply defined at edges",
        " creating shade oases at plantings",
        " releasing distinctive mineral scents",
        " notably different from thoroughfares",
        " increasing in material quality toward destination",
        " demonstrating careful width consideration",
        " efficiently cutting through terrain"
        }));

    addTimeOfDayDescription("afternoon", ({
        " accentuated by lengthening shadows",
        " dappled on western stone faces",
        " cooling at eastern edges",
        " radiating accumulated heat",
        " striped by moving tree shadows",
        " sheltering insects in warming crevices",
        " contrasting with rapidly cooling surfaces",
        " enriched in warmer stone tones",
        " revealing subtle surface unevenness",
        " attracting birds to retained warmth"
        }));

    addTimeOfDayDescription("evening", ({
        " releasing heat as slight mist",
        " enriched in sunset colors",
        " creating islands of illumination",
        " contracting with faint settling sounds",
        " attracting creatures to residual warmth",
        " defined by texture rather than sight",
        " detectably warmer than surroundings",
        " reflecting scattered sunset colors",
        " varying in cooling rates by composition",
        " less distinct visually but tactilely apparent"
        }));

    addTimeOfDayDescription("dusk", ({
        " remaining relatively light against darkness",
        " merging into general road form",
        " creating detectable temperature boundaries",
        " drying evening dew with retained heat",
        " attracting low-swooping bats",
        " apparent in contrasting textures",
        " providing stable surface despite dimness",
        " attracting warmth-seeking creatures",
        " catching final light on raised center",
        " continuing to reflect minimal illumination"
        }));

    addTimeOfDayDescription("night", ({
        " transformed into silvery pathway",
        " providing sure footing in darkness",
        " sparkling with quartz and mica reflections",
        " maintaining distinct thermal signature",
        " forming dew more slowly",
        " used by night-hunting predators",
        " providing auditory navigation cues",
        " monochromatic in shades of silver",
        " distinct from chaotic natural growth",
        " visible from elevation in low light"
        }));

    addTimeOfDayDescription("late night", ({
        " creating subtle crossing sounds",
        " faintly gleaming with collected dew",
        " minimally warmer than surroundings",
        " collecting moisture in geometric patterns",
        " providing open sight lines",
        " contrasting with adjacent vegetation rustlings",
        " perceived through boundary corridors",
        " settling with temperature changes",
        " framing night sky views",
        " reflecting moonlight's changing patterns"
        }));

    addTimeOfDayDescription("midnight", ({
        " reduced to underfoot texture",
        " witnessing countless crossings silently",
        " contrasting sharply with softer terrain",
        " varying in composition subtly",
        " slightly slick with accumulated dew",
        " revealing smallest sounds",
        " channeling air movement",
        " reflecting differently from varied surfaces",
        " carrying mineral scents in night air",
        " focused on static road qualities"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " speckled white with snow between stones",
        " elevated above mud and standing water",
        " forming intricate frost patterns",
        " melting snow in distinctive patterns",
        " absorbing limited winter sunlight",
        " creating miniature frozen pools",
        " forming distinct snowdrift patterns",
        " preventing dangerous ice sheets",
        " creating complex textured surfaces",
        " visible from distance when cleared"
        }));

    addSeasonDescription("spring", ({
        " sprouting green between stones",
        " washed clean by spring rains",
        " efficiently flowing water along camber",
        " rich in mineral colors from moisture",
        " renewed in moss and lichen",
        " forming brief mirrors in depressions",
        " drying more quickly than earth",
        " returning with insect activity",
        " colored by pollen and petals",
        " absorbing more heat with longer days"
        }));

    addSeasonDescription("summer", ({
        " radiating heat well into evening",
        " remaining stable and dust-free",
        " rising with visible heat shimmer",
        " maintaining drought-resistant plants between stones",
        " sharply contrasted with summer growth",
        " sheltering insects in minimal shadows",
        " storing heat efficiently",
        " standing out against deeper greens",
        " channeling water quickly in storms",
        " occasionally cracking from heat expansion"
        }));

    addSeasonDescription("autumn", ({
        " gathering leaves against raised stones",
        " darkened to rich hues by rain",
        " forming white frost lacework",
        " retaining less heat seasonally",
        " creating slick surfaces when wet",
        " providing stable footing in moisture",
        " complementing brilliant foliage",
        " contracting with settling sounds",
        " forming mist over cooling surface",
        " remaining reliable as challenges increase"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## cobblestone road of carefully "
        "fitted stones creating a durable thoroughfare");

    addItemTemplate("the cobblestone road represents considerable engineering skill, "
        "with variously sized stones carefully fitted together to create a durable surface. "
        "The stones show evidence of deliberate placement, with larger blocks along "
        "the edges and a subtle crown in the center for drainage. Years of use "
        "have polished many of the stones smooth, while others have shifted slightly "
        "with time and weather.");
}
