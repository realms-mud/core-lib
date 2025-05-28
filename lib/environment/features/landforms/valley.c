//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("valley");
    addAdjectives(({ "wide", "fertile", "sweeping", "vast", "deep", "sheltered",
        "verdant", "majestic", "river-carved", "glacial" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where morning mist often pools along the lowest points, creating a river "
        "of cloud that flows between slopes still emerging from shadow",
        " where first light touches the eastern ridge while the valley floor remains "
        "in cool twilight, the day arriving in stages from top to bottom"
        }));
    addTimeOfDayDescription("morning", ({
        " where sunlight gradually descends the eastern slopes before finally flooding "
        "across the valley floor, burning away lingering mist or dew",
        " where birds call from tree to tree along the sheltered lowlands, their songs "
        "carrying clearly in air often still compared to exposed heights"
        }));
    addTimeOfDayDescription("noon", ({
        " where the full light of day reveals the valley's true scale, from the "
        "distant ridgelines to the fertile lowlands between them",
        " where the shelter provided by surrounding heights often creates a warmer "
        "microclimate, the air still while winds pass overhead"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where shadows begin their slow climb up the western slopes while the eastern "
        "ridge still basks in golden light, a study in contrasts",
        " where the protected environment often develops its own weather patterns, "
        "clouds sometimes forming over the valley while surrounding peaks remain clear"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset paints the upper reaches of surrounding slopes in brilliant "
        "color while the valley floor falls into soft purple shadow",
        " where cooling air begins to flow downslope, creating gentle breezes that "
        "carry the scents of the day's accumulated warmth and growth"
        }));
    addTimeOfDayDescription("dusk", ({
        " where darkness pools first in the lowest areas, a shadowy sea that rises "
        "slowly up the surrounding slopes as light retreats",
        " where the sheltering ridges become dark silhouettes against the fading sky, "
        "defining the valley's extent even as its details disappear"
        }));
    addTimeOfDayDescription("night", ({
        " where the valley becomes a distinct area of deeper darkness bounded by the "
        "ridgelines that still define its shape against the night sky",
        " where the shelter that moderated day temperatures now often intensifies "
        "the cool of night, sometimes creating ground fog or heavy dew"
        }));
    addTimeOfDayDescription("late night", ({
        " where the valley's presence is defined by absence - of stars, of wind, of "
        "the exposure felt on higher ground - a protected hollow in the night",
        " where nocturnal life moves through the sheltered environment, the natural "
        "corridor guiding movement patterns established over countless generations"
        }));
    addTimeOfDayDescription("midnight", ({
        " where deepest night fills the valley like water in a vessel, flowing around "
        "every contour and pooling most deeply along the central lowlands",
        " where the surrounding heights remain as guardians even in darkness, their "
        "outlines visible against the star-filled sky above"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow often lies deeper and longer than on exposed heights, protected "
        "from wind and melting more slowly in the reduced sunlight",
        " where bare trees reveal the true shape of the land, and streams may freeze "
        "into gleaming ribbons that trace the valley's deeper contours"
        }));

    addSeasonDescription("spring", ({
        " where new growth appears first in the sheltered lowlands, creating a tide "
        "of green that gradually climbs the surrounding slopes",
        " where the valley often bursts into bloom ahead of higher terrain, the "
        "protected environment encouraging earlier awakening from winter dormancy"
        }));

    addSeasonDescription("summer", ({
        " where the lush growth creates a verdant corridor between more exposed "
        "heights, the contrast most striking during the peak growing season",
        " where the sheltered climate often supports agriculture or particularly "
        "rich wild growth, a green heart between more rugged surroundings"
        }));

    addSeasonDescription("autumn", ({
        " where seasonal colors transform the valley into a tapestry of red, gold "
        "and russet, often progressing from the ridgelines downward",
        " where the first frosts typically arrive later than on surrounding heights, "
        "the protected environment extending the growing season's final days"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## valley cutting through the surrounding terrain, creating a natural corridor of lower elevation between higher ground on either side, its sheltered environment often supporting rich vegetation and distinctive microclimates");
}
