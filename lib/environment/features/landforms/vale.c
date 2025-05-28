//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("vale");
    addAdjectives(({ "secluded", "peaceful", "lush", "tranquil", "gentle",
        "idyllic", "hidden", "picturesque", "rustic", "serene" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where morning mist often lingers, creating a dreamy quality as sunlight "
        "gradually filters through the vaporous cover",
        " where birdsong seems especially clear in the still air, echoing gently "
        "between the sheltering slopes as day begins"
        }));
    addTimeOfDayDescription("morning", ({
        " where dew remains longer than in more exposed areas, creating a sparkling "
        "display across grass and foliage as light strengthens",
        " where the protected nature of the setting creates a gentle awakening, warmth "
        "arriving gradually rather than with the sudden intensity of open lands"
        }));
    addTimeOfDayDescription("noon", ({
        " where even midday heat is moderated by the sheltering terrain, creating "
        "a pleasant environment when more exposed areas might feel oppressive",
        " where the full light reveals the rich variety of plant life that thrives "
        "in this protected pocket, often more lush than surrounding regions"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where golden light spills across the gentle slopes, creating an inviting "
        "warmth that seems to gather in this natural cradle",
        " where the lengthening shadows enhance the sense of enclosure and protection, "
        "the surrounding higher ground embracing the lowland between"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset light often creates a particularly magical quality, the vale "
        "holding a golden glow while shadows deepen around its edges",
        " where cooling air sometimes creates tendrils of mist that begin to form "
        "along streams or in the lowest hollows as evening advances"
        }));
    addTimeOfDayDescription("dusk", ({
        " where twilight seems to linger, the sheltered environment holding the day's "
        "last light while surrounding areas have already surrendered to darkness",
        " where evening birdsong creates a peaceful chorus, the acoustics of the vale "
        "gathering and enhancing these natural vespers"
        }));
    addTimeOfDayDescription("night", ({
        " where the darkness feels protective rather than threatening, the embracing "
        "land creating a natural sanctuary under the stars",
        " where night sounds are softened and contained by the surrounding terrain, "
        "creating an intimate soundscape different from more open areas"
        }));
    addTimeOfDayDescription("late night", ({
        " where the sheltered environment often develops its own patterns of air "
        "movement, sometimes holding still while breezes pass overhead",
        " where nocturnal creatures move with a sense of security, the natural "
        "boundaries providing orientation even in the deepest darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the vale becomes a vessel of deepest night, holding darkness like "
        "precious liquid in the cradle of surrounding land",
        " where the sense of enclosure reaches its peak, creating a place apart "
        "from the wider world, a secret garden beneath the midnight stars"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where frost often forms in beautiful patterns, lingering in shadowed "
        "areas while surroundings might have already thawed in morning sun",
        " where snow creates a pristine blanket that transforms the vale into a "
        "scene of quiet winter beauty protected from harsh winds"
        }));

    addSeasonDescription("spring", ({
        " where wildflowers appear in spectacular profusion, the sheltered "
        "environment encouraging bold displays of color among fresh greenery",
        " where the protected setting often hosts the first butterfly sightings "
        "and earliest birdsong, spring arriving here before surrounding terrain"
        }));

    addSeasonDescription("summer", ({
        " where the height of growing season transforms the vale into a lush "
        "paradise, plants thriving in the protected microclimate",
        " where the natural enclosure creates perfect conditions for a rich "
        "ecosystem of flora and fauna, often more diverse than nearby areas"
        }));

    addSeasonDescription("autumn", ({
        " where fall colors create a particularly striking display, the vale "
        "appearing like a cup filled with flaming hues of red and gold",
        " where the first frosts arrive later than in exposed areas, the sheltered "
        "setting extending the final warm days before winter's approach"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## vale nestled between gentle slopes, creating a naturally sheltered environment that feels set apart from the surrounding terrain, typically featuring lusher vegetation and a sense of peaceful seclusion");
}
