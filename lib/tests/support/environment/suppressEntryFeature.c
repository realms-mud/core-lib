//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("suppress feature");
    suppressEntryMessage();

    addAdjectives(({ "majestic" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("morning", ({ " lit from a ray of sunshine piercing through the canopy" }), "default", "autumn");
    addTimeOfDayDescription("noon", ({ ", noonishly glowing" }));
    addTimeOfDayDescription("afternoon", ({ ", afternooningly dreary" }));
    addTimeOfDayDescription("evening", ({ ", oppressive in its late-day glory" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark" }));
    addTimeOfDayDescription("midnight", ({ " outlined in eery black" }));
    addTimeOfDayDescription("midnight", ({ " outlined in eery black. There is a creepy wisp of black energy here" }), "default", "autumn");
    addSeasonDescription("winter", ({ " covered with a thick layer of snow" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud" }));
    addSeasonDescription("summer", ({ " with branches laden with acorns" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of red, yellow, and orange" }));

    addDescriptionTemplate("a stand of ##Adjective## oak trees");

    addDescriptionTemplate("a stand of charred tree stumps", "deadified");
    addTimeOfDayDescription("dawn", ({ " that the sickly first rays barely illuminate" }), "deadified");
    addTimeOfDayDescription("night", ({ " outlined in the dark" }), "deadified");
    addSeasonDescription("winter", ({ " covered with a murky mist" }), "deadified");

    addItemTemplate("many ##Adjective## oaks");
    addItemTemplate("many charred tree stumps", "deadified");
    addAlias("stand of oak trees");
    addAlias("oak");
    addAlias("stand");

    // This duplicate is intentional
    addAlias("stand");

    addAlias("charred stumps", "deadified");
    addAlias("tree stumps", "deadified");
    addAlias("stumps", "deadified");
}
