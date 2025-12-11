//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("tree of constructed researchiness");
    Description("this is the test tree for constructed research");
    Source("blarg");
    addResearchElement("/lib/tests/support/research/constructedRoot.c");
    addResearchElement("/lib/tests/support/research/constructedFormA.c");
    addResearchElement("/lib/tests/support/research/constructedFunctionA.c");
    addResearchElement("/lib/tests/support/research/constructedEffectA.c");
    TreeRoot("/lib/tests/support/research/constructedRoot.c");
}
