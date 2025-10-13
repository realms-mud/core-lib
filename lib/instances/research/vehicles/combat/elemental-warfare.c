//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Warfare");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to conduct warfare using elemental forces, "
        "including summoned elementals and elemental weapon systems.");
    addSpecification("research type", "points");
    addSpecification("research cost", 8);
    addPrerequisite("spellcraft", (["type":"skill", "value" : 12]));
    addPrerequisite("summoning", (["type":"skill", "value" : 8]));
    addPrerequisite("elemental air", (["type":"skill", "value" : 6]));
    addPrerequisite("elemental earth", (["type":"skill", "value" : 6]));
    addPrerequisite("/lib/instances/research/vehicles/combat/mystical-defenses.c", 
        (["type":"research"]));

    addSpecification("bonus fire enchantment", 4);
    addSpecification("bonus cold enchantment", 4);
    addSpecification("bonus electricity enchantment", 4);
    addSpecification("bonus earth enchantment", 4);
    addSpecification("bonus damage", 3);
}
