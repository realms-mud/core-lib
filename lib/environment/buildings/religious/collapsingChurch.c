//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("collapsingChurch");
    setFloorPlanType("ruin");

    addTimeOfDayDescription("dawn", ({
        ". The worn wooden structure creaks and moans in the breeze. You can hardly see inside in the weak dawn light."
        }));
    addTimeOfDayDescription("morning", ({ ". The collapsing wooden church seems to lean dangerously. The interior seems dark in spite of the morning light." }));
    addTimeOfDayDescription("noon", ({ ". The sun shines high above the leaning steeple of the collapsing church. The interior seems dark and filled with floating motes of dust." }));
    addTimeOfDayDescription("afternoon", ({
        ". Citizens on an afternoon stroll give the collapsing church a wide berth. The interior seems dark and filled with exposed rusty nails." }));
    addTimeOfDayDescription("evening", ({
        ". As the sun descends ever lower, the collapsing church seems ever more still. Looking through the empty doorframe, the interior seems dim and, besides some trash, empty." }));
    addTimeOfDayDescription("dusk", ({
        ". The collapsing wooden church seems still, as if it were a great skeletal beast in stasis. Through the gaping doorframe you think you see shadows briefly dance." }));
    addTimeOfDayDescription("night", ({
        ". The moon illuminates the rickety wooden structure. All seems quiet and still. A moonbeam illuminates the interior of the church, making it look almost inviting." }));
    addTimeOfDayDescription("midnight", ({
        ". The collapsing church sags as if the night sat heavily upon it. Through the open doorframe you can see that the interior is well lit in the moonlight. You swear you see a candle flicker, but it's gone." }));
    addSeasonDescription("winter", ({ " A layer of pure, unblemished snow has settled in and around the church." }));
    addSeasonDescription("spring", ({ " Fresh green vines have sprouted and are attempting to climb the rotting wood." }));
    addSeasonDescription("summer", ({ " The summer heat brings out the musty, mildewy smell of the rotting building, mixed with the sweet smell of the deep green vines climbing the outer boards." }));
    addSeasonDescription("autumn", ({ " Dried brown vines cling feebly to the structure." }));
    addDescriptionTemplate("a feeble looking, abandoned place of worship for a forgotten deity");
}
