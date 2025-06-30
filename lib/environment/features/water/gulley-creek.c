//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gulley creek");
    addAdjectives(({ "rushing", "narrow", "swift", "erosive", "channeled" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with waters catching the faint dawn light",
        "outlined in the brightening gulley",
        "emerging from morning gulley mist",
        "touched by filtered rays penetrating down",
        "shimmering in the pale morning light",
        "awakening with swift currents"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight creating patterns on rushing water",
        "bright in the morning gulley shadows",
        "alive with morning erosive activity",
        "sparkling with reflected morning sun",
        "energetic in the morning flow"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates",
        "swift and determined at midday",
        "brilliant when touched by noon sun",
        "prominent in the gulley's depths",
        "dazzling in the filtered daylight",
        "powerful in the midday flow"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waters rushing through the afternoon",
        "swift in the late afternoon current",
        "carving steadily in the afternoon warmth",
        "active in the filtered afternoon light",
        "energetic in the afternoon flow",
        "persistent in the afternoon carving"
        }));
    addTimeOfDayDescription("evening", ({
        "with waters glowing in filtered evening light",
        "as sunset light reaches into the gulley",
        "painted in muted evening colors",
        "beautiful in the gentle evening glow",
        "romantic in the protected twilight",
        "transformed by the filtered golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the gulley shadows",
        "becoming mysterious as dusk deepens",
        "outlined in the darkening gulley",
        "peaceful despite its constant motion",
        "cool in the evening gulley shadows",
        "contemplative in the gathering darkness"
        }));
    addTimeOfDayDescription("night", ({
        "discernable by its rushing sound",
        "outlined by moonlight filtering down",
        "mysterious in the gulley darkness",
        "peaceful despite its constant flow",
        "enchanted by amplified night sounds",
        "active in the protected darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible in the deep gulley shadows",
        "lost in the profound darkness",
        "hidden in the gulley's midnight",
        "present as rushing sounds in the night",
        "mysterious in the midnight flow",
        "embraced by the gulley's darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " partially frozen but still flowing",
        " carving through winter's icy grip", " persistent despite winter's cold",
        " flowing beneath thin ice formations", " active even in winter's embrace",
        " standing as winter's persistent carver" }));
    addSeasonDescription("spring", ({ " swollen with spring rains and snowmelt",
        " carving aggressively with spring energy", " rushing with spring's renewed power",
        " alive with accelerated spring erosion", " energized by spring's flowing force",
        " renewed by seasonal flooding" }));
    addSeasonDescription("summer", ({ " running swift despite summer heat",
        " carving steadily through summer months", " persistent in summer's grip",
        " active with consistent summer flow", " determined in summer's embrace",
        " steady in summer's persistent carving" }));
    addSeasonDescription("autumn", ({ " carrying autumn leaves downstream",
        " carving with autumn's steady flow", " persistent as seasons change",
        " beautiful in autumn's filtered light", " contemplative yet always active",
        " preparing for winter's icy challenge" }));

    addAlias("creek");
    addAlias("water");
    addAlias("flowing water");
    addAlias("gulley");
    addAlias("channel");

    addDescriptionTemplate("a ##Adjective## gulley creek");
    addItemTemplate("The gulley creek rushes determinedly through its "
        "self-carved channel, its swift waters continuously working "
        "to deepen and widen the narrow passage it has created over "
        "time. This energetic waterway demonstrates the persistent "
        "power of flowing water to reshape the landscape, carrying "
        "sediment and debris downstream while cutting ever deeper "
        "into the earth. The creek's banks show clear evidence of "
        "its erosive work - undercut edges, exposed roots, and "
        "deposited materials that tell the story of floods and "
        "droughts. Despite its confined space, the gulley creek "
        "supports a surprising variety of life adapted to its "
        "dynamic environment and swift-changing conditions.");
}
