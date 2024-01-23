//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mantle of Finiasc");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to express their raw magical energy as a magical shield. "
        "This form enhances the scion's mana shield.");

    addSpecification("limited by", (["research active": ({
        "/guilds/scion/common/mana-shield/root.c" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 37 ]));

    addPrerequisite("/guilds/scion/common/mana-shield/shroud-of-finiasc.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist acid", 4);
    addSpecification("bonus resist air", 4);
    addSpecification("bonus resist chaos", 4);
    addSpecification("bonus resist cold", 4);
    addSpecification("bonus resist earth", 4);
    addSpecification("bonus resist electricity", 4);
    addSpecification("bonus resist energy", 4);
    addSpecification("bonus resist evil", 4);
    addSpecification("bonus resist fire", 4);
    addSpecification("bonus resist good", 4);
    addSpecification("bonus resist magical", 4);
    addSpecification("bonus resist neutral", 4);
    addSpecification("bonus resist physical", 4);
    addSpecification("bonus resist psionic", 4);
    addSpecification("bonus resist undead", 4);
    addSpecification("bonus resist water", 4);
}
