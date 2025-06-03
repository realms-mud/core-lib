//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("church of ilyrth");
    setFloorPlanType("church");

    addAdjectives(({
        "serene", "healing", "restorative", "luminous", "compassionate", "tranquil"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## church of Ilyrth with gentle curves, blue-tinted "
        "windows, and a garden of healing herbs surrounding its entrance"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day filters through the blue-tinted windows, "
        "casting a healing glow across the interior that seems to pulse with "
        "divine energy",
        ". At dawn, attendants in robes of soft blue and white emerge to tend "
        "the healing gardens, gathering herbs infused with morning dew"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light fills the church with a radiant blue glow, and the "
        "subtle scent of healing herbs wafts through open doors and windows",
        ". Supplicants seeking healing begin to arrive, some carried by loved "
        "ones, others walking with the aid of staffs or companions"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the church's curved architecture channels sunlight to an "
        "altar of purified water that shimmers with restorative energy",
        ". The healing gardens surrounding the church bustle with activity as "
        "healers harvest plants at their peak potency under the noon sun"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light emphasizes the gentle curves of the architecture, "
        "designed to echo the flow of healing energies rather than hard angles",
        ". A sense of calm and renewal surrounds the church, as if the very air "
        "carries Ilyrth's blessing to all who seek comfort and restoration"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, special blue-flamed lanterns are lit along "
        "the paths, their light believed to carry Ilyrth's soothing touch",
        ". The church glows with inner light as vespers begin, healing prayers "
        "rising in soft harmony as day gives way to night"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the blue-tinted windows transform from transparent to "
        "luminous, glowing with a light that seems to come from within",
        ". The symbol of Ilyrth - a hand holding a water droplet - appears to "
        "shimmer in the fading light, etched in silver above the entrance"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the church becomes a sanctuary of soft blue light, "
        "welcoming those in pain who cannot find rest in darkness",
        ". Moonlight reflects off the carefully positioned crystal accents in "
        "the architecture, creating patterns said to facilitate healing"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with fresh medicinal plants sprouting in carefully tended garden "
        "beds and healing waters flowing through small stone channels",
        " where spring ceremonies celebrate renewal and restoration, with "
        "special blessings for those who survived winter's illnesses"
        }));

    addSeasonDescription("summer", ({
        " with healing gardens in full bloom, their aromas believed to carry "
        "curative properties even before being harvested and prepared",
        " where summer solstice brings a special 'Renewal Ritual' as sunlight "
        "reaches its maximum strength for enhancing healing magic"
        }));

    addSeasonDescription("autumn", ({
        " with healers gathering the final harvests of medicinal plants and "
        "preparing tinctures and poultices for the coming winter",
        " where autumn ceremonies focus on preservation - both of life and of "
        "the healing knowledge that Ilyrth's followers safeguard"
        }));

    addSeasonDescription("winter", ({
        " with evergreen healing plants adorning the interior and heated stones "
        "providing warmth to those who come seeking respite from winter ills",
        " where despite the season's harshness, the warmth within never fades, "
        "Ilyrth's blessing manifest in both spiritual and physical comfort"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a structure emitting a faint blue glow from what appear to be windows"
    );
    addLowLightDescriptionTemplate(
        "a church with curved architecture and blue-tinted windows that seem "
        "to emit their own gentle light"
    );
    addDimLightDescriptionTemplate(
        "a church dedicated to Ilyrth with flowing architectural lines, "
        "blue-tinted windows, and healing gardens surrounding it"
    );
    addSomeLightDescriptionTemplate(
        "a serene church of Ilyrth featuring gentle curved architecture, "
        "blue-tinted windows depicting scenes of healing, an entrance adorned "
        "with the silver symbol of a hand holding a water droplet, and "
        "surrounding gardens of medicinal plants"
    );

    // Single item template
    addItemTemplate(
        "The Church of Ilyrth embodies the goddess's healing nature in every "
        "aspect of its design. Unlike the sharp angles common in other "
        "religious structures, this building features gentle curves that "
        "echo the flow of healing energies. Blue-tinted windows depict scenes "
        "of restoration and compassion, filtering sunlight to cast a calming "
        "glow throughout. The surrounding gardens grow herbs and flowers used "
        "in healing rituals and medicines. Inside, a central fountain of pure "
        "water serves as both altar and source of blessed healing waters. "
        "Crystal accents positioned throughout the structure are said to "
        "channel and amplify Ilyrth's divine energy."
    );

    addSourceOfLight(6, "gentle blue healing radiance", "night");
}
