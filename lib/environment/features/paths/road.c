//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("road");
    addAdjectives(({ "broad", "well-travelled", "major", "established", "important",
        "strategic", "long-distance", "commercial", "engineered", "substantial" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " gradually revealed in engineered surface",
        " highlighted in surface texture variations",
        " emphasized by flanking drainage mist",
        " clearly revealed in intentional engineering",
        " revealing distant destinations"
        }));

    addTimeOfDayDescription("morning", ({
        " refreshed with first traffic patterns",
        " drying from crowned center outward",
        " apparent in substantial accommodating width",
        " evident in deliberate landscape course",
        " visible in maintenance features"
        }));

    addTimeOfDayDescription("noon", ({
        " distinctly different in full sunlight",
        " creating detectable thermal boundaries",
        " ensuring proper drainage when needed",
        " clearly visible in strategic features",
        " distinct in multiple use patterns"
        }));

    addTimeOfDayDescription("afternoon", ({
        " emphasized in texture and elevation",
        " radiating warm microclimate heat",
        " providing room for diverse traffic",
        " emphasized in construction boundaries",
        " apparent in strategic features"
        }));

    addTimeOfDayDescription("evening", ({
        " emphasized in careful grading",
        " releasing heat more slowly",
        " highlighted in stone construction elements",
        " apparent in drainage features",
        " accommodating travelers in both directions"
        }));

    addTimeOfDayDescription("dusk", ({
        " visible longer than surrounding terrain",
        " ensuring sufficient safe passage space",
        " creating subtle temperature differences",
        " providing confidence in engineered direction",
        " shifting from visual to textural"
        }));

    addTimeOfDayDescription("night", ({
        " revealed as pale ribbon",
        " creating significantly better visibility",
        " providing confident footing",
        " allowing ample room for navigation",
        " contrasting in movement sounds"
        }));

    addTimeOfDayDescription("late night", ({
        " perceptible through texture and openness",
        " providing secure footing",
        " ensuring ample room without hazards",
        " providing confidence in purposeful direction",
        " continuing engineering benefits"
        }));

    addTimeOfDayDescription("midnight", ({
        " reduced to width, texture, and openness",
        " detected through subtle slope changes",
        " continuing service regardless of hour",
        " providing confidence against straying",
        " emphasized in permanent road modification"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " revealing precise crown grading",
        " particularly valuable in winter width",
        " creating distinctive snow patterns",
        " preventing dangerous ice formation",
        " demonstrating substantial construction wisdom"
        }));

    addSeasonDescription("spring", ({
        " revealing drainage system effectiveness",
        " thoroughly testing engineering",
        " proving drainage feature value",
        " evident in careful material selection",
        " remaining functional overcoming challenges"
        }));

    addSeasonDescription("summer", ({
        " accommodating peak seasonal traffic",
        " affected distinctively by heat",
        " ensuring proper drainage in downpours",
        " remaining stable despite extremes",
        " demonstrating investment value"
        }));

    addSeasonDescription("autumn", ({
        " collecting leaves at edges",
        " testing drainage capacity efficiently",
        " often increased before winter arrival",
        " providing confidence in shortened daylight",
        " apparent in durability as conditions deteriorate"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## road extending across the "
        "landscape with substantial width and deliberate engineering");

    addItemTemplate("the road stretches across the landscape as a deliberate "
        "construction, its route determined more by necessity than convenience. "
        "The surface shows evidence of maintenance, with drainage ditches along "
        "portions and remnants of gravel or stone reinforcement in areas prone to "
        "erosion. Years of traffic have left parallel ruts that guide wheeled "
        "vehicles along its course.");
}
