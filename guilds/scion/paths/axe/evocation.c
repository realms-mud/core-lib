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
        Name("Path of Evocation");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the knowledge to "
            "express their raw magical energy as pure magical essence "
            "given form.");

        addResearchElement("lib/guilds/scion/paths/axe/evocation/root.c");
        TreeRoot("lib/guilds/scion/paths/axe/evocation/root.c");
    }
}
