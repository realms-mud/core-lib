//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Swordsmithing");
        Description("This research tree tracks the knowledge required to craft knives, daggers, and swords");
        addPrerequisite("weaponsmithing", (["type":"skill", "value" : 3]));
        addResearchElement("lib/instances/research/crafting/craftBasicSwords.c");
        TreeRoot("lib/instances/research/crafting/craftBasicSwords.c");
    }
}

