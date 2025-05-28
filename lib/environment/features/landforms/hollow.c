//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hollow");
    addAdjectives(({ "secluded", "sheltered", "damp", "cool", "lush", "hidden", "quiet", "shadowy" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where mist pools in the depression long after surrounding areas have cleared, creating an otherworldly atmosphere",
        " where the hollow remains in shadow while light touches the rim, outlining its circular form in gold"
        }));
    addTimeOfDayDescription("morning", ({
        " where the sun gradually penetrates the depression, revealing dew-laden vegetation and perhaps small pools of water",
        " where birdsong echoes slightly in the natural amphitheater created by the sloping sides"
        }));
    addTimeOfDayDescription("noon", ({
        " where the hollow creates a natural shelter from the wind, with sunlight now reaching most of its interior",
        " where the temperature differs noticeably from the surrounding landscape, often cooler and more humid"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where shadows begin to creep across the depression earlier than the surrounding land as the sun moves west",
        " where the sheltered basin holds the day's accumulated moisture, nurturing different plants than grow above"
        }));
    addTimeOfDayDescription("evening", ({
        " where darkness pools early in its depths while the rim still catches the last golden light",
        " where cooling air begins to condense as mist in the lowest parts of the depression"
        }));
    addTimeOfDayDescription("dusk", ({
        " where night comes quicker than to the surrounding landscape, the hollow already shrouded in deep shadow",
        " where the rim stands briefly outlined against the darkening sky before fading into the general gloom"
        }));
    addTimeOfDayDescription("night", ({
        " where the depression becomes a pool of deeper darkness, sounds slightly dampened within its confines",
        " where the cooler air settles heavily, sometimes creating a blanket of mist across its lowest points"
        }));
    addTimeOfDayDescription("late night", ({
        " where the hollow feels like a world apart, enclosed and intimate beneath the vast night sky",
        " where nocturnal creatures find protected hunting grounds among its sheltered vegetation"
        }));
    addTimeOfDayDescription("midnight", ({
        " where darkness is most complete, the depression a void of deeper black in the midnight landscape",
        " where sounds seem muffled and distant, creating an island of quiet in the night"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where frost remains longer than in exposed areas, sometimes creating delicate crystal formations",
        " where snow collects more deeply, possibly concealing the hollow entirely beneath a smooth white surface"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt and rain create temporary pools, nurturing specialized plant life and amphibians",
        " where vegetation grows lush and early, protected from harsh winds and late frosts"
        }));

    addSeasonDescription("summer", ({
        " where the depression creates a microclimate that remains cooler and moister than surrounding terrain",
        " where plants grow tall and dense in the sheltered conditions, creating a hidden oasis"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect in drifts, creating a deep natural mulch across the hollow's floor",
        " where the first frosts touch the rim while the protected interior remains milder for longer"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hollow, a natural depression in the landscape where the ground dips to form a sheltered basin, often with different vegetation and microclimate than the surrounding terrain");
}
