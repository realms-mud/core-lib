//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        Source("mage guild");
        addResearchElement("lib/tests/support/research/testTreeRoot.c");
        addResearchElement("lib/tests/support/research/testLimitedByIntoxResearchItem.c");
        addResearchElement("lib/tests/support/research/mockResearchTimed.c");
        addResearchElement("lib/modules/research/activeResearchItem.c");
        addResearchElement("lib/modules/research/instantaneousActiveResearchItem.c");
        addResearchElement("lib/modules/research/instantaneousRitualResearchItem.c");
        addResearchElement("lib/modules/research/knowledgeResearchItem.c");
        addResearchElement("lib/modules/research/passiveResearchItem.c");
        addResearchElement("lib/modules/research/persistedActiveResearchItem.c");
        addResearchElement("lib/modules/research/persistedRitualResearchItem.c");
        TreeRoot("lib/tests/support/research/testTreeRoot.c");
        addChild("lib/tests/support/research/testLimitedByIntoxResearchItem.c", "lib/tests/support/research/testTreeRoot.c");
        addChild("lib/tests/support/research/mockResearchTimed.c", "lib/tests/support/research/testTreeRoot.c");
        addChild("lib/modules/research/activeResearchItem.c", "lib/tests/support/research/testTreeRoot.c");
        addChild("lib/modules/research/instantaneousActiveResearchItem.c", "lib/tests/support/research/testTreeRoot.c");
        addChild("lib/modules/research/instantaneousRitualResearchItem.c", "lib/tests/support/research/testLimitedByIntoxResearchItem.c");
        addChild("lib/modules/research/knowledgeResearchItem.c", "lib/tests/support/research/testLimitedByIntoxResearchItem.c");
        addChild("lib/modules/research/knowledgeResearchItem.c", "lib/modules/research/instantaneousActiveResearchItem.c");
        addChild("lib/modules/research/passiveResearchItem.c", "lib/modules/research/instantaneousActiveResearchItem.c");
        addChild("lib/modules/research/persistedActiveResearchItem.c", "lib/modules/research/passiveResearchItem.c");
        addChild("lib/modules/research/persistedRitualResearchItem.c", "lib/modules/research/passiveResearchItem.c");
        addChild("lib/modules/research/persistedRitualResearchItem.c", "lib/modules/research/knowledgeResearchItem.c");
    }
}

