//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("precipice");
    addAdjectives(({ "sheer", "vertigo-inducing", "dizzying", "dramatic", "stark",
        "plummeting", "breathtaking", "forbidding", "treacherous", "abrupt" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where first light touches the edge while the depths below remain hidden "
        "in shadow, creating an unsettling sense of a drop into nothingness",
        " where rising mist from below catches the early rays, creating an ethereal "
        "veil that softens but does not hide the terrifying drop"
        }));
    addTimeOfDayDescription("morning", ({
        " where growing light slowly reveals the full depth of the precipice, birds "
        "soaring beneath you riding updrafts created by the sheer face",
        " where morning sun casts stark shadows across the face, highlighting every "
        "jutting rock and crevice in the nearly vertical terrain"
        }));
    addTimeOfDayDescription("noon", ({
        " where the harsh midday light shows the precipice in all its terrifying "
        "glory, no detail hidden, the distant bottom clearly visible",
        " where the vertical drop creates its own microclimate, sun-baked at the rim "
        "while cool shadows persist below even at brightest noon"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the angle of light accentuates the texture of the face, creating a "
        "complex pattern of light and shadow down the dizzying drop",
        " where birds circle in the thermals rising along the heated cliff face, "
        "their cries echoing against the stone as the day wanes"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset light strikes the face at an angle, turning the stone gold "
        "and red while the depths fall into deepening shadow",
        " where the precipice's edge catches the last fiery light, creating a "
        "glowing line between the world above and the darkness below"
        }));
    addTimeOfDayDescription("dusk", ({
        " where failing light erases the bottom from view first, creating an "
        "increasingly unsettling sense of a drop into infinite darkness",
        " where the vertical face becomes a wall of deepening shadow, details "
        "fading while the sheer scale remains an imposing presence"
        }));
    addTimeOfDayDescription("night", ({
        " where moonlight transforms the precipice into a study in silver and "
        "absolute black, the depth more sensed than seen",
        " where stars seem to begin just beyond the edge, creating a disorienting "
        "blend of sky and void beneath your feet"
        }));
    addTimeOfDayDescription("late night", ({
        " where the darkness conceals the depth but not the knowledge of the "
        "plummeting emptiness beyond the edge, a tension felt in the body",
        " where night creatures cry from the depths, their voices rising up the "
        "face to create an eerie soundscape in the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the division between solid ground and empty air remains a palpable "
        "line even in the deepest darkness, a boundary that demands respect",
        " where the void beyond the edge seems most profound, a piece of night "
        "somehow deeper than the darkness of the midnight sky"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where ice forms along the edge and in crevices of the face, creating "
        "treacherous beauty and the occasional sound of breaking icicles falling",
        " where winter winds whip more fiercely along the rim, sometimes carrying "
        "snow horizontally past the edge to vanish into the void"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt creates ephemeral waterfalls that cascade down the face, "
        "catching light and adding their music to the precipice's presence",
        " where hardy plants begin to green in cracks and ledges, demonstrating "
        "life's persistence even in this vertical world"
        }));

    addSeasonDescription("summer", ({
        " where the stone face radiates accumulated heat and the clear air allows "
        "views to the utmost depths and across impossible distances",
        " where raptors nest on inaccessible ledges, their young safe from "
        "predators in this vertical realm between earth and sky"
        }));

    addSeasonDescription("autumn", ({
        " where wind-borne leaves occasionally drift over the edge, spiraling "
        "down into the depths in a demonstration of the sheer drop",
        " where morning fog often fills the space below, creating the illusion "
        "of standing at the edge of a clouded sea rather than a precipice"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## precipice where the ground ends with alarming suddenness, dropping away in a nearly vertical face that creates an immediate sense of exposure and vulnerability, the sheer fall inspiring both fear and fascination");
}
