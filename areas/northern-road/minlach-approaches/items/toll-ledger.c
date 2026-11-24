//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("toll ledger");
    addAlias("road ledger");
    addAlias("toll book");
    addDescriptionTemplate("a public ledger open on a stone shelf");
    addNearDarkDescriptionTemplate("a closed book beneath a shutter");
    addLowLightDescriptionTemplate("a thick ledger with marked pages");
    addDimLightDescriptionTemplate("a public book of road tolls");
    addSomeLightDescriptionTemplate("a neatly ruled toll ledger");
    addItemTemplate("The ledger lists the crown road charge by wagon "
        "weight, then names the local farm carts exempt during harvest. "
        "Receipts are numbered and the day's total is signed by two "
        "watchmen. A note at the back records every refused payment "
        "and the reason for refusing it.");
}
