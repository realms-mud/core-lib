//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("well-travelled path");
    addAdjectives(({ "beaten", "hard-packed", "familiar", "winding",
        "wide", "established", "rutted", "time-worn", "trusted" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the first light reveals countless tracks preserved in the "
        "compacted earth like a recorded history of passage",
        " where morning dew dampens the surface just enough to reveal the "
        "most recent tracks that crossed during darkness",
        " where the path begins each day as a silent testament to centuries "
        "of continuous use connecting distant points",
        " where the rising sun casts long shadows along the ruts and ridges, "
        "emphasizing the contours worn into the earth over time",
        " where birdsong seems particularly vibrant along this corridor, the "
        "disturbed edges creating ideal habitats for many species",
        " where the low angle of light illuminates the smoothed stones and "
        "exposed tree roots that mark the path's meandering course",
        " where the stillness of early morning makes the path seem temporarily "
        "abandoned, though fresh tracks attest to nighttime crossings",
        " where dew collects differently on the compacted surface than on "
        "surrounding vegetation, creating a visible line through meadows",
        " where the moist earth carries a rich tapestry of scents - leather, "
        "animals, herbs, and countless other traces of past traffic",
        " where the golden light catches on worn sections, highlighting areas "
        "where countless footsteps have polished stones smooth"
        }));

    addTimeOfDayDescription("morning", ({
        " where the warming earth releases subtle scents of crushed herbs "
        "and grasses that grow along the edges of the trampled route",
        " where the surface gradually dries as the day progresses, starting at "
        "the elevated center and working outward to the moister edges",
        " where small creatures cross at intervals, many using the clear "
        "pathway as a boundary marker between different territories",
        " where the ground has dried enough for dust to rise in small clouds "
        "from the passage of hooves and wheels laden with goods",
        " where the compacted soil reflects the day's warming light differently "
        "than surrounding terrain, creating a visible ribbon across the landscape",
        " where butterflies and insects hover above the sun-warmed surface, "
        "particularly attracted to flowers that thrive along the margins",
        " where the path reveals its subtle contours in the strengthening light, "
        "the center slightly crowned from generations of use",
        " where the adjacent vegetation has been trimmed back, creating a "
        "corridor through otherwise uninterrupted growth",
        " where small songbirds hop along the edges, seeking seeds and insects "
        "disturbed by recent movement along the route",
        " where ribbons of morning mist sometimes hover just above the surface, "
        "lingering longer over the packed earth than over surrounding areas"
        }));

    addTimeOfDayDescription("noon", ({
        " where shade is at a premium, with only the occasional overhanging "
        "tree providing respite from the direct overhead sun",
        " where the compacted surface reflects heat more intensely than "
        "surrounding areas, creating a noticeable temperature difference",
        " where the path almost seems to shimmer in the intensity of midday "
        "heat, the hard-packed earth radiating warmth back upward",
        " where small dust devils occasionally form and dance along the driest "
        "sections, stirred by thermal currents rising from the heated surface",
        " where the hard-packed earth reflects the full heat of day, forming a "
        "ribbon of warmth detectably different from adjacent terrain",
        " where various tracks and impressions stand in starkest relief, the "
        "overhead sun eliminating the shadows that softened morning's view",
        " where insects buzz in greater numbers along the verges, the contrast "
        "between path and vegetation creating ideal hunting grounds",
        " where the eye can follow the route's meandering course for greater "
        "distances, the midday clarity revealing its connection between points",
        " where wildflowers along the edges turn to follow the sun, creating "
        "a colorful border that frames the utilitarian earthen track",
        " where the relative straightness of certain sections becomes more "
        "apparent, speaking to intentional clearing rather than natural formation"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where the steady warmth of the day has completely dried the surface, "
        "revealing the full tapestry of tracks pressed into the hard earth",
        " where small animals sometimes emerge to gather seeds that have fallen "
        "on the open ground, momentarily reclaiming the quiet pathway",
        " where the relative coolness encourages more wildlife activity along "
        "the edges, the path serving as a natural boundary between habitats",
        " where shadows gradually lengthen across the surface, creating striped "
        "patterns where trees or structures stand alongside",
        " where the path's surface shows varying degrees of wear, the center more "
        "compressed than the edges from years of concentrated traffic",
        " where birds of prey may circle overhead, the clear line of the path "
        "providing an excellent hunting ground for spotting small movements",
        " where the packed earth retains the day's accumulated heat, creating a "
        "microclimate slightly warmer than surrounding areas",
        " where occasional breezes raise tiny dust clouds from the driest "
        "sections, the fine particles settling on leaves and grasses nearby",
        " where parallel ruts indicate the regular passage of wheeled vehicles, "
        "their repeated journeys carving lasting impressions in the ground",
        " where the slanting light emphasizes every bump and depression, revealing "
        "the complex topography created by years of constant use"
        }));

    addTimeOfDayDescription("evening", ({
        " where the golden light catches dust hovering above the surface, "
        "creating a glowing haze above the well-used route",
        " where cooling air allows scents to settle more heavily, the path "
        "holding a complex olfactory record of the day's crossings",
        " where lengthening shadows from trees and brush stretch across the way, "
        "creating striped patterns that slowly merge toward darkness",
        " where wild creatures begin to emerge at the periphery, some using the "
        "path as a guide while others cross it on their nightly rounds",
        " where the cooling air carries sounds further, hoofbeats and wheel "
        "noises audible from greater distances than at midday",
        " where bats might begin their evening flights above the open corridor, "
        "taking advantage of insects that congregate over the warm ground",
        " where the path seems to glow briefly with stored sunlight, standing "
        "out against the darkening landscape as night approaches",
        " where nocturnal rodents emerge from burrows along the edges, "
        "venturing onto the exposed surface as daylight fades",
        " where the silhouette of the path becomes more distinct against "
        "surrounding vegetation as direct light yields to shadow",
        " where dew begins to form first on surrounding grasses while the "
        "path remains dry, its retained warmth temporarily resisting moisture"
        }));

    addTimeOfDayDescription("dusk", ({
        " where the path remains visible as a lighter strip through darker "
        "surroundings, guiding movement well into the fading light",
        " where the sounds of day fade, replaced by the chorus of evening "
        "insects and occasional rustling from adjacent vegetation",
        " where nocturnal animals use the open corridor for efficient movement, "
        "their shapes briefly visible crossing from darkness to darkness",
        " where the moist evening air begins to dampen the dust, changing the "
        "scent profile from dry earth to richer, earthier tones",
        " where cooling temperatures cause subtle fog to form in low sections, "
        "creating ethereal pools of mist along the route",
        " where the contrast between the worn path and surrounding growth "
        "becomes less distinct, boundaries softening in the failing light",
        " where owls and bats begin their activities overhead, the path below "
        "serving as a hunting corridor through denser habitat",
        " where the compacted earth retains the day's warmth longer than "
        "surrounding ground, a thermal signature visible to certain creatures",
        " where the transitional light creates strange shadows, turning familiar "
        "landmarks along the way into mysterious forms",
        " where fox and badger tracks appear with increasing frequency, these "
        "animals often using established paths during their nightly rounds"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight reveals the pale track stretching between darker fields "
        "and forests, a ribbon of relative openness through the night",
        " where the path takes on a silvery appearance under starlight, the "
        "compacted surface reflecting what little illumination exists",
        " where the occasional sounds of nocturnal wildlife can be heard crossing "
        "or moving parallel to this natural boundary line",
        " where the sounds change - day's bustle replaced by rustling vegetation, "
        "nocturnal animals, and the whisper of night breezes",
        " where the path feels wider than it looks, its edges sensed rather than "
        "seen against the different texture of surrounding growth",
        " where stars overhead provide just enough light to distinguish the packed "
        "earth from surrounding terrain for night-adapted eyes",
        " where night-blooming flowers along the verges sometimes release their "
        "perfume, creating invisible clouds of scent along certain stretches",
        " where small eyes occasionally reflect back any available light, marking "
        "the presence of nocturnal creatures using the pathway",
        " where the occasional barking of foxes or hooting of owls marks the "
        "hunting territories that intersect with this established route",
        " where moisture settles differently on the hard-packed surface than on "
        "surrounding areas, creating subtle differences in reflection"
        }));

    addTimeOfDayDescription("late night", ({
        " where the path remains perceptible in almost complete darkness, "
        "the difference in texture and elevation guiding even without sight",
        " where the route seems to narrow psychologically if not physically, the "
        "darkness beyond its edges holding unknown potential",
        " where distant wolves might howl, their territories often intersecting "
        "with these established routes between habitations",
        " where the quiet is occasionally broken by the hoot of an owl or rustle "
        "of small creatures moving across or along the cleared way",
        " where nocturnal animals often travel along rather than across, taking "
        "advantage of the easier movement through otherwise dense territory",
        " where the occasional glimpse of eyes reflecting any available light "
        "reveals the path's use as a hunting corridor for predators",
        " where dew forms more heavily on surrounding vegetation while the "
        "packed earth remains relatively dry until deeper into night",
        " where temperature variations become most pronounced, the day's stored "
        "heat still radiating from the compressed soil",
        " where the cold night air carries sounds great distances, movements "
        "along the path audible well before they would become visible",
        " where fog sometimes forms in low-lying sections, creating ethereal "
        "breaks in the otherwise continuous line through the landscape"
        }));

    addTimeOfDayDescription("midnight", ({
        " where the deepest silence falls, broken only by the occasional movement "
        "of creatures that prefer complete darkness to light",
        " where the contrast between the path and surrounding terrain diminishes "
        "to almost nothing, the route becoming more sensed than seen",
        " where the midnight dew finally settles on the path itself, dampening "
        "the surface that remained dry longer than surrounding areas",
        " where occasional rustling in adjacent vegetation reveals the presence of "
        "nocturnal foragers using the path as a navigational reference",
        " where faint scents of crushed vegetation persist through the night, "
        "marking this as a route of regular passage even in darkness",
        " where temperature readings would show the ground still slightly warmer "
        "than untraveled areas, a thermal echo of the day's use",
        " where even familiar landmarks along the route take on different aspects, "
        "their daytime features transformed by deep shadow and limited light",
        " where stars provide the only reliable illumination, their ancient patterns "
        "helping to maintain orientation when the path becomes indistinct",
        " where the chill of night reaches its peak, dew forming heavily on "
        "the hard-packed earth of the timeless thoroughfare",
        " where the occasional cry of a nightjar or rustle of hunting predator "
        "marks the continuing activity along this corridor through the darkness"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow compacts differently on the hard-packed surface than on "
        "surrounding areas, often creating a slightly clearer route",
        " where the exposed path sometimes freezes more quickly than sheltered "
        "areas, ice forming in ruts and depressions after winter rain",
        " where the bare branches of adjacent trees create intricate patterns "
        "against the sky, framing the path carved through winter's stillness",
        " where tracks reveal the passage of various creatures when snow lies "
        "across the landscape, recording traffic both day and night",
        " where the vital connection between isolated areas becomes most "
        "evident, the path remaining viable when less-traveled routes disappear",
        " where snow sometimes drifts across open sections while remaining "
        "shallow where adjacent vegetation provides natural windbreaks",
        " where occasional cairns or marker posts ensure the route remains "
        "identifiable when snow has transformed the familiar landscape",
        " where animal tracks appear with greater frequency, many species "
        "finding the path easier to navigate than deep snow in open fields",
        " where the contrast between the white-covered landscape and the darker, "
        "more traveled surface creates a stark visual guide",
        " where frozen ruts and hoofprints preserved in hardened mud offer "
        "evidence of use before the snowfall transformed the terrain"
        }));

    addSeasonDescription("spring", ({
        " where mud becomes the primary characteristic, the thawing ground "
        "churned by wheels and feet into a morass of remarkable depth",
        " where the first tracks of returning migratory birds appear along muddy "
        "sections, their distinctive prints joining the year-round residents",
        " where early flowers appear along the edges, benefiting from the "
        "additional sunlight where passing traffic prevents overgrowth",
        " where erosion channels form more readily after winter damage, water "
        "finding the path of least resistance through compacted areas",
        " where fresh shoots of green at the margins contrast sharply with the "
        "brown central area still recovering from winter's harshness",
        " where puddles form in depressions and ruts, sometimes remaining for "
        "days or weeks during particularly wet periods",
        " where the path's higher use becomes evident through more rapidly drying "
        "sections, the frequent passage preventing water accumulation",
        " where early insects gather on the sun-warmed surface, the path heating "
        "more quickly than surrounding still-dormant vegetation",
        " where the increasing sunlight reveals the full extent of winter damage, "
        "some sections transformed almost beyond recognition",
        " where the scent of damp earth rises strongly from the well-worn route, "
        "the distinctive smell marking spring's return as surely as visual cues"
        }));

    addSeasonDescription("summer", ({
        " where dust becomes a constant companion, rising in small clouds with "
        "every disturbance of the dry earth packed by countless crossings",
        " where the hard surface contrasts sharply with the lush growth alongside, "
        "creating clear boundaries between path and surrounding nature",
        " where the heat radiating from the exposed surface creates a shimmering "
        "effect visible when looking along longer stretches",
        " where the path widens as traffic gravitates toward the edges to "
        "avoid the center's dust and heat during warmest periods",
        " where wildflowers and grasses encroach from the sides, gradually "
        "narrowing less-used sections through natural reclamation",
        " where insects swarm in greater numbers, particularly attracted to the "
        "disturbed edge areas between maintained path and wild growth",
        " where animal tracks of all sizes appear in dusty sections, revealing "
        "the route's use by creatures both large and small",
        " where the occasional rain creates a steaming effect as moisture hit the "
        "hot, compacted surface before being quickly absorbed",
        " where grasses have been worn away completely in the central channel, "
        "leaving exposed earth vulnerable to both dust and erosion",
        " where the contrast between golden summer fields and the brown earthen "
        "track provides natural wayfinding across the landscape"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect in the slight depressions, creating a "
        "colorful but potentially slippery surface as they decay",
        " where harvest traffic creates deep ruts, the heavily laden carts leaving "
        "their mark on the surface softened by autumn rains",
        " where morning frost forms patterns on fallen leaves, lasting longer "
        "on the path than in adjacent areas sheltered by vegetation",
        " where seasonal fungi sometimes appear along the margins, particularly "
        "where decaying material accumulates against exposed roots",
        " where the lower angle of sunlight emphasizes the contours worn into "
        "the earth by generations of passage",
        " where seasonal migrations of certain birds follow these established "
        "routes, using them as navigational aids during their journeys",
        " where the increased moisture of the season reveals how effectively the "
        "compacted surface sheds water compared to surrounding ground",
        " where the changing colors of surrounding vegetation frame the "
        "path in spectacular seasonal displays before winter's approach",
        " where falling nuts and berries from overhanging vegetation create "
        "natural feeding stations for wildlife along certain stretches",
        " where the sound of movement along the route changes as fallen leaves "
        "create a crackling carpet over the normally bare earth"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## well-travelled path connecting settlements "
        "and vital locations, its surface worn smooth and compacted by the "
        "countless feet, hooves, and wheels that have traversed it over generations, "
        "creating an enduring artery through the landscape");

    addItemTemplate("the path reveals years of continuous use, its surface packed hard and "
        "smooth from countless travelers. The center is worn lower than the edges, "
        "creating a subtle channel that guides foot traffic and sheds rainwater. "
        "Exposed roots and occasional stones break the surface in places, while "
        "the margins show where vegetation struggles to reclaim territory. "
        "##UseDescriptionSet##");
}
