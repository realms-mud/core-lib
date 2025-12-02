//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone observatory");
    setFloorPlanType("observatory");

    addAdjectives(({ "ancient", "tall", "cylindrical", "weathered", "mossy", "scholarly" }));

    // Basic description template
    addDescriptionTemplate("a ##Adjective## limestone observatory tower with a copper-domed roof "
        "and narrow arched windows, perched atop a grassy rise");

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn glimmers on the copper dome, casting a rosy hue "
        "over the weathered limestone",
        ". At dawn, mist curls around the tower's base, lending the observatory an "
        "ethereal presence against the pale sky",
        ". The observatory stands silent in the early light, its dome reflecting "
        "the soft colors of morning"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight streams through the narrow windows, illuminating the "
        "tower's scholarly carvings",
        ". The observatory's silhouette stands out against the brightening sky, "
        "its dome gleaming above the treetops",
        ". Scholars can sometimes be seen ascending the winding path, eager to "
        "study the heavens from the tower's heights"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the limestone walls are warm to the touch, and the dome's "
        "metal surface shines brightly under the sun",
        ". The observatory appears almost austere in the harsh light, its purpose "
        "clear in the simplicity of its design",
        ". The tower casts a short, dark shadow across the hilltop, a silent "
        "sentinel watching the sky"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The slanting afternoon sun brings out the textures of the ancient stone, "
        "highlighting patches of moss and lichen",
        ". Light glints off the dome, and the observatory seems to glow against the "
        "deepening blue of the sky",
        ". As the day wanes, the building takes on a golden hue, its scholarly air "
        "softened by the warmth of the sun"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the dome catches the last light, shining briefly before "
        "the stars begin to appear",
        ". The observatory becomes a gathering place for those eager to glimpse the "
        "night sky, its windows glowing with candlelight",
        ". The building stands ready for nightfall, its instruments prepared for "
        "celestial observation"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the observatory's silhouette is stark against the fading light, "
        "the dome reflecting the last colors of sunset",
        ". Shadows lengthen around the tower, and the first stars become visible "
        "above the dome",
        ". The observatory seems to hold its breath, waiting for the darkness and "
        "the mysteries it brings"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the dome is open to the sky, and faint lamplight spills from "
        "the arched windows",
        ". The observatory is alive with quiet activity, scholars peering through "
        "lenses at the stars above",
        ". The building becomes a beacon for knowledge, its presence marked by the "
        "soft glow of lanterns and the quiet murmur of study"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " surrounded by wildflowers and fresh grass, the hill alive with the sounds "
        "of returning birds",
        " where the air is crisp and clear, perfect for stargazing after the long winter",
        " as scholars gather to chart the changing constellations of the season"
        }));

    addSeasonDescription("summer", ({
        " with ivy climbing the lower stones and the dome gleaming in the long daylight",
        " where warm nights invite extended observation of the heavens",
        " as the hilltop is alive with the hum of insects and the distant calls of night birds"
        }));

    addSeasonDescription("autumn", ({
        " framed by trees shedding their leaves, the observatory stands out against "
        "the gold and crimson of the season",
        " where cool, clear nights offer the best views of the stars",
        " as scholars wrap themselves in cloaks, braving the chill for a glimpse of "
        "rare celestial events"
        }));

    addSeasonDescription("winter", ({
        " with snow dusting the dome and gathering in the crevices of the ancient stone",
        " standing stark and silent against the pale winter sky, its windows glowing warmly",
        " where the cold air brings exceptional clarity to the night sky, drawing "
        "dedicated astronomers to its heights"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate("a tall, shadowy tower with a rounded dome, "
        "its form barely visible atop the hill");

    addLowLightDescriptionTemplate("a cylindrical limestone building with a domed roof, "
        "its narrow windows faintly aglow");

    addDimLightDescriptionTemplate("an ancient observatory with mossy stones and a "
        "copper dome, perched above the surrounding land");

    addSomeLightDescriptionTemplate("a scholarly limestone observatory with a rounded dome "
        "and arched windows, standing tall on a grassy rise");

    addItemTemplate("The observatory is a tall, cylindrical tower of weathered limestone, "
        "topped with a copper-clad dome that can be opened to the sky. Narrow, arched "
        "windows are set at intervals along the walls, and the structure stands as a "
        "beacon of scholarly pursuit atop the grassy rise.");
}
