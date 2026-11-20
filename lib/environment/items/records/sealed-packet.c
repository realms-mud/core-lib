//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sealed packet");
    addAlias("packet");
    addAlias("seal");
    addDescriptionTemplate("a sealed packet with an attached routing slip");
    addItemTemplate("Wax closes the folded outer wrapper. A separate "
        "routing slip is tied beneath its cord, so the destination "
        "can be checked without breaking the seal. Use investigate "
        "for an assigned examination of the packet seal.");
    addNearDarkDescriptionTemplate("a small indistinct bundle");
    addLowLightDescriptionTemplate("a wrapped paper bundle");
    addDimLightDescriptionTemplate("a packet bound with cord");
    addSomeLightDescriptionTemplate("a paper packet with a wax seal");
    addTimeOfDayDescription("dawn", ({ " resting on its dry backing board" }));
    addTimeOfDayDescription("morning", ({ " awaiting collection" }));
    addTimeOfDayDescription("noon", ({ " shaded beneath a loose cover" }));
    addTimeOfDayDescription("afternoon", ({ " with its cord still securely tied" }));
    addTimeOfDayDescription("evening", ({ " set aside from the day's loose papers" }));
    addTimeOfDayDescription("dusk", ({ " tucked clear of the damp" }));
    addTimeOfDayDescription("night", ({ " stored beneath its cover" }));
    addTimeOfDayDescription("midnight", ({ " undisturbed on the board" }));
    addSeasonDescription("spring", ({ " wrapped against rain" }));
    addSeasonDescription("summer", ({ " kept out of direct sunlight" }));
    addSeasonDescription("autumn", ({ " with a dry outer cover" }));
    addSeasonDescription("winter", ({ " protected from wet gloves and snow" }));
}
