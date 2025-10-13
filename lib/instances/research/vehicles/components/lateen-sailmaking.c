//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lateen Sailmaking");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft triangular lateen sails for improved "
        "maneuverability and wind efficiency.");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addPrerequisite("sewing", (["type":"skill", "value" : 3]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 2]));
    addPrerequisite("carpentry", (["type":"skill", "value" : 1]));
    addPrerequisite("/lib/instances/research/vehicles/components/basic-sailmaking.c", 
        (["type":"research"]));

    addSpecification("limited by", (["crafting type":({ "boat", "ship", "barge" })]));
    addSpecification("bonus crafting vehicle speed", 2);
}
