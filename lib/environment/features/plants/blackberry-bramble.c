//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("blackberry bramble");
    addAlias("bramble");
    addAlias("blackberries");
    addDescriptionTemplate("a sprawling blackberry bramble");
    addNearDarkDescriptionTemplate("a tangled shadow");
    addLowLightDescriptionTemplate("a low mass of thorny stems");
    addDimLightDescriptionTemplate("a thorny bramble beside the path");
    addSomeLightDescriptionTemplate("a blackberry bramble with arching canes");
    addTimeOfDayDescription("dawn", ({ " beaded with dew" }));
    addTimeOfDayDescription("morning", ({ " stirring in the breeze" }));
    addTimeOfDayDescription("noon", ({ " warm along its upper canes" }));
    addTimeOfDayDescription("afternoon", ({ " shaded beneath its tangled stems" }));
    addTimeOfDayDescription("evening", ({ " darkening at the hedge edge" }));
    addTimeOfDayDescription("dusk", ({ " blending into the hedge" }));
    addTimeOfDayDescription("night", ({ " rustling softly" }));
    addTimeOfDayDescription("midnight", ({ " still beside the dark path" }));
    addItemTemplate("Arching thorny stems catch at the hedge. White "
        "flowers give way to clusters of fruit as the year advances; "
        "the ripe berries are almost black. Birds have made narrow "
        "tunnels between the canes.");
    addSeasonDescription("spring", ({ " covered with small white flowers" }));
    addSeasonDescription("summer", ({ " bearing ripening blackberries" }));
    addSeasonDescription("autumn", ({ " tangled with fallen leaves" }));
    addSeasonDescription("winter", ({ " stripped to its thorny canes" }));
    harvestableResource("blackberry", 8,
        "/lib/instances/items/food/plants/fruit/blackberry.c",
        "a blackberry bramble with picked stems among the thorns",
        ({ "blackberries" }));
    limitHarvestBySeason("blackberry", "summer");
    limitHarvestBySeason("blackberry", "autumn");
}
