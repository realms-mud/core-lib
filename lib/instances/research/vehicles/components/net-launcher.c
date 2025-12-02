//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Net Launchers");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft devices that launch weighted nets "
        "to entangle and disable enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("carpentry", (["type":"skill", "value" : 3]));
    addPrerequisite("engineering", (["type":"skill", "value" : 2]));
    addPrerequisite("sewing", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/components/harpoon-launcher.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "wagon", "cart", "boat", "ship" })]));
    addSpecification("bonus crafting vehicle attack", 2);
}
