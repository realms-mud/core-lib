//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/discipline/initiates-discipline.c");
    addResearchElement("/guilds/monk/discipline/disciplined-breath.c");

    addChild("/guilds/monk/discipline/initiates-discipline.c",
        "/guilds/monk/discipline/root.c");
    addChild("/guilds/monk/discipline/disciplined-breath.c",
        "/guilds/monk/discipline/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/discipline/steady-practice.c");

    addChild("/guilds/monk/discipline/steady-practice.c",
        "/guilds/monk/discipline/disciplined-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/discipline/teachers-recognition.c");

    addChild("/guilds/monk/discipline/teachers-recognition.c",
        "/guilds/monk/discipline/steady-practice.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/discipline/controlled-expenditure.c");

    addChild("/guilds/monk/discipline/controlled-expenditure.c",
        "/guilds/monk/discipline/disciplined-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/discipline/students-awareness.c");

    addChild("/guilds/monk/discipline/students-awareness.c",
        "/guilds/monk/discipline/disciplined-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/discipline/disciples-insight.c");
    addResearchElement("/guilds/monk/discipline/adepts-trial.c");

    addChild("/guilds/monk/discipline/disciples-insight.c",
        "/guilds/monk/discipline/students-awareness.c");
    addChild("/guilds/monk/discipline/adepts-trial.c",
        "/guilds/monk/discipline/disciples-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/discipline/adepts-focus.c");
    addResearchElement("/guilds/monk/discipline/senior-disciples-trial.c");

    addChild("/guilds/monk/discipline/adepts-focus.c",
        "/guilds/monk/discipline/disciples-insight.c");
    addChild("/guilds/monk/discipline/senior-disciples-trial.c",
        "/guilds/monk/discipline/adepts-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/monk/discipline/inner-discipline.c");
    addResearchElement("/guilds/monk/discipline/master-candidates-trial.c");

    addChild("/guilds/monk/discipline/inner-discipline.c",
        "/guilds/monk/discipline/adepts-focus.c");
    addChild("/guilds/monk/discipline/master-candidates-trial.c",
        "/guilds/monk/discipline/inner-discipline.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/discipline/mastery-of-fundamentals.c");
    addResearchElement("/guilds/monk/discipline/masters-trial.c");

    addChild("/guilds/monk/discipline/mastery-of-fundamentals.c",
        "/guilds/monk/discipline/inner-discipline.c");
    addChild("/guilds/monk/discipline/masters-trial.c",
        "/guilds/monk/discipline/mastery-of-fundamentals.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("monastic discipline");
    Description("The foundations of breath, awareness, focus, and practice that "
        "support advancement through the monk guild.");
    Source("monk");
    deferResearchLoading();

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addResearchElement("/guilds/monk/discipline/root.c");
    TreeRoot("/guilds/monk/discipline/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourteenthLevel();
    TwentiethLevel();
    ThirtiethLevel();
    FortiethLevel();
    FiftyFifthLevel();
    SeventiethLevel();
}
