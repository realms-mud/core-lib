//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("tree of blargness");
    Description("this is the land-loving mother pigeon of all research trees");
    Source("blarg");
    addResearchElement("/lib/tests/support/research/compositeRoot.c");
    addResearchElement("/lib/tests/support/research/compositeResearchItemA.c");
    addResearchElement("/lib/tests/support/research/compositeResearchItemB.c");
    addResearchElement("/lib/tests/support/research/compositeResearchItemC.c");
    addResearchElement("/lib/tests/support/research/compositeResearchItemD.c");
    addResearchElement("/lib/tests/support/research/compositeResearchItemE.c");
    TreeRoot("/lib/tests/support/research/compositeRoot.c");
}
