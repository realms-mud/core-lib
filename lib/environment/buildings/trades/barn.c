//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("barn");
    setFloorPlanType("trade");

    addAdjectives(({
        "large", "weathered", "timber", "red", "spacious", "lofty"
        }));

    addDescriptionTemplate(
        "a ##Adjective## barn with wide double doors and a high, peaked roof"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the barn is filled with the sounds of animals stirring "
        "and the first rays of sunlight",
        ". The barn doors creak open as the day's work begins"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the barn is busy with feeding and milking, and "
        "the scent of hay fills the air",
        ". Sunlight streams through the open doors as animals are led out "
        "to pasture"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the barn offers cool shade for livestock and workers "
        "alike",
        ". The barn is quiet, with animals resting in their stalls"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the barn is alive with the sounds of chores "
        "and the bustle of farm life",
        ". The scent of fresh hay and grain drifts from the open doors"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, animals return to the barn and the doors are "
        "closed for the night",
        ". The barn glows with lamplight as the last chores are finished"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the barn stands silhouetted against the fading sky, a "
        "symbol of shelter and safety",
        ". The last rays of sunlight catch the red paint and weathered wood"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the barn is quiet, with only the soft sounds of "
        "animals and the creak of timbers",
        ". The barn is dark except for the occasional lantern carried by "
        "a farmhand"
        }));

    addSeasonDescription("spring", ({
        " with new foals and calves in the stalls and the scent of fresh "
        "hay in the air",
        " as the barn is busy with the birth of new animals and the start "
        "of the growing season"
        }));

    addSeasonDescription("summer", ({
        " with the doors thrown open to catch the breeze and the lofts "
        "filled with sweet-smelling hay",
        " as the barn is busy with the storage of grain and the care of "
        "livestock"
        }));

    addSeasonDescription("autumn", ({
        " with the lofts filled with hay and the stalls cleaned for the "
        "coming winter",
        " as the barn is prepared for the cold months ahead"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and the barn warm with the "
        "breath of animals",
        " as the barn offers shelter from the cold and wind"
        }));

    addNearDarkDescriptionTemplate(
        "a large barn with a high roof and shadowed doorways"
    );
    addLowLightDescriptionTemplate(
        "a weathered barn with wide doors and the scent of hay"
    );
    addDimLightDescriptionTemplate(
        "a timber-framed barn with stalls and a hayloft"
    );
    addSomeLightDescriptionTemplate(
        "a spacious barn with red-painted walls, open doors, and a high roof"
    );

    addItemTemplate(
        "The barn is a large, timber-framed structure with wide double doors "
        "and a high, peaked roof. Inside, stalls for animals line the walls, "
        "and a hayloft is stacked with bales. The scent of hay and animals "
        "fills the air, and sunlight filters through cracks in the wood. "
        "The barn is the heart of the farm, sheltering livestock and storing "
        "the harvest."
    );
}
