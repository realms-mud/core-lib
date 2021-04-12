//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/bard/melee/melees-melody.c");

    addChild("/guilds/bard/melee/melees-melody.c",
        "/guilds/bard/melee/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/bard/melee/anthem-of-attack.c");

    addChild("/guilds/bard/melee/anthem-of-attack.c",
        "/guilds/bard/melee/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/bard/melee/melee-tune.c");

    addChild("/guilds/bard/melee/melee-tune.c",
        "/guilds/bard/melee/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/bard/melee/defenders-lament.c");

    addChild("/guilds/bard/melee/defenders-lament.c",
        "/guilds/bard/melee/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/bard/melee/footmans-tune.c");

    addChild("/guilds/bard/melee/footmans-tune.c",
        "/guilds/bard/melee/melees-melody.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/bard/melee/melee-march.c");

    addChild("/guilds/bard/melee/melee-march.c",
        "/guilds/bard/melee/melees-melody.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/bard/melee/rhythmic-riposte.c");

    addChild("/guilds/bard/melee/rhythmic-riposte.c",
        "/guilds/bard/melee/melees-melody.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/bard/melee/song-of-the-strong.c");

    addChild("/guilds/bard/melee/song-of-the-strong.c",
        "/guilds/bard/melee/footmans-tune.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/bard/melee/sangine-song.c");

    addChild("/guilds/bard/melee/sangine-song.c",
        "/guilds/bard/melee/melees-melody.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/bard/melee/soldiers-song.c");

    addChild("/guilds/bard/melee/soldiers-song.c",
        "/guilds/bard/melee/melee-march.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/bard/melee/armsmans-form.c");

    addChild("/guilds/bard/melee/armsmans-form.c",
        "/guilds/bard/melee/rhythmic-riposte.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/bard/melee/requiem-of-attack.c");

    addChild("/guilds/bard/melee/requiem-of-attack.c",
        "/guilds/bard/melee/song-of-the-strong.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/bard/melee/serenade-of-the-soldier.c");

    addChild("/guilds/bard/melee/serenade-of-the-soldier.c",
        "/guilds/bard/melee/soldiers-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/bard/melee/armsmans-breath.c");

    addChild("/guilds/bard/melee/armsmans-breath.c",
        "/guilds/bard/melee/armsmans-form.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/bard/melee/arms-lament.c");

    addChild("/guilds/bard/melee/arms-lament.c",
        "/guilds/bard/melee/serenade-of-the-soldier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/bard/melee/armsmasters-tale.c");

    addChild("/guilds/bard/melee/armsmasters-tale.c",
        "/guilds/bard/melee/requiem-of-attack.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/bard/melee/footmans-ballad.c");
    addResearchElement("/guilds/bard/melee/dirge-of-destruction.c");

    addChild("/guilds/bard/melee/footmans-ballad.c",
        "/guilds/bard/melee/arms-lament.c");
    addChild("/guilds/bard/melee/dirge-of-destruction.c",
        "/guilds/bard/melee/sangine-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/bard/melee/minstrels-melee.c");

    addChild("/guilds/bard/melee/minstrels-melee.c",
        "/guilds/bard/melee/armsmans-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/bard/melee/weapon-masters-tale.c");

    addChild("/guilds/bard/melee/weapon-masters-tale.c",
        "/guilds/bard/melee/footmans-ballad.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/bard/melee/lay-of-the-armsmaster.c");

    addChild("/guilds/bard/melee/lay-of-the-armsmaster.c",
        "/guilds/bard/melee/weapon-masters-tale.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Melee Weapons");
    Description("");
    Source("bard");
    addResearchElement("/guilds/bard/melee/root.c");
    TreeRoot("/guilds/bard/melee/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    TenthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SixteenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
}
