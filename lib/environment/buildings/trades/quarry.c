//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("quarry");
    setFloorPlanType("trade");

    addAdjectives(({
        "rocky", "dusty", "open", "sprawling", "noisy", "industrial"
        }));

    addDescriptionTemplate(
        "a ##Adjective## quarry with piles of stone and workers at the face"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the quarry is quiet, the first light glinting off "
        "rough-hewn stone",
        ". Workers gather at the edge, ready to begin the day's labor"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the quarry echoes with the sound of hammers and "
        "chisels",
        ". Dust rises as stone is cut and loaded onto carts"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the quarry is hot and dusty, workers pausing for a meal "
        "in the shade",
        ". The sun beats down on piles of stone and half-finished blocks"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the quarry is busy with carts hauling stone away",
        ". The sound of splitting rock and shouted orders fills the air"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the quarry quiets and the last carts leave for town",
        ". The day's work ends as the sun sets behind the stone face"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the quarry stands silent, the tools set aside for the night",
        ". The last rays of sunlight glint off the rough stone walls"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the quarry is dark and still, watched over by a lone guard",
        ". The quarry rests, the day's labor at an end"
        }));

    addSeasonDescription("spring", ({
        " with new veins of stone revealed by the thaw",
        " as the quarry prepares for a busy season of building"
        }));

    addSeasonDescription("summer", ({
        " with the air thick with dust and the sound of constant work",
        " as the quarry supplies stone for the town's projects"
        }));

    addSeasonDescription("autumn", ({
        " with piles of stone ready for winter construction",
        " as the quarry's output slows with the coming cold"
        }));

    addSeasonDescription("winter", ({
        " with snow dusting the stone and work slowed by the cold",
        " as the quarry is quiet, waiting for spring"
        }));

    addNearDarkDescriptionTemplate(
        "a rocky quarry with shadowed piles of stone and silent tools"
    );
    addLowLightDescriptionTemplate(
        "a dusty quarry with stone blocks and the scent of earth"
    );
    addDimLightDescriptionTemplate(
        "an open quarry with rough stone walls and scattered tools"
    );
    addSomeLightDescriptionTemplate(
        "a sprawling quarry with busy workers, carts, and piles of stone"
    );

    addItemTemplate(
        "The quarry is a wide, open pit with rough stone walls and piles of "
        "cut stone. Workers use hammers and chisels to split blocks from the "
        "rock face, and carts haul the stone away for building. Dust hangs in "
        "the air, and the sound of labor echoes across the site."
    );
}
