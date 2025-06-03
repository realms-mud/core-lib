//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("archery range");
    setFloorPlanType("military");

    addAdjectives(({
        "long", "open", "grassy", "well-marked", "military", "outdoor"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## archery range with straw targets set at measured "
        "intervals and a covered shooting line"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day glistens on dew-covered grass, and the range "
        "stands empty and silent",
        ". At dawn, the targets are shrouded in mist, the field awaiting the "
        "first archers of the day"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the range is busy with archers practicing, arrows "
        "thudding into straw targets",
        ". Sunlight streams across the open field, casting long shadows from "
        "the target butts"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the sun beats down on the range, the grass warm and the "
        "air filled with the sound of arrows in flight",
        ". The targets stand at attention under the bright sky, their straw "
        "centers riddled with shafts"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun casts sharp shadows across the range, and the "
        "air is filled with the twang of bowstrings",
        ". Archers adjust their aim as the wind picks up, flags at the end of "
        "the range fluttering briskly"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the range grows quiet, the last arrows retrieved "
        "from the targets",
        ". The setting sun paints the field in gold, and the targets cast long "
        "shadows across the grass"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the range is bathed in fading light, the targets barely "
        "visible at the far end",
        ". The field empties as archers depart, leaving the range to the "
        "gathering darkness"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the archery range is deserted, the targets looming as "
        "dark shapes in the moonlight",
        ". The field is silent, with only the occasional rustle of wind in the "
        "grass"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with new grass growing thick and green, and wildflowers blooming "
        "along the edges",
        " where the air is fresh and the ground soft from recent rains"
        }));

    addSeasonDescription("summer", ({
        " with the grass dry and sun-bleached, and the targets showing signs "
        "of heavy use",
        " where the heat shimmers above the field and archers seek shade "
        "between rounds"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves scattered across the range and the air crisp and cool",
        " where the targets are patched and replaced in preparation for the "
        "coming competitions"
        }));

    addSeasonDescription("winter", ({
        " with frost on the ground and the targets wrapped in canvas to protect "
        "them from snow",
        " where the range is often empty, the field silent except for the wind"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a long, open field with faint outlines of targets at the far end"
    );
    addLowLightDescriptionTemplate(
        "an open range with straw targets and a covered shooting line, barely "
        "visible in the dim light"
    );
    addDimLightDescriptionTemplate(
        "an archery range with measured lanes, straw targets, and a simple "
        "shelter at one end"
    );
    addSomeLightDescriptionTemplate(
        "a well-marked archery range with straw targets, grassy lanes, and a "
        "covered shooting line"
    );

    // Single item template
    addItemTemplate(
        "The archery range is a long, open field marked with measured lanes. "
        "Straw targets are set at regular intervals, each mounted on a sturdy "
        "frame. A covered shooting line provides shelter for archers, with "
        "benches and racks for bows and arrows. The grass is kept short, and "
        "flags at the far end indicate wind direction. The range is clearly "
        "maintained for both training and competition, with evidence of "
        "frequent use in the worn paths and battered targets."
    );
}
