//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trail");
    addAdjectives(({ "faint", "winding", "narrow", "rough", "animal",
        "meandering", "subtle", "hidden", "overgrown", "wilderness" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the first light reveals delicate patterns of dew clinging to "
        "bent grass blades, subtly marking the trail's meandering course",
        " where morning mist often lingers longer over the subtle depression "
        "of the trail than over adjacent higher ground",
        " where early wildlife activity concentrates along this natural corridor, "
        "their tracks freshly pressed into damp earth still soft from night",
        " where spiderwebs sometimes span the narrower sections, catching the "
        "first golden light in intricate, jewel-like configurations",
        " where the trail temporarily vanishes in shadowed sections only to "
        "reappear where direct sunlight touches the disturbed vegetation",
        " where birdsong seems particularly concentrated along the route, the "
        "edge habitat created by the trail attracting diverse species",
        " where the dampness of morning reveals subtle differences in vegetation-"
        "species that thrive in the disturbed soil of the trail's margins",
        " where the low angle of dawn light emphasizes even the slightest "
        "depression in the earth, making the trail more visible than at midday",
        " where frost patterns form differently on the trail's compressed surface "
        "than on surrounding untrampled vegetation during cooler seasons",
        " where the trail appears as a subtle ribbon of disturbed dew, the "
        "passage of previous travelers having altered the perfect symmetry"
        }));

    addTimeOfDayDescription("morning", ({
        " where the drying surface begins to release earthy scents from crushed "
        "vegetation and disturbed soil along the narrow route",
        " where small butterflies and insects rise from resting places as warmth "
        "returns, often congregating along the open corridor",
        " where the trail reveals its course primarily through subtly different "
        "vegetation rather than clear soil exposure in many sections",
        " where dew burns off in patterns determined by the morning sun's path "
        "and the varying height of grasses along the route",
        " where transition zones become apparent along the trail's edge-different "
        "plant communities meeting where disturbance creates opportunity",
        " where the gentle depression of the trail's center occasionally catches "
        "morning shadows, creating a subtle line across open terrain",
        " where wildlife tracking reveals the trail's importance as a highway "
        "for local fauna, their prints most visible in morning's damp earth",
        " where the path occasionally disappears entirely only to reemerge "
        "some distance ahead, intuition as important as observation",
        " where the subtle differences between trampled and untrampled vegetation "
        "become apparent as morning light strengthens",
        " where seed distribution patterns show the trail's function as a "
        "vector for plant dispersal, new growth concentrated along its course"
        }));

    addTimeOfDayDescription("noon", ({
        " where the minimal shade makes the trail nearly disappear in certain "
        "sections, the overhead sun eliminating revealing shadows",
        " where heat shimmer sometimes rises from open stretches, blurring the "
        "already indistinct boundary between trail and surrounding terrain",
        " where insects concentrate in the microhabitats created by the trail's "
        "disturbance, their activity peaking in the midday warmth",
        " where drought-resistant plants reveal the trail's course in dry "
        "periods, their hardiness allowing survival in compacted soil",
        " where occasional rock outcroppings along the route absorb the midday "
        "heat, creating basking spots for reptiles and heat-loving insects",
        " where the scent of sun-warmed vegetation rises strongly from crushed "
        "plants along the trail's narrowest sections",
        " where the contrast between the trail and surrounding vegetation "
        "diminishes during midday hours, making navigation more challenging",
        " where small dust clouds might rise from drier sections as gusts of "
        "wind sweep across exposed portions of the path",
        " where the trail's subtle changes in elevation become less apparent "
        "without the revealing shadows of morning or evening light",
        " where the direction of bent grasses provides one of the few reliable "
        "indicators of the trail's course during the shadowless midday hours"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where lengthening shadows begin to emphasize the subtle depression of "
        "the trail, making its course increasingly distinct as the day progresses",
        " where warm air carries the mingled scents of sun-heated earth and "
        "vegetation, the trail creating a corridor for these commingled aromas",
        " where disturbed earth along the route releases stored heat differently "
        "than surrounding ground, creating a thermal trace visible to some creatures",
        " where the light catches differently on bent grasses that mark the "
        "trail's passage through meadows and fields",
        " where small animals become increasingly active along the margins, the "
        "edge habitat created by the trail supporting diverse species",
        " where the sun's declining angle illuminates seed heads and flowers "
        "differently along the disturbed corridor than in adjacent growth",
        " where crossing animal trails become more evident, their intersections "
        "with this route creating nodes of increased activity",
        " where sections of complete disappearance alternate with clearly "
        "visible stretches as the trail winds through varying terrain",
        " where western-facing slopes along the trail catch direct sunlight, "
        "creating warm microhabitats that attract insect activity",
        " where the trail's gentle meanders become more appreciable in the "
        "angled light, revealing how it navigates around rather than over obstacles"
        }));

    addTimeOfDayDescription("evening", ({
        " where the golden light catches on seedheads and tall grasses bent by "
        "passage, creating a subtle glowing outline of the trail's course",
        " where cooling earth releases different scents from those of midday, "
        "the dampening soil along the trail carrying earthy aromas",
        " where wildlife activity increases significantly along the route, the "
        "trail serving as a primary movement corridor in the transitional hours",
        " where the low angle of light creates longer shadows from even slight "
        "variations in the trail's surface, enhancing its visibility",
        " where drops in temperature encourage condensation to form first in the "
        "trail's slight depression, sometimes creating a misty trace",
        " where birds follow the trail's course during evening migrations, using "
        "the linear feature as a navigation reference",
        " where certain sections catch the last direct sunlight while adjacent "
        "terrain falls into shadow, temporarily highlighting the route",
        " where the trail becomes more distinct as angled light emphasizes the "
        "subtle compression of soil and vegetation from repeated passage",
        " where the boundary between trail and surroundings softens visually "
        "while remaining detectable through changes in texture underfoot",
        " where evening pollinators concentrate on flowers growing specifically "
        "along the trail's disturbed edges, creating zones of increased activity"
        }));

    addTimeOfDayDescription("dusk", ({
        " where visibility of the trail becomes increasingly dependent on texture "
        "rather than visual distinction as light continues to fade",
        " where cooling air sometimes creates subtle fog effects in the lowest "
        "sections, the trail's depression collecting the first mist",
        " where the sounds of diurnal creatures fade while nocturnal species "
        "become increasingly vocal along the corridor",
        " where navigation increasingly relies on the feel of slightly compacted "
        "earth and shorter vegetation rather than visual markers",
        " where the trail's openness creates a narrow channel of remaining light "
        "between the denser, darker vegetation on either side",
        " where nocturnal hunters begin to position themselves along the trail, "
        "recognizing it as a likely route for prey movement",
        " where bats may follow the linear feature during evening hunts, using "
        "the clear flight path for efficient insect capture",
        " where the scent profile changes dramatically as night-blooming plants "
        "along the edges begin releasing their fragrances",
        " where dew forms patterns that can briefly reveal the trail's course "
        "in the last ambient light before complete darkness",
        " where temperature differences between the compacted trail and "
        "surrounding vegetation become detectable to sensitive thermoreception"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight creates subtle differences in reflection between the "
        "trail's smoother surface and the more varied textures surrounding it",
        " where navigation depends primarily on the feel of the ground underfoot, "
        "the slightly more compacted soil providing tactile guidance",
        " where night-active creatures use the trail extensively, their movements "
        "continuing to reinforce its subtle definition",
        " where starlight provides just enough illumination to distinguish the "
        "trail's course through open areas for night-adjusted vision",
        " where certain night-blooming flowers open specifically along the "
        "edges, taking advantage of the reduced competition for pollinators",
        " where the trail serves as a boundary between different nocturnal "
        "territories, marked by scents detectable primarily to wildlife",
        " where the absence of taller vegetation creates a narrow corridor of "
        "open sky, potentially useful for navigation on clear nights",
        " where temperature differences become more significant, the trail "
        "often remaining marginally warmer than surrounding areas",
        " where occasional eye-shine might reveal wildlife using or crossing "
        "the trail, momentarily catching any available light",
        " where the distinctive sounds of movement along the trail-different "
        "from progress through undisturbed vegetation-provide audio cues"
        }));

    addTimeOfDayDescription("late night", ({
        " where the trail's existence becomes almost theoretical in sections, "
        "detectable more through intuition and experience than observation",
        " where nocturnal wildlife reaches peak activity, their movements along "
        "this natural corridor creating a constant subtle rhythm",
        " where dew formation progresses, sometimes creating a slight difference "
        "in moisture between the trail and surrounding vegetation",
        " where temperature inversions might cause mist to form in the trail's "
        "lowest sections, creating ethereal patches of visibility",
        " where night-hunting predators patrol the length, recognizing the "
        "trail as a likely route for potential prey movement",
        " where any available moonlight creates subtle shadow patterns from "
        "trailside vegetation, occasionally providing visual guidance",
        " where sound travels differently along the open corridor than through "
        "dense vegetation, creating an acoustic channel through the landscape",
        " where the trail serves as a connection between nocturnal feeding "
        "grounds and daytime shelter, heavily used during deepest night",
        " where the complex scent landscape reaches peak differentiation, "
        "with night-blooming plants contributing their strongest fragrances",
        " where the moisture difference between trail and surroundings becomes "
        "most pronounced, dew forming differently on compressed surfaces"
        }));

    addTimeOfDayDescription("midnight", ({
        " where the deepest darkness reduces the trail to a concept rather than "
        "a visual reality, its presence sensed more than seen",
        " where the temperature difference between the trail and surrounding "
        "vegetation reaches its maximum, the bare earth cooling more completely",
        " where nocturnal creatures continue their activities regardless of "
        "the hour, the trail serving wildlife needs around the clock",
        " where the trail exists primarily through negative space-the absence "
        "of certain obstacles rather than the presence of clear markers",
        " where the quietest hours allow the subtlest sounds of movement to "
        "carry further, revealing activity along the route by ear rather than eye",
        " where the compressed earth releases stored aromas differently than "
        "surrounding ground, creating an olfactory guide through darkness",
        " where the open corridor above the trail creates a ribbon of visible "
        "sky on clear nights, stars serving as navigational references",
        " where dew formation reaches its peak, sometimes creating slight "
        "differences in reflection that can reveal the trail's course",
        " where the stillness permits detection of the slightest disturbances, "
        "the passage of small nocturnal creatures suddenly perceptible",
        " where the trail represents a connection between disparate ecosystems, "
        "a corridor through which life flows regardless of hour or season"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow often reveals the trail most clearly, compacted by passage "
        "into a slightly lower track than surrounding untouched powder",
        " where frost forms unique patterns on the compressed soil, creating "
        "crystalline structures different from those on adjacent vegetation",
        " where winter winds sweep certain exposed sections clear while building "
        "drifts across others, creating an inconsistent but traceable route",
        " where the absence of foliage reveals the full course of the trail "
        "through wooded areas, previously hidden connections becoming apparent",
        " where wildlife dependence on the trail increases dramatically, their "
        "tracks concentrated along this efficiently cleared pathway",
        " where the difference between frozen compacted earth and surrounding "
        "ground creates subtle variations in color and texture",
        " where ice forms distinctively in the shallow depression of the "
        "trail, sometimes creating a hazardous but visually striking feature",
        " where melting occurs at different rates along the trail than in "
        "surrounding areas, the compressed soil conducting heat differently",
        " where the simplest markers-a bent twig, a discolored stone-take on "
        "crucial importance when snow transforms the familiar landscape",
        " where the trail's subtle channel sometimes serves as a natural drainage "
        "course during thaws, creating a momentary streambed through the terrain"
        }));

    addSeasonDescription("spring", ({
        " where early growth appears differently along the margins than in "
        "undisturbed areas, pioneering species taking advantage of the disturbance",
        " where mud season creates challenging conditions, the compressed soil "
        "sometimes draining poorly compared to less-trafficked surroundings",
        " where the trail becomes a timeline of spring's progress, showing "
        "different stages of growth than the relatively undisturbed surroundings",
        " where new shoots emerge first along the edges where competition is "
        "reduced, creating green borders that highlight the trail's course",
        " where spring rains reveal drainage patterns, the trail sometimes "
        "becoming a temporary watercourse during heavier precipitation",
        " where migrating birds follow the corridor's course, using it as a "
        "navigation aid during their seasonal journeys",
        " where early insects concentrate along the warming soil of the trail, "
        "emerging sooner here than in shadier surrounding areas",
        " where previously invisible sections reappear as snow retreats, the "
        "trail's full extent gradually revealed by the changing season",
        " where spring blooms occur in a specific sequence along the trail's "
        "margin, different from the progression in undisturbed habitat",
        " where the dampness of the season emphasizes scent markers, both "
        "natural and animal-created, that help define the trail's course"
        }));

    addSeasonDescription("summer", ({
        " where the contrast between the trail and surrounding vegetation "
        "reaches its peak, the path visible as a line of shorter, hardier growth",
        " where heat-resistant plants dominate the trail itself while moisture-"
        "loving species flourish just beyond the compressed soil's edge",
        " where dust might rise from the driest sections, the fine particles "
        "coating vegetation alongside and marking recent passage",
        " where insects establish territories along the natural corridor, "
        "certain species specifically adapted to the edge habitat created",
        " where berry-producing shrubs often concentrate along the margins, "
        "taking advantage of increased sunlight along the clearing",
        " where the trail may narrow as summer growth reaches its peak, "
        "vegetation gradually encroaching on less-traveled sections",
        " where distinct microclimates form along the course, from sun-baked "
        "exposed stretches to cool shaded tunnels through denser growth",
        " where the soil's compaction becomes most evident during dry periods, "
        "the hardened earth resisting both erosion and new growth",
        " where wildlife continues to reinforce the trail through regular use, "
        "their movements maintaining openness despite summer's vegetative surge",
        " where seed distribution patterns reveal the trail's function as a "
        "vector for plant dispersal, new colonies established along its length"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect differently on the trail than in surrounding "
        "areas, sometimes filling the slight depression to level the surface",
        " where the trail may appear to vanish under a carpet of autumn color, "
        "only to be revealed again by the pattern of vegetation beneath",
        " where early frost forms distinctive patterns on the trail's compressed "
        "soil, different from those on adjacent undisturbed ground",
        " where the scent of decay becomes particularly concentrated along the "
        "corridor, fallen leaves breaking down in the higher-traffic area",
        " where seasonal wildlife migrations often follow the trail's course, "
        "the open pathway providing efficient passage through changing terrain",
        " where nuts and seeds collect in the slight depression, creating "
        "feeding opportunities for foraging creatures preparing for winter",
        " where the trail's subtle channel sometimes directs the flow of rainfall "
        "during autumn storms, creating temporary drainage patterns",
        " where the declining angle of seasonal sunlight emphasizes even slight "
        "variations in the trail's surface, enhancing visibility of its course",
        " where certain stretches become more challenging as increased moisture "
        "combines with fallen leaves to create slippery conditions",
        " where the trail serves as a natural firebreak in drier regions, the "
        "reduced vegetation creating a boundary that can slow spreading flames"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## trail winding through the landscape, its "
        "course marked more by subtly disturbed vegetation and compressed soil "
        "than by clear boundaries, a tenuous route created and maintained "
        "primarily by repeated passage rather than intentional construction");

    addItemTemplate("the trail reveals itself as a subtle interruption in the natural "
        "environment, its course marked more by bent grasses and disturbed soil "
        "than by clear boundaries. Animal tracks frequently follow or cross this "
        "route, suggesting it serves wildlife as much as any purposeful travelers. "
        "In places, the trail nearly disappears before becoming evident again a "
        "few paces ahead. ##UseDescriptionSet##");
}
