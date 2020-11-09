//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fake feature");
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
    addNearDarkDescriptionTemplate("a massive silhouette of trees");
    addLowLightDescriptionTemplate("the silhouette of deciduous trees");
    addDimLightDescriptionTemplate("the silhouette of oak trees");
    addSomeLightDescriptionTemplate("a stand of oak trees");

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

    harvestableResource("oak", 25, "/lib/instances/items/materials/wood/oak.c",
        "a heavily-forested stand of oak trees. Several trees remain",
        ({ "deciduous tree", "oak tree", "tree" }));
    harvestRequiresTool("oak", "axe");
    limitHarvestByState("oak", "default");
    limitHarvestBySkill("oak", "forestry", 5);

    harvestableResource("acorn", 25,
        "/lib/instances/items/food/plants/nuts/acorn.c",
        ({ "acorn nut", "nut" }));
    limitHarvestBySeason("acorn", "summer");

    harvestableResource("mana", 5, "/lib/instances/items/potions/mana.c",
        "a heavily-forested stand of oak trees. Several trees remain");
    harvestRequiresOneOfTool("mana", ({ "staff", "rod", "wand" }));
    limitHarvestByState("mana", "deadified");
    limitHarvestBySkill("mana", "spellcraft", 5);
    limitHarvestByTimeOfDay("mana", "midnight");
    limitHarvestByMoonPhase("mana", "full moon");
    limitHarvestBySeason("mana", "winter");

    addBonus("strength", 4);
    limitBonusByTimeOfDay("strength", "noon");
    limitBonusBySeason("strength", "autumn");

    addPenalty("hit points", 3);
    penaltyRequiresOneOfEquipment("hit points", ({ "axe", "rod", "wand" }));
    limitPenaltyByState("hit points", "deadified");
    limitPenaltyBySkill("hit points", "spellcraft", 5);
    limitPenaltyByTimeOfDay("hit points", "midnight");
    limitPenaltyByMoonPhase("hit points", "full moon");
    limitPenaltyBySeason("hit points", "winter");
}

/////////////////////////////////////////////////////////////////////////////
public void testSuppressEntryMessage()
{
    suppressEntryMessage();
}
