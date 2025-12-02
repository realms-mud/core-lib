//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stable");
    setFloorPlanType("trade");

    addAdjectives(({
        "timber", "spacious", "well-kept", "bustling", "hay-scented", "orderly"
        }));

    addDescriptionTemplate(
        "a ##Adjective## stable with wide doors and rows of stalls"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the stable is filled with the sounds of horses stirring",
        ". The first light glimmers on fresh straw and polished tack"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the stable is busy with feeding and grooming",
        ". Sunlight streams through the open doors as horses are led out"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the stable is cool and quiet, horses resting in their stalls",
        ". The scent of hay and leather fills the air"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the stable is alive with the bustle of chores",
        ". The sound of hooves and the clatter of buckets echo through the yard"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, horses return to the stable and the doors are closed",
        ". The stable glows with lamplight as the last chores are finished"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the stable stands quiet, the day's work done",
        ". The last rays of sunlight catch the red paint and weathered wood"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the stable is quiet, with only the soft sounds of horses",
        ". The stable is dark except for the occasional lantern carried by a groom"
        }));

    addSeasonDescription("spring", ({
        " with new foals in the stalls and the scent of fresh hay in the air",
        " as the stable is busy with the birth of new horses"
        }));

    addSeasonDescription("summer", ({
        " with the doors thrown open to catch the breeze and the lofts filled "
        "with sweet-smelling hay",
        " as the stable is busy with the care of horses and the storage of feed"
        }));

    addSeasonDescription("autumn", ({
        " with the lofts filled with hay and the stalls cleaned for the coming winter",
        " as the stable is prepared for the cold months ahead"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and the stable warm with the breath of horses",
        " as the stable offers shelter from the cold and wind"
        }));

    addNearDarkDescriptionTemplate(
        "a timber-framed stable with a high roof and shadowed doorways"
    );
    addLowLightDescriptionTemplate(
        "a well-kept stable with wide doors and the scent of hay"
    );
    addDimLightDescriptionTemplate(
        "a spacious stable with stalls, a hayloft, and polished tack"
    );
    addSomeLightDescriptionTemplate(
        "a bustling stable with fresh straw, open doors, and rows of horses"
    );

    addItemTemplate(
        "The stable is a large, timber-framed structure with wide double doors "
        "and rows of stalls. Inside, horses are groomed and fed, and the air is "
        "filled with the scent of hay and leather. Sunlight filters through the "
        "windows, and the stable is the heart of the town's equestrian life."
    );
}
