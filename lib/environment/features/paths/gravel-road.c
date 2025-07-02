//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gravel road");
    addAlias("road");
    addAlias("gravel");

    addAdjectives(({ "crunchy", "rough", "well-drained", "light-colored",
        "sturdy", "maintained", "all-weather", "durable", "practical", "gray" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " glistening with dew on upper stones",
        " emphasized with miniature shadows",
        " standing out as visible ribbon",
        " outlined in crystalline frost",
        " reflecting sound differently",
        " revealing subtle color variations",
        " sparkling with metallic inclusions",
        " remaining relatively dry",
        " clearly marked with animal tracks",
        " settling with temperature warming"
        }));

    addTimeOfDayDescription("morning", ({
        " releasing distinctive mineral scent",
        " revealed in careful engineering",
        " minimal in washboarding or rutting",
        " visible in varied stone composition",
        " transitioning from damp to loose",
        " reflecting significantly more light",
        " releasing moisture as faint vapor",
        " visited by stone-collecting birds",
        " carrying crunching sounds far",
        " banded in color variation layers"
        }));

    addTimeOfDayDescription("noon", ({
        " appearing uniformly bright white",
        " absorbing and radiating efficiently",
        " remaining dry when alternatives dusty",
        " contrasting maximally with vegetation",
        " briefly basking small creatures",
        " shifting audibly in loose sections",
        " forming heat shimmer above surface",
        " apparent in careful size sorting",
        " revealed in construction quality",
        " visible in full mineral spectrum"
        }));

    addTimeOfDayDescription("afternoon", ({
        " reflecting efficiently through terrain",
        " revealed in sharp shadow relief",
        " settling with heat adjustments",
        " loose enough for shifting stones",
        " transitioning thermally in sun/shade",
        " quickly channeling after rain showers",
        " refreshed in traffic patterns",
        " visible in structured cross-sections",
        " providing practical visibility advantages",
        " enhanced in stone type variations"
        }));

    addTimeOfDayDescription("evening", ({
        " transformed into warmer hues",
        " patterned strongly with shadows",
        " releasing heat more quickly",
        " changing character in cooling air",
        " efficiently reflecting available light",
        " beginning to settle with moisture",
        " glowing briefly in golden hour",
        " crossed more frequently by wildlife",
        " patterned in heat retention",
        " apparent in careful grading"
        }));

    addTimeOfDayDescription("dusk", ({
        " remaining visible longer",
        " settling with faint sounds",
        " important for navigation texture",
        " providing audio confirmation",
        " pronounced in temperature differences",
        " condensing moisture differently",
        " maintaining slightly better visibility",
        " utilized by nocturnal creatures",
        " subtle but detectible in microclimate",
        " continuing engineering benefits"
        }));

    addTimeOfDayDescription("night", ({
        " transformed into silvery ribbon",
        " sparkling with reflected stones",
        " providing significantly better visibility",
        " important for audio confirmation",
        " revealed as textural difference",
        " diminishing in temperature differences",
        " maintaining engineering value",
        " creating visible channel above",
        " occasionally gleaming with moisture",
        " followed by nocturnal wildlife"
        }));

    addTimeOfDayDescription("late night", ({
        " perceptible through texture and sound",
        " providing continuous confirmation",
        " maximized in temperature differences",
        " forming more heavily with moisture",
        " allowing starlight penetration",
        " providing secure footing",
        " marked by distinctive wildlife shifting",
        " patterned by stone composition dew",
        " providing equal engineering benefits",
        " remaining more stable than alternatives"
        }));

    addTimeOfDayDescription("midnight", ({
        " reduced to texture, sound, and structure",
        " completely surrendered to day's heat",
        " dampened with peak dew formation",
        " providing continued security",
        " indicated by settling or movement",
        " maintaining drainage through moisture",
        " heightened in distinctive awareness",
        " providing navigational reference",
        " detected through subtle slope changes",
        " serving regardless of hour"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " melting more quickly than terrain",
        " forming distinctive ice structures",
        " particularly valuable for drainage",
        " scoured or drifted by winds",
        " absorbing winter sunlight efficiently",
        " preventing frost heave damage",
        " contrasted with snow-covered surroundings",
        " concentrated with wildlife tracks",
        " visibly different with fresh application",
        " demonstrating practical construction wisdom"
        }));

    addSeasonDescription("spring", ({
        " revealing superb drainage capabilities",
        " thoroughly testing engineering",
        " depleted by winter requiring fresh stone",
        " contrasting with organic abundance",
        " warming more quickly in sunshine",
        " apparent in winter damage",
        " briefly established along margins",
        " newly smoothed by grading",
        " remaining functional when alternatives muddy",
        " proving worth during thaws"
        }));

    addSeasonDescription("summer", ({
        " reflecting efficiently almost white",
        " noticeably warmer than vegetation",
        " occasionally watered for dust control",
        " most clearly visible in construction",
        " solid when unpaved deteriorates",
        " creating distinctive wear patterns",
        " gradually rounded through use",
        " maintaining integrity properly built",
        " preventing erosion damage",
        " stable despite seasonal extremes"
        }));

    addSeasonDescription("autumn", ({
        " collecting leaves in irregular texture",
        " testing drainage capacity",
        " contrasting dramatically with vegetation",
        " reducing dust with cooler temperatures",
        " increased before winter",
        " emphasized in seasonal sunlight",
        " forming frost patterns before terrain",
        " particularly valuable deteriorating toward winter",
        " followed by wildlife migrations",
        " demonstrating versatility through weather"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## gravel road of carefully layered "
        "stone fragments creating a durable, well-drained thoroughfare");

    addItemTemplate("the gravel road demonstrates practical engineering with minimal "
        "materials-crushed stone of various sizes layered to create superior drainage "
        "and stability. The surface reveals its construction history through subtle "
        "variations in stone color and size, while the carefully maintained crown "
        "prevents water accumulation. Loose material at the edges transitions to a "
        "more compacted center where regular traffic has pressed the fragments into "
        "a surprisingly solid surface.");
}
