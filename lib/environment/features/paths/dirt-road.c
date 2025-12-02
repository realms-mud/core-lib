//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dirt road");
    addAlias("road");

    addAdjectives(({ "dusty", "rutted", "hard-packed", "wide", "well-used",
        "utilitarian", "maintained", "country", "rural", "weathered" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " darkened by morning dew",
        " with wheel ruts highlighted in the low light",
        " emerging from ground-hugging mist",
        " glistening with moisture in the early light",
        " showing fresh nocturnal tracks",
        " with frost patterns on the packed earth",
        " glowing briefly as dawn strikes the damp surface",
        " where drainage ditches fill with morning mist",
        " sharply defined against wild growth",
        " with geometric frost designs in cooler seasons"
        }));

    addTimeOfDayDescription("morning", ({
        " releasing moisture as visible vapor",
        " with efficient drainage from careful grading",
        " showing sharp relief of wheel tracks",
        " revealing patches of different soil types",
        " attracting small birds to dust-bathe",
        " changing color as it dries",
        " clearly delineated from surroundings",
        " with subtle crown apparent at center",
        " revealing different construction materials",
        " showing natural traffic lane separation"
        }));

    addTimeOfDayDescription("noon", ({
        " releasing small dust clouds when disturbed",
        " with heat shimmer above dark sections",
        " flattened visually by lack of shadows",
        " creating a warm microclimate above surface",
        " contrasting with vegetation in ditches",
        " appearing at full width importance",
        " overlaid with fresh midday tracks",
        " showing engineering in culverts and grading",
        " with temperature transitions in shaded areas",
        " problematic with easily disturbed dust"
        }));

    addTimeOfDayDescription("afternoon", ({
        " with heat distortion visible along its length",
        " carrying small dust clouds in any breeze",
        " textured differently in warm afternoon light",
        " accommodating meeting traffic in its width",
        " with shadows emphasizing ruts and ridges",
        " refreshed by day's heaviest traffic patterns",
        " cooling in shadier sections",
        " showing soil responses to extended heat",
        " kept dry by drainage engineering",
        " appearing amber and umber in warm colors"
        }));

    addTimeOfDayDescription("evening", ({
        " with lengthy shadows from every ridge",
        " releasing stored solar heat",
        " creating visible boundary layer of warm air",
        " with settling dust coating roadside vegetation",
        " softening visually while structurally distinct",
        " appreciated for reliable surface as light dims",
        " with dark parallel drainage lines",
        " recording the day's passage clearly",
        " creating a warm detectable corridor",
        " bringing out rich earthy aromas"
        }));

    addTimeOfDayDescription("dusk", ({
        " transformed into textures rather than colors",
        " with potential for mist along edges",
        " remaining visible longer than surroundings",
        " relied upon through feel underfoot",
        " providing guidance through surface sounds",
        " accepting moisture differently across width",
        " perceptible through subtle slope changes",
        " bordered by emerging nocturnal creatures",
        " radiating heat hours after sunset",
        " providing psychological comfort as light fades"
        }));

    addTimeOfDayDescription("night", ({
        " transformed into a silver band by moonlight",
        " creating a corridor of visibility",
        " with subtle temperature boundaries",
        " providing navigational cues through sound",
        " resisting moisture with retained warmth",
        " with pools of open space at wider sections",
        " seeming to glow faintly to dark eyes",
        " used frequently by nocturnal wildlife",
        " apparent through touch and gravity cues",
        " providing confident navigation in darkness"
        }));

    addTimeOfDayDescription("late night", ({
        " primarily navigable through texture differences",
        " with thermal mass still registering differently",
        " showing dew formation by composition",
        " utilized by nocturnal creatures",
        " revealing distinctive settling sounds",
        " with pools of visibility under starlight",
        " perceived through sound environment changes",
        " providing psychological security",
        " marked by changing dew and wildlife patterns",
        " functioning through engineered drainage systems"
        }));

    addTimeOfDayDescription("midnight", ({
        " reduced to texture, direction, and openness",
        " with stillest air allowing dust to settle",
        " with minimal temperature differences remaining",
        " amplifying movement sounds",
        " softened by maximum dew formation",
        " creating a ribbon of visible sky",
        " serving wildlife continuously",
        " providing reliable passage regardless of light",
        " complex in scent with night aromatics",
        " persisting as testament to human intervention"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " with snow revealing precise crown grading",
        " allowing continued use in harsh conditions",
        " tested by freezing and thawing cycles",
        " sometimes cleared by wind patterns",
        " preventing dangerous ice formation",
        " altered by frost heaves",
        " showing packed-snow traffic tracks",
        " providing crucial connections when needed",
        " marked by posts in snow-obscured sections",
        " vital for survival in harshest periods"
        }));

    addSeasonDescription("spring", ({
        " revealing careful drainage engineering",
        " challenged by mud season",
        " receiving repairs from winter damage",
        " forming puddles in depressions",
        " distinct from rapidly reclaiming growth",
        " channeling water through design",
        " followed by spring wildlife migrations",
        " changing visibly as it dries",
        " bordered by early flowers",
        " refreshed by returning traffic"
        }));

    addSeasonDescription("summer", ({
        " defined by rising dust",
        " revealing complete soil composition",
        " creating heat distortion above surface",
        " contrasting sharply with vegetation",
        " supporting specialized plant communities",
        " tested by summer storm drainage",
        " sometimes dampened to control dust",
        " creating distinctive microclimates",
        " demonstrating engineering in dry periods",
        " recording heavy seasonal commerce"
        }));

    addSeasonDescription("autumn", ({
        " collecting leaves differently than surroundings",
        " crucial for drainage during autumn rains",
        " receiving final maintenance before winter",
        " showing frost patterns by composition",
        " tested by increased rainfall",
        " emphasized by declining light angle",
        " responding differently as moisture shifts",
        " followed by wildlife migrations",
        " contrasting with vegetation transformation",
        " valued more as winter approaches"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## dirt road cutting through the "
        "landscape with packed earth and simple drainage");

    addItemTemplate("the dirt road reveals thoughtful engineering despite its "
        "simple materials, with a subtle crown for drainage and parallel ditches "
        "along the sides. Years of traffic have created distinctive patterns "
        "across its width-twin ruts from wheeled vehicles, smoother central "
        "ridges from hoof traffic, and softer margins where passage is less "
        "frequent. The packed earth surface shows varying textures and colors "
        "where different materials have been added for stability.");
}
