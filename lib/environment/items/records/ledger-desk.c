//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ledger desk");
    addAlias("desk");
    addAlias("ledger");
    addAlias("records");
    addDescriptionTemplate("a raised writing desk holding bound ledgers");
    addItemTemplate("Smooth stones hold open pages on the sloping desk. "
        "Leather covers protect the records, and a narrow drawer holds "
        "copying paper. Labels identify the accounts and their dates.");
    addNearDarkDescriptionTemplate("a broad shadow against the wall");
    addLowLightDescriptionTemplate("the outline of a writing desk");
    addDimLightDescriptionTemplate("a desk holding several closed books");
    addSomeLightDescriptionTemplate("a writing desk with leather-bound ledgers");
    addTimeOfDayDescription("dawn", ({ " ready for the first copying work" }));
    addTimeOfDayDescription("morning", ({ " neatly arranged for use" }));
    addTimeOfDayDescription("noon", ({ " with weights keeping the pages flat" }));
    addTimeOfDayDescription("afternoon", ({ " bearing a few fresh ink marks" }));
    addTimeOfDayDescription("evening", ({ " with its loose papers gathered" }));
    addTimeOfDayDescription("dusk", ({ " with books closed against the damp" }));
    addTimeOfDayDescription("night", ({ " silent under its protective cloth" }));
    addTimeOfDayDescription("midnight", ({ " undisturbed in the quiet" }));
    addSeasonDescription("spring", ({ " raised clear of the damp floor" }));
    addSeasonDescription("summer", ({ " dusted along the ledgers' upper edges" }));
    addSeasonDescription("autumn", ({ " with a heavy cloth folded beside it" }));
    addSeasonDescription("winter", ({ " protected from drafts by a fitted cover" }));
}
