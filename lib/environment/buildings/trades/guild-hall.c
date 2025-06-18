//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("guild hall");
    setFloorPlanType("trade");

    addAdjectives(({
        "grand", "timber", "stone", "bustling", "ornate", "spacious"
        }));

    addDescriptionTemplate(
        "a ##Adjective## guild hall with carved doors and a high, arched roof"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the guild hall is quiet, its great doors closed",
        ". The first light of day glints off the hall's carved stonework"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, members gather for meetings and to plan the day's "
        "work",
        ". The hall is filled with the sound of voices and the clatter of boots"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the guild hall is busy with merchants and craftsmen "
        "negotiating deals",
        ". The scent of food drifts from the kitchens as members share a meal"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the hall hosts lessons and lively debate",
        ". Sunlight streams through stained glass, painting the floor with color"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the guild hall glows with lamplight and laughter",
        ". Members gather for feasts and celebrations as the day's work ends"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the hall's windows shine with the last light of day",
        ". The guild's banners hang still in the quiet air"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the guild hall is quiet, its doors locked and the fire "
        "banked",
        ". Only the night watch remains, keeping guard over the hall"
        }));

    addSeasonDescription("spring", ({
        " decorated with fresh flowers and banners for the season's festivals",
        " as the guild welcomes new apprentices and plans for the year"
        }));

    addSeasonDescription("summer", ({
        " bustling with activity as trade and learning are at their peak",
        " as the hall hosts feasts and competitions for its members"
        }));

    addSeasonDescription("autumn", ({
        " with the scent of harvest feasts and the sound of celebration",
        " as the guild tallies the year's successes and prepares for winter"
        }));

    addSeasonDescription("winter", ({
        " warm and bright inside, a refuge from the cold for its members",
        " as the guild hall hosts gatherings and lessons by the hearth"
        }));

    addNearDarkDescriptionTemplate(
        "a grand guild hall with tall windows and a heavy wooden door"
    );
    addLowLightDescriptionTemplate(
        "a timber-framed guild hall with banners and a bustling entryway"
    );
    addDimLightDescriptionTemplate(
        "a spacious guild hall with a high roof and carved stone walls"
    );
    addSomeLightDescriptionTemplate(
        "an ornate guild hall with stained glass windows and a lively crowd"
    );

    addItemTemplate(
        "The guild hall is a grand building of timber and stone, with a high, "
        "arched roof and carved doors. Inside, banners hang from the rafters, "
        "and long tables fill the main hall. The air is filled with the sound "
        "of conversation, laughter, and the clatter of mugs. The guild hall is "
        "the heart of the community, a place for learning, trade, and "
        "celebration."
    );

    addSourceOfLight(2);
}
