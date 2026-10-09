//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/grave-touch.c");
    addResearchElement("/guilds/disciple-of-argloth/death/touch-of-death.c");

    addChild("/guilds/disciple-of-argloth/death/grave-touch.c",
        "/guilds/disciple-of-argloth/death/root.c");
    addChild("/guilds/disciple-of-argloth/death/touch-of-death.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/final-passage.c");

    addChild("/guilds/disciple-of-argloth/death/final-passage.c",
        "/guilds/disciple-of-argloth/death/touch-of-death.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/last-breath.c");

    addChild("/guilds/disciple-of-argloth/death/last-breath.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/death-mark.c");

    addChild("/guilds/disciple-of-argloth/death/death-mark.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/death-knell.c");

    addChild("/guilds/disciple-of-argloth/death/death-knell.c",
        "/guilds/disciple-of-argloth/death/grave-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/mortal-wound.c");

    addChild("/guilds/disciple-of-argloth/death/mortal-wound.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/dying-curse.c");

    addChild("/guilds/disciple-of-argloth/death/dying-curse.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/reaping-wave.c");

    addChild("/guilds/disciple-of-argloth/death/reaping-wave.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/threshold.c");

    addChild("/guilds/disciple-of-argloth/death/threshold.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/undying-hunger.c");

    addChild("/guilds/disciple-of-argloth/death/undying-hunger.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/death-trance.c");

    addChild("/guilds/disciple-of-argloth/death/death-trance.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/sever-soul.c");

    addChild("/guilds/disciple-of-argloth/death/sever-soul.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/black-wind.c");

    addChild("/guilds/disciple-of-argloth/death/black-wind.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/deaths-embrace.c");

    addChild("/guilds/disciple-of-argloth/death/deaths-embrace.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/reaper-form.c");

    addChild("/guilds/disciple-of-argloth/death/reaper-form.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/killing-cold.c");

    addChild("/guilds/disciple-of-argloth/death/killing-cold.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/soul-rend.c");

    addChild("/guilds/disciple-of-argloth/death/soul-rend.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/mortality.c");

    addChild("/guilds/disciple-of-argloth/death/mortality.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/deaths-door.c");

    addChild("/guilds/disciple-of-argloth/death/deaths-door.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/final-silence.c");

    addChild("/guilds/disciple-of-argloth/death/final-silence.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/annihilate.c");

    addChild("/guilds/disciple-of-argloth/death/annihilate.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/death-amplification-ii.c");
    addResearchElement("/guilds/disciple-of-argloth/death/void-touch.c");

    addChild("/guilds/disciple-of-argloth/death/death-amplification-ii.c",
        "/guilds/disciple-of-argloth/death/root.c");
    addChild("/guilds/disciple-of-argloth/death/void-touch.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/deathbound.c");

    addChild("/guilds/disciple-of-argloth/death/deathbound.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/death-chosen.c");

    addChild("/guilds/disciple-of-argloth/death/death-chosen.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/death-resilience.c");

    addChild("/guilds/disciple-of-argloth/death/death-resilience.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/scythe-of-argloth.c");
    addResearchElement("/guilds/disciple-of-argloth/death/inevitable-end.c");

    addChild("/guilds/disciple-of-argloth/death/scythe-of-argloth.c",
        "/guilds/disciple-of-argloth/death/root.c");
    addChild("/guilds/disciple-of-argloth/death/inevitable-end.c",
        "/guilds/disciple-of-argloth/death/scythe-of-argloth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/ending-amplification.c");
    addResearchElement("/guilds/disciple-of-argloth/death/killing-word.c");

    addChild("/guilds/disciple-of-argloth/death/ending-amplification.c",
        "/guilds/disciple-of-argloth/death/root.c");
    addChild("/guilds/disciple-of-argloth/death/killing-word.c",
        "/guilds/disciple-of-argloth/death/inevitable-end.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/morbid-attunement.c");

    addChild("/guilds/disciple-of-argloth/death/morbid-attunement.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/grave-dominion.c");

    addChild("/guilds/disciple-of-argloth/death/grave-dominion.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/dying-blow.c");

    addChild("/guilds/disciple-of-argloth/death/dying-blow.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/reapers-toll.c");

    addChild("/guilds/disciple-of-argloth/death/reapers-toll.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/death-amplification.c");
    addResearchElement("/guilds/disciple-of-argloth/death/deathbringer.c");

    addChild("/guilds/disciple-of-argloth/death/death-amplification.c",
        "/guilds/disciple-of-argloth/death/root.c");
    addChild("/guilds/disciple-of-argloth/death/deathbringer.c",
        "/guilds/disciple-of-argloth/death/killing-word.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/cold-inevitability.c");
    addResearchElement("/guilds/disciple-of-argloth/death/deathbringer-mastery.c");

    addChild("/guilds/disciple-of-argloth/death/cold-inevitability.c",
        "/guilds/disciple-of-argloth/death/root.c");
    addChild("/guilds/disciple-of-argloth/death/deathbringer-mastery.c",
        "/guilds/disciple-of-argloth/death/deathbringer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/entropy.c");

    addChild("/guilds/disciple-of-argloth/death/entropy.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/beyond-death.c");

    addChild("/guilds/disciple-of-argloth/death/beyond-death.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/disciple-of-argloth/death/argloth-reaper.c");

    addChild("/guilds/disciple-of-argloth/death/argloth-reaper.c",
        "/guilds/disciple-of-argloth/death/root.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("The Art of Death");
    Description("The direct application of death energy as a weapon - the power to deliver death itself as a force, as practiced by Argloth's most lethal disciples.");
    Source("Disciple of Argloth");
    addResearchElement("/guilds/disciple-of-argloth/death/root.c");
    TreeRoot("/guilds/disciple-of-argloth/death/root.c");

    FirstLevel();
    FourthLevel();
    FifthLevel();
    SeventhLevel();
    EighthLevel();
    NinthLevel();
    TenthLevel();
    FourteenthLevel();
    SixteenthLevel();
    EighteenthLevel();
    TwentiethLevel();
    TwentySecondLevel();
    TwentyFifthLevel();
    TwentySixthLevel();
    TwentyEighthLevel();
    ThirtiethLevel();
    ThirtySecondLevel();
    ThirtyFourthLevel();
    ThirtySixthLevel();
    ThirtyEighthLevel();
    FortiethLevel();
    FortySecondLevel();
    FortyFourthLevel();
    FortySixthLevel();
    FortyEighthLevel();
    FiftiethLevel();
    FiftySecondLevel();
    FiftyFourthLevel();
    FiftyFifthLevel();
    FiftySixthLevel();
    FiftyEighthLevel();
    SixtiethLevel();
    SixtySecondLevel();
    SixtyFourthLevel();
    SixtySixthLevel();
    SeventiethLevel();
}
