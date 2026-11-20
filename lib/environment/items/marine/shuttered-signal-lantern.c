//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shuttered signal lantern");
    addAlias("false lantern");
    addAlias("signal lantern");
    addDescriptionTemplate("a hooded signal lantern on a scratched stone shelf");
    addActiveSourceOfLight(3,
        "a hooded signal lantern shines through a narrow shutter");
    addItemTemplate("A movable shutter covers the lantern's narrow "
        "opening. Scratches on its stone shelf show repeated use. "
        "It is unlit until someone lights it. You can investigate "
        "the false lantern as part of a signal inquiry.");
    addNearDarkDescriptionTemplate("a small angular shadow");
    addLowLightDescriptionTemplate("a hooded object on a shelf");
    addDimLightDescriptionTemplate("a shuttered metal lantern");
    addSomeLightDescriptionTemplate("an unlit hooded lantern with a narrow shutter");
    addTimeOfDayDescription("dawn", ({ " wet beneath its hood" }));
    addTimeOfDayDescription("morning", ({ " showing worn shutter edges" }));
    addTimeOfDayDescription("noon", ({ " shaded by its heavy hood" }));
    addTimeOfDayDescription("afternoon", ({ " resting over old shelf scratches" }));
    addTimeOfDayDescription("evening", ({ " dark behind its closed shutter" }));
    addTimeOfDayDescription("dusk", ({ " blending into the stone shelf" }));
    addTimeOfDayDescription("night", ({ " silent beneath its hood" }));
    addTimeOfDayDescription("midnight", ({ " still on its scratched shelf" }));
    addSeasonDescription("spring", ({ " sheltered from showers" }));
    addSeasonDescription("summer", ({ " salt-stained along its hood" }));
    addSeasonDescription("autumn", ({ " protected from the wind" }));
    addSeasonDescription("winter", ({ " cold beneath its fitted cover" }));
}
