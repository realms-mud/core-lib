//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tor");
    addAdjectives(({ "rocky", "weathered", "distinctive", "boulder-crowned",
        "ancient", "isolated", "imposing", "wind-scoured", "stark", "prominent" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where early light catches the uppermost rocks first, creating a glowing "
        "crown while the base remains in shadow and mystery",
        " where morning mist often surrounds the lower slopes, enhancing the "
        "impression of the tor rising like an island from a clouded sea"
        }));
    addTimeOfDayDescription("morning", ({
        " where climbing sun gradually reveals the full formation, shadows retreating "
        "down the slope to expose weathered stone and hardy vegetation",
        " where the distinctive silhouette casts a steadily shortening shadow across "
        "the surrounding landscape as morning advances"
        }));
    addTimeOfDayDescription("noon", ({
        " where midday light eliminates most shadows among the crown of rocks, "
        "revealing the intricate textures created by millennia of weathering",
        " where the exposed position offers little shelter from the sun, the stone "
        "absorbing heat until it radiates back into the surrounding air"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the western face begins to glow with warm light while eastern aspects "
        "fall into shadow, enhancing the three-dimensional presence",
        " where the stone seems to hold the day's heat, creating rippling air currents "
        "that distort views of the distinctive profile"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset transforms the weathered boulders into silhouettes against the "
        "flaming sky, each familiar shape now redrawn in dramatic black",
        " where the day's accumulated heat radiates from the stone, creating a pocket "
        "of warmth that lingers even as surrounding air cools"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the failing light reduces the tor to its essential form, the crown of "
        "rocks now dark shapes against the deepening blue of twilight",
        " where the formation seems to settle into the landscape as details fade, "
        "becoming more a presence felt than a collection of features seen"
        }));
    addTimeOfDayDescription("night", ({
        " where moonlight transforms the rocky crown into a collection of silver-edged "
        "sentinels, their shadows creating pools of deeper darkness",
        " where the elevation catches whatever light remains, standing more visible "
        "against the night sky than the surrounding terrain"
        }));
    addTimeOfDayDescription("late night", ({
        " where the distinctive outline remains visible even in darkness, the tor's "
        "presence a constant landmark regardless of illumination",
        " where night creatures sometimes use the sheltered spaces between boulders, "
        "their calls or movements betraying life within the stone crown"
        }));
    addTimeOfDayDescription("midnight", ({
        " where deepest night emphasizes the ancient nature of the formation, a "
        "sentinel that has witnessed countless cycles of light and dark",
        " where the crown of rocks creates a jagged interruption in the star field, "
        "a meeting of earth and sky that predates all living memory"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow collects in pockets and crevices between the weathered rocks "
        "while wind scours other surfaces completely bare",
        " where ice forms fantastic shapes on the windward sides of stones, and the "
        "sparse vegetation retreats to dormancy between protective boulders"
        }));

    addSeasonDescription("spring", ({
        " where hardy plants emerge first in the sheltered pockets between rocks, "
        "creating surprising bursts of color against weathered stone",
        " where the warming rocks provide sanctuary for early insects and reptiles, "
        "offering heat long before the surrounding landscape fully thaws"
        }));

    addSeasonDescription("summer", ({
        " where the rocky crown stands stark against blue skies, heat shimmering around "
        "stones that have absorbed the full strength of summer sun",
        " where small, drought-resistant plants display remarkable resilience, finding "
        "life in the seemingly inhospitable surface of the weathered tor"
        }));

    addSeasonDescription("autumn", ({
        " where early frost touches the crown of rocks before the surrounding lowlands, "
        "and wind-blown leaves collect in natural hollows among the stones",
        " where the setting perfectly frames the seasonal changes visible across the "
        "landscape below, a natural viewpoint for the turning year"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## tor rising from the landscape, its "
        "distinctive profile created by a crown of exposed, weathered rock "
        "formations atop a hill, the stones sculpted by countless years of wind, "
        "rain and frost into a natural monument");
}
