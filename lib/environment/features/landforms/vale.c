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
        " misty with lingering vapors",
        " clear with echoing birdsong",
        " dreamy in filtered sunlight",
        " peaceful in still morning air",
        " gentle in gradual awakening",
        " serene with morning vapors",
        " quiet in sheltered dawn",
        " fresh with protected dew",
        " tranquil in early light",
        " idyllic in morning mist"
        }));

    addTimeOfDayDescription("morning", ({
        " sparkling with lingering dew",
        " gentle in gradual warming",
        " protected from harsh exposure",
        " fresh in moderated light",
        " peaceful in sheltered awakening",
        " lush in morning moisture",
        " serene in gentle illumination",
        " quiet in protected morning",
        " beautiful in soft light",
        " tranquil in morning peace"
        }));

    addTimeOfDayDescription("noon", ({
        " pleasant in moderated heat",
        " lush with thriving plant life",
        " comfortable in sheltered exposure",
        " rich in protected growth",
        " peaceful in gentle warmth",
        " verdant in ideal conditions",
        " serene in moderate light",
        " beautiful in full bloom",
        " tranquil in perfect conditions",
        " idyllic in sheltered sunshine"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in spilling light",
        " warm in natural cradle",
        " embraced by lengthening shadows",
        " protected by surrounding slopes",
        " beautiful in gathering warmth",
        " peaceful in afternoon glow",
        " serene in golden illumination",
        " tranquil in sheltered warmth",
        " idyllic in perfect light",
        " gentle in afternoon peace"
        }));

    addTimeOfDayDescription("evening", ({
        " magical in golden glow",
        " misty along forming streams",
        " peaceful in gathered light",
        " beautiful in sunset colors",
        " serene in evening warmth",
        " tranquil in gathering dusk",
        " idyllic in golden hour",
        " gentle in cooling air",
        " romantic in evening glow",
        " dreamy in fading light"
        }));

    addTimeOfDayDescription("dusk", ({
        " lingering with last light",
        " peaceful in evening chorus",
        " protective in gathering darkness",
        " serene in twilight embrace",
        " tranquil in evening acoustics",
        " gentle in fading illumination",
        " beautiful in twilight peace",
        " idyllic in evening calm",
        " dreamy in gathering shadows",
        " peaceful in natural vespers"
        }));

    addTimeOfDayDescription("night", ({
        " protective under starlight",
        " intimate in night sounds",
        " peaceful in embracing darkness",
        " serene under star sanctuary",
        " tranquil in night embrace",
        " gentle in protective darkness",
        " beautiful in starlit peace",
        " idyllic in night security",
        " dreamy in contained darkness",
        " quiet in natural boundaries"
        }));

    addTimeOfDayDescription("late night", ({
        " still in sheltered air",
        " secure in natural boundaries",
        " peaceful in protected darkness",
        " tranquil in oriented night",
        " serene in contained stillness",
        " gentle in night security",
        " beautiful in deep peace",
        " idyllic in night protection",
        " dreamy in sheltered quiet",
        " quiet in embracing darkness"
        }));

    addTimeOfDayDescription("midnight", ({
        " holding precious darkness",
        " secret under midnight stars",
        " peaceful in deepest enclosure",
        " tranquil in midnight cradle",
        " serene in contained darkness",
        " gentle in midnight embrace",
        " beautiful in star-filled peace",
        " idyllic in deepest night",
        " dreamy in midnight sanctuary",
        " mystical in perfect enclosure"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " frosted in beautiful patterns",
        " pristine with protected snow",
        " peaceful in winter beauty",
        " gentle in sheltered cold",
        " serene in winter protection",
        " tranquil in snow blanket",
        " beautiful in winter peace",
        " idyllic in pristine white",
        " dreamy in winter quiet",
        " magical in frost patterns"
        }));

    addSeasonDescription("spring", ({
        " spectacular with wildflowers",
        " early with butterfly sightings",
        " vibrant in color displays",
        " fresh with spring arrival",
        " peaceful in early warmth",
        " beautiful in spring profusion",
        " serene in seasonal awakening",
        " tranquil in spring peace",
        " idyllic in perfect spring",
        " dreamy in flower paradise"
        }));

    addSeasonDescription("summer", ({
        " lush in protected paradise",
        " rich with diverse ecosystem",
        " peaceful in perfect conditions",
        " verdant in sheltered growth",
        " beautiful in summer abundance",
        " serene in peak season",
        " tranquil in lush peace",
        " idyllic in summer perfection",
        " dreamy in green abundance",
        " magical in summer richness"
        }));

    addSeasonDescription("autumn", ({
        " striking with flaming colors",
        " late with extended warmth",
        " beautiful in autumn cup",
        " peaceful in fall protection",
        " serene in golden display",
        " tranquil in autumn peace",
        " idyllic in fall beauty",
        " dreamy in seasonal colors",
        " magical in autumn light",
        " gentle in extended season"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## vale nestled between gentle "
        "slopes, creating natural shelter and peaceful seclusion");

    addItemTemplate("The vale forms a natural depression between gentle "
        "slopes, creating a sheltered environment that feels removed from "
        "the surrounding terrain. The protected location typically supports "
        "lusher vegetation than nearby areas, with streams often flowing "
        "through the lowest points. The enclosing slopes provide shelter "
        "from wind and harsh weather, creating ideal conditions for both "
        "plant and animal life. This natural sanctuary offers a sense of "
        "peace and seclusion rare in more exposed landscapes.");
}
