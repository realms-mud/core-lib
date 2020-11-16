//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("tree of researchiness");
        Description("this is the land-loving mother pigeon of all research trees");
        addPrerequisite("long sword", (["type":"skill", "value" : 10]));
        addResearchElement("lib/tests/support/research/testTreeRoot.c");
        TreeRoot("lib/tests/support/research/testTreeRoot.c");
    }
}
