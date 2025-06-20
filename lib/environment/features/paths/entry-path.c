//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("entry path");
    addAdjectives(({ "short", "direct", "formal", "designed", "tended",
        "deliberate", "functional", "purposeful", "connecting", "approach" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where morning dew highlights the path's edges, creating a glistening "
        "boundary that defines its purpose as a connecting route",
        " where the first light catches on decorative elements often found along "
        "these purposeful approaches to significant structures",
        " where the path's careful design becomes evident as dawn illuminates "
        "its deliberate course from thoroughfare to destination",
        " where the low angle of early light emphasizes any subtle grading or "
        "elevation changes engineered into this connecting route",
        " where mist sometimes hovers just above the surface, highlighting "
        "the path's course as it leads to its intended destination",
        " where birdsong seems particularly focused around the ornamental "
        "plantings that often border such formal approaches",
        " where the damp, compacted surface carries clear impressions of recent "
        "passages, preserved in the cool morning moisture",
        " where the path's boundaries catch the first sunlight, creating a "
        "corridor of illumination that guides toward its destination",
        " where dew forms differently on the well-trodden center versus the "
        "less-compressed edges, revealing patterns of typical use",
        " where the short route's complete course can often be visualized "
        "in the clear morning light, its purpose immediately evident"
        }));

    addTimeOfDayDescription("morning", ({
        " where the purpose-built connection efficiently channels movement "
        "between the main thoroughfare and its specific destination",
        " where the surface dries in patterns determined by exposure and "
        "composition, creating a temporary map of the path's materials",
        " where decorative borders of stones or plantings become more evident "
        "as full morning light reveals intentional design elements",
        " where the concentrated wear of the surface speaks to its specific "
        "function, focusing traffic between particular points",
        " where contrast develops between the warming path and adjacent areas "
        "still cool from night, particularly visible in any morning mist",
        " where the structural elements - gravel, stone edging, or carefully "
        "graded earth - reveal careful planning beyond mere convenience",
        " where the distinctive sounds of movement along this surface - different "
        "from the main road or surrounding terrain - mark its unique composition",
        " where shadows from intentional elements like bordering plants or "
        "decorative features create patterns that enhance the approach",
        " where the crisp definition between path and surroundings emphasizes "
        "its deliberate creation rather than gradual formation through use",
        " where the morning light fully reveals any ornamental touches that "
        "distinguish entry paths from more utilitarian routes"
        }));

    addTimeOfDayDescription("noon", ({
        " where the overhead sun eliminates most shadows, highlighting any "
        "decorative elements or borders that define this formal approach",
        " where the full illumination reveals the entry path's intentional "
        "design, from surface materials to careful grading and edging",
        " where the distinctive surface - often more refined than connecting "
        "thoroughfares - absorbs and reflects the midday heat distinctively",
        " where the path's edges show sharp definition, the formal boundaries "
        "clearly separating designed access from adjacent areas",
        " where any ornamental plantings along the borders may create small "
        "oases of shade that contrast with the exposed central route",
        " where the path's materials might release distinctive scents when "
        "fully warmed - crushed stone, clay, or specific minerals",
        " where the concentrated use of this connecting route has created a "
        "surface notably different from both destination and thoroughfare",
        " where the quality of materials often increases noticeably as the "
        "path approaches its destination, signaling increasing importance",
        " where the deliberate width - neither too narrow nor wastefully broad - "
        "demonstrates careful consideration of the approach's purpose",
        " where the direct route efficiently cuts through what might otherwise "
        "be challenging terrain, its engineered nature most evident at midday"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where lengthening shadows from borders or decorative elements create "
        "patterns that emphasize the designed nature of this approach",
        " where the day's accumulated heat radiates from the compacted surface, "
        "creating a thermal signature distinct from surrounding areas",
        " where the western exposure of any vertical elements creates strong "
        "directional shadows that can emphasize or obscure the path's features",
        " where the warming air carries scents from bordering plantings that "
        "may have been specifically selected to enhance the approach",
        " where the specific purpose of connecting important points becomes "
        "most evident as activity between them continues throughout the day",
        " where the declining sun may directly illuminate the path's destination, "
        "highlighting the purposeful orientation of this connecting route",
        " where the entry's formal nature is emphasized by the contrast between "
        "its maintained surface and the less-tended areas beyond its borders",
        " where the boundaries between path and surroundings remain sharply "
        "defined, revealing ongoing maintenance of this important access",
        " where the surface texture - often more refined than major thoroughfares - "
        "catches the warm afternoon light differently from surrounding terrain",
        " where the short distance between points of significance emphasizes "
        "the path's role as a connector rather than a journey in itself"
        }));

    addTimeOfDayDescription("evening", ({
        " where the cooling earth releases different scents from the path's "
        "surface than from surrounding areas, marking its distinct composition",
        " where the low angle of sunset illumination may shine directly along "
        "the path's course, highlighting its direct connection between points",
        " where decorative elements along the borders catch the last light, "
        "sometimes creating dramatic silhouettes or glowing highlights",
        " where the retained heat creates a subtle temperature difference "
        "detectable when crossing from natural ground to this constructed surface",
        " where the formal nature of many entry paths includes features that take "
        "on different aspects in evening light - carved posts, lantern stands, or markers",
        " where the boundaries become less visually distinct while remaining "
        "tactilely apparent, the edges still providing guidance as light fails",
        " where the surface cooling occurs at a different rate than surrounding "
        "areas, sometimes resulting in faint mist formation as evening progresses",
        " where any deliberate grading becomes more apparent as shadows lengthen, "
        "the subtle engineering revealed by changing light angles",
        " where the direct sightline to the destination may be emphasized by the "
        "setting sun's position, illuminating the path's purpose",
        " where the day's accumulated impression of consistent passage begins to "
        "fade, the formal connection preparing for night's different rhythms"
        }));

    addTimeOfDayDescription("dusk", ({
        " where the path may be bordered by small lights or luminous markers that "
        "become increasingly visible as natural light diminishes",
        " where the difference between the formal entry and surrounding areas "
        "remains perceptible through texture long after visual distinction fades",
        " where the cooling surface creates different thermal patterns than "
        "adjacent ground, sometimes visible as subtle vapor differences",
        " where intentional design elements like borders or edging provide "
        "continuing guidance even as detailed visibility diminishes",
        " where the direct connection between points remains functional through "
        "the transition from day to night, its purpose unchanged by darkness",
        " where any decorative features take on mysterious aspects as detailed "
        "visibility yields to silhouettes and suggestions of form",
        " where seasonal wildlife may begin to cross or travel along this "
        "connecting route as the day's activities subside",
        " where the path's composition - often including stone or gravel elements - "
        "creates subtle sounds distinct from surrounding natural surfaces",
        " where the surface texture provides confident footing even as visual "
        "cues diminish, the constructed nature providing security through touch",
        " where the formal approach retains its identity as a deliberate "
        "connection long after its visual details have faded into darkness"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight may illuminate the pale surface of many entry paths, "
        "their refined materials often reflecting available light effectively",
        " where the direct route between connected points remains functional "
        "despite darkness, its engineered surface providing reliable passage",
        " where nocturnal wildlife may utilize this clear corridor through "
        "otherwise complex terrain, finding efficient passage along its course",
        " where any intentional lighting elements reveal the path's continuing "
        "importance regardless of hour, its purpose transcending daylight",
        " where the borders remain perceptible through changes in texture or "
        "elevation, providing guidance even in minimal illumination",
        " where the night air carries different scents from the path than from "
        "surrounding areas, its distinct materials creating olfactory boundaries",
        " where stars or moonlight reflect differently from decorative elements "
        "that may edge formal approaches to significant locations",
        " where the short distance between connection points provides reassurance "
        "in darkness, the destination remaining within easy reach",
        " where sounds travel differently along this engineered surface than "
        "through adjacent terrain, creating an auditory corridor as well",
        " where the constructed nature of the path provides secure footing "
        "regardless of illumination, its deliberate design serving through darkness"
        }));

    addTimeOfDayDescription("late night", ({
        " where the entry's formal nature persists regardless of hour, the "
        "connection between points maintained through deepest night",
        " where night dew forms patterns determined by the path's materials "
        "and surroundings, sometimes creating subtle gleaming in any available light",
        " where nocturnal creatures may pause before crossing this open space, "
        "the clear sight lines creating moments of vulnerability",
        " where the temperature difference between path and surroundings has "
        "equalized, though textural differences remain constant",
        " where the quietest hours reveal the subtle sounds of the path itself - "
        "settling stones, shifting gravel, or cooling material adjustments",
        " where the confident design of the entry persists through darkness, "
        "the direct connection between points unaltered by the absence of light",
        " where the borders provide continuing guidance through touch or subtle "
        "visual cues even in the diminished illumination of deep night",
        " where occasional glistening of dew or frost may briefly catch starlight, "
        "creating momentary illumination of the path's course",
        " where the engineered surface provides distinct feedback through sound "
        "and texture, differentiating it from adjacent natural areas",
        " where the formal approach maintains its identity and purpose through "
        "the night's progression, awaiting the return of revealing daylight"
        }));

    addTimeOfDayDescription("midnight", ({
        " where the deepest night reduces the entry path to its essential "
        "qualities - direction, connection, and purposeful construction",
        " where the designed route between points transcends visual confirmation, "
        "continuing to provide guided access through complete darkness",
        " where the carefully maintained surface offers security even at this "
        "challenging hour, its engineered nature providing confidence",
        " where any decorative elements have transformed into abstract shapes, "
        "their detailed nature surrendered to darkness until dawn",
        " where the path's directness becomes its most valuable quality, "
        "allowing efficient connection even when visibility is minimal",
        " where the borders may be detected through subtle changes in texture "
        "or elevation rather than visual boundaries",
        " where nighttime moisture collects differently on the path's surface "
        "than on surrounding areas, creating tactile differentiation",
        " where the formal entry's purpose remains unchanged by darkness, "
        "the connection between significant points maintained through all hours",
        " where the engineered surface responds differently to weight and "
        "pressure than natural ground, providing feedback through touch and sound",
        " where the entry path's deliberate design provides greatest value when "
        "visual navigation is most challenging, its directness offering security"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow may be cleared more consistently than from less significant "
        "routes, maintaining the important connection between points",
        " where frost patterns form distinctively on the path's surface, "
        "influenced by its composition and exposure",
        " where the entry's borders might be marked with snow-resistant elements "
        "to ensure continued guidance during winter conditions",
        " where wind patterns around adjacent structures create distinctive "
        "snowdrifts that can either obscure or emphasize the path's course",
        " where the path's materials may respond differently to freezing "
        "temperatures than surrounding terrain, changing its relative safety",
        " where winter sunlight, when available, might warm the path differently "
        "than adjacent areas due to composition and exposure differences",
        " where careful grading prevents the dangerous ice accumulation that "
        "affects poorly designed routes during freeze-thaw cycles",
        " where decorative elements along formal entries take on new aspects "
        "when outlined in snow or adorned with ice formations",
        " where the contrast between the entry's maintained surface and "
        "surrounding winter landscape emphasizes its continuing importance",
        " where the direct connection between significant points shows its "
        "greatest value when winter conditions make longer routes challenging"
        }));

    addSeasonDescription("spring", ({
        " where early flowers sometimes appear along the borders before blooming "
        "in less protected areas, benefiting from the path's microclimate",
        " where spring rainfall reveals the careful drainage engineering often "
        "incorporated into these connecting routes between important points",
        " where the seasonal renewal may include refreshing decorative elements "
        "or borders that enhance the formal nature of the approach",
        " where thawing occurs in patterns determined by the path's materials "
        "and exposure, sometimes creating a usable route while surroundings remain frozen",
        " where puddles form and drain in ways determined by intentional grading, "
        "demonstrating the engineering underlying these purposeful connections",
        " where the entry path's surface dries more quickly after spring showers "
        "than surrounding areas, its construction facilitating drainage",
        " where boundary plantings burst into new growth, sometimes receiving "
        "special attention to maintain the formal appearance of the approach",
        " where spring migrations might bring birds to decorative plantings "
        "along the borders, adding seasonal activity to the entry's atmosphere",
        " where the increased moisture brings out different qualities in the "
        "path's materials - richer colors, distinct scents, or textural changes",
        " where the contrast between the maintained entry and the exuberant "
        "spring growth beyond its borders emphasizes its designed nature"
        }));

    addSeasonDescription("summer", ({
        " where the path may be bordered by ornamental plantings in full bloom, "
        "enhancing the formal approach to significant destinations",
        " where the surface absorbs and radiates summer heat differently than "
        "surrounding ground, creating a distinct thermal signature",
        " where the boundaries between entry and adjacent areas stand in "
        "stark contrast due to maintenance that controls summer's abundant growth",
        " where shade patterns from bordering elements create shifting patterns "
        "of cooler areas as the summer sun moves across the sky",
        " where the engineered surface remains stable despite heat that might "
        "cause natural pathways to become dusty or overgrown",
        " where insects may be drawn to flowering borders while avoiding the "
        "exposed, hotter surface of the central pathway",
        " where the formal nature of many entries includes regular maintenance "
        "that prevents summer growth from obscuring their purpose",
        " where the materials - often chosen for durability and appearance - "
        "demonstrate their quality by withstanding summer's extremes",
        " where the direct connection between points provides minimal exposure "
        "to summer heat, the efficient route reducing time in open sun",
        " where the contrast between the controlled entry path and the abundant "
        "growth beyond its edges emphasizes human intention versus natural processes"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves gather in patterns determined by the path's design "
        "and the prevailing autumn winds around adjacent structures",
        " where bordering deciduous plants contribute seasonal color that frames "
        "the approach differently than during other seasons",
        " where the entry's formal nature often includes more frequent clearing "
        "of fallen leaves than would be afforded to less significant routes",
        " where the path's materials show through accumulated leaves in patterns "
        "determined by use, wind, and the specific layout of the approach",
        " where autumn mists might cling differently to the entry path than to "
        "surrounding areas due to temperature and elevation differences",
        " where early frost forms patterns influenced by the path's construction "
        "and exposure, sometimes creating temporary decorative effects",
        " where the seasonal transformation affects bordering elements while "
        "the path itself remains relatively unchanged, emphasizing its permanence",
        " where the connection between points remains clear despite seasonal "
        "changes that might obscure less formal or maintained routes",
        " where the decreased daylight emphasizes the direct efficiency of the "
        "entry's design, its minimal distance becoming increasingly valuable",
        " where maintenance may increase to counter autumn's effects, preserving "
        "the formal appearance and function appropriate to significant approaches"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## entry path providing direct access to a "
        "specific destination, its purposeful design creating an intentional "
        "transition between the main thoroughfare and a location of significance");

    addItemTemplate("the entry path serves as a transition between main thoroughfares "
        "and specific destinations, its relatively short length showing concentrated "
        "wear. The edges are often more clearly defined than longer routes, with "
        "evidence of intentional borders in some sections. The surface may be "
        "reinforced with gravel, stone, or packed earth depending on local materials "
        "and importance.");
}
