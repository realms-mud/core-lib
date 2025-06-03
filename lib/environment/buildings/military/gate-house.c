//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gate house");
    setFloorPlanType("military");

    addAdjectives(({
        "fortified", "defensive", "stone", "imposing", "guarded", "strategic"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## gatehouse with twin towers flanking a heavily "
        "reinforced entrance"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day shows guards preparing to open the massive "
        "gates for the day's traffic",
        ". At dawn, the portcullis is raised with a mechanical grinding, the "
        "gatehouse coming to life as a new day begins"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the defensive complexity of the structure, from "
        "murder holes above to arrow slits covering every approach",
        ". The gatehouse bustles with activity as merchants, travelers, and "
        "supply wagons are inspected before passing through"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the gatehouse manages a steady flow of traffic, guards "
        "vigilant despite the routine nature of their duty",
        ". The sun illuminates the defensive features - machicolations, "
        "embrasures, and the heavy iron reinforcements of the wooden gates"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light emphasizes the craftsmanship of the stonework, "
        "each block precisely cut to create this critical defensive point",
        ". Guards change shift as afternoon progresses, fresh eyes taking up "
        "the duty of monitoring all who enter and leave"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, traffic increases as merchants and travelers "
        "hurry to enter before the gates close for the night",
        ". The gatehouse towers catch the last light of day, torches being lit "
        "at the entrance and along the parapet"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the warning bell rings from one of the towers, signaling "
        "that the gates will soon close for the night",
        ". The massive wooden doors begin to swing closed as darkness falls, "
        "the gatehouse transforming from passage to barrier"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the gatehouse stands sealed and vigilant, torches "
        "illuminating the approaches while guards watch from the towers",
        ". The portcullis remains lowered until dawn, the gatehouse fulfilling "
        "its primary purpose as defender of this vulnerable point in the walls"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with fresh banners hanging from the towers and guards in polished "
        "armor managing the increased traffic of the season",
        " where spring rains wash the winter soot from the stonework, revealing "
        "the true colors of the carefully selected building materials"
        }));

    addSeasonDescription("summer", ({
        " with the guards suffering in heavy armor as the sun heats the stone "
        "structure like an oven",
        " where the gatehouse provides welcome shade for those waiting their "
        "turn to pass through the inspection point"
        }));

    addSeasonDescription("autumn", ({
        " with preparations visible for winter - firewood being stockpiled in "
        "the towers and mechanics checking the portcullis",
        " where autumn winds funnel through the gateway, creating a constant "
        "draft that keeps the guards alert but uncomfortable"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering on every horizontal surface and braziers lit to "
        "provide some comfort to the duty-bound guards",
        " where the massive doors are opened less frequently, guards hurrying to "
        "close them again to preserve what warmth they can"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive structure with twin towers and what appears to be a passage "
        "between them"
    );
    addLowLightDescriptionTemplate(
        "a stone gatehouse with towers flanking a reinforced entrance, guards "
        "visible on duty"
    );
    addDimLightDescriptionTemplate(
        "a fortified gatehouse with twin towers, a raised portcullis, and heavy "
        "wooden doors standing open"
    );
    addSomeLightDescriptionTemplate(
        "an imposing stone gatehouse with twin defensive towers, multiple arrow "
        "slits, a portcullis mechanism, and heavily reinforced oak doors"
    );

    // Single item template
    addItemTemplate(
        "The gatehouse is a formidable defensive structure designed to control "
        "access through the wall. Twin towers flank a central passageway, "
        "providing multiple levels of defense including murder holes in the "
        "ceiling, arrow slits covering all approaches, and a deadly portcullis "
        "that can trap enemies in the passage. Massive wooden doors reinforced "
        "with iron straps can be closed and barred from within. The upper levels "
        "of the towers house the mechanisms for the portcullis as well as "
        "guardrooms and storage for weapons. In times of peace, the structure "
        "serves as checkpoint and customs house; in war, it becomes a killing "
        "zone for any who attempt unauthorized entry."
    );

    addSourceOfLight(2);
}
