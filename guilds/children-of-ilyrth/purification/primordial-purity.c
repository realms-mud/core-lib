//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Purity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of the primordial purity of the first waters. The caster "
        "gains a deep connection to the untainted essence of creation, "
        "greatly enhancing all purification abilities.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 57 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/divine-purification.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 5);
    addSpecification("bonus elemental water", 4);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus magical essence", 3);
}
