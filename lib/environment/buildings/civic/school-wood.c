//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wooden school");
    setFloorPlanType("school");

    addAdjectives(({
        "rustic", "timber", "wooden", "simple", "charming", "weathered"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## wooden schoolhouse with a shingled roof and a modest "
        "bell tower"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day warms the weathered timbers, bringing out the "
        "honey tones of the aged wood",
        ". At dawn, the schoolhouse sits quiet, dew glistening on its wooden "
        "steps as birds begin to sing in nearby trees"
        }));

    addTimeOfDayDescription("morning", ({
        ". The school bell rings cheerfully from its small tower, summoning "
        "children from farms and cottages nearby",
        ". Morning sunlight streams through the windows, illuminating dust motes "
        "dancing above rows of simple desks"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the wooden structure creaks and settles in the sun's heat "
        "as lessons continue inside",
        ". Children's laughter fills the schoolyard during the noon break, some "
        "sitting in the shade of the building with their meals"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light brings out the texture of the hand-hewn timbers "
        "that form the walls of the simple structure",
        ". Shadows lengthen across the wooden floor as students focus on their "
        "afternoon lessons"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, students file out with their books, the wooden "
        "floorboards creaking beneath their feet",
        ". Oil lamps cast a warm glow through the windows as the schoolmaster "
        "remains to prepare the next day's lessons"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the wooden schoolhouse seems to blend with the gathering "
        "shadows, only its bell tower distinct against the sky",
        ". The schoolhouse settles into evening quiet, the day's lessons ended "
        "until dawn brings a new day of learning"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the wooden structure stands dark and peaceful, occasionally "
        "creaking as if whispering secrets of the day's lessons",
        ". Moonlight casts the shadow of the bell tower across the empty yard, "
        "the building resting until morning"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with wildflowers growing alongside its foundation and a small kitchen "
        "garden taking shape beside it",
        " where sounds of recitation mingle with birdsong drifting through the "
        "open windows on mild spring days"
        }));

    addSeasonDescription("summer", ({
        " with all windows thrown open to catch any breeze, the scent of sun-warmed "
        "wood filling the air",
        " surrounded by a dusty yard where children play hopscotch and other games "
        "during their short breaks"
        }));

    addSeasonDescription("autumn", ({
        " with colorful leaves gathered against its foundation and smoke curling "
        "from the stone chimney at one end",
        " as students return with baskets of apples for the teacher and stories of "
        "harvest work to share"
        }));

    addSeasonDescription("winter", ({
        " with snow on the shingled roof and frost patterns decorating the windows "
        "like nature's own lesson in geometry",
        " where a woodstove keeps the single room warm enough for lessons, though "
        "students keep their coats close at hand"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a simple wooden structure with what appears to be a small bell tower"
    );
    addLowLightDescriptionTemplate(
        "a timber building with several windows and a small tower at one end"
    );
    addDimLightDescriptionTemplate(
        "a wooden schoolhouse with a shingled roof and modest bell tower"
    );
    addSomeLightDescriptionTemplate(
        "a charming wooden schoolhouse with multiple windows, a shingled roof, "
        "and a small bell tower"
    );

    // Single item template
    addItemTemplate(
        "The schoolhouse is constructed of hand-hewn timbers with a shingled "
        "roof and a small bell tower rising from one end. Large windows with "
        "wooden shutters allow plenty of light into the single large room where "
        "students of all ages gather to learn. A stone chimney rises from the "
        "rear wall, connecting to a woodstove that heats the space in winter. "
        "A simple porch with wooden steps welcomes students through a door "
        "painted red for visibility even in snowstorms."
    );

    addSourceOfLight(3);
}
