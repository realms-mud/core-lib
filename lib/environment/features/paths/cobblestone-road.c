//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cobblestone road");
    addAdjectives(({ "well-maintained", "moss-covered", "weathered",
        "meandering", "sturdy", "expertly-laid", "worn", "smooth", "elegant" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where moisture from the night settles on the stones, giving the surface "
        "a glistening sheen as the first rays of sunlight touch the road",
        " where the first light reveals the varying shades and textures of the "
        "stones, each one uniquely highlighted in the angled illumination",
        " where small puddles between stones catch the golden light, creating "
        "scattered points of brilliance along the roadway",
        " where morning mist often clings to the lower sections, the cobblestones "
        "emerging like islands from a gentle fog sea",
        " where dew droplets form primarily along the mortar lines, emphasizing "
        "the geometric pattern of the road's construction",
        " where the cool stones release visible wisps of vapor as they begin to "
        "warm in the first light of day",
        " where the road appears to glow subtly as dawn light reflects off the "
        "moisture-covered stones after a quiet night",
        " where the eastern faces of raised stones catch direct light while "
        "western faces remain in cool shadow, creating a dappled effect",
        " where the surface's irregularities cast long, exaggerated shadows "
        "that will shorten and disappear as the sun climbs higher",
        " where bird tracks can sometimes be seen in the moisture between "
        "stones, recording the early morning activities of local wildlife"
        }));

    addTimeOfDayDescription("morning", ({
        " where the warming stones begin to dry from the previous night's dew, "
        "revealing their varied colors and textures more clearly",
        " where the low angle of morning light emphasizes the contours and joins "
        "between individual stones, highlighting the craftsmanship of the road",
        " where small tufts of hardy grass and moss cling to life between certain "
        "stones, adding touches of green to the mineralized pathway",
        " where the edges of the roadway show the distinct boundary between "
        "constructed thoroughfare and the natural ground alongside",
        " where the warming surface begins to release the scents of the stones "
        "themselves - mineral, earthy, and sometimes slightly mossy",
        " where shadows retreat steadily across the surface as the morning "
        "progresses, revealing the full spectrum of stone colors",
        " where occasional loose stones might rock slightly when pressure is "
        "applied, evidence of the constant need for maintenance",
        " where the road's careful grading becomes evident as morning dew drains "
        "efficiently away rather than pooling on the surface",
        " where the stones' varied composition becomes apparent - some with quartz "
        "veins that catch the light, others with fossil imprints from ancient seas",
        " where the surface temperature rises noticeably with each passing hour, "
        "the dark stones absorbing the strengthening sunlight"
        }));

    addTimeOfDayDescription("noon", ({
        " where the sun directly overhead eliminates most shadows between the "
        "stones, creating a uniform surface that reflects heat back upward",
        " where heat shimmer can sometimes be seen rising from the hottest "
        "sections, distorting the view along lengthy straight stretches",
        " where the stones have fully dried except in the deepest recesses, "
        "revealing the full range of colors from slate blue to warm amber",
        " where occasional lizards might bask on the sun-warmed surface, "
        "quickly retreating to crevices when disturbed",
        " where the distinction between lighter and darker stones becomes most "
        "pronounced, the darker specimens absorbing significantly more heat",
        " where the geometric precision of the road's construction is displayed "
        "to full advantage in the shadowless midday illumination",
        " where the crown of the road becomes most evident, its subtle central "
        "ridge designed to shed water toward the edges",
        " where any metal inclusions in the stones might become hot enough to "
        "singe unwary bare feet or paws crossing without caution",
        " where dust might collect in the driest depressions, occasionally rising "
        "in tiny clouds when disturbed by wind or movement",
        " where the boundaries between individual stones seem to diminish as "
        "the harsh direct light minimizes the shadows that define their edges"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where the lengthening shadows accentuate the texture of the road, "
        "each stone casting a tiny shadow that gives depth to the surface",
        " where the western face of each slightly raised stone catches the warm "
        "light, creating a subtly dappled pattern across the road's width",
        " where the cooling begins at the shaded eastern edges while the "
        "sun-exposed western side remains noticeably warmer",
        " where the stones have absorbed the day's heat and now radiate it "
        "steadily upward, creating a warm microclimate just above the surface",
        " where elongated shadows from adjacent trees or structures create "
        "striped patterns that move slowly across the cobblestones",
        " where insects might gather in the warming crevices as larger stones "
        "provide shelter from the cooling afternoon breeze",
        " where the road becomes a ribbon of retained warmth, contrasting with "
        "the more rapidly cooling natural surfaces nearby",
        " where the declining sun brings out richer, warmer tones in the stones, "
        "particularly those with red or golden mineral content",
        " where the subtle unevenness of the surface becomes more apparent as "
        "angled light creates small shadow pools in every depression",
        " where birds might briefly land to capture insects drawn to the "
        "warmth still radiating from the sun-baked cobblestones"
        }));

    addTimeOfDayDescription("evening", ({
        " where the cooling stones release the day's accumulated heat, sometimes "
        "creating a slight mist that hovers just above the road surface",
        " where the oblique light of sunset brings out the richest colors in the "
        "stones, from warm amber and russet to deep gray and charcoal",
        " where the last direct sunlight catches only the tallest stones, "
        "creating islands of illumination in a sea of advancing shadow",
        " where declining temperatures cause the stones to contract slightly, "
        "occasionally resulting in faint settling sounds as pressure shifts",
        " where small nocturnal creatures begin to emerge from hiding places "
        "near the roadside, drawn to the residual warmth of the cobblestones",
        " where the road becomes increasingly defined by its texture rather than "
        "visual appearance as direct light fades from the landscape",
        " where the heat signature of the road makes it distinctly warmer than "
        "surrounding areas, detectable even without touching the surface",
        " where any remaining moisture from the day creates scattered reflections "
        "of the deepening colors of sunset",
        " where the stones' mineral composition creates subtle variations in "
        "cooling rates, some sections remaining warm long after others cool",
        " where the boundary between road and surroundings becomes less distinct "
        "as shadow claims both, though the difference in texture remains"
        }));

    addTimeOfDayDescription("dusk", ({
        " where the road becomes a ribbon of relative lightness against the "
        "darkening landscape, guiding travelers until the last light fades",
        " where the individual stones become less distinct as details merge into "
        "the general form of the road stretching into the gathering darkness",
        " where any remaining heat creates a temperature boundary detectable "
        "when crossing from natural ground onto the constructed surface",
        " where the cobblestones retain enough warmth to occasionally dry "
        "evening dew that settles on cooler surrounding surfaces",
        " where bats might swoop low over the open corridor, hunting insects "
        "attracted to the residual warmth rising from the stones",
        " where the contrasting textures of smooth stones and rough mortared "
        "joints become more apparent to the touch as visibility diminishes",
        " where the road's careful engineering provides a stable surface that "
        "remains navigable even as visual cues diminish with the light",
        " where nocturnal creatures seeking warmth might be found near or on "
        "the stones that release heat accumulated during daylight hours",
        " where the last visible detail is often the subtle crown of the road, "
        "its raised center catching the final ambient light",
        " where the more reflective stones continue to respond to minimal "
        "illumination long after matte surfaces have disappeared into darkness"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight transforms the cobblestones into a silvery pathway, the "
        "smoother stones reflecting more light than the rougher surroundings",
        " where the solid construction provides sure footing even in darkness, "
        "the regularities and irregularities becoming familiar through touch",
        " where starlight catches occasionally on quartz veins or mica flecks "
        "embedded in certain stones, creating tiny points of reflection",
        " where the thermal signature of the road remains distinct hours after "
        "sunset, the stones releasing stored heat gradually through the night",
        " where dew forms more slowly on the road than on adjacent vegetation, "
        "the residual warmth temporarily resisting moisture accumulation",
        " where night-hunting predators sometimes use the open corridor as an "
        "efficient route through otherwise dense terrain",
        " where the subtle sound differences between the road and surrounding "
        "areas provide auditory navigation cues in darkness",
        " where moonlight creates a monochromatic version of the colorful "
        "daytime palette, reducing the rich variety to shades of silver and gray",
        " where the road's edges create a distinct boundary between the ordered "
        "construction and the more chaotic natural growth alongside",
        " where the absence of vegetation makes the road a clear channel through "
        "the landscape, visible from elevated perspectives even in low light"
        }));

    addTimeOfDayDescription("late night", ({
        " where the relative hardness of the road surface creates subtle sounds as "
        "nocturnal creatures cross from one side to the other",
        " where the cooled stones sometimes collect a light dew, making them faintly "
        "gleam when caught in the light of moon, stars, or passing lanterns",
        " where the temperature difference between road and surroundings has "
        "minimized, though the stones still retain marginally more warmth",
        " where moisture collects differently in the geometric pattern of the "
        "cobblestones, creating a subtle map of the construction technique",
        " where small nocturnal creatures might use the more open sight lines "
        "of the road to watch for predators while foraging",
        " where the solid, unmoving nature of the stones contrasts with the "
        "occasional rustlings and movements from adjacent vegetation",
        " where the road forms a distinct corridor through the landscape, its "
        "boundaries perceived even when visual cues are minimal",
        " where the occasional settling sound might break the silence as "
        "temperature changes cause minute shifts in the stone arrangement",
        " where the open space above the road creates a window to the night sky, "
        "framed by the silhouettes of trees or structures along the edges",
        " where the journey of moonlight across the sky is reflected in the "
        "changing patterns of light and shadow on the cobblestone surface"
        }));

    addTimeOfDayDescription("midnight", ({
        " where deepest night reduces the road to texture felt underfoot rather "
        "than seen, its careful construction providing guidance even in darkness",
        " where the silent stones have witnessed countless crossings, the road's "
        "purpose unchanged whether in brilliant daylight or absolute darkness",
        " where the cool, hard surface contrasts sharply with softer adjacent "
        "terrain, providing clear tactile boundaries even without visibility",
        " where subtle differences in stone composition create variations in "
        "temperature and texture detectable to sensitive touch",
        " where the accumulated dew creates a slight slickness that differentiates "
        "the cobblestone surface from drier elevated areas",
        " where the quietest hours reveal the smallest sounds - the faint settling "
        "of stones, distant animal movements, or the whisper of breezes",
        " where the open corridor through vegetation creates a channel for air "
        "movement, sometimes resulting in marginally different temperatures",
        " where the minimal available light - from stars, moon, or distant "
        "sources - reflects differently from the varied stone surfaces",
        " where the moist night air carries the mineral scent of the stones, "
        "strongest during the still hours when other odors have diminished",
        " where the absence of activity allows attention to focus on the static "
        "qualities of the road itself - its permanence, solidity, and purpose"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow collects in the slight depressions between stones, creating "
        "a white-speckled surface that provides better grip for winter travel",
        " where travelers appreciate the elevated surface that keeps them above "
        "the worst of the mud and standing water of winter thaws",
        " where frost patterns form intricate designs across the stone surfaces, "
        "each cobble becoming a miniature canvas for ice crystals",
        " where the thermal properties of the stones cause snow to melt in "
        "distinctive patterns, revealing the underlying structure",
        " where the darker stones absorb what little winter sunlight exists, "
        "sometimes creating small melted areas around their edges",
        " where ice forms preferentially in the lowest points, creating a "
        "treacherous but beautiful landscape of miniature frozen pools",
        " where snowdrifts form distinct patterns determined by the road's "
        "relationship to prevailing winds and adjacent structures",
        " where the road's careful drainage design proves its worth, preventing "
        "the dangerous ice sheets that form on less sophisticated surfaces",
        " where the contrasting textures of snow, ice, and exposed stone create "
        "a complex surface requiring careful navigation",
        " where the road becomes most visible from a distance in winter, its "
        "cleared or partially cleared surface distinct from snow-covered surroundings"
        }));

    addSeasonDescription("spring", ({
        " where small green shoots sometimes emerge from between the stones "
        "where dust and soil have collected, tiny splashes of new life",
        " where spring rains wash the cobblestones clean, revealing the full "
        "spectrum of their natural colors previously dulled by winter grime",
        " where water flows efficiently along the carefully engineered "
        "camber, demonstrating the road builders' understanding of drainage",
        " where the increased moisture brings out the rich mineral colors "
        "of the varied stones, from deep reds to cool blues and greens",
        " where moss and lichen begin their annual renewal, adding subtle "
        "textures and colors to the northern faces of certain stones",
        " where puddles form briefly in any depressions, creating transient "
        "mirrors that reflect clouds and sky between periods of use",
        " where the warming stones dry more quickly than surrounding earth "
        "after spring showers, creating visible boundaries of moisture",
        " where small insects return to the crevices between stones, their "
        "activities part of the ecosystem that has adapted to this human structure",
        " where pollen and flower petals occasionally collect in the mortar lines, "
        "adding ephemeral touches of color to the permanent structure",
        " where the lengthening days allow the stones to absorb more heat, "
        "creating a detectably warmer microclimate along the thoroughfare"
        }));

    addSeasonDescription("summer", ({
        " where the stones radiate accumulated heat well into the evening, "
        "creating a microclimate slightly warmer than the surrounding area",
        " where the solid surface remains passable and relatively dust-free "
        "even during the driest periods when dirt roads would deteriorate",
        " where heat shimmer rises visibly from the sun-baked surface during "
        "the hottest hours, distorting the view along its length",
        " where drought-resistant plants somehow maintain footholds in tiny "
        "soil deposits between stones, adding touches of life to the mineral expanse",
        " where the contrast between the road's hard surface and the lush "
        "summer growth alongside creates a sharp visual and textural boundary",
        " where insects seek shade in the minimal shadows between stones, "
        "creating tiny ecosystems within the road's structure",
        " where the stones store the day's heat so efficiently that the "
        "temperature difference remains palpable hours after sunset",
        " where the road's pale surface stands out against the deeper greens "
        "of summer vegetation, creating a visible pathway from great distances",
        " where occasional summer storms reveal the excellent drainage design, "
        "water quickly channeling away rather than pooling on the surface",
        " where the hottest stones might occasionally release tiny fractures "
        "with audible snaps as thermal expansion tests their structural integrity"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves gather against any slight rise in the stones, "
        "creating patches of seasonal color against the muted background",
        " where autumn rains darken the stones to rich, deep hues, the wet "
        "surface reflecting the gold and crimson of changing trees",
        " where early morning frost forms more quickly on the stones than "
        "surrounding earth, creating a temporary white lacework before melting",
        " where the decreased sun angle means the road retains less heat, "
        "the seasonal cooling evident in both touch and thermal behavior",
        " where fallen leaves occasionally create slick surfaces when wet, "
        "their decomposition adding subtle organic elements to the mineral way",
        " where the road provides increasingly valuable stable footing as "
        "surrounding natural surfaces become slippery with autumn moisture",
        " where the contrast between stone colors and the brilliant autumn "
        "foliage creates a complementary visual relationship",
        " where cooling temperatures cause the road to contract slightly, "
        "occasionally resulting in subtle settling sounds in the quieter hours",
        " where morning mist forms more readily over the cooling stone surface, "
        "sometimes creating a fog-lined pathway through clearer surroundings",
        " where the road's resilient construction becomes more apparent as "
        "seasonal challenges increase, its engineered surface remaining reliable"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## cobblestone road extending across the "
        "landscape, its surface composed of carefully fitted stones of varying "
        "sizes and shapes, testament to skilled road-builders who created a "
        "durable thoroughfare designed to withstand centuries of use and weather");

    addItemTemplate("the cobblestone road represents considerable engineering skill, "
        "with variously sized stones carefully fitted together to create a durable surface. "
        "The stones show evidence of deliberate placement, with larger blocks along "
        "the edges and a subtle crown in the center for drainage. Years of use "
        "have polished many of the stones smooth, while others have shifted slightly "
        "with time and weather.");
}
