//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("path");
    addAdjectives(({ "modest", "earthen", "simple", "rural", "winding",
        "established", "rustic", "irregular", "practical", "local" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where morning dew reveals the path's edges with crystalline clarity, "
        "droplets clinging to vegetation along the trampled earth route",
        " where the first light catches the uneven surface, creating tiny shadows "
        "that emphasize every depression and rise along its course",
        " where mist often hovers just above the ground, the path cutting through "
        "it like a channel through the ethereal morning vapor",
        " where birdsong seems to follow the path's course, the open corridor "
        "creating an acoustic channel through denser vegetation",
        " where emerging light gradually reveals previously hidden details—worn "
        "stones, exposed roots, subtle drainage channels along the sides",
        " where early moisture darkens the exposed earth differently from "
        "surrounding ground, making the path's course distinctly visible",
        " where soft dawn light illuminates the diverse textures that compose the "
        "surface—packed soil, scattered gravel, occasional flat stepping stones",
        " where the gentle depression of years of use catches long shadows, "
        "outlining the path's meandering course through the landscape",
        " where nocturnal animal tracks remain preserved in the damp earth, "
        "recording the night's activities along this convenient route",
        " where the path captures the golden quality of early light, standing "
        "out as a ribbon of illumination through shadowed surroundings"
        }));

    addTimeOfDayDescription("morning", ({
        " where gradually drying earth releases rich organic scents, the "
        "distinctive aroma of the path different from surrounding ground",
        " where diverse textures become increasingly apparent—patches of pebbles, "
        "sections of bare earth, occasional rough stone surfaces",
        " where the boundary between path and surroundings gains definition as "
        "light strengthens, revealing the extent of human intervention",
        " where small insects may gather on sun-warmed sections, the path "
        "heating more quickly than shadier adjacent areas",
        " where brief morning showers leave distinctive patterns of moisture, "
        "the path's varied surfaces absorbing or repelling water differently",
        " where the undulating course becomes fully visible, revealing how it "
        "navigates the terrain's challenges with minimal modification",
        " where wildflowers and herbs often grow densely along the edges, "
        "thriving in the disturbed soil where competition is reduced",
        " where the path reveals its history through visible layers—newer "
        "surface material overlaying older, more compacted substrates",
        " where subtle engineering becomes apparent—slight banking on curves, "
        "minimal grading to prevent erosion, strategic placement of stones",
        " where the incomplete transformation from natural ground to constructed "
        "way gives the path its distinctive character, neither wild nor formal"
        }));

    addTimeOfDayDescription("noon", ({
        " where direct overhead light eliminates most shadows, revealing the "
        "full texture and composition of the surface material",
        " where heat sometimes creates shimmers of rising air above the more "
        "exposed sections, the path absorbing sunlight efficiently",
        " where the contrast between the bare earth of the path and the "
        "surrounding vegetation reaches its peak in the strong midday light",
        " where the surfaces shows its varied character, from smoother central "
        "sections to rougher, less-traveled edges",
        " where small creatures might seek shade along the borders, the path "
        "itself becoming uncomfortably warm during the hottest hours",
        " where dry earth may occasionally rise in tiny dust clouds when "
        "disturbed by breezes across the most exposed stretches",
        " where the path's subtle crown becomes visible, centuries of use and "
        "maintenance creating a barely perceptible center ridge for drainage",
        " where shadows retreat to their minimum extent, briefly removing the "
        "visual cues that emphasize the path's edges and texture",
        " where the midday sun reveals the full spectrum of colors in the "
        "path's composition—ochres, umbers, subtle grays of stone",
        " where the distinction between deliberately placed materials and "
        "naturally occurring features blurs in the revealing light"
        }));

    addTimeOfDayDescription("afternoon", ({
        " where lengthening shadows begin to emphasize the texture of the "
        "surface, each small stone and depression casting visible shade",
        " where the western-facing slopes and edges catch warm light, "
        "creating a subtly illuminated boundary along one side",
        " where the path's variable surface absorbs the day's heat "
        "differently—stones warming thoroughly while earth remains cooler",
        " where the course appears particularly well-defined, the lower "
        "sun angle increasing the visibility of its subtle engineering",
        " where dust might hang briefly in the air above drier sections, "
        "catching the warm afternoon light in golden suspension",
        " where small wildlife becomes more active along the margins, "
        "venturing from shadier refuges as the direct heat diminishes",
        " where the path's meanders become more pronounced in the angled "
        "light, revealing how it accommodates both terrain and convenience",
        " where the varied materials show different thermal properties, some "
        "sections radiating stored heat while others cool more rapidly",
        " where the warmed surface releases the day's accumulated scents—"
        "earth, crushed vegetation, mineral notes from stone elements",
        " where the relative elevation of the path compared to surroundings "
        "becomes more apparent, centuries of use creating a subtle berm"
        }));

    addTimeOfDayDescription("evening", ({
        " where the golden hour light transforms the ordinary surface into a "
        "warm-toned ribbon wending through the landscape",
        " where the path appears to glow briefly as it releases stored solar "
        "energy, standing out against the more rapidly cooling surroundings",
        " where long shadows from even minimal features create striped patterns "
        "across the width, emphasizing texture and direction",
        " where the day's compression of soil releases distinct earthy aromas, "
        "the scent profile changing as temperatures fall",
        " where cooling air sometimes creates a slight haze just above the "
        "relatively warmer surface, visible when viewing along its length",
        " where the boundary between path and untrampled ground gains "
        "definition through dramatic shadow patterns and light contrasts",
        " where exposed stones retain heat longer than surrounding soil, "
        "creating a patchwork of warmer and cooler sections",
        " where the day's accumulated impressions remain clearly visible in "
        "the surface, recording the passage of all who traveled its course",
        " where certain sections catch the last direct light while others "
        "fall into shadow, creating dramatic alternating patterns",
        " where the path's deliberate course becomes most apparent, its "
        "navigation between obstacles and challenges clearly revealed"
        }));

    addTimeOfDayDescription("dusk", ({
        " where visibility depends increasingly on the path's textural "
        "difference rather than color contrast as light continues to fade",
        " where the open corridor creates a channel of lingering light "
        "between the more rapidly darkening vegetation on either side",
        " where temperature differences between the path and surroundings "
        "become more pronounced, detectable even without visual cues",
        " where night-active creatures begin to emerge along the edges, "
        "using the relative openness for efficient movement",
        " where the path's surface cools unevenly, certain materials "
        "releasing heat more readily than others",
        " where navigation becomes increasingly dependent on the feel of "
        "compressed earth underfoot rather than visual markers",
        " where the boundary between path and surroundings softens visually "
        "while remaining distinct through texture and elevation",
        " where evening moisture begins to settle differently on the path "
        "than on surrounding vegetation, altering reflective properties",
        " where the sounds of movement along the path change character, "
        "footfalls producing different acoustics as the surface cools",
        " where the open corridor above the path creates a visible channel "
        "of sky, providing a navigational reference as darkness increases"
        }));

    addTimeOfDayDescription("night", ({
        " where moonlight transforms the ordinary surface into a silver "
        "ribbon winding through darker surroundings",
        " where the textural differences between path and adjacent ground "
        "provide guidance even with minimal illumination",
        " where starlight reflects differently from various surface materials—"
        "glinting occasionally from mica-flecked stones or damp patches",
        " where nocturnal creatures use the convenient corridor for efficient "
        "movement, their passage continuing to maintain the clear route",
        " where cooler night air sometimes creates subtle mist effects along "
        "the path's lowest sections, vapor clinging to the depression",
        " where the sound of movement changes distinctly when crossing from "
        "surrounding vegetation onto the more compressed surface",
        " where the path remains warmer than adjacent areas well into the night, "
        "the thermal signature detectable hours after sunset",
        " where the openness above creates a corridor of visible sky for "
        "celestial navigation when other landmarks disappear in darkness",
        " where the path's course is sometimes revealed by what it lacks—the "
        "absence of taller vegetation creating negative space in starlight",
        " where night dew forms patterns that highlight the path's edges, "
        "moisture collecting differently on compressed versus natural ground"
        }));

    addTimeOfDayDescription("late night", ({
        " where the path exists more as a felt presence than a seen one, its "
        "surface texture and relative hardness perceptible underfoot",
        " where temperature differences reach their peak, the path having "
        "cooled more thoroughly than surrounding vegetation-insulated earth",
        " where nocturnal wildlife creates subtle soundscapes along the "
        "route, different species preferring different sections for activity",
        " where occasional clearings or wider sections create pools of "
        "starlight, briefly illuminating the continuing course",
        " where the scent profile changes dramatically from daytime, cooler "
        "temperatures bringing out different aromatic elements from the soil",
        " where the path sometimes seems to disappear completely only to be "
        "rediscovered a few steps later as texture changes underfoot",
        " where dew formation progresses unevenly, creating patterns of moisture "
        "that can help define the edges in minimal light conditions",
        " where night-hunting predators may patrol the length, taking advantage "
        "of the relatively unobstructed hunting corridor",
        " where the breeze travels differently along the open channel than through "
        "surrounding vegetation, creating subtle air movement cues",
        " where moonlight occasionally penetrates through the darkest sections, "
        "creating momentary glimpses of the continuing route ahead"
        }));

    addTimeOfDayDescription("midnight", ({
        " where the deepest darkness reveals the path primarily through touch "
        "and subtle temperature variations rather than visual cues",
        " where the silence accentuates the different sounds made when moving "
        "along the path versus through adjacent untrampled areas",
        " where the completeness of night reduces the path to its essential "
        "qualities—direction, texture, and relative openness",
        " where dew formation reaches its peak, sometimes creating enough "
        "moisture difference to affect reflected starlight",
        " where nocturnal life continues its activities regardless of hour, the "
        "path serving as a natural movement corridor through the landscape",
        " where the reduced sensory input heightens awareness of the path's "
        "subtle grade changes and surface variations",
        " where the open corridor above sometimes allows starlight or moonlight "
        "to penetrate where it otherwise couldn't reach the ground",
        " where the path's existence becomes almost theoretical in sections, "
        "more an absence of obstacles than a presence of definite features",
        " where the boundary between path and surroundings blurs to its maximum "
        "extent, requiring other senses to maintain orientation",
        " where the accumulated history of countless passages remains beneath "
        "one's feet, sensed but unseen in the deepest hours"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow often reveals the path most clearly, slightly lower depths "
        "or different melting patterns marking its course",
        " where frost creates distinctive patterns on the path's surface, the "
        "moisture content and compaction affecting crystal formation",
        " where the bare branches of adjacent vegetation allow more light to "
        "reach the path, sometimes creating a brighter corridor in winter",
        " where strategic placement of the occasional stone or log becomes more "
        "valuable when snow or ice might obscure the usual visual cues",
        " where wind patterns along the open corridor sometimes clear sections "
        "completely while building drifts across others",
        " where animal tracks concentrate, many species finding the path's "
        "relatively cleared course easier to navigate than deep snow",
        " where the path's subtle drainage engineering proves its worth, "
        "remaining passable when poor drainage would create ice sheets elsewhere",
        " where the winter sun sometimes briefly warms the darker elements of "
        "the path's surface, creating micro-thaw patterns not seen in surroundings",
        " where resilient markers—a notched tree, a distinctive stone—take on "
        "greater importance when snow transforms the familiar landscape",
        " where the path's vulnerability to ice formation reveals much about its "
        "construction, from carefully placed stones to intentional grading"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt reveals the path's course through subtle drainage "
        "patterns, water naturally following the gentle depression",
        " where early green growth appears differently along the edges, pioneer "
        "species taking advantage of the disturbed soil conditions",
        " where spring rains test the path's construction, revealing both "
        "ingenious drainage solutions and problematic erosion points",
        " where mud season creates distinctive challenges, the path's variable "
        "surface responding differently to excess moisture across its length",
        " where returning birdsong seems to follow the path's course, many "
        "species preferring the edge habitat created by its presence",
        " where early flowers often appear first along the margins, taking "
        "advantage of increased sunlight where taller vegetation is absent",
        " where the scent of warming earth rises distinctively from the path, "
        "different from the aromas of the surrounding awakening landscape",
        " where seasonal maintenance may be visible—new stones placed in "
        "muddy sections, drainage channels cleared, major obstacles removed",
        " where temporary streams sometimes form along or across the path during "
        "thaw, creating ephemeral water features that reshape sections",
        " where emerging insects concentrate along the warmer earth of the path, "
        "often emerging earlier here than in shadier surrounding areas"
        }));

    addSeasonDescription("summer", ({
        " where the contrast between the path and surrounding vegetation "
        "reaches its peak, boundaries clearly defined by growth patterns",
        " where heat creates noticeable microclimates along the route, from "
        "sun-baked exposed sections to cool shaded tunnels through trees",
        " where dust might rise from the driest portions, momentarily hanging "
        "in the air before settling on adjacent vegetation",
        " where summer flowers crowd the edges, taking advantage of the "
        "reduced competition and increased sunlight along the clearing",
        " where insects establish territories along different sections, some "
        "species specifically adapted to the conditions created by the path",
        " where the scent profile changes dramatically as various plants along "
        "the margins reach flowering stage in sequence throughout summer",
        " where berries and edible plants sometimes grow more abundantly along "
        "the edges, benefiting from the distinct boundary ecology",
        " where the path's surface reveals its composition most clearly in "
        "the dry season—packed earth, occasional stone, exposed roots",
        " where careful observation might reveal the path's history of "
        "modifications, from seasonal maintenance to gradual rerouting",
        " where cooling shade becomes a precious resource along certain "
        "stretches, the path's relationship with overhanging vegetation suddenly vital"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect in distinctive patterns determined by "
        "the path's contours and the surrounding vegetation types",
        " where the forest canopy above the path creates a timeline of color "
        "change, the open corridor offering views of the seasonal progression",
        " where mushrooms and fungi might appear along damper sections, "
        "particularly where decomposing leaves collect in natural depressions",
        " where autumn rains reveal the path's drainage characteristics, from "
        "well-engineered crowns to problematic collection points",
        " where the scents of decay become concentrated along the corridor, "
        "fallen leaves breaking down in the higher-traffic area",
        " where seasonal wildlife migrations might utilize the path's course, "
        "the clear route providing efficient passage through changing terrain",
        " where nuts and seeds collect in certain sections, creating feeding "
        "zones for wildlife preparing for winter scarcity",
        " where early frost patterns form differently on the path than on "
        "surrounding vegetation, revealing subtle temperature variations",
        " where the declining angle of seasonal light emphasizes the path's "
        "texture, long shadows highlighting features invisible in summer",
        " where the path itself seems to prepare for winter, its surface "
        "hardening with autumn rains while collecting the insulation of fallen leaves"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## path winding through the landscape, its "
        "surface showing the deliberate but minimal improvements that transform "
        "a casual trail into a more reliable route, balancing natural terrain "
        "with modest interventions to ensure consistent passage");

    addItemTemplate("the path forms a narrow corridor through the surrounding terrain, "
        "distinguishable primarily by the absence of vegetation where repeated "
        "passage has prevented growth. Its course follows the path of least "
        "resistance through the landscape, winding around obstacles rather than "
        "through them. The surface shows intermittent signs of use without the "
        "heavy wear of more frequented routes. ##UseDescriptionSet##");
}
