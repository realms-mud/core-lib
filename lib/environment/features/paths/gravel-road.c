//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gravel road");
    addAdjectives(({ "crunchy", "rough", "well-drained", "light-colored",
        "sturdy", "maintained", "all-weather", "durable", "practical", "gray" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where morning dew settles on the upper layer of stones, causing them to "
        "glisten subtly as the first rays of light catch their varied surfaces",
        " where the low angle of dawn illumination creates miniature shadows "
        "behind each stone, emphasizing the road's distinctive texture",
        " where the pale surface stands out against darker surroundings, creating "
        "a visible ribbon cutting through the misty landscape",
        " where occasional frost forms lacy patterns between the stones during "
        "cooler seasons, outlining each piece in crystalline white",
        " where birdsong carries differently along this corridor, the sound "
        "reflecting from the hard stone surface unlike softer surroundings",
        " where early morning moisture reveals the subtle color variations in the "
        "gravel mixture-grays, tans, and occasionally flecks of quartz",
        " where the first light catches on any metallic or crystalline inclusions "
        "in the stone, creating momentary sparkles along the roadway",
        " where the distinctive surface remains relatively dry compared to "
        "surrounding terrain, the excellent drainage quickly removing dew",
        " where animal tracks from nocturnal crossings remain clearly visible "
        "in the damp upper layer, recording the night's activities",
        " where the gradual warming causes minor settling sounds as moisture "
        "evaporates and stones shift microscopically with temperature change"
        }));

    addTimeOfDayDescription("morning", ({
        " where the drying surface releases the distinctive mineral scent of stone, "
        "a clean, dry aroma quite different from earthen pathways",
        " where the increasingly bright light reveals the careful engineering of "
        "the road-its subtle crown for drainage, packed foundation, and graded edges",
        " where well-constructed sections show minimal washboarding or rutting, "
        "testament to proper installation and regular maintenance",
        " where the stones' varied composition becomes increasingly visible-granite, "
        "limestone, quartz, and local rock types mingled in practical harmony",
        " where the texture transitions from damp compaction to drier looseness "
        "as the day progresses, altering both appearance and sound underfoot",
        " where the road's pale surface reflects significantly more light than "
        "surrounding terrain, creating a distinct visual pathway",
        " where the warming stones release any remaining moisture as faint vapor, "
        "occasionally visible in cooler weather as a subtle haze",
        " where birds sometimes visit to collect small stones for digestive use, "
        "selecting particular mineral types from the varied mixture",
        " where the distinctive crunching sound carries surprisingly far in the "
        "still morning air, announcing movement well before visual confirmation",
        " where the surface shows subtle bands of color variation as different "
        "layers of gravel become exposed through regular use patterns"
        }));

    addTimeOfDayDescription("noon", ({
        " where the overhead sun eliminates most shadows between the stones, "
        "creating a uniformly bright surface that can almost appear white",
        " where heat builds quickly in the exposed stones, the mineral composition "
        "absorbing and radiating solar energy more efficiently than soil",
        " where the road's superior drainage becomes most evident, remaining "
        "dry and stable when unpaved dirt alternatives might turn dusty",
        " where the contrast between the pale gravel and surrounding vegetation "
        "reaches maximum definition under the direct midday illumination",
        " where small lizards or insects might briefly bask on sun-warmed stones "
        "before retreating from the exposed surface's accumulating heat",
        " where occasional loose sections shift audibly under pressure, the "
        "distinctive sound marking areas needing maintenance or recompaction",
        " where heat shimmer sometimes forms just above the surface on especially "
        "warm days, the stone radiating accumulated thermal energy",
        " where the careful sorting of different stone sizes becomes apparent-"
        "larger base materials topped with progressively smaller grades",
        " where the quality of construction reveals itself in how the surface "
        "handles midday heat expansion, well-built sections remaining stable",
        " where the full spectrum of mineral colors is visible, from cool grays "
        "and blues to warmer tans and occasional rusty iron-bearing stones"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where the road's pale surface efficiently reflects the warming light, "
        "creating a ribbon of brightness through increasingly shadowed terrain",
        " where the angle of illumination once again creates distinct shadows "
        "between stones, revealing the surface texture in sharp relief",
        " where accumulated heat causes occasional settling sounds, tiny "
        "adjustments in the packed material audible during quieter moments",
        " where the gravel has completely dried, the surface loose enough that "
        "individual stones might shift slightly with each footfall",
        " where sections exposed to direct sun maintain significantly higher "
        "temperatures than adjacent shaded areas, creating thermal transitions",
        " where the drainage engineering shows its value after brief rain showers, "
        "the water quickly channeling away rather than forming puddles",
        " where the day's traffic has refreshed any tracks and impressions, "
        "creating patterns of use visible in the redistributed surface stones",
        " where the carefully structured layers become visible in cross-section "
        "along the edges, revealing the thoughtful engineering beneath",
        " where the light-colored surface provides practical visibility "
        "advantages as daylight begins its gradual decline",
        " where the subtle color variations between different stone types become "
        "enhanced in the warmer tones of afternoon illumination"
        }));

    addTimeOfDayDescription("evening", ({
        " where the declining sun transforms the ordinarily gray surface into "
        "warmer hues, briefly gilding the stone with amber light",
        " where lengthening shadows create strong textural patterns across the "
        "road, each stone casting a distinct dark projection",
        " where the cooling gravel releases the day's accumulated heat more "
        "quickly than surrounding terrain, creating detectible thermal boundaries",
        " where the distinctive sound changes character in the cooling air, "
        "the stones settling and contracting with temperature shifts",
        " where the pale surface continues reflecting available light efficiently, "
        "maintaining better visibility than darker alternatives",
        " where evening moisture might begin to settle between the stones, "
        "slightly dampening the surface and changing its acoustic properties",
        " where the road seems to glow briefly in the golden hour, standing out "
        "against the increasingly shadowed landscape surrounding it",
        " where wildlife more frequently crosses as temperatures moderate, "
        "their prints sometimes visible in looser sections of the surface",
        " where the gravel's mineral composition creates distinct patterns of "
        "heat retention, some stone types cooling more rapidly than others",
        " where the careful grading of the road becomes more apparent as "
        "shadows emphasize its subtle crown and drainage channels"
        }));

    addTimeOfDayDescription("dusk", ({
        " where the road remains visible longer than surrounding terrain, its "
        "pale surface continuing to reflect the diminishing ambient light",
        " where the cooling stones occasionally emit faint settling sounds, "
        "the surface adjusting microscopically to temperature changes",
        " where the textural difference between the road and adjacent ground "
        "becomes increasingly important for navigation as light fails",
        " where the distinctive crunching sound provides audio confirmation "
        "of correct path-finding when visual cues diminish",
        " where temperature differences between the rapidly cooling stone and "
        "more insulated surrounding terrain become more pronounced",
        " where moisture begins condensing differently on the mineral surface "
        "than on organic surroundings, altering reflective properties",
        " where the open corridor maintains slightly better visibility, the "
        "absence of overhanging vegetation preserving ambient light",
        " where nocturnal creatures begin utilizing the convenient pathway, "
        "their movement occasionally detectable by subtle shifts in the gravel",
        " where any remaining warmth in the stones creates a subtle but "
        "detectible microclimate just above the road's surface",
        " where the engineering that makes the road valuable in daylight-"
        "durability, drainage, stability-continues providing benefits at dusk"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight transforms the ordinary gray surface into a silvery "
        "ribbon winding through the darkened landscape",
        " where individual stones occasionally catch and reflect available "
        "light, creating a subtly sparkling effect under clear night skies",
        " where the pale surface provides significantly better visibility than "
        "darker alternatives, an advantage increasingly valued after sunset",
        " where the distinctive sound of movement across the gravel takes on "
        "heightened importance, providing audio confirmation of correct path",
        " where starlight reveals the road as a textural difference rather than "
        "color variation, the regular pattern distinct from natural ground",
        " where temperature differences from surrounding terrain diminish as the "
        "night progresses, though stone cools more completely than soil",
        " where the careful engineering maintains its value in darkness-stable "
        "footing, predictable surface, minimal hazards, reliable drainage",
        " where the open corridor above the road creates a visible channel "
        "through which stars and moon remain visible despite adjacent growth",
        " where moisture may begin to collect on the stones' surfaces, "
        "occasionally catching available light in momentary gleams",
        " where nocturnal wildlife often follows these convenient corridors, "
        "finding easier movement along the maintained surface"
        }));

    addTimeOfDayDescription("late night", ({
        " where the road's existence becomes primarily perceptible through "
        "texture and sound rather than visual identification",
        " where the distinctive crunch of footfalls provides continuous "
        "confirmation of remaining on the engineered surface",
        " where temperature differences reach their maximum, the stone surface "
        "having released heat more completely than insulated surroundings",
        " where moisture begins forming more heavily on the gravel, creating "
        "subtle changes in how the surface responds to weight and pressure",
        " where the open channel above sometimes allows starlight or moonlight "
        "to penetrate where it otherwise couldn't reach the ground",
        " where the carefully maintained surface provides secure footing even "
        "in minimal visibility, a crucial advantage in late hours",
        " where the stillness allows detection of subtle wildlife movements "
        "along or across the road, marked by distinctive shifting sounds",
        " where night dew forms patterns determined by stone composition and "
        "exposure, some sections collecting moisture before others",
        " where the careful engineering that makes daylight travel efficient "
        "provides equal benefits during challenging nighttime navigation",
        " where the well-drained surface remains more stable than alternatives, "
        "avoiding the muddy deterioration that affects earthen paths"
        }));

    addTimeOfDayDescription("midnight", ({
        " where the deepest darkness reduces the road to its fundamental "
        "characteristics-texture, sound, structure, and relative openness",
        " where the stones have completely surrendered the day's heat, the "
        "surface now cooler than surrounding vegetation-insulated earth",
        " where midnight dew reaches its peak formation, dampening the upper "
        "layer of stones and slightly altering their acoustic properties",
        " where the gravel's existence provides continued security even at this "
        "challenging hour, its engineered stability unaffected by darkness",
        " where occasional sounds of settling or minor wildlife movement may be "
        "the only indication of the road's continuing presence and function",
        " where the careful layering of different stone sizes maintains drainage "
        "even as surface moisture accumulates with night condensation",
        " where the absence of visual confirmation heightens awareness of the "
        "distinctive sound and feel that differentiates the road from surroundings",
        " where the corridor of open sky above sometimes provides navigational "
        "reference when stars or moon remain visible through darkness",
        " where the subtle crown of the road's center can be detected through "
        "careful attention to slope changes even without visual cues",
        " where the accumulated engineering intelligence that created this "
        "practical thoroughfare continues serving regardless of hour"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow often melts more quickly than on surrounding terrain, "
        "the stones' thermal properties creating different patterns of accumulation",
        " where ice forms differently on the mineral surface than organic "
        "surroundings, creating distinctive crystalline structures",
        " where the road's superior drainage becomes particularly valuable, "
        "preventing the dangerous pooling that leads to ice sheet formation",
        " where winter winds sometimes scour exposed sections entirely clear "
        "while building drifts across other portions, creating variable conditions",
        " where darker stones absorb available winter sunlight more efficiently, "
        "occasionally creating small zones of accelerated melting",
        " where the careful construction prevents the frost heaves that plague "
        "poorly built roads, the drainage layers allowing expansion without damage",
        " where the contrast between snow-covered surroundings and the partially "
        "visible road surface creates heightened visibility in winter landscapes",
        " where wildlife tracks concentrate along the partially cleared way, many "
        "species finding the gravel an easier route through snow-covered terrain",
        " where winter maintenance sometimes includes additional gravel application "
        "to improve traction, the fresh stones visibly different in color and angle",
        " where the road's continuing function through challenging conditions "
        "demonstrates the practical wisdom of its construction methods"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt reveals the road's superb drainage capabilities, water "
        "quickly channeling through the stone layers rather than pooling",
        " where spring rains thoroughly test the engineering, well-constructed "
        "sections maintaining integrity while poorly built areas show damage",
        " where maintenance crews may add fresh gravel to sections depleted by "
        "winter conditions, the new stone noticeably different in color and texture",
        " where the pale, dry surface contrasts sharply with the surrounding "
        "explosion of spring growth and color, a mineral line through organic abundance",
        " where the gravel warms more quickly than surrounding soil in spring "
        "sunshine, creating a microclimate that affects both moisture and vegetation",
        " where the winter's damage becomes fully apparent, from minor washboarding "
        "to more significant erosion requiring prompt attention",
        " where early spring flowers sometimes establish briefly along the margins "
        "before being disrupted by maintenance grading or traffic",
        " where fresh grading often occurs as weather permits, the newly smoothed "
        "surface showing distinctive patterns from maintenance equipment",
        " where the road demonstrates its all-weather capability, remaining "
        "functional when dirt alternatives become impassably muddy",
        " where the layered construction proves its worth during spring thaws, "
        "the carefully engineered base preventing the seasonal collapse of lesser roads"
        }));

    addSeasonDescription("summer", ({
        " where the light-colored surface reflects summer sun efficiently, "
        "the road appearing almost white under intense midday illumination",
        " where heat builds quickly in the exposed mineral surface, the stones "
        "becoming noticeably warmer than surrounding vegetation-covered terrain",
        " where maintenance may include occasional watering in populated areas, "
        "dampening the surface to control dust during the driest periods",
        " where the road's composition appears most clearly in full summer light, "
        "revealing the mixture of stone types and sizes used in its construction",
        " where the gravel remains solid and passable when unpaved dirt "
        "alternatives might deteriorate into dusty or deeply rutted conditions",
        " where increased traffic during peak season creates distinctive wear "
        "patterns, from twin wheel tracks to central crown compression",
        " where the stones' corners gradually round through summer use, the "
        "freshly angular pieces of spring maintenance becoming smoother",
        " where heat stress reveals construction quality, properly built sections "
        "maintaining integrity while poorly constructed areas deteriorate rapidly",
        " where the superior drainage prevents the erosion damage that summer "
        "cloudbursts inflict on less resilient road surfaces",
        " where the careful layering creates a remarkably stable surface despite "
        "the season's extremes of heat, drought, and occasional downpours"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect differently than on smoother surfaces, "
        "the irregular stone texture creating unique patterns of accumulation",
        " where autumn rains test the road's drainage capacity, well-engineered "
        "sections channeling water efficiently while problem areas form puddles",
        " where the pale mineral surface contrasts dramatically with the vibrant "
        "seasonal colors of surrounding vegetation",
        " where cooler temperatures reduce the dust associated with drier periods, "
        "the slightly damp surface maintaining better structural integrity",
        " where maintenance often increases before winter, additional gravel being "
        "applied to thin sections and drainage channels cleared of debris",
        " where the declining angle of seasonal sunlight emphasizes the road's "
        "texture, creating more pronounced shadows between individual stones",
        " where morning frost forms distinctive patterns on the gravel before "
        "surrounding terrain, the mineral surface cooling more completely overnight",
        " where the engineering that created this practical thoroughfare proves "
        "particularly valuable as conditions deteriorate toward winter",
        " where wildlife migrations might follow these reliable corridors, the "
        "maintained surface providing efficient passage through changing terrain",
        " where the road's continued function through autumn's challenging weather "
        "variations-from warm dry spells to freezing rain-demonstrates its versatility"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## gravel road cutting through the landscape, "
        "its surface composed of carefully layered stone fragments of varying sizes "
        "that create a durable, well-drained thoroughfare maintained through "
        "regular grading and periodic additions of fresh material");

    addItemTemplate("the gravel road demonstrates practical engineering with minimal "
        "materials-crushed stone of various sizes layered to create superior drainage "
        "and stability. The surface reveals its construction history through subtle "
        "variations in stone color and size, while the carefully maintained crown "
        "prevents water accumulation. Loose material at the edges transitions to a "
        "more compacted center where regular traffic has pressed the fragments into "
        "a surprisingly solid surface.");
}
