//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("precipice");
    addAdjectives(({ "sheer", "terrifying", "vertical", "dizzying", "dangerous",
        "vertiginous", "stark", "imposing", "deadly", "breathtaking" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " terrifying in morning clarity",
        " sheer in dawn's revealing light",
        " vertical in early illumination",
        " dizzying in morning exposure",
        " dangerous in dawn visibility",
        " vertiginous in first light",
        " stark in morning definition",
        " imposing in dawn grandeur",
        " deadly in clear revelation",
        " breathtaking in sunrise beauty"
        }));

    addTimeOfDayDescription("morning", ({
        " sheer in full morning light",
        " terrifying in bright clarity",
        " vertical in stark exposure",
        " dizzying in clear visibility",
        " dangerous in full revelation",
        " vertiginous in morning detail",
        " stark in bright definition",
        " imposing in morning grandeur",
        " deadly in obvious peril",
        " breathtaking in morning majesty"
        }));

    addTimeOfDayDescription("noon", ({
        " sheer in harsh illumination",
        " terrifying in shadowless clarity",
        " vertical in stark exposure",
        " dizzying in full revelation",
        " dangerous in blazing visibility",
        " vertiginous in noon definition",
        " stark in harsh light",
        " imposing in noon grandeur",
        " deadly in obvious threat",
        " breathtaking in intense beauty"
        }));

    addTimeOfDayDescription("afternoon", ({
        " sheer in angled sunlight",
        " terrifying in textured light",
        " vertical in afternoon clarity",
        " dizzying in golden exposure",
        " dangerous in warm visibility",
        " vertiginous in afternoon detail",
        " stark in golden definition",
        " imposing in afternoon grandeur",
        " deadly in clear peril",
        " breathtaking in golden beauty"
        }));

    addTimeOfDayDescription("evening", ({
        " sheer in evening drama",
        " terrifying in sunset glow",
        " vertical in golden light",
        " dizzying in evening beauty",
        " dangerous in alpenglow",
        " vertiginous in evening grandeur",
        " stark in sunset definition",
        " imposing in evening majesty",
        " deadly in beautiful peril",
        " breathtaking in sunset glory"
        }));

    addTimeOfDayDescription("dusk", ({
        " sheer in gathering darkness",
        " terrifying in twilight mystery",
        " vertical in dusk shadow",
        " dizzying in fading light",
        " dangerous in dim visibility",
        " vertiginous in twilight fear",
        " stark in darkening outline",
        " imposing in dusk mystery",
        " deadly in hidden threat",
        " breathtaking in twilight beauty"
        }));

    addTimeOfDayDescription("night", ({
        " sheer in moonlit terror",
        " terrifying in night mystery",
        " vertical in lunar light",
        " dizzying in night exposure",
        " dangerous in night concealment",
        " vertiginous in stellar fear",
        " stark in night definition",
        " imposing in nocturnal grandeur",
        " deadly in night threat",
        " breathtaking in night beauty"
        }));

    addTimeOfDayDescription("late night", ({
        " sheer in felt terror",
        " terrifying in night presence",
        " vertical in unseen threat",
        " dizzying in night mystery",
        " dangerous in concealed peril",
        " vertiginous in deep fear",
        " stark in night reality",
        " imposing in felt presence",
        " deadly in hidden danger",
        " breathtaking in night mystery"
        }));

    addTimeOfDayDescription("midnight", ({
        " sheer in cosmic terror",
        " terrifying in stellar presence",
        " vertical in midnight threat",
        " dizzying in cosmic fear",
        " dangerous in absolute peril",
        " vertiginous in stellar dread",
        " stark in midnight reality",
        " imposing in cosmic presence",
        " deadly in ultimate danger",
        " breathtaking in stellar beauty"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " sheer with icy coating",
        " terrifying in winter conditions",
        " vertical with frozen dangers",
        " dizzying in snow and ice",
        " dangerous with winter hazards",
        " vertiginous in icy terror",
        " stark in winter exposure",
        " imposing in frozen grandeur",
        " deadly with ice formation",
        " breathtaking in winter beauty"
        }));

    addSeasonDescription("spring", ({
        " sheer with spring runoff",
        " terrifying despite mild weather",
        " vertical with water dangers",
        " dizzying in spring clarity",
        " dangerous with unstable edges",
        " vertiginous in spring fear",
        " stark in spring exposure",
        " imposing in spring grandeur",
        " deadly with erosion risks",
        " breathtaking in spring beauty"
        }));

    addSeasonDescription("summer", ({
        " sheer in blazing heat",
        " terrifying in summer exposure",
        " vertical in harsh conditions",
        " dizzying in heat shimmer",
        " dangerous in summer clarity",
        " vertiginous in blazing fear",
        " stark in summer harshness",
        " imposing in summer grandeur",
        " deadly in heat exposure",
        " breathtaking in summer majesty"
        }));

    addSeasonDescription("autumn", ({
        " sheer in autumn clarity",
        " terrifying in crisp visibility",
        " vertical in clear conditions",
        " dizzying in autumn exposure",
        " dangerous with falling debris",
        " vertiginous in autumn fear",
        " stark in autumn definition",
        " imposing in autumn grandeur",
        " deadly with seasonal hazards",
        " breathtaking in autumn beauty"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## precipice dropping away "
        "in a terrifying vertical plunge");

    addItemTemplate("The precipice forms a sheer, nearly vertical drop that "
        "plunges dramatically downward from the edge of higher ground. This "
        "terrifying geological feature represents the ultimate expression of "
        "gravity's power, where weathering and erosion have created a cliff "
        "face so steep that safe passage is impossible without specialized "
        "equipment. The exposed rock face may show layers of geological "
        "history, while loose stones and debris at the top edge serve as "
        "constant reminders of the precipice's deadly nature. The mere "
        "proximity to such a drop can induce vertigo and fear in even "
        "experienced climbers.");
}
