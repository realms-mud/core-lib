//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("iron dispatch ledger");
    addAlias("dispatch ledger");
    addAlias("iron orders");
    addAdjectives(({ "iron-bound", "smoke-stained", "folded" }));
    addDescriptionTemplate("an ##Adjective## dispatch ledger");
    addItemTemplate("The ledger lists a five-ton iron shipment and orders "
        "for arms destined for Serach. A silver payment is due before the "
        "next delivery to the Nightmaster.");
    addSomeLightDescriptionTemplate(
        "an iron dispatch ledger lies open on the table");
    addDimLightDescriptionTemplate(
        "a smoke-stained ledger rests on the table");
}
