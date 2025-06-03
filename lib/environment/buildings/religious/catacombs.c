//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("catacombs");
    setFloorPlanType("church");

    addAdjectives(({
        "ancient", "dark", "labyrinthine", "subterranean", "sacred", "silent"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## catacomb entrance with stone stairs descending into "
        "darkness beneath an unassuming stone structure"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day barely touches the entrance, leaving the "
        "descending stairs cloaked in perpetual shadow",
        ". At dawn, the faintest wisps of stale air escape from the entrance, "
        "as if the underworld briefly exhales with the new day"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight illuminates the entrance structure, but cannot "
        "penetrate the absolute darkness of the stairs leading below",
        ". The stark contrast between the bright morning outside and the "
        "impenetrable darkness within emphasizes the boundary between worlds"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the entrance appears most ordinary - a simple doorway "
        "that belies the vast network of death that lies beneath",
        ". Even the strong noon sun cannot banish the chill that emanates from "
        "the stairwell descending into the earth"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light casts long shadows at the entrance, as if "
        "reaching tentative fingers toward the darkness below",
        ". Occasionally, visitors come with solemn faces and flowers, "
        "descending briefly to pay respects before returning to sunlight"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the entrance seems more imposing, the "
        "boundary between day and the eternal night below growing thinner",
        ". Small lamps are sometimes lit at the entrance during evening hours, "
        "guiding those who must visit the dead at this liminal time"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the catacomb entrance becomes one with the growing "
        "darkness, the line between above and below blurring",
        ". The last light catches on the worn stone archway, briefly "
        "illuminating ancient symbols carved by those long since interred within"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, only the structure above ground is visible, a dark shape "
        "that guards access to the realm of the dead below",
        ". Moonlight reveals the entrance as a black void, occasionally visited "
        "by robed figures carrying lanterns for nighttime rituals"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with small offerings of spring flowers placed at the entrance by those "
        "remembering loved ones interred in the darkness below",
        " where the contrast between the renewal of life above ground and the "
        "unchanging stillness below seems most pronounced"
        }));

    addSeasonDescription("summer", ({
        " with the cool air flowing from the entrance providing momentary "
        "relief from summer heat to those who approach",
        " where the warm world above makes the perpetual chill of the catacombs "
        "feel especially pronounced to those who descend"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering around the entrance, occasionally "
        "spiraling down the stairs when the wind catches them",
        " where autumn's reminder of mortality seems particularly appropriate, "
        "the world above briefly acknowledging what lies below"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering on the entrance structure but never reaching "
        "the protected stairs that lead to the unchanging chambers below",
        " where winter's chill above matches the eternal cold below, the "
        "boundary between worlds momentarily less distinct"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small structure with what appears to be an entrance to something "
        "below ground"
    );
    addLowLightDescriptionTemplate(
        "a stone entrance structure with stairs leading down into "
        "absolute darkness"
    );
    addDimLightDescriptionTemplate(
        "a catacomb entrance with stone stairs descending into darkness, "
        "ancient symbols carved around the archway"
    );
    addSomeLightDescriptionTemplate(
        "a well-constructed catacomb entrance with carved stone archway, worn "
        "steps descending into darkness, and small niches for offering lamps"
    );

    // Single item template
    addItemTemplate(
        "The catacomb entrance is marked by a modest stone structure that "
        "protects the stairs leading underground. Worn stone steps descend into "
        "darkness, leading to an extensive network of tunnels and chambers where "
        "generations of dead are interred. The air from below carries the "
        "unmistakable coolness of deep earth and ancient stone. Small niches "
        "beside the entrance hold offerings and memorial objects, while sacred "
        "symbols carved into the archway offer protection for both the dead "
        "below and the living who visit them."
    );
}
