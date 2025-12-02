//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Square Sailmaking");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft large square sails for maximum speed "
        "with favorable winds on ocean voyages.");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addPrerequisite("sewing", (["type":"skill", "value" : 4]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 3]));
    addPrerequisite("carpentry", (["type":"skill", "value" : 2]));
    addPrerequisite("/lib/instances/research/vehicles/components/lateen-sailmaking.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting vehicle speed", 3);
}
