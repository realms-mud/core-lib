//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("managed ash coppice");
    addAlias("ash coppice");
    addAlias("coppiced ash");
    addAdjectives(({ "managed", "young", "straight", "cut", "regrowing" }));

    addDescriptionTemplate("a ##Adjective## ash coppice");
    addNearDarkDescriptionTemplate("a low stand of ash in the darkness");
    addLowLightDescriptionTemplate("straight young ash stems in rows");
    addDimLightDescriptionTemplate("a managed ash coppice beside the road");
    addSomeLightDescriptionTemplate("a managed coppice of ash trees");
    addItemTemplate("The ash stools have been cut in rotation, leaving "
        "straight young stems to grow beside older trees. Survey marks keep "
        "the working plot within Eolach's boundary; only the winter cutting "
        "is taken for shafts and other straight-grained work.");

    addTimeOfDayDescription("dawn", ({ " damp beneath the new leaves" }));
    addTimeOfDayDescription("morning", ({ " bright between the young stems" }));
    addTimeOfDayDescription("noon", ({ " casting broken shade" }));
    addTimeOfDayDescription("afternoon", ({ " striped with long shadows" }));
    addTimeOfDayDescription("evening", ({ " dark at the edge of the wood" }));
    addTimeOfDayDescription("dusk", ({ " fading into the surrounding trees" }));
    addTimeOfDayDescription("night", ({ " still beneath the canopy" }));
    addTimeOfDayDescription("midnight", ({ " dark between the ash stools" }));

    addSeasonDescription("spring", ({ " sending up pale new shoots" }));
    addSeasonDescription("summer", ({ " shaded by a thick young canopy" }));
    addSeasonDescription("autumn", ({ " scattered with fallen leaves" }));
    addSeasonDescription("winter", ({ " marked for the permitted cut" }));

    harvestableResource("ash", 10,
        "/lib/instances/items/materials/wood/ash.c",
        "a managed ash coppice with its winter stems cut");
    harvestRequiresTool("ash", "axe");
    limitHarvestBySeason("ash", "winter");
}
