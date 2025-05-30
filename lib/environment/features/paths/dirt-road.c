//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dirt road");
    addAdjectives(({ "dusty", "rutted", "hard-packed", "wide", "well-used",
        "utilitarian", "maintained", "country", "rural", "weathered" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where morning dew darkens the surface to a rich umber hue, highlighting "
        "the wheel ruts and hoof impressions from previous days",
        " where wisps of ground-hugging mist often follow the depression of the "
        "roadway, creating an ethereal path through the landscape",
        " where the first light reveals the complex textures of the surface—packed "
        "central sections, softer margins, and transitional borders",
        " where birdsong carries differently along this open corridor, creating "
        "a distinct acoustic channel through otherwise dense terrain",
        " where the low angle of dawn light emphasizes every ridge and furrow, "
        "casting long shadows from even minor surface variations",
        " where the roadway appears to glow briefly as the first golden rays "
        "strike its damp surface, standing out against shadowed surroundings",
        " where fresh tracks from nocturnal creatures remain clearly visible "
        "in the damper sections, recording the night's movements",
        " where drainage ditches along the sides sometimes fill with morning mist, "
        "creating parallel ribbons of vapor flanking the main surface",
        " where the distinct boundary between the deliberately maintained road "
        "and the wild growth alongside becomes sharply defined in dawn light",
        " where frost patterns in cooler seasons form distinctively on the "
        "compacted surface, creating temporary geometric designs"
        }));

    addTimeOfDayDescription("morning", ({
        " where the warming earth begins to release moisture as visible vapor, "
        "creating a subtle haze above the darker surface",
        " where the road's careful grading becomes apparent as morning dew drains "
        "efficiently away rather than forming puddles or muddy sections",
        " where wheel tracks from previous days' traffic stand in sharp relief, "
        "the parallel ruts defining the preferred paths along the width",
        " where patches of different soil types reveal the road's history of "
        "repairs and maintenance, each section wearing differently with use",
        " where small birds might gather to dust-bathe in drier sections or pick "
        "at seeds that have fallen from passing loads",
        " where gradual drying creates a progression of color changes across the "
        "surface, from darker dampness to lighter dry earth",
        " where the distinction between road and surrounding terrain reaches peak "
        "visibility, the maintained corridor clearly delineated",
        " where the subtle crown of the road's center becomes apparent, centuries "
        "of careful grading creating efficient drainage to the sides",
        " where the morning light reveals different soil textures used in "
        "construction—clay for binding, gravel for drainage, sand for stability",
        " where the wider berth of the dirt road compared to simple paths allows "
        "observation of how traffic naturally separates into lanes"
        }));

    addTimeOfDayDescription("noon", ({
        " where the fully dried surface might release small clouds of dust when "
        "disturbed, the fine particles temporarily hanging in still air",
        " where heat shimmer becomes visible above the darkest sections, the road "
        "absorbing and radiating the midday sun's intensity efficiently",
        " where the complete lack of shadows flattens the visual texture, briefly "
        "minimizing the appearance of ruts and irregularities",
        " where the exposed surface reaches its maximum temperature, creating a "
        "distinct warm microclimate just above the roadway",
        " where any moisture-loving vegetation along the drainage ditches stands "
        "in stark contrast to the dry central thoroughfare",
        " where the road's full width becomes most apparent, its broad swath "
        "through the landscape speaking to its commercial importance",
        " where midday traffic has created the day's first fresh tracks, overlaying "
        "the preserved impressions from previous passages",
        " where the deliberate engineering becomes most evident—carefully placed "
        "culverts, strategic grading, reinforced edges in vulnerable sections",
        " where the contrast between sunny exposed stretches and shaded sections "
        "creates dramatic transitions in surface temperature and moisture",
        " where the fine dust that characterizes many dirt roads becomes most "
        "problematic, easily disturbed and slow to settle in still air"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where the heat-soaked surface creates a distinct boundary layer of warm "
        "air, visible as slight distortion when viewed along its length",
        " where any breeze might carry small dust clouds from the driest sections, "
        "temporarily marking the passing of air currents",
        " where the western-facing slopes and features catch warm afternoon light, "
        "creating a textured appearance quite different from morning's view",
        " where the greater width accommodates meeting traffic, the roadway's "
        "dimensions carefully planned for practical commerce",
        " where lengthening shadows begin to emphasize the road's texture again, "
        "the ruts and ridges casting visible patterns across the width",
        " where the day's heaviest use has refreshed the surface patterns, new "
        "tracks overlaying older impressions in the compacted earth",
        " where comparative coolness begins to return to shadier sections while "
        "exposed stretches continue radiating accumulated heat",
        " where the different soil components respond distinctively to extended "
        "heat—clay cracking slightly, sandy sections shifting, gravel stable",
        " where the distinct engineering of drainage features becomes apparent, "
        "ditches and culverts keeping the mainline dry despite surrounding terrain",
        " where the warm colors of the dirt reach their richest hues, the road "
        "appearing as a ribbon of amber and umber through the landscape"
        }));

    addTimeOfDayDescription("evening", ({
        " where the declining sun casts lengthy shadows from every ridge and rut, "
        "creating a highly textured appearance across the entire width",
        " where the road appears to glow briefly as it releases stored solar "
        "heat, standing out thermally against more rapidly cooling surroundings",
        " where cooling air above the still-warm surface sometimes creates a "
        "visible boundary layer, a slight haze marking the road's course",
        " where the day's dust begins to settle more permanently as air movement "
        "calms, fine particles coating roadside vegetation near high-traffic areas",
        " where the contrast between the maintained surface and wilder surroundings "
        "softens visually while remaining structurally distinct",
        " where the road's deliberate engineering becomes most appreciated, its "
        "reliable surface providing confident passage as light diminishes",
        " where drainage ditches collect evening shadows first, creating dark "
        "parallel lines that emphasize the road's course through the landscape",
        " where the day's record of passage remains clearly visible, the most "
        "recent tracks overlaying older patterns in the compacted surface",
        " where the road retains heat longer than surrounding areas, creating a "
        "warm corridor detectable even without visual confirmation",
        " where evening moisture begins to affect the scent profile, bringing out "
        "rich earthy aromas from the road's mineral and organic components"
        }));

    addTimeOfDayDescription("dusk", ({
        " where the fading light reduces color perception, transforming the road "
        "into a study of textures rather than hues",
        " where temperature differences between the road and surroundings become "
        "more pronounced, creating potential for mist formation along the edges",
        " where the open corridor permits slightly longer visibility than adjacent "
        "areas, the road remaining discernible after surroundings darken",
        " where navigation increasingly relies on the feel of the compacted surface "
        "underfoot as visual cues diminish with failing light",
        " where the distinct sounds of movement along the road provide additional "
        "guidance—the crunch of the harder surface different from softer margins",
        " where evening dew forms differential patterns, the road's varied "
        "composition accepting moisture differently across its width",
        " where the road's careful grading remains perceptible through subtle slope "
        "changes even as detailed visibility diminishes",
        " where nocturnal creatures begin to emerge along the edges, many species "
        "using the road as a boundary marker between territories",
        " where the day's accumulated heat continues radiating from the surface, "
        "creating a thermal signature detectable hours after sunset",
        " where the structured nature of the road provides psychological comfort "
        "as natural light fades, its purposeful course a human-made constant"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight transforms the ordinary surface into a silver band "
        "stretching through darker surroundings",
        " where the open sky above creates a corridor of visibility, starlight "
        "reaching the road where it might be blocked from adjacent areas",
        " where the thermal properties of the compacted earth create subtle "
        "temperature boundaries detectable even in darkness",
        " where the distinctive sound of movement along the road provides "
        "navigational cues—the packed surface creating different acoustics than "
        "surrounding terrain",
        " where night dew forms more slowly on the road than on surrounding "
        "vegetation, the retained warmth temporarily resisting moisture",
        " where occasional wider sections or engineered passing areas create "
        "pools of open space, particularly visible under clear night skies",
        " where the road sometimes seems to glow faintly to dark-adapted eyes, "
        "the mineral content reflecting available light differently than surroundings",
        " where nocturnal wildlife frequently uses the efficient corridor for "
        "movement, many species preferring the open route through complex terrain",
        " where the careful grading remains apparent through touch and subtle "
        "gravitational cues even when visual confirmation is impossible",
        " where the road's deliberate course provides confidence in navigation "
        "during darkness, its engineered direction rarely leading astray"
        }));

    addTimeOfDayDescription("late night", ({
        " where the texture difference between the road and surrounding terrain "
        "remains the primary navigational cue in limited visibility",
        " where temperature differences have largely equilibrated, though the "
        "road's thermal mass may still register slightly differently",
        " where dew formation progresses according to the varying composition of "
        "the road surface, some sections darkening before others",
        " where nocturnal creatures continue to utilize the convenient corridor, "
        "their movements occasionally visible as subtle disturbances",
        " where the quieter hours reveal the distinctive sounds of the road "
        "itself—minor settling, the soft crunch of frost formation in cold seasons",
        " where occasional clearings or wider sections create pools of relatively "
        "greater visibility under starlight or moonlight",
        " where the road's course through the landscape may be perceived through "
        "changes in the sound environment as much as visual cues",
        " where the structured nature of the road provides psychological security "
        "during the deepest hours, its purposeful existence a comfort",
        " where the night's progression can be marked by changes in dew formation "
        "and wildlife activity along the road's course",
        " where the complete engineered system—drainage ditches, culverts, graded "
        "surface—continues functioning regardless of illumination or hour"
        }));

    addTimeOfDayDescription("midnight", ({
        " where the deepest darkness reduces the road to its essential "
        "characteristics—texture, direction, and relative openness",
        " where complete night often brings the stillest air, allowing dust to "
        "fully settle and scents to stratify in complex layers",
        " where temperature differences between road and surroundings reach their "
        "minimum, though subtle variations remain detectable",
        " where the quietest hours amplify the different sounds produced by "
        "movement on the road versus through adjacent terrain",
        " where maximum dew formation may temporarily soften the road's surface, "
        "changing its texture and scent profile until morning's drying",
        " where the open corridor above the road creates a ribbon of visible sky "
        "even in the darkest hours, stars serving as navigational references",
        " where nocturnal life continues regardless of human activity, the road "
        "serving wildlife needs continuously through day and night cycles",
        " where the engineering that creates reliable passage during daylight "
        "continues to provide benefits through the challenging midnight hours",
        " where the scent profile reaches its most complex state, the day's "
        "accumulated impressions mixing with night's unique aromatics",
        " where the accumulated history of the road's creation and maintenance "
        "persists regardless of visibility, a testament to purposeful intervention"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow reveals the precise grading of the road's crown, often "
        "melting first from the center where traffic concentrates",
        " where the broader width compared to simple paths makes winter "
        "maintenance more feasible, allowing continued use in harsh conditions",
        " where freezing and thawing cycles test the road's construction, revealing "
        "both ingenious engineering solutions and problematic sections",
        " where wind patterns along the open corridor sometimes clear snow "
        "completely from exposed sections while building drifts across others",
        " where the carefully planned drainage systems prove critical, preventing "
        "the dangerous ice formation that makes winter travel hazardous",
        " where frost heaves may temporarily alter the road's normally smooth "
        "profile, the ground beneath expanding and contracting with temperature",
        " where winter traffic creates distinctive packed-snow tracks, often "
        "revealing the transition from wheels to runners as conditions change",
        " where the road's importance becomes most evident, its maintained surface "
        "providing crucial connections when other routes become impassable",
        " where strategic placement of marker posts or distinctive features helps "
        "define the road's edges when snow threatens to obscure boundaries",
        " where survival itself sometimes depends on finding and following these "
        "engineered routes between settlements during winter's harshest periods"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt reveals the road's careful engineering, drainage systems "
        "efficiently channeling water away from the main surface",
        " where mud season creates the road's greatest annual challenge, its "
        "composition and construction tested by excess moisture",
        " where repairs often begin as weather permits, fresh materials being "
        "applied to sections damaged by winter's freeze-thaw cycles",
        " where puddles form in any depressions or ruts, sometimes remaining for "
        "days before the combination of drainage and evaporation removes them",
        " where the distinct boundary between road and surroundings becomes most "
        "pronounced, spring growth quickly reclaiming any untrafficked areas",
        " where temporary streams sometimes form along drainage ditches, the road's "
        "design turning potential damage into controlled water management",
        " where spring migrations of wildlife and birds often follow these "
        "established routes, the clear corridors providing efficient passage",
        " where the road's composition changes visibly as it dries, revealing the "
        "different materials used in its construction and maintenance",
        " where early flowers may appear along the margins before surrounding "
        "areas, the disturbed soil and increased sunlight creating ideal conditions",
        " where returning traffic after winter's relative quiet quickly refreshes "
        "the road's surface patterns, new impressions overlaying winter's damage"
        }));

    addSeasonDescription("summer", ({
        " where dust becomes the defining characteristic, fine particles rising "
        "with every disturbance and settling on adjacent vegetation",
        " where the fully dry surface reveals its complete composition—clay for "
        "binding, gravel for structure, sand for drainage, earth for mass",
        " where heat creates visible distortion above the darkest sections, the "
        "road absorbing and radiating summer sun with particular efficiency",
        " where the contrast between the road and surrounding vegetation reaches "
        "its peak, boundaries clearly defined by growth patterns",
        " where specialized road-edge plant communities thrive, species adapted "
        "to both the disturbed soil conditions and regular dust coating",
        " where summer storms test drainage systems, the road's careful grading "
        "determining whether water flows safely away or creates damaging erosion",
        " where dry conditions sometimes require water application in settled areas, "
        "deliberate dampening controlling problematic dust near habitations",
        " where heat patterns create distinctive microclimates along the route, "
        "affecting both wildlife behavior and vegetation distribution",
        " where the road's full engineering becomes most apparent during extended "
        "dry periods, its resilient construction maintaining functionality",
        " where increased summer traffic creates the year's heaviest use patterns, "
        "the surface recording the commerce of the productive season"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect differently on the road than in surrounding "
        "areas, sometimes filling ruts or collecting against any raised edges",
        " where the road's drainage features become crucial during autumn rains, "
        "channeling water away from the surface to prevent deterioration",
        " where preparation for winter might include final maintenance work, "
        "critical repairs being completed before harsh conditions arrive",
        " where morning frost forms distinctive patterns on the road's surface, "
        "revealing subtle moisture and composition differences across its width",
        " where increased rainfall tests the road's construction, revealing both "
        "well-designed sections and areas needing attention before winter",
        " where the declining angle of seasonal light emphasizes the road's "
        "texture, long shadows highlighting features invisible in summer",
        " where falling temperatures begin to change the road's physical properties, "
        "the surface responding differently to traffic as moisture content shifts",
        " where seasonal wildlife migrations might follow these established routes, "
        "the clear corridor providing efficient passage through changing terrain",
        " where the contrast between the road's relatively static appearance and "
        "the dramatic transformation of surrounding vegetation becomes notable",
        " where the road's resilient engineering provides confidence as seasonal "
        "conditions deteriorate, its purpose more valued as winter approaches"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## dirt road cutting through the landscape, "
        "its surface showing deliberate construction and maintenance with "
        "packed earth, strategic grading, and simple drainage features creating "
        "a durable thoroughfare wider than a path but less formal than a "
        "paved highway");

    addItemTemplate("the dirt road reveals thoughtful engineering despite its "
        "simple materials, with a subtle crown for drainage and parallel ditches "
        "along the sides. Years of traffic have created distinctive patterns "
        "across its width—twin ruts from wheeled vehicles, smoother central "
        "ridges from hoof traffic, and softer margins where passage is less "
        "frequent. The packed earth surface shows varying textures and colors "
        "where different materials have been added for stability. ##UseDescriptionSet##");
}
