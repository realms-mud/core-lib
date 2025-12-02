//*****************************************************************************
//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large museum");
    setFloorPlanType("museum");

    addAdjectives(({ "grand", "majestic", "magnificent", "ornate",
        "prestigious" }));

    // Basic description template
    addDescriptionTemplate("a ##Adjective## marble museum with imposing columns "
        "and a broad staircase leading to the entrance");

    // Add time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the marble facade, giving the stone "
        "a soft pink glow that enhances the building's classical beauty",
        ". Dawn light casts long shadows behind the towering columns, creating "
        "dramatic silhouettes across the entrance plaza",
        ". In the stillness of early morning, the museum stands as a silent "
        "guardian of knowledge, its marble gleaming with subtle promise"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight illuminates the intricate friezes adorning the "
        "pediment, bringing the carved figures almost to life",
        ". As the sun rises higher, visitors begin to ascend the grand staircase, "
        "dwarfed by the massive columns flanking the entrance",
        ". The morning light reveals the meticulous craftsmanship of the stone "
        "carvings, each detail standing out in sharp relief"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the brilliant white marble seems to glow against the "
        "blue sky, the building embodying the ideals of classical architecture",
        ". Under the full light of day, the museum's grand proportions become "
        "most apparent, its design intended to inspire awe in visitors",
        ". Noon sunlight casts almost no shadows, giving the marble facade a "
        "uniform brightness that highlights its monumental scale"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The westering sun warms the stone to a golden hue, softening the "
        "building's imposing presence while emphasizing its grandeur",
        ". Afternoon light strikes the massive windows, creating bright "
        "reflections that contrast with the deepening shadows of the portico",
        ". As the day advances, the carved details catch shadows that accentuate "
        "their depth, adding drama to the building's classical lines"
        }));

    addTimeOfDayDescription("evening", ({
        ". With evening's approach, carefully positioned lights begin to "
        "illuminate the facade, dramatically highlighting architectural features",
        ". The fading daylight transitions seamlessly to the glow of artfully "
        "hidden spotlights, keeping the museum's grandeur visible into the night",
        ". Evening transforms the building from an imposing institution to a "
        "luminous monument, its white marble taking on an almost ethereal quality"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the building seems suspended between worlds, the last "
        "natural light fading as artificial illumination brings new focus",
        ". The transitional light of dusk creates mysterious shadows among "
        "the columns, giving the museum an ancient, timeless quality",
        ". As darkness falls, strategically placed lights activate in sequence, "
        "gradually revealing the building's architectural splendor"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, dramatic lighting accentuates the columns and sculptural "
        "elements, making the museum a beacon of culture in the darkness",
        ". Moonlight combines with artificial illumination to create a "
        "striking contrast between light and shadow across the marble surfaces",
        ". The night transforms the museum into a different kind of spectacle, "
        "its lit facade standing out against the dark sky like a cultural beacon"
        }));

    // Add seasonal variations
    addSeasonDescription("spring", ({
        " with carefully maintained flower beds adding vibrant color to the "
        "stark elegance of the marble structure",
        " where ornamental trees lining the approach burst with fresh blossoms, "
        "softening the building's monumental presence",
        " as touring groups gather on the steps under the warming spring sun, "
        "eager to explore the treasures housed within"
        }));

    addSeasonDescription("summer", ({
        " where the white marble radiates the accumulated heat of the sun, "
        "creating a shimmering effect in the summer haze",
        " with the grand doors held open, offering glimpses of the cool interior "
        "that provides welcome respite from the summer heat",
        " surrounded by meticulously maintained gardens at their summer peak, "
        "the landscaping designed to complement the building's classical lines"
        }));

    addSeasonDescription("autumn", ({
        " framed by trees whose changing leaves provide a striking contrast "
        "to the timeless white stone of the building",
        " where fallen leaves occasionally drift across the broad entrance plaza, "
        "small splashes of color against the monumental stonework",
        " as the slanting autumn light emphasizes the texture of the carved "
        "marble, highlighting details often missed in harsher illumination"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering on the steps and cornices, adding another layer "
        "of sculptural beauty to the already impressive architecture",
        " standing pristine against the winter sky, its white marble almost "
        "indistinguishable from the snow that dusts its surfaces",
        " where the warmly lit interior visible through massive windows offers "
        "an inviting contrast to the cold, classical exterior"
        }));

    // Add lighting condition descriptions
    addNearDarkDescriptionTemplate("a massive silhouette with regularly spaced "
        "columns, its form suggesting a building of considerable importance");

    addLowLightDescriptionTemplate("a large structure with classical columns "
        "and what appears to be a broad staircase leading to the entrance");

    addDimLightDescriptionTemplate("an impressive building with marble columns "
        "and elaborate carvings visible along its facade");

    addSomeLightDescriptionTemplate("a grand marble museum with towering "
        "columns and intricate sculptural details adorning its classical facade");

    // Single item template
    addItemTemplate("The imposing structure features a classical design with "
        "massive fluted columns supporting a triangular pediment adorned with "
        "elaborate reliefs depicting scenes of historical and artistic "
        "significance");
}
