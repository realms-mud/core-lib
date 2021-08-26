//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void AttackResearch()
{

}

/////////////////////////////////////////////////////////////////////////////
public void DamageResearch()
{

}

/////////////////////////////////////////////////////////////////////////////
public void DefenseResearch()
{

}

/////////////////////////////////////////////////////////////////////////////
public void HealthResearch()
{

}


/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Infantry Research");
    Description("This research tree tracks the knowledge required to enhance "
        "ones infantry combat abilities.");
    Source("domain");
    TreeRoot("/lib/instances/research/domains/troops/combat/infantry/root.c");

    AttackResearch();
    DamageResearch();
    DefenseResearch();
    HealthResearch();
}
