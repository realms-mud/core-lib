//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gunpowder");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft weapons using gunpowder to discharge "
        "a projectile.");
    addSpecification("research type", "granted");

    addPrerequisite("/lib/instances/research/crafting/weapons/craftWeapons.c", (["type":"research"]));
    addPrerequisite("chemistry", (["type":"skill", "value": 35 ]));
    addPrerequisite("physics", (["type":"skill", "value": 35 ]));
}
