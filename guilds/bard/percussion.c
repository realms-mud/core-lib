//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/bard/percussion/snare-of-the-soldier.c");

    addChild("/guilds/bard/percussion/snare-of-the-soldier.c",
        "/guilds/bard/percussion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/bard/percussion/percussive-blast.c");

    addChild("/guilds/bard/percussion/percussive-blast.c",
        "/guilds/bard/percussion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/bard/percussion/drums-of-doom.c");
    addResearchElement("/guilds/bard/percussion/drums-of-dedication.c");

    addChild("/guilds/bard/percussion/drums-of-doom.c",
        "/guilds/bard/percussion/root.c");
    addChild("/guilds/bard/percussion/drums-of-dedication.c",
        "/guilds/bard/percussion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/bard/percussion/beat-of-the-broken.c");

    addChild("/guilds/bard/percussion/beat-of-the-broken.c",
        "/guilds/bard/percussion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/bard/percussion/double-time.c");
    addResearchElement("/guilds/bard/percussion/slow-dance.c");

    addChild("/guilds/bard/percussion/double-time.c",
        "/guilds/bard/percussion/drums-of-dedication.c");
    addChild("/guilds/bard/percussion/slow-dance.c",
        "/guilds/bard/percussion/drums-of-doom.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/bard/percussion/mystic-rhythms.c");

    addChild("/guilds/bard/percussion/mystic-rhythms.c",
        "/guilds/bard/percussion/beat-of-the-broken.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/bard/percussion/keeping-time.c");

    addChild("/guilds/bard/percussion/keeping-time.c",
        "/guilds/bard/percussion/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/bard/percussion/metered-malaise.c");

    addChild("/guilds/bard/percussion/metered-malaise.c",
        "/guilds/bard/percussion/slow-dance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/bard/percussion/fell-beat.c");

    addChild("/guilds/bard/percussion/fell-beat.c",
        "/guilds/bard/percussion/drums-of-dedication.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/bard/percussion/counterspell-knell.c");

    addChild("/guilds/bard/percussion/counterspell-knell.c",
        "/guilds/bard/percussion/fell-beat.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/bard/percussion/blessing-of-bhelac.c");

    addChild("/guilds/bard/percussion/blessing-of-bhelac.c",
        "/guilds/bard/percussion/counterspell-knell.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/bard/percussion/advanced-timing.c");

    addChild("/guilds/bard/percussion/advanced-timing.c",
        "/guilds/bard/percussion/keeping-time.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/bard/percussion/beat-of-baxeros.c");

    addChild("/guilds/bard/percussion/beat-of-baxeros.c",
        "/guilds/bard/percussion/fell-beat.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/bard/percussion/blast-beat.c");

    addChild("/guilds/bard/percussion/blast-beat.c",
        "/guilds/bard/percussion/counterspell-knell.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/bard/percussion/bhelacs-tune.c");

    addChild("/guilds/bard/percussion/bhelacs-tune.c",
        "/guilds/bard/percussion/blessing-of-bhelac.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/bard/percussion/modulated-timing.c");

    addChild("/guilds/bard/percussion/modulated-timing.c",
        "/guilds/bard/percussion/advanced-timing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/bard/percussion/baxeros-meter.c");

    addChild("/guilds/bard/percussion/baxeros-meter.c",
        "/guilds/bard/percussion/beat-of-baxeros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/bard/percussion/rhythm-of-landros.c");

    addChild("/guilds/bard/percussion/rhythm-of-landros.c",
        "/guilds/bard/percussion/counterspell-knell.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/bard/percussion/fibonacci-timing.c");

    addChild("/guilds/bard/percussion/fibonacci-timing.c",
        "/guilds/bard/percussion/modulated-timing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/bard/percussion/duotime-drive.c");

    addChild("/guilds/bard/percussion/duotime-drive.c",
        "/guilds/bard/percussion/baxeros-meter.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/bard/percussion/golden-measures.c");

    addChild("/guilds/bard/percussion/golden-measures.c",
        "/guilds/bard/percussion/fibonacci-timing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/bard/percussion/percussion-mastery.c");

    addChild("/guilds/bard/percussion/percussion-mastery.c",
        "/guilds/bard/percussion/duotime-drive.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Percussive Components for Compositions");
    Description("");
    Source("bard");
    addResearchElement("/guilds/bard/percussion/root.c");
    TreeRoot("/guilds/bard/percussion/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
}
