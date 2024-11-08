//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object ResearchItem;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/modules/domains/domainResearchItem");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(ResearchItem);
}

/////////////////////////////////////////////////////////////////////////////
void TypeIsKnowledge()
{
    ExpectEq("domain", ResearchItem.query("type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void ScopeIsSelf()
{
    ExpectEq("domain", ResearchItem.query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void EffectIsStrategic()
{
    ExpectEq("strategic", ResearchItem.query("effect"), "query the research effect");
}
