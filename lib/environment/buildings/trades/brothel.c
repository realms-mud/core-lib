//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("brothel");
    setFloorPlanType("trade");

    addAdjectives(({
        "discreet", "opulent", "colorful", "bustling", "lavish", "welcoming"
        }));

    addDescriptionTemplate(
        "a ##Adjective## brothel with lantern-lit windows and silken curtains"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the brothel is quiet, its windows shuttered after a long "
        "night of revelry",
        ". The first light of day finds the brothel's staff tidying up and "
        "preparing for rest"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the brothel is peaceful, with only a few guests "
        "lingering over breakfast",
        ". The scent of perfume and laughter from the night before still "
        "lingers in the air"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, sunlight filters through colored glass, illuminating "
        "plush furnishings and rich draperies",
        ". The brothel is quiet, its staff resting and preparing for the "
        "evening's festivities"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, deliveries arrive and staff prepare rooms for "
        "the coming night",
        ". The brothel's doors are closed to the public, but laughter and "
        "music can be heard within"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, lanterns are lit and the brothel comes alive "
        "with music and laughter",
        ". The brothel's windows glow invitingly, drawing patrons from the "
        "bustling streets"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the brothel's staff greet guests at the door, and the "
        "building fills with lively conversation",
        ". The brothel's colorful lanterns are lit, casting a warm glow "
        "over the entrance"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the brothel is filled with music, laughter, and the "
        "soft glow of candlelight",
        ". The brothel's rooms are alive with revelry, and the scent of "
        "perfume drifts into the street"
        }));

    addSeasonDescription("spring", ({
        " with fresh flowers adorning the windowsills and a sense of renewal "
        "in the air",
        " as the brothel hosts lively celebrations for the season's festivals"
        }));

    addSeasonDescription("summer", ({
        " with open windows letting in warm breezes and the sounds of "
        "festivity",
        " as the brothel is busy with travelers and townsfolk seeking "
        "entertainment"
        }));

    addSeasonDescription("autumn", ({
        " with rich tapestries and autumnal decorations brightening the "
        "interior",
        " as the brothel hosts harvest feasts and masquerades"
        }));

    addSeasonDescription("winter", ({
        " with fires burning in every hearth and thick curtains keeping out "
        "the cold",
        " as the brothel offers warmth and comfort during the long, dark "
        "nights"
        }));

    addNearDarkDescriptionTemplate(
        "a discreet building with shuttered windows and a welcoming lantern"
    );
    addLowLightDescriptionTemplate(
        "a brothel with glowing lanterns and colorful curtains at the windows"
    );
    addDimLightDescriptionTemplate(
        "an opulent brothel with plush furnishings and soft candlelight"
    );
    addSomeLightDescriptionTemplate(
        "a lavish brothel with silken drapes, polished wood, and a warm, "
        "inviting glow"
    );

    addItemTemplate(
        "The brothel is a two-story building with a brightly painted door and "
        "lanterns hanging from the eaves. Inside, plush carpets and silken "
        "drapes create an atmosphere of luxury and comfort. The air is filled "
        "with the scent of perfume and the sound of laughter. Private rooms "
        "are tucked away behind heavy curtains, and a grand staircase leads "
        "to the upper floor. The brothel is a place of music, revelry, and "
        "discretion."
    );

    addSourceOfLight(2);
}
