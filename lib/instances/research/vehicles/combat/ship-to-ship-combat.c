//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ship-to-Ship Combat");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required for advanced naval combat between vessels, "
        "including artillery coordination and battle line tactics.");
    addSpecification("research type", "points");
    addSpecification("research cost", 6);
    addPrerequisite("tactics", (["type":"skill", "value" : 8]));
    addPrerequisite("engineering", (["type":"skill", "value" : 6]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 7]));
    addPrerequisite("/lib/instances/research/vehicles/combat/boarding-actions.c", 
        (["type":"research"]));

    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 2);
    addSpecification("bonus fire enchantment", 2);
}
