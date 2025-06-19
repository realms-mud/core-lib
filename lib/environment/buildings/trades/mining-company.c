//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mining company");
    setFloorPlanType("trade");

    addAdjectives(({
        "stone", "industrial", "busy", "dusty", "noisy", "fortified"
        }));

    addDescriptionTemplate(
        "a ##Adjective## mining company office with stone walls and iron doors"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, miners gather outside, ready for the day's work",
        ". The first light glints off pick axes and carts lined up by the door"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the office is busy with the sound of voices and "
        "the clatter of ledgers",
        ". Foremen assign crews and tally the day's output"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the office is filled with the scent of dust and sweat",
        ". Miners return for a brief meal before heading back underground"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the office is alive with the sound of carts "
        "rolling in and out",
        ". The day's ore is weighed and recorded by busy clerks"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the office quiets as miners return from the shafts",
        ". The day's tallies are finalized and the doors are locked"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the office stands silent, the day's work done",
        ". The last rays of sunlight glint off the iron-bound doors"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the office is dark and silent, watched over by a lone guard",
        ". The mining company rests, ready for another day"
        }));

    addSeasonDescription("spring", ({
        " with new crews arriving and the promise of rich veins ahead",
        " as the company prepares for a busy season of digging"
        }));

    addSeasonDescription("summer", ({
        " with the air thick with dust and the sound of picks on stone",
        " as the company works long hours to meet demand"
        }));

    addSeasonDescription("autumn", ({
        " with carts full of ore and the office tallying the season's yield",
        " as the company prepares for the winter slowdown"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and the fires burning inside",
        " as the company focuses on maintenance and planning"
        }));

    addNearDarkDescriptionTemplate(
        "a stone mining office with iron doors and shadowed windows"
    );
    addLowLightDescriptionTemplate(
        "a busy mining company with carts and miners coming and going"
    );
    addDimLightDescriptionTemplate(
        "an industrial office with ledgers, ore samples, and stone walls"
    );
    addSomeLightDescriptionTemplate(
        "a fortified mining company with busy clerks and iron-bound doors"
    );

    addItemTemplate(
        "The mining company office is a sturdy stone building with iron-bound "
        "doors and barred windows. Inside, clerks tally ore and miners report "
        "their findings. Ledgers, maps, and ore samples fill the shelves. The "
        "air is thick with dust and the promise of wealth from the earth."
    );
}
