//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("amphitheater");
    setFloorPlanType("amphitheater");

    addAdjectives(({ "semicircular", "grand", "ancient", "classical",
        "magnificent" }));

    // Basic description template
    addDescriptionTemplate("##Adjective## amphitheater built of limestone with "
        "tiered seating");

    // Add time of day variations with multiple options
    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn casts long shadows across the ancient stone "
            "seats, giving the structure an otherworldly appearance",
        ". Wisps of morning mist drift across the semicircular seating as the "
            "first rays of sunlight touch the topmost tiers",
        ". The pale light of dawn illuminates the stage, while the seating "
            "remains in shadow, creating a dramatic contrast"
        }));

    addTimeOfDayDescription("morning", ({
        ". Sunlight bathes the limestone structure in a warm glow, highlighting "
            "the intricate carvings on the stage façade",
        ". Morning light streams across the amphitheater, bringing to life the "
            "fine details of the stone masonry",
        ". The eastern sun illuminates the western tiers of seating, making the "
            "limestone appear almost golden in hue"
        }));

    addTimeOfDayDescription("noon", ({
        ". Under the full light of day, the amphitheater's impressive scale "
            "becomes apparent with every detail sharply defined",
        ". The midday sun beats down on the stone seating, heating the "
            "limestone and releasing the scent of sun-warmed stone",
        ". At noon, shadows are minimal, revealing the amphitheater's perfect "
            "proportions and acoustic design"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The western sun throws elongated shadows across the eastern tiers of "
            "seating, creating dramatic patterns",
        ". Afternoon light softens the amphitheater's features, lending a warm "
            "amber tone to the ancient limestone",
        ". The slanting light of afternoon emphasizes the wear patterns on the "
            "stone steps, testament to centuries of use"
        }));

    addTimeOfDayDescription("evening", ({
        ". As daylight fades, the amphitheater takes on a golden hue, the "
            "limestone seeming to glow with accumulated heat",
        ". Evening light casts the amphitheater in shades of amber and gold, "
            "perfect for performances as was tradition",
        ". The setting sun silhouettes the upper rim of the amphitheater "
            "against the darkening sky, creating a dramatic frame"
        }));

    addTimeOfDayDescription("dusk", ({
        ". In the fading light of dusk, the amphitheater becomes a study in "
            "shadows, with only the stage remaining faintly illuminated",
        ". Dusk shrouds the amphitheater in purple shadows, with only the "
            "highest tiers catching the last light of day",
        ". At dusk, the stone structure appears to recede into the landscape, "
            "its features softening in the dim light"
        }));

    addTimeOfDayDescription("night", ({
        ". Moonlight transforms the amphitheater into a ghostly venue, the pale "
            "stone gleaming softly under the stars",
        ". Under the night sky, the amphitheater stands silent and majestic, "
            "the tiered seating like steps into darkness",
        ". Stars shine above the open amphitheater, the ancient venue seemingly "
            "designed for performances under the heavens"
        }));

    // Add seasonal variations with multiple options
    addSeasonDescription("spring", ({
        " with small wildflowers pushing through cracks between the stone "
            "seating, adding dashes of color to the weathered limestone",
        " where fresh green shoots emerge from between the stone joints, "
            "reclaiming parts of the ancient structure",
        " adorned with patches of fresh moss and tiny blossoming flowers that "
            "soften the hard edges of the stone"
        }));

    addSeasonDescription("summer", ({
        " where the hot stone radiates accumulated heat, while small lizards "
            "bask on the warm surfaces of the upper tiers",
        " with hardy drought-resistant plants flourishing in the crevices "
            "between seats, their tiny flowers adding color to the scene",
        " offering welcome shade in its deeper recesses, contrasting with the "
            "sun-baked exposed seating areas"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves scattered across the tiers of seating, creating a "
            "mosaic of red and gold against the pale stone",
        " where windblown leaves collect in corners and niches, their rustle "
            "the only sound in the ancient performance space",
        " its stone surfaces dampened by autumn rains, bringing out the rich "
            "colors and textures of the aged limestone"
        }));

    addSeasonDescription("winter", ({
        " covered in a light dusting of snow that highlights the semicircular "
            "tiers of seating and architectural details",
        " with icicles hanging from the decorative cornices, transforming the "
            "ancient structure into a crystalline wonder",
        " standing stark against the winter landscape, its cold stone surfaces "
            "rimed with frost patterns"
        }));

    // Add lighting condition descriptions
    addNearDarkDescriptionTemplate("the looming shape of an amphitheater, its "
        "tiered structure barely visible in the darkness");
    addLowLightDescriptionTemplate("a semicircular structure with rows of stone "
        "seating, dimly visible in the low light");
    addDimLightDescriptionTemplate("an amphitheater with concentric rows of "
        "seating rising from a central stage area");
    addSomeLightDescriptionTemplate("a limestone amphitheater with tiered "
        "seating arranged in a semicircular pattern around a stage");

    // Single item template
    addItemTemplate("The semicircular design allows for excellent acoustics, "
        "with sound carrying clearly from the stage to the uppermost seats, "
        "while stone masks depicting comedy and tragedy are carved into the "
        "facade above the stage");
}
