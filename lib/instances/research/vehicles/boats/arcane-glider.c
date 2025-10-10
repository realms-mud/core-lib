//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Gliders");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct small, swift vessels that glide "
        "above water or air through pure magical energy, offering unmatched speed.");
    addSpecification("research type", "points");
    addSpecification("research cost", 7);
    addPrerequisite("carpentry", (["type":"skill", "value" : 8]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 6]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 12]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("/lib/instances/research/vehicles/boats/crystal-vessels.c", 
        (["type":"research"]));
}
