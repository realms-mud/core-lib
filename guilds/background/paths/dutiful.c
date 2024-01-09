//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("A Dutiful Child");
    Description("");
    Source("background");
    addResearchElement("/guilds/background/paths/dutiful/root.c");
    TreeRoot("/guilds/background/paths/dutiful/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
}
