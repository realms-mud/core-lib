//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("entry path");
    addAlias("path");

    addAdjectives(({ "short", "direct", "formal", "designed", "tended",
        "deliberate", "functional", "purposeful", "connecting", "approach" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " highlighted with glistening dew",
        " revealing decorative elements",
        " evident in deliberate course",
        " emphasized by grading and elevation",
        " traced by hovering mist",
        " focused with ornamental birdsong",
        " preserved with clear recent impressions",
        " creating corridor of illumination",
        " showing use patterns in moisture",
        " visualized completely in morning light"
        }));

    addTimeOfDayDescription("morning", ({
        " efficiently channeling movement",
        " drying in material patterns",
        " evident in decorative borders",
        " focused by concentrated wear",
        " contrasting with adjacent coolness",
        " revealing careful planning elements",
        " distinctive in movement sounds",
        " enhanced by intentional shadows",
        " defined crisply from surroundings",
        " fully revealed in ornamental touches"
        }));

    addTimeOfDayDescription("noon", ({
        " highlighted in decorative elements",
        " revealed in intentional design",
        " distinctive in refined surface materials",
        " defined sharply at formal boundaries",
        " shaded by ornamental plantings",
        " releasing distinctive material scents",
        " notably different from connecting routes",
        " increasing in quality toward destination",
        " demonstrating careful width consideration",
        " cutting efficiently through terrain"
        }));

    addTimeOfDayDescription("afternoon", ({
        " patterned by decorative shadows",
        " radiating accumulated surface heat",
        " creating directional shadow effects",
        " carrying scents from selected plantings",
        " evident in connecting important points",
        " illuminated toward destination",
        " emphasized by maintained contrast",
        " remaining sharply defined",
        " catching warm light differently",
        " emphasized in connecting role"
        }));

    addTimeOfDayDescription("evening", ({
        " releasing different material scents",
        " illuminated directly along course",
        " dramatic in decorative elements",
        " detectably warmer than natural ground",
        " featuring changing evening aspects",
        " remaining tactilely apparent",
        " cooling at different rates",
        " apparent in subtle grading",
        " emphasized in direct sightline",
        " preparing for night's different rhythms"
        }));

    addTimeOfDayDescription("dusk", ({
        " increasingly visible with lighting markers",
        " perceptible through texture differences",
        " creating different thermal patterns",
        " providing continuing guidance",
        " remaining functionally unchanged",
        " mysterious in decorative aspects",
        " crossed by transitional wildlife",
        " distinctive in composed sounds",
        " confident in constructed texture",
        " retaining deliberate connection identity"
        }));

    addTimeOfDayDescription("night", ({
        " illuminated in pale reflective materials",
        " remaining functionally reliable",
        " utilized by nocturnal wildlife",
        " revealing continuing importance",
        " perceptible through textural borders",
        " carrying distinct material scents",
        " reflecting from decorative elements",
        " reassuring in short destination distance",
        " creating auditory corridor",
        " providing secure constructed footing"
        }));

    addTimeOfDayDescription("late night", ({
        " persisting in formal connection",
        " patterned by material dew formation",
        " creating vulnerability in open crossings",
        " equalized in temperature differences",
        " revealing subtle material sounds",
        " confident in designed directness",
        " guiding through borders",
        " occasionally glistening in starlight",
        " distinct in engineered feedback",
        " maintaining identity through night"
        }));

    addTimeOfDayDescription("midnight", ({
        " reduced to essential connection qualities",
        " transcending visual confirmation needs",
        " offering security in engineering",
        " abstracted in decorative elements",
        " valued in directness",
        " detected through textural borders",
        " differentiated by moisture collection",
        " unchanged in formal purpose",
        " providing touch and sound feedback",
        " offering greatest value in darkness"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " cleared more consistently than routes",
        " distinctively frosted on surface",
        " marked with snow-resistant borders",
        " emphasized or obscured by snowdrifts",
        " responding differently to freezing",
        " warmed differently in winter sunlight",
        " preventing dangerous ice accumulation",
        " transformed in decorative winter aspects",
        " contrasted with winter landscape",
        " valued most when routes are challenging"
        }));

    addSeasonDescription("spring", ({
        " bordered by early protected blooms",
        " revealed in careful drainage engineering",
        " refreshed in decorative elements",
        " thawing in material patterns",
        " drained in intentional grading",
        " dried more quickly after showers",
        " burst in boundary plantings",
        " active with spring bird migrations",
        " rich in increased material moisture",
        " contrasted with exuberant growth"
        }));

    addSeasonDescription("summer", ({
        " bordered by ornamental full blooms",
        " absorbed and radiated distinctively",
        " contrasted by maintenance boundaries",
        " patterned by shifting shade",
        " stable in engineered heat resistance",
        " avoided by insects on exposed surface",
        " maintained preventing summer overgrowth",
        " quality in withstanding extremes",
        " efficient in minimizing heat exposure",
        " contrasted with abundant growth"
        }));

    addSeasonDescription("autumn", ({
        " patterned by design and winds",
        " framed by seasonal border color",
        " cleared more frequently than routes",
        " revealed through leaf patterns",
        " clinged by different fog",
        " patterned by construction frost",
        " affected in borders while unchanged",
        " clear despite seasonal changes",
        " valuable in decreased daylight",
        " maintained preserving formal appearance"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## entry path providing direct "
        "access to a specific destination");

    addItemTemplate("the entry path serves as a transition between main thoroughfares "
        "and specific destinations, its relatively short length showing concentrated "
        "wear. The edges are often more clearly defined than longer routes, with "
        "evidence of intentional borders in some sections. The surface may be "
        "reinforced with gravel, stone, or packed earth depending on local materials "
        "and importance.");
}
