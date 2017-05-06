//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object ResearchItem;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/modules/research/knowledgeResearchItem");
    ResearchItem->init();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(ResearchItem);
}

/////////////////////////////////////////////////////////////////////////////
void TypeIsKnowledge()
{
    ExpectEq("knowledge", ResearchItem->query("type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void ScopeIsSelf()
{
    ExpectEq("self", ResearchItem->query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void EffectIsStrategic()
{
    ExpectEq("strategic", ResearchItem->query("effect"), "query the research effect");
}

