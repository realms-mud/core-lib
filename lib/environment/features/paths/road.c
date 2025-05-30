//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        " where morning light gradually reveals the engineered surface, its width "
        "and careful construction distinguishing it from lesser pathways",
        " where low-angled sunlight catches on surface variations, highlighting "
        "the texture of packed earth, stone, or other materials used in construction",
        " where morning mist often lingers in the drainage ditches that flank the "
        "roadway, emphasizing its raised profile above the surrounding terrain",
        " where the first light clearly reveals the road's intentional engineering - "
        "from crowned center to sloped sides and protective drainage features",
        " where distant features come into view along the road's relatively straight "
        "course, its deliberate routing revealing faraway destinations"
        }));

    addTimeOfDayDescription("morning", ({
        " where the day's first traffic refreshes the surface patterns, overlaying "
        "the preserved impressions from previous days with new tracks",
        " where warming gradually dries the road surface from the center outward, "
        "revealing the careful engineering that keeps the crown well-drained",
        " where the substantial width becomes most apparent, the road designed "
        "specifically to accommodate multiple lanes of simultaneous traffic",
        " where the road's deliberate course across the landscape becomes evident - "
        "cutting through hills, bridging low areas, avoiding natural hazards",
        " where maintenance features become visible-culverts channeling water "
        "beneath the roadbed, ditches directing runoff, reinforced edges"
        }));

    addTimeOfDayDescription("noon", ({
        " where the full width catches maximum sunlight, the broad engineered "
        "surface distinctly different from surroundings in both appearance and function",
        " where heat builds differently on the compacted road surface than on "
        "adjacent natural ground, creating detectable thermal boundaries",
        " where the careful grading ensures proper drainage even during heavy "
        "rainfall, the crowned center shedding water toward protective ditches",
        " where strategic features become clearly visible-fords at water crossings, "
        "reinforced sections over wet ground, cuttings through higher terrain",
        " where the multiple use patterns show most distinctly, with different "
        "lanes forming for various types of traffic across the ample width"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where the declining sun angle once again creates shadows that emphasize "
        "the road's texture and subtle variations in elevation",
        " where heat accumulated throughout the day radiates from the surface, "
        "creating a warm microclimate just above the engineered structure",
        " where the substantial width provides ample room for diverse traffic, "
        "with established patterns worn into the surface by regular use",
        " where afternoon light emphasizes the boundaries between different "
        "construction materials and repair sections accumulated over years",
        " where strategic features become more apparent in angled light - "
        "reinforced edges, drainage channels, subtle grading for water control"
        }));

    addTimeOfDayDescription("evening", ({
        " where the declining light creates long shadows that emphasize the "
        "road's elevation above surrounding terrain and its careful grading",
        " where the broad surface releases accumulated heat more slowly than "
        "adjacent areas, creating detectable thermal boundaries at the edges",
        " where the golden hour light catches on any stone elements used in "
        "construction, briefly highlighting culverts, bridges, or reinforcements",
        " where the carefully engineered drainage features become more apparent "
        "as shadows fill ditches and channels along the road's boundaries",
        " where the significant width accommodates travelers moving in both "
        "directions, the broad surface designed specifically for heavy use"
        }));

    addTimeOfDayDescription("dusk", ({
        " where the constructed surface remains visible longer than surrounding "
        "terrain, its engineered materials and elevation preserving definition",
        " where the broad width ensures that even as darkness increases, there "
        "remains sufficient space for safe passage in both directions",
        " where cooling creates subtle temperature differences between the road "
        "and adjacent areas, detectable as one crosses the boundaries",
        " where the road's deliberate course provides confidence even as visual "
        "references fade, its engineered direction rarely leading astray",
        " where the distinction between road surface and surroundings gradually "
        "shifts from visual to textural as light continues failing"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight reveals the road as a pale ribbon cutting through "
        "darker surroundings, its broad width clearly visible from elevation",
        " where the open corridor above creates significantly better visibility, "
        "the absence of overhanging vegetation allowing starlight to reach the surface",
        " where the road's careful grading provides confident footing despite "
        "darkness, its predictable surface a sharp contrast to natural ground",
        " where the substantial width allows ample room for night travel without "
        "risk of accidentally straying onto uneven adjacent terrain",
        " where the distinctive sound of movement along the road contrasts with "
        "that of adjacent terrain, providing audio confirmation of correct path"
        }));

    addTimeOfDayDescription("late night", ({
        " where the road's existence becomes primarily perceptible through "
        "texture and relative openness rather than visual identification",
        " where the carefully engineered surface provides secure footing even "
        "in minimal visibility, its predictability a crucial advantage",
        " where the broad width ensures that even in near-darkness, there remains "
        "ample room to navigate without risk of encountering hidden hazards",
        " where the road's deliberate course through the landscape provides "
        "confidence during challenging visibility, its direction purposeful",
        " where the significant engineering that makes daylight travel efficient "
        "continues providing benefits during the darkest hours"
        }));

    addTimeOfDayDescription("midnight", ({
        " where the deepest darkness reduces the road to its essential "
        "characteristics-width, texture, structure, and relative openness",
        " where the subtle crown of the road's center can be detected through "
        "careful attention to slope changes even without visual cues",
        " where the significant engineering that created this thoroughfare continues "
        "serving regardless of hour, its function transcending illumination",
        " where the substantial width provides confidence that one will not "
        "accidentally stray from the engineered surface even in complete darkness",
        " where the absolute stillness of deepest night emphasizes the road's "
        "permanence, an enduring human modification to the natural landscape"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow often reveals the precise grading of the road's crown, "
        "melting patterns highlighting the careful engineering of the surface",
        " where the substantial width proves particularly valuable in winter "
        "conditions, allowing room to navigate around problematic sections",
        " where the road's elevation above surrounding terrain creates distinctive "
        "snow patterns, with wind often clearing exposed sections naturally",
        " where the careful drainage engineering prevents the dangerous ice "
        "formation that makes winter travel hazardous on lesser routes",
        " where the road's continuing function through challenging winter conditions "
        "demonstrates the practical wisdom of its substantial construction"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt reveals the effectiveness of the road's drainage systems, "
        "water efficiently channeling away from the travel surface",
        " where spring rains thoroughly test the engineering, well-constructed "
        "sections maintaining integrity while problem areas require attention",
        " where the significant investment in drainage features proves its value, "
        "preventing the seasonal destruction that plagues lesser routes",
        " where the careful material selection becomes evident, certain sections "
        "drying more rapidly after rain based on composition and drainage",
        " where the road remains fully functional during conditions that render "
        "lesser routes impassable, its engineering overcoming seasonal challenges"
        }));

    addSeasonDescription("summer", ({
        " where the road's full width accommodates peak seasonal traffic, its "
        "substantial engineering designed specifically for heavy regular use",
        " where heat affects different construction materials distinctively, "
        "from earth sections to graveled areas to stone reinforcements",
        " where the careful grading ensures proper drainage during sudden summer "
        "downpours, preventing the erosion that damages lesser routes",
        " where the road's engineered surface remains stable despite summer's "
        "extremes of heat, drought, and occasional violent storms",
        " where the substantial investment in construction demonstrates its value "
        "during peak travel season, the road efficiently handling heavy demand"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect differently on the road than on surrounding "
        "areas, often blown to the edges by the corridor's distinct air patterns",
        " where autumn rains test the road's drainage capacity, well-engineered "
        "sections channeling water efficiently away from the travel surface",
        " where maintenance often increases before winter's arrival, critical "
        "repairs being completed while conditions still permit",
        " where the road's substantial width provides confidence as daylight hours "
        "shorten, reducing the risk of travel extending into darkness",
        " where the road's durability becomes particularly apparent as conditions "
        "deteriorate, its engineered resilience outperforming natural alternatives"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## road extending across the landscape, "
        "its substantial width and deliberate engineering distinguishing it "
        "from lesser paths, the significant investment in construction creating "
        "a durable thoroughfare designed specifically for heavy, regular traffic");

    addItemTemplate("the road stretches across the landscape as a deliberate "
        "construction, its route determined more by necessity than convenience. "
        "The surface shows evidence of maintenance, with drainage ditches along "
        "portions and remnants of gravel or stone reinforcement in areas prone to "
        "erosion. Years of traffic have left parallel ruts that guide wheeled "
        "vehicles along its course. ##UseDescriptionSet##");
}
